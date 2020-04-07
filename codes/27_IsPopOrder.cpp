#include<iostream>
#include<vector>
#include<stack>

using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> testStack;
        unsigned int i = 0;        //记录弹出序列访问到哪了
        unsigned int j = 0;        //记录压栈序列访问到哪了
        testStack.push(pushV[j]);
        j++;
        for (;i<popV.size();i++) {
        	if (testStack.top() == popV[i]) {
        		testStack.pop();
        		continue;
        	}
        	if (j>=pushV.size()) return false;
        	testStack.push(pushV[j]);
        	i--;
        	j++;
        }
        if (i == j && i == popV.size()) {
        	return true;
        }
        else {
        	return false;
        }
    }
};

int main() {
	Solution sol;
	vector<int> vec1 = {1,2,3,4,5};
	vector<int> vec2 = {5,4,3,2,1};
	cout<<sol.IsPopOrder(vec1, vec2)<<endl;
	return 0;
}