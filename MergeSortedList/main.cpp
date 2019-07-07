/*
 * 合并两个递增的列表为一个递增的大列表
*/
#include <iostream>
#include <vector>
#include "../utils/ListNode.h"

using namespace std;
ListNode* MergeLists(ListNode *pHead1, ListNode *pHead2){
    if (pHead1 == nullptr)
        return pHead2;
    if (pHead2 == nullptr)
        return pHead1;

    ListNode *pMergeHead = nullptr;
    if (pHead1->m_value <= pHead2->m_value){
        pMergeHead = pHead1;
        pMergeHead->m_pNext = MergeLists(pHead1->m_pNext, pHead2);
    }
    else{
        pMergeHead = pHead2;
        pMergeHead->m_pNext = MergeLists(pHead1, pHead2->m_pNext);
    }
    return pMergeHead;
}

int main(int argc, char *argv[])
{
    vector<int> value1 = {1,2,4,6,8};
    vector<int> value2 = {3,4,5,7,9};
    ListNode *pHead1 = TailCreateList(value1);
    ListNode *pHead2 = TailCreateList(value2);
    ListNode *pMergeHead = MergeLists(pHead1, pHead2);
    PrintList(pMergeHead);
    return 0;
}
