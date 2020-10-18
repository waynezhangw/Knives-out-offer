#include <deque>
#include <iostream>
#include <queue>  // std::queue
#include <stack>
#include <vector>

using std::cout;
using std::deque;
using std::endl;
using std::queue;
using std::stack;
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
    vector<vector<int>> Print(TreeNode* pRoot) {  //reference knives book idea
        vector<vector<int>> vec;
        if (pRoot == NULL) return vec;
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        stack1.push(pRoot);
        vector<int> temp;
        vec.push_back(temp);
        int currentLine = 0;
        while (!stack1.empty() || !stack2.empty()) {
            if (currentLine % 2 == 0) {
                if (stack1.top()->left != NULL) {
                    stack2.push(stack1.top()->left);
                }
                if (stack1.top()->right != NULL) {
                    stack2.push(stack1.top()->right);
                }
                vec[currentLine].push_back(stack1.top()->val);
                stack1.pop();
                if (stack1.empty()) {
                    currentLine++;
                    if (!stack2.empty()) vec.push_back(temp);  //be careful, dont add empty vec
                }
            } else {
                if (stack2.top()->right != NULL) {
                    stack1.push(stack2.top()->right);
                }
                if (stack2.top()->left != NULL) {
                    stack1.push(stack2.top()->left);
                }
                vec[currentLine].push_back(stack2.top()->val);
                stack2.pop();
                if (stack2.empty()) {
                    currentLine++;
                    if (!stack1.empty()) vec.push_back(temp);
                }
            }
        }
        return vec;
    }

    vector<vector<int>> Print2(TreeNode* pRoot) {   //reference knives code, concise array stack
        vector<vector<int>> vec;
        if (pRoot == NULL) return vec;
        stack<TreeNode*> stackNode[2];
        stackNode[0].push(pRoot);
        vector<int> temp;
        vec.push_back(temp);
        int currentLine = 0;
        int nextLine = 1;
        int lineNum = 0;
        while (!stackNode[0].empty() || !stackNode[1].empty()) {
            TreeNode* tempNode = stackNode[currentLine].top();
            vec[lineNum].push_back(tempNode->val);
            if (currentLine == 0) {
                if (tempNode->left != NULL) {
                    stackNode[nextLine].push(tempNode->left);
                }
                if (tempNode->right != NULL) {
                    stackNode[nextLine].push(tempNode->right);
                }
            } 
            else {
                if (tempNode->right != NULL) {
                    stackNode[nextLine].push(tempNode->right);
                }
                if (tempNode->left != NULL) {
                    stackNode[nextLine].push(tempNode->left);
                }
            }
            stackNode[currentLine].pop();         // pop before judge
            if (stackNode[currentLine].empty()) {
                if (!stackNode[nextLine].empty()) {
                    vec.push_back(temp);
                    lineNum++;            // indicate how many rows
                }
                currentLine = nextLine;
                nextLine = 1 - currentLine;   // be careful
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

