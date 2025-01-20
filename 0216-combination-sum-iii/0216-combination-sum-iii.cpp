class Solution {
    vector<vector<int>> ans;
    void solverRec(vector<int> &arr,  int ind,int target, vector<int> &temp,int k){

            if(target ==0 && temp.size()==k){
                //sort(temp.begin(),temp.end());
                //reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                return;
            }
        for(int i=ind; i<arr.size();i++){

            // if(i>ind && arr[i]==arr[i-1])continue;

            if(arr[i]>target){
                return;
            }
            temp.push_back(arr[i]);
            solverRec(arr,i+1,target-arr[i],temp,k);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> arr;
        for(int i=1;i<10;i++){
            arr.push_back(i);
        }
        vector<int> temp;
        solverRec(arr, 0,n,temp,k);
        return ans;
        
    }
};