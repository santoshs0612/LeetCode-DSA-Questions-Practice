class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count =0;
        while(a>0 || b>0 ||c>0){
            bool reqC = (c&1);
            bool reqA = (a&1);
            bool reqB = (b&1);
            // check for the a abd b 
            if(reqC){

                if(!(reqA || reqB)){
                    count++;
                }
            }else {

                if(reqA && reqB){
                    count+=2;
                }else if(reqA ){
                    count++;
                }else if(reqB){
                    count++;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;

        }
        return count;
        
    }
};