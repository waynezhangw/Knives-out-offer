#include<iostream>
#include<vector>

using std::vector;
class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {   //from my thought with hint on the book, 3ms and 480k
        if (rows < 1 || cols < 1) return 0;
        vector<bool> visited(rows*cols, false);
        return movingStep(threshold, rows, cols, 0, 0, visited);
    }

    int movingStep(int threshold, int rows, int cols, int nowR, int nowC, vector<bool>& visited) {
        int count = 0;
        if (nowC >= 0 && nowC < cols && nowR >= 0 && nowR < rows && !visited[nowR*cols+nowC] &&
            getRCSum(nowR)+getRCSum(nowC) <= threshold) {
            visited[nowR*cols+nowC] = true;
            count = 1 + movingStep(threshold, rows, cols, nowR-1, nowC, visited) + 
            movingStep(threshold, rows, cols, nowR+1, nowC, visited) + 
            movingStep(threshold, rows, cols, nowR, nowC+1, visited) + 
            movingStep(threshold, rows, cols, nowR, nowC-1, visited);
        }
        return count;
    }

    int getRCSum(int num) {
        int sumRC = 0;
        while(num != 0) {
            sumRC += num%10;
            num = num/10;
        }
        return sumRC;
    }
};

int main () {    //the direct iteration will not work, because of the Isolated island point(for example, 10,10)
    Solution sol;
    std::cout<<sol.movingCount(2, 4, 1)<<std::endl;
    return 0;
}