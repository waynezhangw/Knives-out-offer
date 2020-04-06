#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

bool myfunction (int num1, int num2) {   //希望num1大,才能i++或者j--,看完剑指offer之后的改进版
	string str1 = to_string(num1);
	string str2 = to_string(num2);      //这种string是可以直接相加减的,代替了strcat(针对char的)
    return str1+str2 < str2+str1 ? true:false;      //string可以直接比大小,代替了strcmp(针对char的)
}

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {  //用快速排序的思想解决
    	string res = "";
    	quickSortVec(numbers, 0, numbers.size()-1);
    	// sort(numbers.begin(), numbers.end(), myfunction);
    	for (unsigned int i=0;i<numbers.size();i++) {
    		res.append(to_string(numbers[i]));
    	}
    	return res;
    }

    void quickSortVec(vector<int> &numbers, int left, int right) {
    	int i = left;
    	int j = right;
    	int base = numbers[left];
    	while (i < j) {
    		while (compareWhoFirst2(numbers[j], base) && i < j) {
    			j--;
    		}
    		while (compareWhoFirst2(base, numbers[i]) && i < j) {
    			i++;
    		}
    		if (i == j) {
    			numbers[left] = numbers[i];
    			numbers[i] = base;
    			break;
    		}
    		int temp = numbers[i];
    		numbers[i] = numbers[j];
    		numbers[j] = temp;
    	}
    	if (i-1 > left) quickSortVec(numbers, left, i-1);
    	if (j+1 < right) quickSortVec(numbers, j+1, right);
    }

    bool compareWhoFirst(int num1, int num2) {   //希望num1大,才能i++或者j--
    	string str1 = to_string(num1);
    	string str2 = to_string(num2);
    	if (str1.length() == str2.length()) {
    		return num1 >= num2 ? true:false;
    	}
    	else {
    		int diff = str1.length() > str2.length() ? str1.length()-str2.length() : str2.length()-str1.length();
    		if (str1.length() < str2.length()) {
    			for (int i=0;i<diff;i++) {
    				str1.append(1,str1[str1.length()-1]);
    			}
    		}
    		else {
    			for (int i=0;i<diff;i++) {
    				str2.append(1,str2[str2.length()-1]);
    			}
    		}
    		return stoi(str1) >= stoi(str2) ? true:false;
    	}
    }

    bool compareWhoFirst2(int num1, int num2) {   //希望num1大,才能i++或者j--,看完剑指offer之后的改进版
    	string str1 = to_string(num1);
	    string str2 = to_string(num2);                   //这种string是可以直接相加减的,代替了strcat(针对char的)
        return str1+str2 >= str2+str1 ? true:false;      //string可以直接比大小,代替了strcmp(针对char的)
    }
};

int main() {
	Solution sol;
	vector<int> vec = {21, 4, 3, 32, 321};
	cout<<sol.PrintMinNumber(vec)<<endl;
	return 0;
}