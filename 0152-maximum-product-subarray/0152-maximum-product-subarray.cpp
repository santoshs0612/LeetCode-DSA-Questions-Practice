class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;
        int leftProd=0;
        int rightProd=0; 
        int i =0;
        while(i<n){
            
            if(leftProd ==0) leftProd =1;
            if(rightProd ==0) rightProd =1;
            leftProd = leftProd * nums[i];
            rightProd= rightProd * nums[n-i-1];
            maxProd = max(maxProd , max(leftProd, rightProd));
            i++;
        }
        
        return int(maxProd);
    }
};