#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int LastRemaining_Solution(int n, int m) {  //类似于环装链表的思路，空间O(n),时间O(nm)
		if (n <= 0) return -1;
		vector<int> childOut;
		for (int i=0;i<n;i++) {
			childOut.push_back(1);
		}
		int countOut = 0;
		int go = -1;
		int final_i = 0;
		for (int i=0;i<n && countOut<n;i++) {  	
			if (childOut[i] == 0) {
				if (i == n-1) i = -1;
				continue;
			}
			if (go < m) go++;
			if (go == m-1) {
				childOut[i] = 0;
				countOut++;
				go = -1;
				final_i = i;
			}
			if (i == n-1) i = -1;
		}
		return final_i;
	}

	int LastRemaining_Solution2(int n, int m) {   //基于数学公式推导的思路，空间O(1),时间O(n)
		if (n <= 0) return -1;
		int final_i = 0;
		for (int i=2;i<=n;i++) {
			final_i = (final_i+m) % i;
		}
		return final_i;
	}
};

int main () {
	Solution sol;
	cout<<sol.LastRemaining_Solution2(40000, 997)<<endl;
	return 0;
}