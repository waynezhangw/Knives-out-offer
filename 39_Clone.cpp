
// struct RandomListNode {
//     int label;
//     struct RandomListNode *next, *random;
//     RandomListNode(int x) :
//             label(x), next(NULL), random(NULL) {
//     }
// };

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (pHead == NULL) return NULL;
        CreateNodes(pHead);
        PutRandomNodes(pHead);
        return CutNodes(pHead);
    }

    void CreateNodes(RandomListNode* pHead){
    	RandomListNode* movinghead = pHead;
        while (movinghead != NULL) {
        	RandomListNode* temp = new RandomListNode(-99);
        	temp->label = movinghead->label;
        	temp->next = movinghead->next;
        	temp->random = NULL;

        	movinghead->next = temp;
        	movinghead = temp->next;
        }
    }

    void PutRandomNodes(RandomListNode* pHead){
    	RandomListNode* movinghead = pHead;
        while (movinghead != NULL) {
        	if (movinghead->random != NULL) {         //要加这个判断
        		movinghead->next->random = movinghead->random->next;
        	}
        	movinghead = movinghead->next->next;
        }
    }

    RandomListNode* CutNodes(RandomListNode* pHead){
    	RandomListNode* movinghead = pHead;
    	RandomListNode* cloneHead = NULL;
    	RandomListNode* moving_cloneHead = NULL;
    	if (movinghead != NULL) {
    		cloneHead = moving_cloneHead = movinghead->next;
    		movinghead->next = moving_cloneHead->next;
    		movinghead = movinghead->next;
    	}
        while (movinghead != NULL) {
        	moving_cloneHead->next = movinghead->next;
        	moving_cloneHead = moving_cloneHead->next;
        	movinghead->next = moving_cloneHead->next;
        	movinghead = movinghead->next;
        }
        return cloneHead;
    }

};