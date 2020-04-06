#include<iostream>

using namespace std;
class Solution {
public:
    int Sum_Solution(int n) {
        int result = n;
        (n>0) && (result += Sum_Solution(n-1))>0;   //利用 && 的短路特性，别人讨论中的天才！！！
        return result;
    }
};

int main() {
	Solution sol;
	cout<<sol.Sum_Solution(10)<<endl;
	return 0;
}