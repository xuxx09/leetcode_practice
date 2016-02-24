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
    /**
     * 在这个方法中，使用了一个辅助的栈操作，通过
     * 栈进行数据的翻转。这是一个很容易想到的方法。
     */
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        //ListNode** HEAD = &head;
        ListNode HEAD(0);
        ListNode* tail = &HEAD;
        vector<ListNode*> vec;
        while(head)
        {
            while(vec.size()<k && head)
            {
                vec.push_back(head);
                head = head->next;
            }
            if(vec.size()== k)
            {
                while(vec.size() != 0)
                {
                    tail->next = vec.back();
                    vec.pop_back();
                    tail = tail->next;
                }
            }
            else
            {
                while(vec.size() !=0)
                {
                    tail->next = vec.front();
                    vec.erase(vec.begin());
                    tail = tail->next;
                }
            }
        }

        tail->next = head;
        return HEAD.next;
    }

    //还可以使用一种先进行遍历计算结点的个数，
    //然后根据个数采用前插法进行处理。
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode HEAD(0);
        int num = 0;
        ListNode* pre=head;
        ListNode* result=&HEAD;

        while(pre)
        {
            num++;
            pre = pre->next;
        }
        while(num >= k)
        {
            ListNode* tail = head;
            for(int i=0; i<k; i++)
            {
                ListNode* temp = head;
                head = head->next;
                temp->next = result->next;
                result->next=temp;
            }
            num -= k;
            result = tail;
        }
        result->next = head;
        return HEAD.next;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
