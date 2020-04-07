#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int GetUglyNumber_Solution(int index) {  //结合剑指offer暴力解的提示写得
    	int i = 0;
    	int ugly_num = 1;
    	while (i < index) {
    		if (isUgly(ugly_num)) i++;
    		ugly_num++;
    		if (ugly_num%1000000 == 0) cout<<i<<endl;
    	}
    	return ugly_num-1;
    }

    bool isUgly(int num) {
    	while (num % 2 == 0) {
    		num /= 2;
    	}
    	while (num % 3 == 0) {
    		num /= 3;
    	}
    	while (num % 5 == 0) {
    		num /= 5;
    	}
    	return (num == 1) ? true : false;
    }

    int GetUglyNumber_Solution2(int index) {  //这个是看了剑指offer才会的,用空间换时间的做法
    	if (index <= 0) return 0;
    	vector<int> vec = {1,2,3,4,5,6};    //这个vec里得先有一部分丑数才能执行函数
    	if (index < 7) return vec[index-1];
    	int pos2 = 3;
    	int pos3 = 2;
    	int pos5 = 1;
    	while ((int)vec.size() < index) {
    		int local_max = vec[vec.size()-1];
    		int temp2 = vec[pos2]*2;
    		int temp3 = vec[pos3]*3;
    		int temp5 = vec[pos5]*5;
    		int current_min = min(min(temp2,temp3),temp5);
    		if (current_min == temp2) pos2++;
    		if (current_min == temp3) pos3++;
    		if (current_min == temp5) pos5++;
    		if (local_max < current_min) vec.push_back(current_min);
    	}
    	return vec[vec.size()-1];
    }

};

int main() {
	Solution sol;
	cout<<sol.GetUglyNumber_Solution2(1550)<<endl;
	return 0;
}