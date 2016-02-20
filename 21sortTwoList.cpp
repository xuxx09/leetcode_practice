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
     *�ڽ��нڵ㴦��ʱ����һ����������⣬��һ���ڵ���ôȡ�����⣬
     *�������ڣ�������������еĴ�������ʹ������������鷳��
     *��������ͷ������⣬�ڲ��õĵڶ��ַ����ϣ�ʹ��ͷ�������һ�㻯��
     *��������������̡�
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


    //һ�㻯ͷ�������
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
