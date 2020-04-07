/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){ //总体思路：1.先找与B根节点相同的节点；2.然后顺着这个节点往下找有没有包含B树的
    	if (pRoot2 == NULL || pRoot1 == NULL) return false;   //ps：我们约定空树不是任意一个树的子结构
    	hasSub = false;
    	seeTree(pRoot1, pRoot2);   //递归遍历二叉树
    	return hasSub;
    }

    void seeTree(TreeNode* pRoot1, TreeNode* pRoot2) {
    	if (pRoot1 != NULL){
    		if (pRoot1->val == pRoot2->val) {
    			if(checkTree(pRoot1->left, pRoot2->left) && checkTree(pRoot1->right, pRoot2->right)) {
    				hasSub = true;                        //左右都为真才return
    				return;
    			} 
    		}
    		seeTree(pRoot1->left, pRoot2);                  //如果左节点找了一圈没找到，那再找右边
    		if (!hasSub) seeTree(pRoot1->right, pRoot2);    //if 来避免，左边找到了，右边没找到又给他置为假了
    	}
    }

    bool checkTree(TreeNode* currentR, TreeNode* pRoot2){
    	if (pRoot2 == NULL) return true;                  //找到了B树的末端就置为真把
    	else if (currentR == NULL) return false;          //那个不为假你都为假了，那就false
    	else {
    		if (currentR->val == pRoot2->val) {             //值相等，才往下找
    			return checkTree(currentR->left, pRoot2->left) && checkTree(currentR->right, pRoot2->right);  //得同时为真才行
    		}
    		else {
    			return false;
    		}
    	}
    }

private:
	bool hasSub;     //全局变量指示是否真的有子结构
};