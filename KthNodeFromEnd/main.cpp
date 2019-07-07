#include <iostream>
#include <vector>
#include "../utils/ListNode.h"

using namespace std;

ListNode *FindKthToTail(ListNode *pListHead, unsigned int k){
    //注意代码完整性判断
    if (pListHead == nullptr || k == 0)
        return nullptr;


    ListNode *pFast = pListHead;
    ListNode *pSlow = pListHead;
    for (unsigned int i=0; i<k-1; ++i){
        if (pFast->m_pNext == nullptr)
            return nullptr;
        pFast = pFast->m_pNext;
    }
    while(pFast->m_pNext != nullptr){
        pFast = pFast->m_pNext;
        pSlow = pSlow->m_pNext;
    }
    return pSlow;
}

int main()
{
    vector<int> value = {1,2,3,4,5,6,7};
    ListNode *pHead = TailCreateList(value);

    ListNode *pNode = FindKthToTail(pHead, 1);
    PrintListNode(pNode);

    return 0;
}
