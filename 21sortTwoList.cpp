#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /**
     *在进行节点处理时遇到一个最常见的问题，第一个节点怎么取的问题，
     *很明显在，下面这个函数中的处理方法，使得问题的求解很麻烦，
     *特例化了头结点问题，在采用的第二种方法上，使得头结点问题一般化，
     *简化了问题的求解过程。
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* Head=NULL;
        ListNode* End=NULL;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        while(l1 && l2)
        {
            if(Head == NULL)
            {
                if(l1->val > l2->val)
                {
                    Head=l2;
                    End=l2;
                    l2 = l2->next;
                    Head->next = NULL;
                }
                else
                {
                    Head=l1;
                    End=l1;
                    l1 = l1->next;
                    Head->next = NULL;
                }
            }
            else
            {
                if(l1->val > l2->val)
                {
                    End->next = l2;
                    l2 = l2->next;
                    End = End->next;
                    End->next = NULL;
                }
                else
                {
                    End->next = l1;
                    l1 = l1->next;
                    End = End->next;
                    End->next = NULL;
                }
            }
        }
        if(l1) End->next = l1;
        if(l2) End->next = l2;
        return Head;
    }


    //一般化头结点问题
    ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2)
    {
        ListNode Head(0);
        ListNode* Tail = &Head;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                Tail->next = l2;
                l2=l2->next;
            }
            else
            {
                Tail->next = l1;
                l1 = l1->next;
            }
            Tail = Tail->next;
        }
        Tail->next = l1 ? l1 : l2;
        return Head.next;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
