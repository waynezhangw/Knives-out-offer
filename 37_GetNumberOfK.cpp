#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return count(data.begin(),data.end(),k);
    }

    int GetNumberOfK2(vector<int> data ,int k) {   //方法2，二分法找到第一个k和最后一个k的位置然后相减
    	if (data.size() == 0) return 0;
    	if (k < data[0] || k > data[data.size()-1]) return 0;
        int firstK = getFirstK(data, 0, data.size()-1, k);
        int lastK = getLastK(data, 0, data.size()-1, k);
        int number = 0;
        if (firstK != -1 && lastK != -1) number = lastK-firstK+1;
        return number;
    }

    int getFirstK(vector<int> &data, int start, int end, int &k) {
    	if (start > end) return -1;           //不加这个可能会越界
    	int middle = (end+start)/2;
    	if (data[middle] > k) {
    		return getFirstK(data, start, middle-1, k);
    	}
    	else if (data[middle] < k) {
    		return getFirstK(data, middle+1, end, k);
    	}
    	else {
    		if (middle-1<0 || data[middle-1]!=k) return middle;
    		else return getFirstK(data, start, middle-1, k);
    	}
    }

    int getLastK(vector<int> &data, int start, int end, int &k) {
    	if (start > end) return -1;          //不加这个可能会越界
    	int middle = (end+start)/2;
    	if (data[middle] > k) {
    		return getLastK(data, start, middle-1, k);
    	}
    	else if (data[middle] < k) {
    		return getLastK(data, middle+1, end, k);
    	}
    	else {
    		if (middle+1>=data.size() || data[middle+1]!=k) return middle;
    		else return getLastK(data, middle+1, end, k);
    	}
    }

};

int main() {
	Solution sol;
	vector<int> data = {1,2,3,4,4,5,5,5,5,6,8};
	cout<<sol.GetNumberOfK2(data, 8);
	return 0;
}