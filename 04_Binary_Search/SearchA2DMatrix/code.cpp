#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // guard for empty matrix / empty rows
        if (matrix.empty() || matrix[0].empty()) return false;

        int ROWS = (int)matrix.size();
        int COLS = (int)matrix[0].size();

        // 1) binary search to find the row that could contain target
        int top = 0, bot = ROWS - 1;
        int row = -1;
        while (top <= bot) {
            int mid = top + (bot - top) / 2;
            int rowFirst = matrix[mid][0];
            int rowLast  = matrix[mid][COLS - 1];

            if (target > rowLast) {
                top = mid + 1;           // target is in a later row
            } else if (target < rowFirst) {
                bot = mid - 1;           // target is in an earlier row
            } else {
                // target is between rowFirst and rowLast (inclusive)
                row = mid;
                break;
            }
        }

        if (row == -1) return false;     // no row can contain target

        // 2) binary search inside that row
        int l = 0, r = COLS - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;     // correct midpoint
            if (target > matrix[row][m]) {
                l = m + 1;
            } else if (target < matrix[row][m]) {
                r = m - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
