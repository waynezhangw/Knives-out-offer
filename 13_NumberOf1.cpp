#include<iostream>

using namespace std;
class Solution {
public:
     int NumberOf1(int n) {
         int one = 0;
         while (n != 0 ){
         	if (n%2 == 1){
         		one++;
         	}
         	n = n/2;          //除法效率低
         }
         return one;
     }

     int NumberOf1_method2(int n) {
         int one = 0;
         unsigned int flag = 1;
         while (flag){           //效率依然不高，因为必须循环32次（整型是32位）
         	cout<<flag<<endl;
         	if (n & flag){
         		one++;
         	}
         	flag = flag << 1;
         }
         return one;
     }

     int NumberOf1_method3(int n) {
     	int one = 0;
     	while (n){
     		one++;
     		n = (n-1) & n;
     	}
     	return one;
     }
};

int main(){
	Solution sol;
	cout<<sol.NumberOf1_method3(9)<<endl;
	return 0;
}