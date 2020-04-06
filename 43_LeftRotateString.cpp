#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
class Solution {
public:
    string LeftRotateString(string str, int n) {
    	if (n < 0 || n > (int)str.length()) return str;
        string str1 = str.substr(0,n);
        string str2 = str.substr(n);
        return str2+str1;
    }
};

int main() {
	Solution sol;
	string str = "abcXYZdef acd";
	cout<<sol.LeftRotateString(str, 3)<<endl;
	return 0;
}