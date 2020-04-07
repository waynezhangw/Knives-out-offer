#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
class Solution
{
public:
	Solution() {
		firstPos = 0;
	}
  //Insert one char from stringstream
    void Insert(char ch) { 
    	vec.push_back(ch);
    	pair<map<char, int>::iterator, bool> ret;
    	ret = mapC.insert(pair<char, int> (ch, 1));
    	if (ret.second == false) {
    		mapC[ch]++;
    	}
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() { 
    	// while (count(vec.begin(), vec.end(), vec[firstPos]) != 1 && firstPos < (int)vec.size()) {
    	// 	firstPos++;
    	// }
    	while (mapC[vec[firstPos]] != 1 && firstPos < (int)vec.size()) {
    		firstPos++;
    	}
    	// for (unsigned int i=0;i<vec.size();i++) {
    	// 	cout<<vec[i];
    	// }
    	// cout<<endl;
    	return firstPos < (int)vec.size() ? vec[firstPos]:'#';
    }
private:
	vector<char> vec;
	map<char, int> mapC;
	int firstPos;
};

int main () {
	Solution sol;
	while (1) {
		char temp;
		cin>>temp;
		sol.Insert(temp);
		cout<<sol.FirstAppearingOnce()<<endl;
		if (temp == '#') break;  
	}
	return 0;
}