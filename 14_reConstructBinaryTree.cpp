#include<iostream>
#include<vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    	if (pre.size() == 0 || vin.size() == 0){
    		return NULL;
    	}
    	TreeNode* root = new TreeNode(pre[0]);
    	root->left = NULL;
    	root->right = NULL;
    	vector<int> pre1, pre2, vin1, vin2;
    	bool flag = false;
    	for (unsigned int i=0;i<vin.size();i++){
    		if (vin[i] == pre[0]){
    			flag = true;
    			continue;
    		}
    		if (flag){
    			vin2.push_back(vin[i]);
    		}
    		else {
    			vin1.push_back(vin[i]);
    		}
    	}

    	for (unsigned int i=1;i<pre.size();i++){
    		if (pre1.size()<vin1.size()){
    			pre1.push_back(pre[i]);
    		}
    		else {
    			pre2.push_back(pre[i]);
    		}
    	}

    	root->left = reConstructBinaryTree(pre1, vin1);
    	root->right = reConstructBinaryTree(pre2, vin2);
    	return root;
    }

    void seeTree(TreeNode* root){
        if(root){
            
            seeTree(root->left);

            seeTree(root->right);
            cout<<root->val<<",";
        }
        else{
            //cout<<"NULL"<<",";
        }
    }
};

int main(){
	Solution sol;
	vector<int> vec1 = {1,2,4,7,3,5,6,8};
	vector<int> vec2 = {4,7,2,1,5,3,8,6};
	sol.seeTree(sol.reConstructBinaryTree(vec1, vec2));
	return 0;
}