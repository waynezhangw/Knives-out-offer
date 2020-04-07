#include<iostream>

using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *create(ListNode *head) {
		ListNode* p1 = new ListNode(-1);
		ListNode* p2 = new ListNode(-1);
		int i = 1;
		cout<<"type in your head value:"<<endl;
		cin>>p1->val;
		while(p1->val > -1){
			if (head->next == NULL) {
				head = p1;
				head->next = p2;
			}
			else {
				p2->next = p1;
			}
			p2 = p1;
			p1 = new ListNode(-1);
			i++;
			cout<<"type in next value:"<<endl;
			cin>>p1->val;
		}
		delete p1;
		p1 = NULL;
		p2->next = NULL;
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

    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    	if (pHead1 == NULL && pHead2 != NULL) {
    		return pHead2;
    	}
    	else if (pHead1 != NULL && pHead2 == NULL) {
    		return pHead1;
    	}
    	else if (pHead1 == NULL && pHead2 == NULL) {
    		return NULL;
    	}
    	else {
    		ListNode* temp = NULL;
    		if (pHead1->val > pHead2->val) {
    			temp = pHead2;
    			pHead2 = pHead1;
    			pHead1 = temp;
    		}
    		ListNode* p1 = new ListNode(-1);
    		ListNode* p2 = new ListNode(-1);
    		p1 = pHead1;
    		p2 = pHead1->next;
    		while (pHead2 != NULL) {
    			while (p2 != NULL && pHead2->val > p2->val) {
    				p1 = p2;
    				p2 = p2->next;
    			}
    			p1->next = pHead2;
    			temp = pHead2;
    			pHead2 = pHead2->next;
    			p1->next->next = p2;
    			p1 = temp;
    		}
    	}
    	return pHead1;
    }

    ListNode* Merge2(ListNode* pHead1, ListNode* pHead2) {  //解法2，递归解
    	if (pHead1 == NULL && pHead2 != NULL) {
    		return pHead2;
    	}
    	else if (pHead1 != NULL && pHead2 == NULL) {
    		return pHead1;
    	}
    	else if (pHead1 == NULL && pHead2 == NULL) {
    		return NULL;
    	}
    	else {
    		if (pHead1->val > pHead2->val) {
    			ListNode* temp = pHead2;
    			pHead2 = pHead1;
    			pHead1 = temp;
    		}
    		ListNode* mergedHead = pHead1;
    		mergedHead->next = Merge2(pHead1->next, pHead2);
    		return mergedHead;
    	}
    }
};

int main() {
	Solution sol;
	ListNode* link1 = new ListNode(-1);
	link1 = sol.create(link1);
	sol.printList(link1);
	ListNode* link2 = new ListNode(-1);
	link2 = sol.create(link2);
	sol.printList(link2);
	link1 = sol.Merge2(link1, link2);
	sol.printList(link1);
	return 0;
}