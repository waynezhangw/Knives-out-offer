#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
    	vector<int> data_print;
    	unsigned int m = matrix.size();
    	unsigned int n = matrix[0].size();
    	if (m*n == 0) return data_print;
    	unsigned int row = 0; 
    	unsigned int column = 0;
    	while (data_print.size() < m*n) {
    		for (unsigned int j=column;j<n-column;j++) {
    			data_print.push_back(matrix[row][j]);
    		}
    		for (unsigned int i=row+1;i<m-row;i++) {
    			data_print.push_back(matrix[i][n-column-1]);
    		}
    		for (unsigned int j=column+1;j<n-column && m-row-1>row;j++) {
    			data_print.push_back(matrix[m-row-1][n-j-1]);
    		}
    		for (unsigned int i=row+1;i<m-row-1 && column<n-column-1;i++) {
    			data_print.push_back(matrix[m-i-1][column]);
    		}
    		row++;
    		column++;
    	}
    	return data_print;
    }

    void seeVector(vector<int> vec){
    	for(unsigned int i=0;i<vec.size();i++) {
    		cout<<vec[i]<<",";
    	}
    	cout<<endl;
    }
};

int main(){
	Solution sol;
	vector<vector<int> > matrix = {{1,2,3,4,99},{5,6,7,8,88},{9,10,11,12,77},{13,14,15,16,66}};
	// vector<vector<int> > matrix= {{1}};
	sol.seeVector(sol.printMatrix(matrix));
	return 0;
}