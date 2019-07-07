/*链表定义
 *
 * */

#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;
struct ListNode{
    int m_value;
    ListNode *m_pNext = nullptr;
    ListNode(int x):m_value(x){}
};

ListNode *CreateListNode(int value);
ListNode *HeadCreateList(vector<int> &value_vec);
ListNode *TailCreateList(vector<int> &value_vec);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode *pHead);
void DestroyList(ListNode *pHead);
void AddToTail(ListNode **pHead, int value);
void RemoveNode(ListNode **pHead, int value);

#endif

ListNode *CreateListNode(int value)
{
    ListNode *pNode = new ListNode(value);
    return pNode;
}
//尾插法，插入顺序与最后一致
ListNode *TailCreateList(vector<int> &value_vec)
{
    if (value_vec.empty())
        return nullptr;
    ListNode *pHead = new ListNode(value_vec[0]);
    ListNode *pNode = pHead;
    for (size_t i=1; i<value_vec.size(); ++i){
        ListNode *pNew = new ListNode(value_vec[i]);
        pNode->m_pNext = pNew;
        pNode = pNew;
    }
    return pHead;
}
// 头插法，插入顺序与最后相反
ListNode *HeadCreateList(vector<int> &value_vec)
{
    if (value_vec.empty())
        return nullptr;
    ListNode *pHead = new ListNode(0);
//    pHead->m_pNext = nullptr;
    for (size_t i=0; i<value_vec.size(); ++i){
        ListNode *pNew = new ListNode(value_vec[i]);
        pNew->m_pNext = pHead->m_pNext;
        pHead->m_pNext = pNew;
    }
    return pHead->m_pNext;
}

void PrintListNode(ListNode *pNode)
{
    if (pNode == nullptr){
        cout << "This node is nullptr" << endl;
    }
    else{
        cout << "This node is " << pNode->m_value << endl;
    }
}

void PrintList(ListNode *pHead)
{
    cout << "Print List Start" << endl;
    ListNode *pNode = pHead;
    while (pNode != nullptr){
        cout << pNode->m_value << "\t";
        pNode = pNode->m_pNext;
    }
    cout << "\nPrint List End" << endl;
}

void DestroyList(ListNode *pHead)
{
    ListNode *pNode = pHead;
    while (pNode != nullptr){
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode **pHead, int value)
{
    ListNode *pNew = new ListNode(value);
    if (*pHead = nullptr){
        *pHead = pNew;
    }
    else{
        ListNode *pNode = *pHead;
        while (pNode->m_pNext != nullptr){
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }

}

void RemoveNode(ListNode **pHead, int value)
{
    //必须考虑删除的是否为头文件
    if (pHead == nullptr || *pHead == nullptr)
        return;
    ListNode *pNodeToDeleted = nullptr;
    if ((*pHead)->m_value == value){
        pNodeToDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else{
        ListNode *pNode = *pHead;
        while (pNode->m_pNext != nullptr && pNode->m_pNext->m_value != value)
                pNode = pNode->m_pNext;
        while (pNode->m_pNext != nullptr && pNode->m_pNext->m_value == value){
            pNodeToDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }

    if (pNodeToDeleted != nullptr){
        delete pNodeToDeleted;
        pNodeToDeleted = nullptr;
    }
}

