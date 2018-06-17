#ifndef QT_LINKED_LIST_H
#define QT_LINKED_LIST_H

#include <iostream>
#include <map>
using std::cout;
using std::endl;
using std::map;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
typedef std::map<RandomListNode*, RandomListNode*> map_random_node;


namespace linked_list {
    void insert_front(ListNode** phead, int ele)
    {
        ListNode* nn = new ListNode(ele);
        nn->next = *phead;
        *phead = nn;
        return;
    }

    void insert_back(ListNode** phead, int ele)
    {
        ListNode* nn = new ListNode(ele);
        nn->next = nullptr;
        if(!*phead)
        {
            *phead = nn;
        }
        else
        {
            ListNode* ptmp = *phead;
            while (ptmp->next) {
                ptmp = ptmp->next;
            }
            ptmp->next = nn;
        }

        return;
    }

    void print_lst(ListNode* phead)
    {
        while(phead)
        {
            cout << "[" << phead->val << "]" << endl;
            phead = phead->next;
        }
    }

    ListNode* get_tail(ListNode* phead)
    {
        if(!phead) return nullptr;
        while(phead->next)
            phead = phead->next;
        return phead;
    }

    void bubble_sort(ListNode* phead)
    {
        if(!phead || !(phead)->next)
            return;

        ListNode* ptarget = phead;
        ListNode* piter = (phead)->next;

        while(ptarget->next)
        {
            piter = ptarget->next;
            while(piter)
            {
                if(ptarget->val > piter->val)
                {
                    int tmp = ptarget->val;
                    ptarget->val = piter->val;
                    piter->val = tmp;
                }

                piter = piter->next;
            }
            ptarget = ptarget->next;
        }
    }

    void insert_bef(ListNode** pphead, ListNode* paftnode, ListNode* pinsertnode)
    {
        if(!(pphead) || !*pphead || !paftnode || !pinsertnode)
            return;

        if(*pphead == paftnode)
        {
            pinsertnode->next = *pphead;
            *pphead = pinsertnode;
        }
        else {
            ListNode* pbefnode = *pphead;
            if(!pbefnode->next)
                return;

            while (pbefnode->next != paftnode) {
                pbefnode = pbefnode->next;

                if(!pbefnode) //cannot found node to put inserted node
                    return;
            }

            //remove the link to the node to be insert
            ListNode* pbefinsert = *pphead;
            while(pbefinsert->next != pinsertnode)
            {
                pbefinsert = pbefinsert->next;

                if(!pbefinsert)
                    return;
            }
            pbefinsert->next = pbefinsert->next->next;

            //do insert
            pbefnode->next = pinsertnode;
            pinsertnode->next = paftnode;
        }
    }

    /*void insert_sort(ListNode** pphead)
    {
        /*if(!pphead || !*pphead || !(*pphead)->next)
            return;

        ListNode* psorted = *pphead;
        ListNode* punsorted = (*pphead)->next;

        while(punsorted)
        {
            ListNode* ptmp = *pphead;
            while(ptmp != punsorted)
            {

            }
        }*/

    ListNode* rotateRight(ListNode* phead, int k)
    {
        if(phead == nullptr || k <= 0)
            return phead;

        //get length of list
        ListNode* ptmp = phead;
        ListNode* ptail = nullptr;
        int len = 0;
        while(ptmp != nullptr)
        {
            ++len;
            ptail = ptmp;
            ptmp = ptmp->next;
        }
        k %= len;

        //form a loop with list
        ptail->next = phead;

        //step len-k steps backward
        ptmp = ptail;
        for(int i = 0; i < len - k; ++i)
        {
            //ptail = ptmp;
            ptmp = ptmp->next;
        }
        ptail = ptmp;
        phead = ptail->next;
        ptail->next = nullptr;

        return phead;
    }

    ListNode* swap_pairs(ListNode* phead)
    {
        if(!phead || !phead->next)
            return phead;

        ListNode dummy(-1);
        dummy.next = phead;

        for(ListNode *pprev = &dummy, *pcur = dummy.next, *pnext = dummy.next->next;
            pnext != nullptr;
            pprev = pcur, pcur = pcur->next, pnext = (pcur == nullptr)?nullptr:pcur->next)
        {
            pprev->next = pnext;
            pcur->next = pnext->next;
            pnext->next = pcur;
        }

        return dummy.next;
    }

    RandomListNode* copy_random_lst(RandomListNode* lst)
    {
        map_random_node map;
        RandomListNode* pold = lst;
        while(pold)
        {
            map[pold] = new RandomListNode(pold->label);
            pold = pold->next;
        }

        pold = lst;
        while(pold)
        {
            map[pold]->next = map[pold->next];
            map[pold]->random = map[pold->random];
            pold = pold->next;
        }

        return map[lst];
    }

};

namespace test_linked_list{
using namespace linked_list;
    void populate_list()
    {
        ListNode* phead = nullptr;
        insert_back(&phead, 1);
        insert_back(&phead, 2);
        insert_back(&phead, 3);
        insert_back(&phead, 4);
        insert_front(&phead, 0);
        //print_lst(phead);
        //bubble_sort(phead);
        ListNode* ptail = get_tail(phead);
        insert_bef(&phead, phead->next, ptail);
        print_lst(phead);
    }
};

#endif // QT_LINKED_LIST_H
