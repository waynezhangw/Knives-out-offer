#include<iostream>
#include<vector>
#include<numeric>       // std::accumulate
#include<algorithm>     // std::min_element, std::max_element

using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int sum = *max_element(array.begin(), array.end());   //获取vector中的最大值
    	vector<int> temp;
    	for (unsigned int i=0;i<array.size();i++) {     //复杂度On2
    		if (array[i] <= 0) continue;
    		for (unsigned int j=i;j<array.size();j++) {
    			temp.push_back(array[j]);
    			int accu = accumulate(temp.begin(), temp.end(), 0);
    			if (accu > sum) sum = accu;
    		}
    		temp.clear();
    	}
    	return sum;
    }

    int FindGreatestSumOfSubArray2(vector<int> array) {      //改进（复杂度On），利用动态规划的思想求解
    	int sum = *max_element(array.begin(), array.end());   
    	int tempSum = array[0];
    	for (unsigned int i=1;i<array.size();i++) {
    		if (tempSum < 0) {        //如果前面累加的对当前是帮倒忙，那累计就直接变为当前值
    			tempSum = array[i];
    		} 
    		else {
    			tempSum += array[i];
    		}

    		if (tempSum > sum) {
    			sum = tempSum;
    		}
    	}
    	return sum;
    }
};

int main() {
	Solution sol;
	vector<int> vec = {-2,-8,-1,-5,9,4};
	cout<<sol.FindGreatestSumOfSubArray(vec)<<endl;
	return 0;
}

//{6,-3,-2,7,-15,1,2,2}