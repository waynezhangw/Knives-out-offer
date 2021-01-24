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
    int minNumberInRotateArray2(vector<int> rotateArray) {
        if (rotateArray.size() == 0) return 0;
        if (rotateArray.size() == 1) return rotateArray[0];
        int left = 0;
        int right = rotateArray.size()-1;
        int middle = 0;
        while (rotateArray[left] >= rotateArray[right]) {
            if (right - left == 1) {
                middle = right;
                break;
            }
            middle = left + (right - left)/2;
            if (rotateArray[left] == rotateArray[middle] && rotateArray[right] == rotateArray[middle]) {
                return cornerCase(rotateArray, left, right);
            }
            if (rotateArray[middle] >= rotateArray[left]) left = middle;
            if (rotateArray[middle] <= rotateArray[right]) right = middle;
        }
        return rotateArray[middle];
    }
    int cornerCase(const vector<int> &rotateArray, int left, int right) {
        int small = rotateArray[left];
        while (left <= right) {
            if (rotateArray[left] < small) small = rotateArray[left];
            left++;
        }
        return small;
    }
};

int main(){
    Solution sol;
    vector<int> a = {2,4,5,6,9,1,2,2};
    //vector<int> a = {1,0,1,1,1};
    cout<<sol.minNumberInRotateArray2(a)<<endl;
    return 0;
}