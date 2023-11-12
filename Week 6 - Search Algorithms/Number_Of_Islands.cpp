class Solution {
public:
    vector<int> xdir{1, -1, 0, 0};
    vector<int> ydir{0, 0, 1, -1};

    bool isValid(int n, int m, int i, int j) {
        return !(i<0 || i>=n || j<0 || j>=m);
    }

    void func(vector<vector<char> > &grid, vector<vector<bool> > &visited, int n, int m, int i, int j) {
        for(int k=0; k<4; k++) {
            int x = i + xdir[k];
            int y = j + ydir[k];

            if(isValid(n, m, x, y) && !visited[x][y] && grid[x][y] == '1') {
                visited[x][y] = true;
                func(grid, visited, n, m, x, y);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        vector<vector<bool> > visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j]) {
                    visited[i][j] = true;

                    if(grid[i][j] == '1') {
                        ans++;
                        func(grid, visited, n, m, i, j);
                    }
                }
            }
        }

        return ans;
    }
};