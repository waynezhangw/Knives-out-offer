#include<iostream>
#include<vector>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};

class Solution {
   public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode) {
        if (pNode == nullptr) return nullptr;
        TreeLinkNode *pNext = nullptr;
        if (pNode->right != nullptr) {     // when node has right subtree
            pNext = pNode->right;
            while(pNext->left != nullptr) pNext = pNext->left;
        }
        else if (pNode->next != nullptr && pNode->next->left == pNode) {  // when node is father's left
            pNext = pNode->next;
        }
        else {                   // when node is at far right sub, have to go up
            pNext = pNode->next;
            while (pNext != nullptr && pNext->next != nullptr && pNext->next->right == pNext) {
                pNext = pNext->next;
            }
            if (pNext == nullptr) return nullptr;    // be careful with root node
            pNext = pNext->next;
        }
        return pNext;
    }
};

int main() {
    return 0;
}