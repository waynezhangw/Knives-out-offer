#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) { //暴力解，O(size*n)复杂度
        unsigned int left = 0;
        unsigned int right = size;
        vector<int> ret;
        if (size == 0) return ret;
        while (left <= num.size()-size && right <= num.size()) {
        	ret.push_back(*max_element(num.begin()+left, num.begin()+right));
        	left++;
        	right++;
        }
        return ret;
    }

    vector<int> maxInWindows2(const vector<int>& num, unsigned int size) {  //看完剑指offer的解，O(n)复杂度
    	vector<int> ret;
        if (size == 0 || num.size() < size) return ret;  //1.判断当前最大值是否过期; 2.新增加的值从队尾开始比较，把所有比他小的值丢掉
        deque<int> deqPos;        //存最大值的下标
        for (unsigned int i=0;i<size;i++) {
        	while (!deqPos.empty() && num[deqPos.back()] <= num[i]) {
        		deqPos.pop_back();
        	}
        	deqPos.push_back(i);
        }
        ret.push_back(num[deqPos.front()]);

        for (unsigned int right = size; right < num.size(); right++) {
        	while (!deqPos.empty() && num[deqPos.back()] < num[right]) deqPos.pop_back();   //更新尾部
        	if (!deqPos.empty() && right - deqPos.front() > (size-1)) deqPos.pop_front();  //头部该退休了，窗口过了
        	deqPos.push_back(right);
        	ret.push_back(num[deqPos.front()]);  //窗口到位之后开始push
        }
        return ret;
    }
};

int main() {
	Solution sol;
	vector<int> vec = {10,14,12,11}; //10,14,12,1116,14,12,10,8,6,4
	vector<int> ret = sol.maxInWindows2(vec, 4);
	for (unsigned int i=0;i<ret.size();i++) {
		cout<<ret[i]<<",";
	}
	return 0;
}