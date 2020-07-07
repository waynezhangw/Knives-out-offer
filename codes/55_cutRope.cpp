#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using std::cout;
using std::vector;
class Solution {
public:
    /*
    int cutRope(int number) {
        if (number < 2) return 0;
        else if (number == 2) history[2] = 1;
        else if (number == 3) history[3] = 2;
        else {
            vector<int> history(number+1, 0);
            recursiveCut(4, 1, history);
        }
        return history[number];
    }
    int recursiveCut(int number, int now, vector<int>& history) {   //my recursive method is not working here
        if (number <= 1) {
            return now;
        }
        if (history[number] > 0) {
            return now*history[number];
        }
        for (int i = 0; i <= number; i++) {
            int temp = recursiveCut(number - i, now * i, history);
            history[number - i] = temp;
        }
    }
    */

    int cutRope(int number) {               //greedy algorithm from discussion's method, 5ms and 632k
        if (number < 2) return 0;
        else if (number == 2) return 1;
        else if (number == 3) return 2;
        else if (number == 4) return 4;
        else {
            int n = number%3;
            if (n == 1) return int(pow(3.0, number/3 - 1) * pow(2.0, 2));
            else if (n == 0) return int(pow(3.0, number/3));
            else return int(pow(3.0, number/3) * n);
        }
    }

    int cutRope2(int number) {      //dynamic programming from kives book, 5ms and 620k, feels that the time and space is not accurate
        vector<int> history(number+1, 0);
        if (number < 2) return 0;
        else if (number == 2) return 1;
        else if (number == 3) return 2;
        else {
            history[1] = 1;
            history[2] = 2;
            history[3] = 3;
            for (int i=4;i<=number;i++) {
                int tempMax = 0;
                for (int j=1;j<=i/2;j++) {
                    tempMax = std::max(tempMax, history[j]*history[i-j]);
                }
                history[i] = tempMax;
            }
        }
        return history[number];
    }
};

int main() {
    Solution sol;
    int result = sol.cutRope2(50);
    cout << "result: " << result << std::endl;
    return 0;
}