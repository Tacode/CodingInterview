/*
 * 链表中的环的入口节点
*/
#include <iostream>
#include <vector>
#include "../utils/ListNode.h"
using namespace std;

//////////////建立有环的链表///////////////////////////////
ListNode *CreateLoopList(vector<int> &value, int node){
    ListNode *pHead = new ListNode(value[0]);
    ListNode *pNode = pHead;
    ListNode *pNodeCross = nullptr;
    for (size_t i=1; i<value.size(); ++i){
        ListNode *pNew = new ListNode(value[i]);
        pNode->m_pNext = pNew;
        pNode = pNew;
        if (value[i] == node)
            pNodeCross = pNew;
    }
    pNode->m_pNext = pNodeCross;
    return pHead;
}

void PrintLoopList(ListNode *pHead, int len_node){
    ListNode *pNode = pHead;
    for (int i=0; i<len_node; ++i){
        if (pNode == nullptr)
            break;
        cout << pNode->m_value << " " ;
        pNode = pNode->m_pNext;
    }
    cout << endl;
}

ListNode *GetTestList(){
    vector<int> value = {1,2,3,4,5};
    int node = 2;
    int len_node = value.size();
    ListNode *pHead = CreateLoopList(value, node);
//    PrintLoopList(pHead, len_node+1);
    return pHead;
}

////////////////////////////////////////////////////
// 快慢指针相遇节点，可以判断是否有环
ListNode *MeetNode(ListNode *pHead){
    if (pHead == nullptr)
        return nullptr;
    ListNode *pSlow = pHead;
    ListNode *pFast = pHead->m_pNext;

    while(pSlow != nullptr && pFast != nullptr){
        if (pFast == pSlow)
            return pFast;
        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;
        if (pFast != nullptr)
            pFast = pFast->m_pNext;
    }

    return nullptr;
}

// 求解链表环的入口节点
ListNode *EntroyNodeOfLoop(ListNode *pHead){
    // 判断是否有环，若有，得到环中的一个节点
    ListNode *pMeetNode = MeetNode(pHead);
    if (pMeetNode == nullptr)
        return nullptr;

    //通过环中的一个节点，得到环中节点数目
    ListNode *pNode1 = pMeetNode;
    int numInLoops = 1;
    while (pNode1->m_pNext != pMeetNode){
        pNode1 = pNode1->m_pNext;
        numInLoops++;
    }
    // 一个节点走环中节点数步，然后两个节点同时走，相遇的节点为环入口节点
    pNode1 = pHead;
    ListNode *pNode2 = pHead;
    for (int i=0; i<numInLoops; ++i){
        pNode1 = pNode1->m_pNext;
    }

    while (pNode1 != pNode2){
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    return pNode1;

}


int main(int argc, char *argv[])
{
    ListNode *pHead = GetTestList();
    ListNode *pEntroyNode = EntroyNodeOfLoop(pHead);
    PrintListNode(pEntroyNode);
    return 0;
}
