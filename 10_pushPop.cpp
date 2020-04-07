#include<iostream>
#include<stack>

using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
    	int popOut;
        if (stack1.empty() && stack2.empty()){
        	cout<<"please push data to the queue!"<<endl;
        }
        else {
        	if (!stack2.empty()){
        		popOut = stack2.top();
        		stack2.pop();
        	}
        	else {
        		while (!stack1.empty()){
        			stack2.push(stack1.top());
        			stack1.pop();
        		}
        		popOut = stack2.top();
        		stack2.pop();
        	}
        }
        return popOut;
    }

private:
    stack<int> stack1;    //专门负责入队列
    stack<int> stack2;    //专门负责出队列
};

int main(){
	Solution sol;
	for(int i=0;i<5;i++){
		sol.push(i);
	}
	for(int i=0;i<5;i++){
		cout<<sol.pop()<<"-";
	}
	return 0;
}