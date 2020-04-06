#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if (numbers.size() == 0) return 0;
    	if (numbers.size() == 1) return numbers[0];
    	int half = numbers.size()/2;
    	for (unsigned int i=0;i<numbers.size();i++) {
    		if (count(numbers.begin(),numbers.end(),numbers[i]) > half) {
    			return numbers[i];
    		}
    	}
    	return 0;
    }

    int MoreThanHalfNum_Solution2(vector<int> numbers) {   //看剑指offer的O(n)算法改进
    	if (numbers.size() == 0) return 0;
    	if (numbers.size() == 1) return numbers[0];
    	int mostLikeResult = numbers[0];
    	int times = 1;
    	for (unsigned int i=1;i<numbers.size();i++) {
    		if (times == 0) {
    			mostLikeResult = numbers[i];
    			times = 1;
    		}
    		else if (numbers[i] == mostLikeResult) times++;
    		else times--;
    	}
    	int half = numbers.size()/2;
    	int occurence = 0;
    	for (unsigned int i=0;i<numbers.size();i++) {
    		if (numbers[i] == mostLikeResult) {
    			occurence++;
    		}
    	}
    	if (occurence > half) return mostLikeResult;
    	else return 0;
    }
};

int main(){
	Solution sol;
	vector<int> vec = {1,2,3,2,2,2,5,4,2};
	cout<<sol.MoreThanHalfNum_Solution2(vec)<<endl;
	return 0;
}