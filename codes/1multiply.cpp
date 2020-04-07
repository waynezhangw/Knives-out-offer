#include<iostream>   //数组   构建乘积数组
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size());
        vector<int> left_T(A.size(), 1);
        vector<int> right_T(A.size(), 1);
        for(unsigned int i=1;i<A.size();i++) {
            left_T[i] = left_T[i-1] * A[i-1];
            right_T[A.size()-i-1] = right_T[A.size()-i]*A[A.size()-i];
            cout<<left_T[i]<<endl;
        }
        for(unsigned int i=0;i<A.size();i++) {
            B[i] = left_T[i]*right_T[i];
        }
        return B;
    }
    void see_vector(vector<int>& vec){
        for(unsigned int i = 0;i<vec.size();i++) {
            cout<<vec[i]<<", ";
        }
        cout<<endl;
    }
};

int main(){
	Solution test;
	vector<int> A = {1,2,3,4,5};
    //vector<int> A = {1,2,3,4,5,0,6};
    test.see_vector(A);
	vector<int> B = test.multiply(A);
	test.see_vector(B);
}