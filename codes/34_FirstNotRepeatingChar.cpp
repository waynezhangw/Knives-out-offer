#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        for (unsigned int i=0;i<str.size();i++) {
        	if (count(str.begin(),str.end(),str[i]) == 1) {
        		return i;
        	}
        }
        return -1;
    }

    int FirstNotRepeatingChar2(string str) {       //利用空间换时间的思想，用到map累积次数，时间复杂度O(n)
    	map<char,int> myMap;
    	pair<map<char,int>::iterator,bool> ret;
        for (unsigned int i=0;i<str.size();i++) {
        	ret = myMap.insert(pair<char,int>(str[i],1));
        	if (ret.second == true) continue;
        	else {
        		myMap[str[i]]++;
        	}
        }
        for (unsigned int i=0;i<str.size();i++) {
        	if (myMap.count(str[i]) > 0 && myMap[str[i]] == 1) return i;
        }
        return -1;
    }

    int FirstNotRepeatingChar3(string str) {       //利用空间换时间的思想,参考评论里的方法，建立数组而不是用map
    	int myArray[58] = {0};
        for (unsigned int i=0;i<str.size();i++) {
        	myArray[str[i]-65]++;
        }
        for (unsigned int i=0;i<str.size();i++) {
        	if (myArray[str[i]-65] == 1) return i;
        }
        return -1;
    }
};

int main(){
	Solution sol;
	cout<<sol.FirstNotRepeatingChar3("agbAWQaccdeffg")<<endl;
	return 0;
}