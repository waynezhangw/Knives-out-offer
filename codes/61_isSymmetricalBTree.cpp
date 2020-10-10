#include <iostream>
#include <vector>

using std::cout;
using std::endl;
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
        cout << "isSymmetrical yes or no: " << isSymmetrical(root) << endl;
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
    bool isSymmetrical(TreeNode* pRoot) {  // after reference knives book
        vector<int> A, B;
        seeRootLR(pRoot, A, true);
        seeRootLR(pRoot, B, false);
        return A == B;
    }
    void seeRootLR(TreeNode* root, vector<int>& vec, bool LR) {
        if (root) {
            vec.push_back(root->val);
            cout << root->val << ",";
            if (LR) {
                seeRootLR(root->left, vec, LR);
                seeRootLR(root->right, vec, LR);
            } else {
                seeRootLR(root->right, vec, LR);
                seeRootLR(root->left, vec, LR);
            }
        } else {
            vec.push_back(NULL);
        }
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
