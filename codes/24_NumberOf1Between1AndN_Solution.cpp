#include<iostream>
#include<algorithm>
#include<string>     // std::string, std::to_string

using namespace std;
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n){
    	int sum = 0;
    	for (int i=1;i<=n;i++) {
    		string temp = to_string(i);
    		sum += count(begin(temp), end(temp), '1');
    	}
    	return sum;
    }

    int NumberOf1Between1AndN_Solution2(int n){   //解法2，看了别人的评论，可以用数学归纳法来做
    	if (n <= 0) {
    		return 0;
    	}
    	int sum = 0;
    	for (int i=1;i<=n;i*=10) {
    		int divider = i*10;
    		sum += (n/divider)*i + min(max(n%divider-i+1,0),i);
    	}
    	return sum;
    }
};

int main() {
	Solution sol;
	cout<<sol.NumberOf1Between1AndN_Solution(21235)<<endl;
	return 0;
}