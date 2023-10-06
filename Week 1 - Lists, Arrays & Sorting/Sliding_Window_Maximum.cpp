class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> m;
        priority_queue<int> pq;

        int n = nums.size(), currWindowMax = INT_MIN;

        for(int i=0; i<k; i++) {
            pq.push(nums[i]);
            m[nums[i]]++;
        }

        int low = 0, high = k-1;

        while(high < n) {
            ans.push_back(pq.top());

            m[nums[low]]--;
            low++;

            high++;
            if(high == n)
                break;
            
            m[nums[high]]++;
            pq.push(nums[high]);

            while(m[pq.top()] == 0)
                pq.pop();
        }

        return ans;
    }
};