#include<iostream>
#include<vector>
#include<queue>        // std::queue

using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(){
        val = 0;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
	Solution(){
	    root = new TreeNode();
        L2_1 = new TreeNode();
        R2_1 = new TreeNode();
        L3_1 = new TreeNode();
        L3_2 = new TreeNode();
        R3_1 = new TreeNode();
        R3_2 = new TreeNode();
        L4_4 = new TreeNode();
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
        delete L4_4;
        L4_4 = NULL;
        delete R4_4;
        R4_4 = NULL;
    }

    void initialization(){
        vector<int> A = {3,9,20,5,6,15,7,NULL,NULL,NULL,NULL,NULL,NULL,1,2};
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
        L3_2->val = A[5];
        R3_2->val = A[6];
        R3_2->left = L4_4;
        R3_2->right = R4_4;

        L4_4->val = A[13];
        R4_4->val = A[14];
        cout<<"Postorder Traversal (LRD):"<<endl;
        seeTree(root);
        cout<<endl;
        cout<<"yes or no: "<<IsBalanced_Solution2(root)<<endl;
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

    bool IsBalanced_Solution(TreeNode* pRoot) {
    	if (pRoot == NULL) return true;   //空树也是平衡二叉树
    	int leftDepth = 0;
    	int rightDepth = 0;
    	int leftMax = 0;
    	int rightMax = 0;
    	goDeeper(pRoot->left, leftDepth, leftMax);    //这种由上而下遍历做法会造成重复遍历
    	goDeeper(pRoot->right, rightDepth, rightMax);
    	if (abs(leftMax-rightMax) > 1) return false;
    	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }

    void goDeeper(TreeNode* pRoot, int &depth, int &maxDepth) {
    	if (pRoot) {
    		depth++;
    		maxDepth = (depth > maxDepth) ? depth : maxDepth;
    		goDeeper(pRoot->left, depth, maxDepth);
    		goDeeper(pRoot->right, depth, maxDepth);
    		depth--;
    	}
    }

    bool IsBalanced_Solution2(TreeNode* pRoot) {  //剑指offer建议用后序遍历,每个节点只遍历一次
    	int depth = 0;
    	return IsBalanced(pRoot, depth);
    }

    bool IsBalanced(TreeNode* pRoot, int &depth) {               
    	if (pRoot == NULL) {     //到了叶子节点深度就赋值为0
    		depth = 0;
    		return true;   
    	}
    	int leftDepth, rightDepth;
    	if (IsBalanced(pRoot->left, leftDepth) && IsBalanced(pRoot->right, rightDepth)) {
    		int diff = abs(leftDepth - rightDepth);
    		cout<<pRoot->val<<endl;
    		cout<<leftDepth<<"--"<<rightDepth<<endl;
    		if (diff <= 1) {
    			depth = 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    			return true;
    		}
    	}
    	return false;
    }

private:
	TreeNode* root;
    TreeNode* L2_1;
    TreeNode* R2_1;
    TreeNode* L3_1;
    TreeNode* L3_2;
    TreeNode* R3_1;
    TreeNode* R3_2;
    TreeNode* L4_4;
    TreeNode* R4_4;
};

int main(){
	Solution test;
    test.initialization();
    return 0;
}