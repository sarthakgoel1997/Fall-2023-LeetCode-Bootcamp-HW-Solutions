class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size()-1, ans = INT_MIN;

        while(low < high) {
            int currArea = min(height[low], height[high]) * (high - low);
            ans = max(ans, currArea);

            if(height[low] <= height[high])
                low++;
            else
                high--;
        }

        return ans;
    }
};