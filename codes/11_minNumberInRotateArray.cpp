#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
    	if (rotateArray.size()==0){
    		return 0;
    	}
    	if (rotateArray.size()==1){
    		return rotateArray[0];
    	}
    	bool flag = false;
        for (unsigned int i=0;i<rotateArray.size()-1;i++){
        	if (rotateArray[i]<=rotateArray[i+1]){
        		continue;
        	}
        	else {
        		flag = true;
        		return rotateArray[i+1];
        	}
        }
        if (!flag){
        	return rotateArray[0];  //没有反转数字
        }
        return 0;
    }
};

int main(){
	Solution sol;
	vector<int> a = {2,4,5,6,9,2,2};
	cout<<sol.minNumberInRotateArray(a)<<endl;
	return 0;
}