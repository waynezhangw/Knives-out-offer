#include<iostream>
#include<set>
#include<stack>

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

	ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {  //O(n)
        if (pHead1 == NULL || pHead2 == NULL) {
    		return NULL;
    	}
    	else {
    		set<ListNode*> link;
    		while (pHead1 != NULL) {
    			link.insert(pHead1);
    			pHead1 = pHead1->next;
    		}
    		pair <set<ListNode*>::iterator,bool> it;
    		while (pHead2 != NULL) {
    			it = link.insert(pHead2);
    			if (it.second == false) return pHead2;
    			pHead2 = pHead2->next;
    		}
    		return NULL;
    	}
    }

    ListNode* FindFirstCommonNode2( ListNode* pHead1, ListNode* pHead2) {  //方法2，用两个辅助栈，从最后开始同时比较,O(3n)
        if (pHead1 == NULL || pHead2 == NULL) {
    		return NULL;
    	}
    	else {
    		stack<ListNode*> stack1;
    		stack<ListNode*> stack2;
    		while (pHead1 != NULL) {
    			stack1.push(pHead1);
    			pHead1 = pHead1->next;
    		}
    		while (pHead2 != NULL) {
    			stack2.push(pHead2);
    			pHead2 = pHead2->next;
    		}
    		ListNode* temp = NULL;
    		while (!stack1.empty() && !stack2.empty()) {
    			if (stack1.top() == stack2.top()) {
    				temp = stack1.top();
    			}
    			else {
    				return temp;
    			}
    			stack1.pop();
    			stack2.pop();
    		}
    		return temp;
    	}
    }

    ListNode* FindFirstCommonNode3( ListNode* pHead1, ListNode* pHead2) {  //方法3，不用辅助栈，算两个链表的长度，让长的先走,O(3n)
        if (pHead1 == NULL || pHead2 == NULL) {
    		return NULL;
    	}
    	else {
    		int length1 = 0;
    		int length2 = 0;
    		ListNode* temp1 = pHead1;
    		ListNode* temp2 = pHead2;
    		while (temp1 != NULL) {
    			length1++;
    			temp1 = temp1->next;
    		}
    		while (temp2 != NULL) {
    			length2++;
    			temp2 = temp2->next;
    		}
    		int lengthDiff = abs(length1-length2);
    		if (length1 >= length2) {
    			for (int i=0;i<lengthDiff;i++) {
    				pHead1 = pHead1->next;
    			}
    		}
    		else {
    			for (int i=0;i<lengthDiff;i++) {
    				pHead2 = pHead2->next;
    			}
    		}
    		while (pHead1 != NULL) {    //此时phead1和phead2一样长了
    			if (pHead1 == pHead2) return pHead1;
    			pHead1 = pHead1->next;
    			pHead2 = pHead2->next;
    		}
    		return NULL;
    	}
    }

    ListNode* FindFirstCommonNode4( ListNode* pHead1, ListNode* pHead2) {  //方法4，看完评论，最短的代码哈哈哈
        if (pHead1 == NULL || pHead2 == NULL) {
    		return NULL;
    	}
    	else {
    		ListNode *p1 = pHead1;
    		ListNode *p2 = pHead2;
    		while(p1!=p2){
    			p1 = (p1==NULL ? pHead2 : p1->next);    //相当于把两个链表合起来遍历，总能找到公共点，最多遍历m+n次
    			p2 = (p2==NULL ? pHead1 : p2->next);    //要是没有公共点，他俩会一起到NULL，而弹出while循环
    		}
    		return p1;
    	}
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
	ListNode* link3 = new ListNode(-1);
	link3 = sol.FindFirstCommonNode4(link1, link2);
	sol.printList(link3);
	return 0;
}
