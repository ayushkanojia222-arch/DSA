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
        vector<int> vals;
        for (ListNode* head : lists) {
            while (head) {
                vals.push_back(head->val);
                head = head->next;
            }
        }

        sort(vals.begin(), vals.end());

        ListNode dummy(0);
        ListNode* cur = &dummy;
        for (int v : vals) {
            cur->next = new ListNode(v);
            cur = cur->next;
        }
        return dummy.next;
    }
};