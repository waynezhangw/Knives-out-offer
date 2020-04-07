#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x){
		val = x;
		next = NULL;
	}
	// ListNode(int x): val(x), next(NULL) {}
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
		if (head->next == NULL){
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
	void printListAddress(ListNode *head){
		if (head->next == NULL){
			cout<<"link is empty!"<<endl;
		}
		else {
			ListNode* temp = new ListNode(-1);
			temp = head;
			while (temp != NULL){
				cout<<temp<<endl;
				temp = temp->next;
			}
		}
	}
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret, tempVec;
        if (head == NULL){        //关键的一步，之前是head->next == NULL
			return ret;
		}
		else {
			ListNode* temp = new ListNode(-1);
			temp = head;
			while (temp != NULL){
				tempVec.push_back(temp->val);
				temp = temp->next;
			}
		}
		unsigned int forTimes = tempVec.size()-1;
		for(int i=(int)forTimes;i>=0;i--){
			cout<<tempVec[i]<<"->";
			ret.push_back(tempVec[i]);
		}
		cout<<endl;
        return ret;
    }
	
};

int main(){
	Solution sol;
	ListNode* head = new ListNode(-1);
	head = sol.create(head);
	sol.printList(head);
	sol.printListAddress(head);
	vector<int> receive = sol.printListFromTailToHead(head);
	cout<<receive.size()<<endl;
	for(unsigned int i=0;i<receive.size();i++){
		cout<<receive[i]<<"->";
	}

	delete head;
	head = NULL;
	return 0;
}