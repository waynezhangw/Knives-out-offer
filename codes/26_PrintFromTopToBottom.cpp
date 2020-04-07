#include<iostream>
#include<vector>
#include<queue>        // std::queue

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
        cout<<"Breadth First Search (BFS):"<<endl;
        seeVector(PrintFromTopToBottom(root));
        cout<<"method 2 BFS:"<<endl;
        seeVector(PrintFromTopToBottom2(root));
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

    vector<int> PrintFromTopToBottom(TreeNode* root) {
    	vector<int> result;
    	if (root == NULL) {
    		return result;
    	}
    	vector<TreeNode*> vec1, vec2;
    	vec1.push_back(root);
    	do {
    		for (unsigned int i=0;i<vec1.size();i++) {
    			result.push_back(vec1[i]->val);
    			if (vec1[i]->left != NULL) vec2.push_back(vec1[i]->left);
    			if (vec1[i]->right != NULL) vec2.push_back(vec1[i]->right);
    		}
    		vec1.clear();
    		vec1 = vec2;
    		vec2.clear();
    	} while(vec1.size() != 0);
    	return result;
    }

    vector<int> PrintFromTopToBottom2(TreeNode* root) {   //看完评论发现，广度优先BFS可以借助队列来实现，先进先出
    	vector<int> result;
    	if (root == NULL) {
    		return result;
    	}
    	queue<TreeNode*> myqueue;
    	myqueue.push(root);
    	while(!myqueue.empty()) {
    		result.push_back(myqueue.front()->val);
    		if (myqueue.front()->left != NULL) myqueue.push(myqueue.front()->left);
    	    if (myqueue.front()->right != NULL) myqueue.push(myqueue.front()->right);
    		myqueue.pop();
    	} 
    	return result;
    }

    void seeVector(vector<int> vec) {
    	for (unsigned int i=0;i<vec.size();i++) {
    		cout<<vec[i]<<",";
    	}
    	cout<<endl;
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
