#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int *num1,int *num2) {  //时间复杂度O(n2),空间复杂度O(1)
    	bool num1Has = false;
    	for (unsigned int i=0;i<data.size();i++) {
    		if (count(data.begin(),data.end(),data[i]) == 1 && !num1Has) {  //count是O(n)
    			num1 = &data[i];
    			num1Has = true;
    		} 
    		if (count(data.begin(),data.end(),data[i]) == 1 && num1Has) {
    			num2 = &data[i];
    		}
    	}
    	cout<<*num1<<endl;
	    cout<<*num2<<endl;
    }

    void FindNumsAppearOnce2(vector<int> data,int *num1,int *num2) {  //时间复杂度O(nlogN),空间复杂度O(n)
    	map<int, bool> appearOnce;
    	pair<map<int,bool>::iterator, bool> ret;
    	for (unsigned int i=0;i<data.size();i++) {
    		ret = appearOnce.insert(pair<int, bool>(data[i],true));
    		if (ret.second == false) appearOnce[data[i]] = false;
    	}
    	bool num1Has = false;
    	for (unsigned int i=0;i<data.size();i++) {
    		if (appearOnce[data[i]] && !num1Has) {    //查看要O(logN)
    			num1 = &data[i];
    			num1Has = true;
    		} 
    		if (appearOnce[data[i]] && num1Has) {
    			num2 = &data[i];
    		}
    	}
    	cout<<*num1<<endl;
	    cout<<*num2<<endl;
    }

    void FindNumsAppearOnce3(vector<int> data,int *num1,int *num2) {  //看了书的方法,时间复杂度O(n),空间复杂度O(1)
    	int notOr = 0;
    	for (unsigned int i=0;i<data.size();i++) { //先异或遍历一遍,找出区分那两个只出现一次的数的办法
    		notOr ^= data[i]; 
    	}
    	int indicate = 0;
    	while (notOr != 0) {
    		if ((notOr&1) == 1) break;
    		notOr = notOr>>1;
    		indicate++;
    	}
    	indicate = pow(2.0,double(indicate));   //要是最右边为1,那此值就是1,右数第三位为1,此值就是4
    	int temp1 = 0;
    	int temp2 = 0;
    	for (unsigned int i=0;i<data.size();i++) {  //再遍历一遍将data分成两组来处理
    		if ( (data[i]&indicate) == indicate ) {
    			temp1 ^= data[i];
    		} 
    		else {
    			temp2 ^= data[i];
    		}
    	}
    	num1 = &temp1;
    	num2 = &temp2;
    	cout<<*num1<<endl;
	    cout<<*num2<<endl;
    }
};

int main() {
	Solution sol;
	vector<int> data = {1,2,3,4,5,4,3,1,2,7,5,9};
	int *num1 = NULL;
	int *num2 = NULL;
	sol.FindNumsAppearOnce3(data, num1, num2);
	
	return 0;
}