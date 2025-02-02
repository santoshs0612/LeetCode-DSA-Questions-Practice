class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> mp(bank.begin(),bank.end());


        queue<pair<string,int>> q;
        q.push({startGene,0});
        // unordered_map<string> visited;

        while(!q.empty()){

            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word==endGene){
                return step;
            }

            for(int i=0;i<word.length();i++){
                char prev= word[i];

                for(auto w:"ACGT"){
                    word[i]=w;
                    if(mp.find(word)!=mp.end()){
                        q.push({word,step+1});
                        mp.erase(word);
                    }
                    word[i] = prev;
                }
            }
        }
        return -1;
    }
};