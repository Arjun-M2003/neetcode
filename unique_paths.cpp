// cache results from certain spots
// for each spot farther used cached results and add on to it

#include <vector>
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m, vector<int>(n, -1));

        int result = findPath(paths, 0, 0, m, n);

        return result;
    }

    int findPath(vector<vector<int>>& paths, int row, int col, int m, int n){
        if(row == m-1 && col == n-1) return 1;
        if(row > m-1 || row < 0 || col > n-1 || col < 0) return 0;

        if(paths[row][col] != -1){
            return paths[row][col];
        }
        
        int right = findPath(paths, row + 1, col, m, n);
        int down = findPath(paths, row, col + 1, m, n);

        int total = right + down;
        paths[row][col] = total;

        return total;
    }
};
