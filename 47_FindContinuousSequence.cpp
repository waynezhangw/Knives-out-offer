#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> vec;
		vector<int> tempVec;
		int divide=2;
		int leftNum = sum/divide;
		while (leftNum >= divide/2) {
			leftNum = leftNum - divide/2 - 1;
			if (leftNum < 1) leftNum = 1;
			bool hasSum = false;
			for (int i=0;i<5;i++) {
				for (int j=0;j<divide;j++) {
					tempVec.push_back(leftNum+j);
				}
				if(accumulate(tempVec.begin(), tempVec.end(), 0) == sum) {
					hasSum = true;
					break;
				}
				tempVec.clear();
				leftNum += 1;
			}
			if(hasSum) vec.push_back(tempVec);
			tempVec.clear();
			divide++;
			leftNum = sum/divide;
		}
		vector<vector<int>> vec2;
		for(unsigned int i=0;i<vec.size();i++) {
			vec2.push_back(vec[vec.size()-i-1]);
		}
		vec.clear();
		return vec2;
	}

	vector<vector<int> > FindContinuousSequence2(int sum) {   //这个是看完剑指offer的双指针思路又写了一遍
		vector<vector<int>> vec;
		vector<int> tempVec;
		int left = 1;
		int right = 2;
		int currentSum = left + right;
		int middle = sum/2 + 1;
		while (left < middle) {
			if (currentSum == sum) {
				for (int i=left;i<=right;i++) {
					tempVec.push_back(i);
				}
				vec.push_back(tempVec);
				tempVec.clear();
			}
			if (currentSum > sum) {
				currentSum -= left;
				left += 1;
			}
			else {
				right += 1;
				currentSum += right;
			}
		}
		return vec;
	}
};

int main () {
	Solution sol;
	vector<vector<int>> vec = sol.FindContinuousSequence2(3);
	for (unsigned int i=0;i<vec.size();i++) {
		for (unsigned int j=0;j<vec[i].size();j++) {
			cout<<vec[i][j]<<",";
		}
		cout<<endl;
	}
	return 0;
}