#include<iostream>

using std::cout;
using std::cin;
using std::endl;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode *create(ListNode *head) {
        ListNode* p1 = new ListNode(-1);
        ListNode* p2 = new ListNode(-1);
        ListNode* entryNode = new ListNode(-1);
        int i = 1;
        cout<<"type in your head value:"<<endl;
        cin>>p1->val;
        while(p1->val > -1){
            if (head->next == NULL) {
                head = p1;
                head->next = p2;     //temporary point to p2, so the next node of the head won't be NULL
            }
            else {
                p2->next = p1;     
            }
            p2 = p1;
            p1 = new ListNode(-1);
            if(i == 3) entryNode = p2;  //1
            i++;
            cout<<"type in next value:"<<endl;
            cin>>p1->val;
        }
        delete p1;
        p1 = NULL;
        // p2->next = NULL;
        p2->next = entryNode;   //2
        cout<<"type link over!"<<endl;
        return head;
    }

    void printList(ListNode *head){
        if (head == NULL || head->next == NULL){
            cout<<"link is empty!"<<endl;
        }
        else {
            ListNode* temp = new ListNode(-1);
            temp = head;
            while (temp != NULL){
                cout<<temp->val<<"->";
                temp = temp->next;
            }
        }
        cout<<endl;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead) {                //finished by reading kives book description, 3ms and 376k
        if (pHead == NULL || pHead->next == NULL) return NULL;  //the second judge is very important
        ListNode* p1 = new ListNode(-1);
        ListNode* p2 = new ListNode(-1);
        p1 = pHead->next;               //slow node
        p2 = p1->next;                  //fast node
        int i = 1, j = 2;
        while(p1 != p2) {
            p1 = p1->next;
            i++;
            for (int i=0;i<2;i++) p2 = p2->next;
            j = j + 2;
            if (p2 == NULL || p2->next == NULL) return NULL;
        }
        int circleLength = j - i;
        p1 = pHead;
        p2 = pHead;
        while (circleLength--) {
            p2 = p2->next;
        }
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;  //or p1
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(-1);
    head = sol.create(head);
    // sol.printList(head);
    head = sol.EntryNodeOfLoop(head);
    cout<<head->val<<endl;
    // sol.printList(head);
    return 0;
}