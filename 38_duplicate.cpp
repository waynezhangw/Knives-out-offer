#include<iostream>
#include<algorithm>
#include<vector>

using std::cout;
using std::endl;
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for (int i=0;i<length;i++) {
        	if (std::count(numbers, numbers+length, numbers[i]) > 1) {
        		// *duplication = numbers[i];     //这样的才能在牛客通过，但本地通过不了
        		duplication = &numbers[i];
        		return true;
        	}
        }
        return false;
    }

    bool duplicate2(int numbers[], int length, int* duplication) {  //看了评论,用O(n)空间复杂度得到O(n)时间复杂度的算法
    	bool* k = (bool*)malloc(sizeof(bool)*length);
    	for (int i=0;i<length;i++) k[i] = false;
        for (int i=0;i<length;i++) {
        	if (k[numbers[i]] == true) {
        		duplication = &numbers[i];
        		return true;
        	}
        	k[numbers[i]] = true;
        }
        free(k);
        return false;
    }

    bool duplicate3(int numbers[], int length, int* duplication) {  //看了剑指offer,用O(1)空间复杂度得到O(n)时间复杂度的算法
        for (int i=0;i<length;i++) {
        	while (numbers[i] != i) {
        		if (numbers[i] == numbers[numbers[i]]) {
        			duplication = &numbers[i];
        			return true;
        		}
        		int temp = numbers[i];
        		numbers[i] = numbers[numbers[i]];
        		numbers[temp] = temp;
        	}	
        }
        return false;
    }
};

int main() {
	Solution sol;
	int a[5] = {2,1,3,1,4,};
	int* duplication = NULL; 
	cout<<sol.duplicate3(a, 5, duplication)<<endl;
	return 0;
}