#include<iostream>

using namespace std;
class Solution {
public:
    int Fibonacci(int n) {
    	if (n<=0){
    		return 0;
    	}
    	else if (n==1 || n==2){
    		return 1;
    	}
    	else {
    		return Fibonacci(n-1)+Fibonacci(n-2);
    	}
    }
};

int main(){
	Solution sol;
	for(int i=0;i<10;i++){
		cout<<sol.Fibonacci(i)<<endl;
	}
	
	return 0;
}