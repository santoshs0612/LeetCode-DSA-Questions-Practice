class Solution {
private:
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {


        sort(potions.begin(),potions.end());

        vector<int> ans;
        int n = potions.size();
        for(int i =0;i<spells.size();i++){

            int left= 0, right = n,mid =0;

            while(left<right){

                mid = left +(right-left)/2;

                if((long long)spells[i]*potions[mid]>=success){
                    right = mid;
                }else{
                    left = mid+1;
                }
            }
            ans.push_back(n-left);
        }

        return ans;

        
    }
};