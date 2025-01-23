class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        int count=0;

        // sort the arra y with respect to the second element 

        sort(intervals.begin(), intervals.end(), [](vector<int>&a,vector<int>&b){return a[1]<b[1];});

        // for(int i=0;i<n;i++){
        //     cout<<"["<<intervals[i][0]<<" "<<intervals[i][1]<<"]";
        // }
        int a = intervals[0][0];
        int b = intervals[0][1];
        for(int i=1;i<n;i++){

            if(intervals[i][0]>=b){
                a = min(a,intervals[i][0]);
                b = max(b,intervals[i][1]);
            }
            else{
                count++;
            }
        }
        return count;

    }
};