/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        vector<ListNode*> vec;
        ListNode* p = head;
        while(p)
        {
            vec.push_back(p);
            p = p->next;
        }

        int del = vec.size()-n;
        if(del == 0)
        {
            head = head->next;
            delete vec[0];
        }
        else
        {
            ListNode* left = vec[del-1];
            ListNode* right = vec[del];
            left->next=right->next;
            delete right;
        }
        return head;
    }
};
