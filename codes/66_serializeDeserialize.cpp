#include <deque>
#include <iostream>
#include <queue>  // std::queue
#include <stack>
#include <string>
#include <vector>

using std::cout;
using std::deque;
using std::endl;
using std::queue;
using std::stack;
using std::string;
using std::vector;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
   public:
    Solution() {
        root = new TreeNode(0);
        L2_1 = new TreeNode(0);
        R2_1 = new TreeNode(0);
        L3_1 = new TreeNode(0);
        L3_2 = new TreeNode(0);
        R3_1 = new TreeNode(0);
        R3_2 = new TreeNode(0);
        L4_4 = new TreeNode(0);
        R4_4 = new TreeNode(0);
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
        cout << "Inorder Traversal:" << endl;
        seeTree(root);
        cout << endl;
        cout << "preorder display: " << endl;
        char* c = Serialize(root);
        int i = 0;
        while (*(c+i) != '\0') {
            cout<<*(c+i);
            i++;
        }
        cout<<endl;
        TreeNode* newRoot = Deserialize(c);
        cout << "Reconstruct tree:" << endl;
        seeTree(newRoot);
        cout << endl;
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
    char* Serialize(TreeNode* root) {
        string str;
        subSerialize(root, str);
        //--------very strange, this part didn't work at nowcoder website--------
        // change last one from ',' to '\0'
        // if(str.size() != 0 && str[str.size()-1] == ',') str[str.size()-1] = '\0';
        // if(str[str.size()-1] != '\0') str += '\0';
        // char* cstr = (char*)str.c_str();
        // return cstr;
        //--------very strange, this part didn't work at nowcoder website--------
        char *ret = new char[str.length() + 1];
        int i;
        for(i = 0; i < str.length(); i++){
            ret[i] = str[i];
        }
        ret[i] = '\0';
        return ret;
    }
    void subSerialize(TreeNode* root, string& str) {
        if (root != NULL) {
            str += std::to_string(root->val);;
            str += ',';
            subSerialize(root->left, str);
            subSerialize(root->right, str);
        } else {
            str += '#';
            str += ',';
        }
    }
    TreeNode* Deserialize(char* str) {
        if (str == NULL) return NULL;
        TreeNode* rootRet = subDeserialize(&str);
        return rootRet;
    }
    TreeNode* subDeserialize(char **str) {
        char temp = **str;
        if (**str == '#') {
            ++(*str);      //for pointing the ',' and ready to skip
            ++(*str);      //original answer's '#' dosen't follow ',' , so here must skip ','
            return NULL;
        }
        int num = 0;
        while (**str != '\0' && **str != ',') {
            num = num*10 + ((**str) - '0');
            ++(*str);   //for pointing the ',' and ready to skip    
        }
        TreeNode *rootSub = new TreeNode(num);
        if (**str == '\0') return rootSub;
        else (*str)++;                //for skiping ',' that after the number
        rootSub->left = subDeserialize(str);
        rootSub->right = subDeserialize(str);
        return rootSub;
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

