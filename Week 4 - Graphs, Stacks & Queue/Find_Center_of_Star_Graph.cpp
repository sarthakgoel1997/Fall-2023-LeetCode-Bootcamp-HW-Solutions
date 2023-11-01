class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> indegree(n+1);

        for(int i=0; i<n-1; i++) {
            int from = edges[i][0];
            int to = edges[i][1];

            indegree[from]++;
            indegree[to]++;

            if(indegree[from] == n-1)
                return from;
            
            if(indegree[to] == n-1)
                return to;
        }

        return -1;
    }
};