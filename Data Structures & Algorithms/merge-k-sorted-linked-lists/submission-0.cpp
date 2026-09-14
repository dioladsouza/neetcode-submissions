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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
        greater<pair<int, ListNode*>>> min_heap;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i])
                min_heap.push({lists[i]->val, lists[i]});
        }
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(!min_heap.empty())
        {
            auto it = min_heap.top();
            min_heap.pop();
            temp->next = it.second;
            temp = temp->next;
            if(it.second->next) 
                min_heap.push({it.second->next->val, it.second->next});
        }
        return dummyNode->next;
    }
};
