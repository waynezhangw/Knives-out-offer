#include<iostream>

using namespace std;
class Solution {
public:
    int rectCover(int number) {
    	if (number <= 2){
    		return number;
    	}
    	int f1 = 1;
    	int f2 = 2;
    	int fn = 0;
    	for (int i=3 ;i<=number;i++){
    		fn = f1 + f2;
    		f1 = f2;
    		f2 = fn;
    	}
    	return fn;
    }
    int rectCover2(int number) {
    	if (number <= 2){
    		return number;
    	}
    	return rectCover(number-1)+rectCover(number-2);
    }

};

int main(){
	Solution sol;
	cout<<sol.rectCover(10)<<endl;
	return 0;
}