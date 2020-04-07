#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::istringstream;
class Solution {
public:
    string ReverseSentence(string str) {   //这个是看了剑指offer得到的思路,两次reverse
        reverse(str.begin(),str.end());
        string::iterator start = str.begin();
        string::iterator end = str.begin();
        bool flag = false;
        while (end != str.end()) {
        	while (*end != ' '){
        		end++;
        		if (end == str.end()){
        			flag = true;
        			reverse(start, end);
        	        break;
        		}
        	}
        	if (flag) break;
        	reverse(start, end);
        	start = end+1;
        	end = start;
        }
        return str;
    }

    string ReverseSentence2(string str) {   //这里用逗号分隔重新排
    	if (str.length() < 1) return str;
        string result = "";
        istringstream sin(str);
        string field;
        while (getline(sin,field,' ')) {
        	result = " " + field + result;
        }
        if (str[str.length()-1] != ' ') result.erase(result.begin(),result.begin()+1);
        return result;
    }
};

int main() {
	Solution sol;
	string str = " student. a are You";
	cout<<sol.ReverseSentence(str)<<endl;
	cout<<sol.ReverseSentence2(str)<<endl;
	return 0;
}