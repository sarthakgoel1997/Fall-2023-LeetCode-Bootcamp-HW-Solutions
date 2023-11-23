class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());

        int currStart = points[0][0], currEnd = points[0][1];
        int ans = 1;

        for(int i=1; i<n; i++) {
            if(points[i][0] > currEnd) {
                ans++;
                currStart = points[i][0], currEnd = points[i][1];
            } else {
                currStart = max(currStart, points[i][0]);
                currEnd = min(currEnd, points[i][1]);
            }
        }

        return ans;
    }
};