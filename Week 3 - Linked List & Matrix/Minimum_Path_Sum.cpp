class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > aux(m, vector<int>(n));

        aux[0][0] = grid[0][0];

        for(int i=1; i<m; i++)
            aux[i][0] = grid[i][0] + aux[i-1][0];
        
        for(int i=1; i<n; i++)
            aux[0][i] = grid[0][i] + aux[0][i-1];
        
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++)
                aux[i][j] = grid[i][j] + min(aux[i-1][j], aux[i][j-1]);
        }

        return aux[m-1][n-1];
    }
};