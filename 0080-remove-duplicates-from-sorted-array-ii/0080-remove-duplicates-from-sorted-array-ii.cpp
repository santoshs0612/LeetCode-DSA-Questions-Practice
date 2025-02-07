class Solution {
public:
    int removeDuplicates(vector<int>& arr) {

        int k=2;

        if(arr.size()<=2){
            return arr.size();
        }

        for(int i=2;i<arr.size();i++){

            if(arr[i]!=arr[k-2]){
                arr[k]=arr[i];
                k++;
            }
        }

        return k;

        
    }
};