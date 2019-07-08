#include <iostream>
#include "ComplexList.hpp"

using namespace std;

template <typename T>
void CopyNode(ComplexListNode<T> *pHead){
    ComplexListNode<T> *pNode = pHead;
    while (pNode != nullptr){
        ComplexListNode<T> *pCloneNode = new ComplexListNode<T>(pNode->m_nValue);
        pCloneNode->m_pNext = pNode->m_pNext;
        pNode->m_pNext = pCloneNode;
        pNode = pCloneNode->m_pNext;
    }
}

template <typename T>
void CopySiblingNode(ComplexListNode<T> *pHead){
    ComplexListNode<T> *pNode = pHead;

    while (pNode != nullptr){
        ComplexListNode<T> *pCloneNode = pNode->m_pNext;
        if (pNode->m_pSibling != nullptr)
            pCloneNode->m_pSibling = pNode->m_pSibling->m_pNext;
        pNode = pCloneNode->m_pNext;
    }
}


template <typename T>
ComplexListNode<T> *ObtainClonedHeadNode(ComplexListNode<T> *pHead){
    if (pHead == nullptr)
        return nullptr;
    ComplexListNode<T> *pCloneHead = pHead->m_pNext;
    ComplexListNode<T> *pNode = pHead;
    ComplexListNode<T> *pCloneNode = pCloneHead;

    while (pNode != nullptr){
        pNode = pCloneNode->m_pNext;
        if (pNode == nullptr)
            break;
        pCloneNode->m_pNext = pNode->m_pNext;
        pCloneNode = pCloneNode->m_pNext;
    }

    return pCloneHead;
}

template <typename T>
ComplexListNode<T> *CloneList(ComplexListNode<T> *pHead){
    PrintList(pHead); //打印原始链表

    CopyNode(pHead);
    PrintList(pHead); //完成第一阶段克隆

    CopySiblingNode(pHead);
    PrintList(pHead); //完成第二阶段克隆

    ComplexListNode<T> *pCloneHead = ObtainClonedHeadNode<T>(pHead); //第三阶段:拆分出克隆链表
    return pCloneHead;

}

int main(int argc, char *argv[])
{
    ComplexListNode<int> *pHead = BuildList4<int>();
    ComplexListNode<int> *pCloneHead = CloneList(pHead);
    PrintList(pCloneHead);
    return 0;
}
