#include<iostream>

using namespace std;
class Solution {
public:
    int jumpFloorII(int number) {
    	int last = 2;
    	int result = 0;
    	if (number<=2){
    		return number;
    	}
    	else {
    		for (int i=3;i<=number;i++){
    			result = 2*last;
    			last = result;
    		}
    	}
    	return result;
    }
};

int main()
{
	Solution sol;
	cout<<sol.jumpFloorII(4)<<endl;
	return 0;
}