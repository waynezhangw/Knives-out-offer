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

    ListNode* ReverseList(ListNode* pHead) {
    	if (pHead == NULL){
    		return NULL;
    	}
    	if (pHead->next == NULL){
    		return pHead;
    	}
    	ListNode* p1 = NULL;    //一开始拿到是：p1->p2->p3
    	ListNode* p2 = pHead;   //想变成：p1<-p2<-p3
    	ListNode* p3 = pHead->next;
    	p2->next = p1;
    	p1 = p2;
    	while (p3->next != NULL){
    		p2 = p3;
    		p3 = p3->next;
    		p2->next = p1;
    		p1 = p2;
    	}
    	p3->next = p2;    //相当于到原链表的尾节点，此时就他一个是断裂的
    	return p3;
    }
};

int main(){
	Solution sol;
	ListNode* head = new ListNode(-1);
	head = sol.create(head);
	sol.printList(head);
	head = sol.ReverseList(head);
	sol.printList(head);
	return 0;
}