class Solution {
public:
    int maxProduct(vector<int>& nums) {


        int maxProd= 0;
        if(nums.size()==1){
            return nums[0];
        }
        for(int i=0;i<nums.size();i++){
            int tempProd = nums[i];
            maxProd = max(maxProd , tempProd);
            for(int j=i+1;j<nums.size();j++){
                tempProd = tempProd * nums[j];
                maxProd = max(maxProd, tempProd);
            }
        }
        return maxProd;
        
    }
};