class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        map<int, int> indegree;

        for(int i=0; i<prerequisites.size(); i++) {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];

            graph[from].push_back(to);
            indegree[to]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        int visited = 0;

        while(!q.empty()) {
            int course = q.front();
            q.pop();

            visited++;
            for(int i=0; i<graph[course].size(); i++) {
                indegree[graph[course][i]]--;

                if(indegree[graph[course][i]] == 0)
                    q.push(graph[course][i]);
            }
        }

        return visited == numCourses;
    }
};