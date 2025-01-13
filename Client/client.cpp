// includes 

#include<bits/stdc++.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;

// Assumend constants 

const int PORT = 3000;
const char* HOST = "127.0.0.1";
const int BUFFER_SIZE = 1024*2;
const int SOCKET_TIMEOUT = 5;

// packet format as defined 

struct packet {
    char symbol[4];
    char buySellIndicator;
    int32_t quantity;
    int32_t price;
    int32_t sequence;
};


// Function to set socket timeout
bool setSocketTimeout(int sockfd) {
    struct timeval timeout{};
    timeout.tv_sec = SOCKET_TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Failed to set socket timeout");
        return false;
    }
    return true;
}

void hadelingPackets(int sockfd){
    // Call Type 1 
    uint8_t reqType = 1;


    if(send(sockfd,&reqType,sizeof(reqType),0)<0){
        cerr<< "Error Sending Stream All Packet request"<<endl;
        return;
    }

    vector<int32_t> receivedSeq;

    set<int32_t> missedSeq;


    char buffer[BUFFER_SIZE];
    int byteRead;

    // Reciveing the response packet 

    while((byteRead = recv(sockfd,buffer,BUFFER_SIZE,0))>0){

        for(int i=0;i<byteRead;i+=sizeof(packet)){

            packet p;
            memcpy(&p,buffer+i,sizeof(packet));


            // convert fields to host order 
            // p.quantity = ntohl(p.quantity);
            // p.price=ntohl(p.price);
            // p.sequence = ntohl(p.sequence);

            cout<<"Symbol: "<< string(p.symbol,4)<< ",Buy/Sell: "<<p.buySellIndicator<<", Quantity: "<<p.quantity<<", Price: "<<p.price<<", Sequence: "<<p.sequence<<endl;
            receivedSeq.push_back(p.sequence);
        }
    }

    if(byteRead<0){
        cerr<<"Error receiving packets"<<endl;
    }

    // finding out the missing packets 

    cout<<"The missing packets are as follows:"<<endl;

    for(size_t i= 1; i<receivedSeq.size();i++){

        for(int seq = receivedSeq[i-1]+1;seq<receivedSeq[i];seq++){
            missedSeq.insert(seq);
        }
    }
    int ind=1;
    for(auto it:missedSeq){
        cout<<ind++<<" "<<it<<endl;
    }
    // cout<< "Not any Missing packet";
    close(sockfd);

    // request for the missing packets 

    for(int seq:missedSeq){
        int sockfd = socket(AF_INET,SOCK_STREAM,0);
        if(sockfd < 0){
            cerr<<"Error Creating socket"<<endl;
            return;
        }

        // connecting to the server 
        
        struct sockaddr_in server_addr;
        memset(&server_addr,0,sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(PORT);


        if(inet_pton(AF_INET,HOST,&server_addr.sin_addr)<=0){
            cerr<<"Invalid Address/ Address not supported"<< endl;
            close(sockfd);
            return;
        }


        if(connect(sockfd, (struct sockaddr*)&server_addr,sizeof(server_addr))<0){
            cerr<< "Connection Failed "<<endl;
            close(sockfd);
            return;
        }

        uint8_t req[2];
        req[0]=2;
        req[1]= seq;


        if(send(sockfd,&req,sizeof(req),0)<0){
            cerr<< "Error Sending Stream resent Packet request"<<endl;
            close(sockfd);
            continue;
        }

        byteRead = recv(sockfd,buffer,BUFFER_SIZE,0);

        if(byteRead > 0){

            packet p;
            memcpy(&p,buffer,sizeof(p));

            cout<<"[Resent Packet] Symbol: "<< string(p.symbol,4)<< ",Buy/Sell: "<<p.buySellIndicator<<", Quantity: "<<p.quantity<<", Price: "<<p.price<<", Sequence: "<<p.sequence<<endl;
        }
        close(sockfd);
    }
    return;
}




int main(){

    // create a socket 

    int sockfd = socket(AF_INET,SOCK_STREAM,0);

    if(sockfd <0){
        cerr<< "Error Creating a Scoket"<<endl;
        return 1;
    }


    // connecting to the server 
    
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);


    if(inet_pton(AF_INET,HOST,&server_addr.sin_addr)<=0){
        cerr<<"Invalid Address/ Address not supported"<< endl;
        close(sockfd);
        return 1;
    }


    if(connect(sockfd, (struct sockaddr*)&server_addr,sizeof(server_addr))<0){
        cerr<< "Connection Failed "<<endl;
        close(sockfd);
        return 1;
    }

    // Time out handleing
    if (!setSocketTimeout(sockfd)) {
        close(sockfd);
        return 1;
    }
    cout<<"Processing Started"<<endl;
    hadelingPackets(sockfd);
    cout<<"Processing Ended"<<endl;

    close(sockfd);
    return 0;
}