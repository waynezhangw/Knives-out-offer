#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int InversePairs(vector<int> data) {
        int num = 0;
        for (unsigned int i=0;i<data.size()-1;i++) {
        	for (unsigned int j=i+1;j<data.size();j++) {
        		if (data[i] > data[j]) {
        			num++;
        			if (num >= 1000000007) num = num%1000000007;
        		} 
        	}
        }
        return num;          //只能通过50%,会超时
    }

    int InversePairs2(vector<int> data) {
        if (data.size() == 0) return 0;
        vector<int> copy;
        for (unsigned int i=0;i<data.size();i++) {
        	copy.push_back(data[i]);
        }
        long long count = inversePairsCore(data, copy, 0, data.size()-1);
        return count%1000000007;
    }

    long long inversePairsCore(vector<int> &data, vector<int> &copy, int start, int end) {
    	if (start == end) {
    		copy[start] = data[start];
    		return 0;
    	}
    	int length = (end - start) / 2;

    	long long left = inversePairsCore(copy, data, start, start+length);
    	long long right = inversePairsCore(copy, data, start+length+1, end);   //利用归并排序的思想

    	int i = start+length;
    	int j = end;
    	int indexCopy = end;
    	long long count = 0;
    	while (i >= start && j >= start+length+1) {        //归并的时候就是找逆序对个数的最佳时机
    		if (data[i] > data[j]) {                       //如果前半部分有值比后面大，那原始序列中肯定有逆序对
    			copy[indexCopy] = data[i];
    			count += j - start - length;   //隐含的大数问题，要用long long，超出范围记得取模
    			indexCopy--;
    			i--;
    		}
    		else {
    			copy[indexCopy] = data[j];
    			indexCopy--;
    			j--;
    		}
    	}
    	//各自还有剩余的没比完，直接赋值到辅助数组里
    	for (; i>= start; i--) {
    		copy[indexCopy--] = data[i];
    	}
    	for (; j>= start + length + 1; j--) {
    		copy[indexCopy--] = data[j];
    	}

    	return left+right+count;
    }
};

int main () {
	Solution sol;
	vector<int> data = {1,2,3,4,5,6,7,0};   //这个求逆序对的是剑指offer中通过率最低的一道题，真难，得先理解归并排序
	cout<<sol.InversePairs2(data);
	return 0;
}