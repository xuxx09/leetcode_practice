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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0)return NULL;
        while(lists.size()>1)
        {
            ListNode* temp = mergeList(lists[0], lists[1]);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.push_back(temp);
        }
        return lists[0];
    }
    /**
     *使用递归方法合并两个链表。
     */
    ListNode* mergeList(ListNode* left, ListNode* right)
    {
        if(left==NULL) return right;
        if(right==NULL) return left;
        if(left->val > right->val)
        {
            right->next = mergeList(left, right->next);
            return right;
        }
        else
        {
            left->next = mergeList(left->next, right);
            return left;
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
