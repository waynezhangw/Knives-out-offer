#include <iostream>
#include <set>
#include <algorithm> 
#include <cstring>

using namespace std;
class Solution {
public:
    bool isNumeric(char* str) {
    	string S = "";
    	for (unsigned int i=0;i<strlen(str);i++) {  //e的两边只能是整数，且e后面必须有值
    		S.push_back(str[i]);                   //+ - 后面只能是整数
    	}                                             // . 的两边只能是整数
    	set<char> special = {'.','+','-','e','E'};
    	for (unsigned int i=0;i<S.size();i++) {
    		if (!inNumbers(S[i])) {              //如果找到非数字的，那就要分割了
    			if (count(special.begin(), special.end(), S[i]) == 1) {    //如果是特殊符号就看下是不是那五个里的
    				string left = S.substr(0, i);
    			    string right = S.substr(i+1,S.size()-i);
    			    //如果是 .
    			    if (S[i] == '.') {
    			    	if (i+1 < S.size() && inNumbers(S[i+1])) {
    			    		for (unsigned int j=i+1;j<S.size();j++) if (S[j] == '.') return false;
    			    		return pureNumber(left) && isNumeric((char*)right.c_str());
    			    	}
    			    	else return false;
    			    }
    			    //如果是 e
    			    if (S[i] == 'e' || S[i] == 'E' ) {
    			    	if (i+1 < S.size()) return pureNumber(left) && pureNumber(right);
    			    	else return false;
    			    }
    			    //如果是 + -
    			    if (S[i] == '+' || S[i] == '-' ) {
    			    	if (i == 0 && S.size()>1 && (inNumbers(S[i+1]) || S[i+1] == '.')) return isNumeric((char*)right.c_str());
    			    	else return false;
    			    }
    			}
    			else return false;   //如果是特殊符号，还不是那5个之一，那就假了
    		}
    	}
    	return true;
    }

    bool pureNumber(string str) {  //判断是不是纯数字
    	if (str.length() == 0) return true;
    	if (str[0] == '-' || str[0] == '+') {
    		for (unsigned int i=1;i<str.size();i++) if (!inNumbers(str[i])) return false;
    	}
    	else {
    		for (unsigned int i=0;i<str.size();i++) if (!inNumbers(str[i])) return false;
    	}
    	return true;
    }

    bool inNumbers (char c) {   //看是不是0-9
    	if (c >= '0' && c <= '9') return true;
    	return false;
    }
};

int main () {
	Solution sol;
	char str[] = "12e";
	cout<<sol.isNumeric(str)<<endl;
	return 0;
}