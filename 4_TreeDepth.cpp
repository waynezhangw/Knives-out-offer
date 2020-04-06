#include<iostream>
#include<vector>

using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(){
        val=0;
        left=NULL;
        right=NULL;
    }
	//TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	Solution(void){
		deepth = 0;
		deepthMax = 0;
        root = new TreeNode();
        L2_1 = new TreeNode();
        R2_1 = new TreeNode();
        L3_1 = new TreeNode();
        L3_2 = new TreeNode();
        R3_1 = new TreeNode();
        R3_2 = new TreeNode();
        R4_2 = new TreeNode();
        R4_4 = new TreeNode();
    }
    virtual ~Solution(void){
        delete root;
        root = NULL;
        delete L2_1;
        L2_1 = NULL;
        delete R2_1;
        R2_1 = NULL;
        delete L3_1;
        L3_1 = NULL;
        delete L3_2;
        L3_2 = NULL;
        delete R3_1;
        R3_1 = NULL;
        delete R3_2;
        R3_2 = NULL;
        delete R4_2;
        R4_2 = NULL;
        delete R4_4;
        R4_4 = NULL;
    }
    void initialization(){
        vector<int> A = {4,1,6,0,2,5,7,NULL,NULL,NULL,3,NULL,NULL,NULL,8};
        root->val = A[0];                       
        root->left = L2_1;
        root->right = R2_1;

        L2_1->val = A[1];
        L2_1->left = L3_1;
        L2_1->right = R3_1;
        R2_1->val = A[2];
        R2_1->left = L3_2;
        R2_1->right = R3_2;

        L3_1->val = A[3];
        R3_1->val = A[4];
        R3_1->right = R4_2;
        L3_2->val = A[5];
        R3_2->val = A[6];
        R3_2->right = R4_4;

        R4_2->val = A[10];
        R4_4->val = A[14];
        cout<<TreeDepth(root)<<endl;
    }
    int TreeDepth(TreeNode* pRoot){
    	findTreeDepth(pRoot);
    	return deepthMax;
    }
    void findTreeDepth(TreeNode* pRoot){
    	if (pRoot != NULL){
    		deepth++;
    		deepthMax = deepth>deepthMax ? deepth : deepthMax;
    		//cout<<pRoot->val<<"   "<<deepth<<endl;
    		TreeDepth(pRoot->left);
    		TreeDepth(pRoot->right);
    		deepth--;
    	}
    	else {
    		//deepth--;
    	}
    }
private:
	int deepth;
	int deepthMax;
	TreeNode* root;
    TreeNode* L2_1;
    TreeNode* R2_1;
    TreeNode* L3_1;
    TreeNode* L3_2;
    TreeNode* R3_1;
    TreeNode* R3_2;
    TreeNode* R4_2;
    TreeNode* R4_4;
};

int main(){
	Solution test;
    test.initialization();
}