#include <iostream>

using namespace std;
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
    ListNode* swapPairs(ListNode* head)
    {
        if(head == NULL) return head;
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode HEAD(0);
        ListNode *tail=&HEAD;
        while(second != NULL)
        {
            head = second->next;
            tail->next = second;
            second->next = first;
            tail = first;
            if(head == NULL)
            {
                break;
            }
            else
            {
            first = head;
            second = head->next;
            }
        }
        tail->next=head;
        return HEAD.next;
    }
    /**这是一个简单的代码，
     *这里对head和一般指针之间的处理，十分的巧妙
     */
    ListNode* swapPairs(ListNode* head) {
    ListNode **p = &head, *a, *b;
    while ((a = *p) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *p = b;
        p = &(a->next);
    }
    return head;
}


};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
