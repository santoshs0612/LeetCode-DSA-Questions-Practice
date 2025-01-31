class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {


        unordered_map<int,int> mp;
        for(auto it:hand){
            mp[it]++;
        }
        sort(hand.begin(),hand.end());

        for(int i=0;i<hand.size();i++){
            int it = hand[i];
            if(mp.find(it)!=mp.end()){
                for(int j=it;j<it+groupSize;j++){

                    if(mp.find(j)==mp.end()){
                        return false;
                    }
                    mp[j]--;
                    if(mp[j]==0){
                        mp.erase(j);
                    }
                }
            }
        }
        return true;
    }
};