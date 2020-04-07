#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
    	if (sequence.size() == 0) return false;
    	return verifySubTree(sequence);
    }

    bool verifySubTree(vector<int> sequence) {
    	if (sequence.size() <= 2) return true;
    	vector<int> left, right;
    	int root = sequence[sequence.size()-1];
    	bool flagLeftHas = true;
    	for (unsigned int i=0;i<sequence.size()-1;i++) {
    		if (sequence[i] < root && flagLeftHas) left.push_back(sequence[i]);
    		else {
    			right.push_back(sequence[i]);
    			flagLeftHas = false;
    		} 
    		if (!flagLeftHas && sequence[i] < root) return false;
    	}
    	if (verifySubTree(left) && verifySubTree(right)) {
    		return true;
    	}
    	else {
    		return false;
    	}
    }
};

int main(){
	Solution sol;
	// vector<int> vec = {5,7,6,9,11,10,8};
	vector<int> vec = {9,11,10,8};
	cout<<sol.VerifySquenceOfBST(vec)<<endl;
	return 0;
}