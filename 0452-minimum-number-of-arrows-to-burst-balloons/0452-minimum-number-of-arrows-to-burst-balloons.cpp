class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int>&b){return a[1]<b[1];});

        for(auto  it: points){
            cout<<it[0]<<" "<<it[1];
        }

        int end = points[0][1];
        int count=1;
        for(int i=0;i<n;i++){
            
            if(points[i][0]> end){   
                end = points[i][1];
                count++;
            }

        }
        return count;
        
    }
};