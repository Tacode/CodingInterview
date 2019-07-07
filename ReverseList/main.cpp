#include <iostream>
#include <vector>
#include "../utils/ListNode.h"

using namespace std;

ListNode *ReversedList(ListNode *pHead){
    ListNode *pReverseHead = nullptr;
    ListNode *pNode = pHead;
    ListNode *pPre = nullptr;
    while(pNode != nullptr){
        ListNode *pNext = pNode->m_pNext;
        if (pNext == nullptr)
            pReverseHead = pNode;
        pNode->m_pNext = pPre;
        pPre = pNode;
        pNode = pNext;
    }
    return pReverseHead;
}

int main(int argc, char *argv[])
{
    vector<int> value = {1,2,3,4,5};
    ListNode *pHead = TailCreateList(value);
    ListNode *pReverseHead = ReversedList(pHead);
    PrintList(pReverseHead);
    return 0;
}
