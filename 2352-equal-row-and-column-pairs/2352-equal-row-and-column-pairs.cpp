class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
          int count = 0, n = grid.size();
        
        // Check each row r against each column c.
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                bool match = true;

                // Iterate over row r and column c.
                for (int i = 0; i < n; ++i) {
                    if (grid[r][i] != grid[i][c]) {
                        match = false;
                        break;
                    }
                }

                // If row r equals column c, increment count by 1.
                count += match ? 1 : 0;
            }
        }
        
        return count;  
    }
};