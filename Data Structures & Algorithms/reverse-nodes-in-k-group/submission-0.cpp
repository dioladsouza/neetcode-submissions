/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    ListNode* findKNode(int k, ListNode* temp)
    {
        k -= 1;
        while(temp != NULL && k > 0)
        {
            temp = temp->next;
            k--;
        }
        return temp;
    }
    void reverseList(ListNode* node)
    {
        ListNode* prev = NULL;
        ListNode* current = node;
        ListNode* next;
        while(current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* kNode;
        ListNode* prevNode = NULL;
        while(temp != NULL)
        {
            kNode = findKNode(k, temp);
            if(kNode == NULL)
            {
                if(prevNode) 
                    prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kNode->next;
            kNode->next = NULL;
            reverseList(temp);
            if(head == temp)
                head = kNode;
            else
                prevNode->next = kNode;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
