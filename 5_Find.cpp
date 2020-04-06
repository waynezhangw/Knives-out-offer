#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {  
    	if(array.empty()){
    		return false;
    	}
    	bool flag = false;
        unsigned int hang = array.size();
        unsigned int lie = array[0].size();
        int i = hang-1;                       //如果这里是unsigned int，那减减就无法小于0了
        int j = 0;
        while (i>=0 && j<(int)lie){       //unsigned int i,j就会爆炸，白白试了4次都没通过
        	cout<<i<<"  "<<j<<endl;
        	if (array[i][j] == target){
        		flag = true;
        		break;
        	}
        	else {
        		if (array[i][j] < target){
        			j++;
        		}
        		else {
        			i--;
        		}
        	}
        }
        return flag;
    }
};

int main(){
	vector<vector<int> > arr;
	arr = {
		{1,2,3,4,5},
		{7,9,10,11,12},
		{10,11,15,16,17},
		{11,12,16,17,18},
	};
	vector<vector<int> > arr1;
	Solution solu;
	for(unsigned int i=0;i<arr.size();i++){
		for(unsigned int j=0;j<arr[0].size();j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"hang:"<<arr.size()<<endl;
	cout<<"lie:"<<arr[0].size()<<endl;
	cout<<solu.Find(9,arr);
	return 0;
}