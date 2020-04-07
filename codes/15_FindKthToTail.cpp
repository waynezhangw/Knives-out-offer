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
				head->next = p2;     //临时指一下p2，这样头节点的next值就不会是NULL
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

    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if (pListHead == NULL || k == 0){
    		return NULL;
    	}
    	ListNode* forward = pListHead;
    	ListNode* behind = NULL;

    	for (unsigned int i=1;i<k;i++){
    		if (forward->next != NULL){
    			forward = forward->next;
    		}
    		else {
    			return NULL;
    		}
    	}

    	behind = pListHead;
    	while (forward->next != NULL){
    		forward = forward->next;
    		behind = behind->next;
    	}
    	return behind;
    }

    ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k) {  //看完评论，改进版之先让你跑两步
    	if (pListHead == NULL || k == 0){
    		return NULL;
    	}
    	ListNode* forward = pListHead;
    	ListNode* behind = pListHead;

    	unsigned int i=1;
    	for ( ;forward->next != NULL; i++){
    		if (i >= k){
    			behind = behind->next;
    		}
    		forward = forward->next;
    	}
    	return i<k ? NULL:behind ;
    }
};

int main(){
	Solution sol;
	ListNode* head = new ListNode(-1);
	head = sol.create(head);
	sol.printList(head);
	head = sol.FindKthToTail2(head,3);
	sol.printList(head);
	return 0;
}