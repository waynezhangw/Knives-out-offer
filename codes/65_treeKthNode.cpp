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
        vector<int> A = {5, 3, 7, 2, 4, 6, 8,
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
        cout << "Inorder Traversal:" << endl;
        seeTree(root);
        cout << endl;
        cout << "row by row display: " << endl;
        TreeNode* kthNode = KthNode4(root, 2);
        cout << "the kth node is:" <<kthNode->val << endl;
    }

    void seeTree(TreeNode* root) {
        if (root) {
            seeTree(root->left);
            cout << root->val << ",";
            seeTree(root->right);
        } else {
            //cout<<"NULL"<<",";
        }
    }

    //a high upvote solution from comments, very smart
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == NULL) return pRoot;
        int now = 0;
        TreeNode* knode = seeTreeInOrder(pRoot, now, k);
        return knode;
    }
    TreeNode* seeTreeInOrder(TreeNode* root, int &now, int k) {   
        if (root) {
            TreeNode* knode = seeTreeInOrder(root->left, now, k);
            if (knode != NULL) return knode;
            now++;
            if (now == k) return root;
            knode = seeTreeInOrder(root->right, now, k);
            if (knode != NULL) return knode;
        }
        return NULL;
    }

    //a easy way to think by using vector push
    TreeNode* KthNode2(TreeNode* pRoot, int k) {
        if (pRoot == NULL || k<=0) return NULL;
        vector<TreeNode*> vec;
        appendVector(pRoot, vec);
        if (k > vec.size()) return NULL;
        return vec[k-1];
    }
    void appendVector(TreeNode* pRoot, vector<TreeNode*> &vec) {
        if (pRoot == NULL) return;
        appendVector(pRoot->left, vec);
        vec.push_back(pRoot);
        appendVector(pRoot->right, vec);
    }

    //a easy way to think by using vector push with less ram
    TreeNode* KthNode3(TreeNode* pRoot, int k) {
        if (pRoot == NULL || k<=0) return NULL;
        vector<TreeNode*> vec;
        appendLessVector(pRoot, vec, k);
        if (k > vec.size()) return NULL;
        return vec[k-1];
    }
    void appendLessVector(TreeNode* pRoot, vector<TreeNode*> &vec, int k) {
        if (pRoot == NULL) return;
        if (vec.size() == k) return;
        appendLessVector(pRoot->left, vec, k);
        vec.push_back(pRoot);
        if (vec.size() == k) return;
        appendLessVector(pRoot->right, vec, k);
    }

    //from knives code
    TreeNode* KthNode4(TreeNode* pRoot, int k) {
        if (pRoot == NULL || k<=0) return NULL;
        return kthNodeCore(pRoot, k);
    }
    TreeNode* kthNodeCore(TreeNode* pRoot, int &k) {   //&k, gradually change it
        TreeNode* target = NULL;
        if (pRoot->left != NULL) target = kthNodeCore(pRoot->left, k);
        if (target == NULL) {
            if (k == 1) target = pRoot;
            k--;
        }
        if (target == NULL && pRoot->right != NULL) target = kthNodeCore(pRoot->right, k);
        return target;
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