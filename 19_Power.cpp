#include<iostream>

using namespace std;
class Solution {
public:
    double Power(double base, int exponent) {
    	if (base == 0) {
    		return 0;
    	}
    	if (exponent == 0) {
    		return 1.0;
    	}
    	if (exponent == 1) {
    		return base;
    	}
    	if (exponent == -1) {
    		return 1.0/base;
    	}
    	double result = base;
    	for (int i=1;i<abs(exponent);i++) {
    		result = result * base;
    	}
    	if (exponent < 0) {
    		return 1.0/result;
    	}
    	else {
    		return result;
    	}
    }

    double Power2(double base, int exponent) {    //解法2，用公式和递归做的改进
    	if (base == 0) {
    		return 0;
    	}
    	if (exponent == 0) {
    		return 1.0;
    	}
    	if (exponent == 1) {
    		return base;
    	}
    	double result = Power2(base, abs(exponent)>>1);
    	if ( (exponent & 0x1) == 1){
    		result = result*result*base;
    	} 
    	else {
    		result *= result;
    	}
    	if (exponent < 0) {
    		return 1.0/result;
    	}
    	else {
    		return result;
    	}
    }
};

int main(){
	Solution sol;
	cout<<sol.Power2(-2.0, -98)<<endl;
	return 0;
}