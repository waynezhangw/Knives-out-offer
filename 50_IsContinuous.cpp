#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
    	if (numbers.size() == 0) return false;
        int zero = 0;
        int gap = 0;
        sort(numbers.begin(), numbers.end());
        for (unsigned int i=0;i<numbers.size()-1;i++) {      //有非0的重复的必不是顺子
        	if (numbers[i] == 0) continue;
        	if (numbers[i] == numbers[i+1]) return false;
        	gap += (numbers[i+1] - numbers[i] - 1);          //统计相差的间隔数是不是都为1
        }
        for (unsigned int i=0;i<numbers.size();i++) {      //变色龙有几张
        	if (numbers[i] == 0) zero++;
        }
        if (gap <= zero) return true;
        else return false;
    }
};

int main () {
	Solution sol;
	vector<int> numbers = {0,0,0,0,3};
	cout<<sol.IsContinuous(numbers)<<endl;
	return 0;
}