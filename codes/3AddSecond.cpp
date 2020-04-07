#include <iostream>
#include <vector>        //看了网上的解析才做的

using namespace std;
class Solution {
public:
    int Add(int num1, int num2)
    {
    	while(num2!=0){
            int sum = num1^num2;
            int jin = (num1&num2)<<1;
            num1 = sum;
            num2 = jin;
        }
        return num1;
    }
};

int main(){
	Solution a;
	cout<<a.Add(999,999);   
    // int a = 9;
    // int b = 7;
    // int temp = a^b;
    // cout<<temp;
	return 0;
}