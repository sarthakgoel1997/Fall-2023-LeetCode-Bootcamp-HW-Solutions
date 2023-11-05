class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for(int i=0; i<nums.size(); i++)
            freq[nums[i]]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        int el = 0;
        
        for(auto it = freq.begin(); it != freq.end(); it++) {
            if(el < k) {
                el++;
                pq.push({it->second, it->first});
            } else if(it->second > pq.top().first) {
                pq.pop();
                pq.push({it->second, it->first});
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};