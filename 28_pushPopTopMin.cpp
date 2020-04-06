#include<iostream>
#include<stack>
#include <assert.h>     /* assert */

using namespace std;
class Solution {
public:
    void push(int value) {
        stack_data.push(value);
        if (stack_min.empty() || stack_min.top() > value) {
        	stack_min.push(value);
        }
        else {
        	stack_min.push(stack_min.top());
        }
    }
    void pop() {
    	assert(stack_data.size()>0 && stack_min.size());
        stack_data.pop();
        stack_min.pop();
    }
    int top() {
    	assert(stack_data.size()>0 && stack_min.size());
        return stack_data.top();
    }
    int min() {
    	assert(stack_data.size()>0 && stack_min.size());
        return stack_min.top();
    }
private:
	stack<int> stack_data;
	stack<int> stack_min;
};

int main(){
	Solution sol;
	sol.push(3);
	sol.push(1);
	sol.push(31);
	sol.push(12);
	sol.pop();
	cout<<sol.top()<<endl;
	cout<<sol.min()<<endl;
	return 0;

}