#include<iostream>
#include<vector>

using std::vector;
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {     //copied the code on the kives book, 3ms and 380k
        if (matrix == NULL || rows < 1 || cols < 1 || str == NULL) return false;
        vector<bool> visted(rows*cols, false);
        int pathStrPos = 0;
        for (int row = 0;row < rows;row++) {
            for (int col = 0;col < cols;col++) {
                if (hasPathNow(matrix, rows, cols, row, col, str, pathStrPos, visted)) return true;
            }
        }
        return false;
    }

    bool hasPathNow(char* matrix, int rows, int cols, int nowR, int nowC, 
        char* str, int& pathStrPos, vector<bool>& visted) {
        if (str[pathStrPos] == '\0') return true;
        bool hasOne = false;
        if (nowR >= 0 && nowC >= 0 && nowR < rows && nowC < cols && !visted[nowR*cols + nowC] && 
            str[pathStrPos] == matrix[nowR*cols + nowC]) {
            pathStrPos++;
            visted[nowR*cols + nowC] = true;

            hasOne = hasPathNow(matrix, rows, cols, nowR-1, nowC, str, pathStrPos, visted) || 
            hasPathNow(matrix, rows, cols, nowR+1, nowC, str, pathStrPos, visted) || 
            hasPathNow(matrix, rows, cols, nowR, nowC-1, str, pathStrPos, visted) || 
            hasPathNow(matrix, rows, cols, nowR, nowC+1, str, pathStrPos, visted);

            if (!hasOne) {
                pathStrPos--;
                visted[nowR*cols + nowC] = false;
            }
        }
        return hasOne;
    }
};

int main() {
    Solution sol;
    char matrix[13] = "abcesfcsadee";
    char str[9] = "abcesee";
    std::cout<<sol.hasPath(matrix, 3, 4, str)<<std::endl;
    return 0;
}