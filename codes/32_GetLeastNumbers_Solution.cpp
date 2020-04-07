#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    	vector<int> k_vec;
    	if (input.size() == 0 || k>(int)input.size()) return k_vec;
        sort(input.begin(),input.end());
        k_vec.assign(input.begin(),input.begin()+k);
        return k_vec;
    }

    vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
    	vector<int> k_vec;
    	if (input.size() == 0 || k>(int)input.size()) return k_vec;
    	for (int i=0;i<k;i++) {
    		auto min_data = min_element(input.begin(),input.end());
    		k_vec.push_back(*min_data);
    		//vector<int>::iterator it = find(input.begin(),input.end(),*min_data);
    		input.erase(min_data);
    	}
        return k_vec;
    }

    void seeVector(vector<int> vec) {
    	for (unsigned int i=0;i<vec.size();i++) {
    		cout<<vec[i]<<",";
    	}
    	cout<<endl;
    }
};

int main(){
	Solution sol;
	vector<int> vec = {4,5,1,6,2,7,3,8};
	sol.seeVector(sol.GetLeastNumbers_Solution2(vec,4));
	return 0;
}