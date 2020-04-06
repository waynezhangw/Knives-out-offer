#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
    	vector<string> ret;
    	if (str == "") return ret;
        set<string> result;
        permutation_recursion(str, 0, result);
        ret.assign(result.begin(),result.end());  //set会自动按字典排序
        return ret;
    }

    void permutation_recursion(string &str, int begin, set<string> &result) {
    	if (begin >= (int)str.size()) {
    		result.insert(str);          //insert本来会返回一个迭代器的，来判断second的真假
    		return;
    	}
    	else {
    		for (int i=begin;i<(int)str.size();i++) {
    			swap(str[begin], str[i]);
    			permutation_recursion(str, begin+1, result);
    			swap(str[begin], str[i]);
    		}
    	}
    }

    void seeVector(vector<string> &vec) {
    	for (unsigned int i=0;i<vec.size();i++) {
    		cout<<vec[i]<<endl;
    	}
    }
};

int main(){
	Solution sol;
	string str = "cbB";        //字母个数小于等于9
	vector<string> vec = sol.Permutation(str);
	cout<<"result:"<<endl;
	sol.seeVector(vec);
	return 0;
}