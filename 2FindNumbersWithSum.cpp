#include<iostream>    //知识迁移能力  和为S的两个数字
#include<vector>
#include<map>

using namespace std;
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> vec_two;
        map<int,int> map_array;
        int boundry = INT_MAX;
        pair<map<int,int>::iterator,bool> Insert_Pair;
        for(unsigned int i=0;i<array.size();i++){
            Insert_Pair = map_array.insert(pair<int,int>(array[i],i));
        }
        for(unsigned int i=0;i<array.size();i++){
            int temp = sum-array[i];
            if(map_array.count(temp)!=0 && (temp*array[i])<boundry){
                vec_two.clear();
                vec_two.push_back(temp<=array[i]?temp:array[i]);
                vec_two.push_back(temp>array[i]?temp:array[i]);
                boundry = temp*array[i];
            }
        }
        return vec_two;
    }
};

int main(){
	Solution test;
	//vector<int> A = {1,2,3,4,5};
    vector<int> A = {1,2,3,4,5,0,6};
	vector<int> B = test.FindNumbersWithSum(A, 6);
    cout<<B[0]<<","<<B[1]<<endl;
}