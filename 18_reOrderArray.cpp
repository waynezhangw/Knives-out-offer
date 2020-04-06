#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    void reOrderArray(vector<int> &array) {
    	if (array.size() == 0) {
    		return;
    	}
        vector<int> odds;
        vector<int> even;
        for (unsigned int i=0;i<array.size();i++) {
        	if (array[i]%2 != 0) {
        		odds.push_back(array[i]);
        	}
        	else {
        		even.push_back(array[i]);
        	}
        }
        array.clear();
        array.insert(array.end(),odds.begin(),odds.end());
		array.insert(array.end(),even.begin(),even.end());
    }

    //解法2，直接用C++现成的函数，C++ reference里面有stable_partition说明
    void reOrderArray2(vector<int> &array) {    
    	stable_partition(array.begin(), array.end(), IsOdd);
    }

    static bool IsOdd (int i) { 
    	return (i%2)==1; 
    }

    void printArray(vector<int> &array) {
    	for (unsigned int i=0;i<array.size();i++) {
    		cout<<array[i]<<",";
    	}
    	cout<<endl;
    }
};

int main(){
	Solution sol;
	vector<int> vec = {1,2,3,4,5,2,5,6,9};
	sol.printArray(vec);
	sol.reOrderArray2(vec);
	sol.printArray(vec);
	return 0;
}