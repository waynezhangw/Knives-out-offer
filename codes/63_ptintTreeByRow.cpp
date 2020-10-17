#include <deque>
#include <iostream>
#include <queue>  // std::queue
#include <vector>

using std::cout;
using std::deque;
using std::endl;
using std::queue;
using std::vector;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode() {
        val = 0;
        left = NULL;
        right = NULL;
    }
};

class Solution {
   public:
    Solution() {
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
    virtual ~Solution(void) {
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
    void initialization() {
        vector<int> A = {3, 9, 20, 5, 6, 15, 7,
                         NULL, NULL, NULL, NULL, NULL, NULL, 1, 2};
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
        cout << "Preorder Traversal:" << endl;
        seeTree(root);
        cout << endl;
        cout << "row by row display: " << endl;
        vector<vector<int>> vec = Print2(root);
        cout << "the vec is:" << endl;
        seeVec(vec);
    }

    void seeTree(TreeNode* root) {
        if (root) {
            cout << root->val << ",";
            seeTree(root->left);
            seeTree(root->right);
        } else {
            //cout<<"NULL"<<",";
        }
    }
    void seeVec(vector<vector<int>>& vec) {
        for (unsigned int i = 0; i < vec.size(); i++) {
            for (unsigned int j = 0; j < vec[i].size(); j++) {
                cout << vec[i][j] << ",";
            }
            cout << endl;
        }
    }
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> vec;
        if (pRoot == NULL) return vec;
        queue<TreeNode*> nodeQu;
        queue<int> rowNum;
        nodeQu.push(pRoot);
        rowNum.push(0);
        while (!nodeQu.empty()) {
            if (nodeQu.back() != NULL && rowNum.back() + 1 > int(vec.size())) {
                vector<int> temp;
                vec.push_back(temp);
            }
            vec[rowNum.front()].push_back(nodeQu.front()->val);
            if (nodeQu.front()->left != NULL) {
                nodeQu.push(nodeQu.front()->left);
                rowNum.push(rowNum.front() + 1);
            }
            if (nodeQu.front()->right != NULL) {
                nodeQu.push(nodeQu.front()->right);
                rowNum.push(rowNum.front() + 1);
            }
            nodeQu.pop();
            rowNum.pop();
        }
        return vec;
    }

    vector<vector<int>> Print2(TreeNode* pRoot) {  // reference knives code, one queue
        vector<vector<int>> vec;
        if (pRoot == NULL) return vec;
        queue<TreeNode*> nodeQu;
        nodeQu.push(pRoot);
        int currentLeftNodeNum = 1;
        int nextLineNodeNum = 0;
        vector<int> temp;
        vec.push_back(temp);
        while (!nodeQu.empty()) {
            vec[vec.size()-1].push_back(nodeQu.front()->val);
            if (nodeQu.front()->left != NULL) {
                nodeQu.push(nodeQu.front()->left);
                nextLineNodeNum++;
            }
            if (nodeQu.front()->right != NULL) {
                nodeQu.push(nodeQu.front()->right);
                nextLineNodeNum++;
            }
            nodeQu.pop();
            currentLeftNodeNum--;
            if (currentLeftNodeNum == 0) {
                currentLeftNodeNum = nextLineNodeNum;
                nextLineNodeNum = 0;
                if (currentLeftNodeNum != 0) vec.push_back(temp);
            }
        }
        return vec;
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

int main() {
    Solution test;
    test.initialization();
    return 0;
}