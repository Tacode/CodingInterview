#ifndef COMPLEXLIST_HPP
#define COMPLEXLIST_HPP
#include <iostream>
#include <vector>
using namespace std;

//////////////////////////////链表结构体////////////////////////////////////
template <typename T>
struct ComplexListNode{
    T m_nValue;
    ComplexListNode *m_pNext = nullptr;
    ComplexListNode *m_pSibling = nullptr;
    ComplexListNode(T value):m_nValue(value){}
};

//////////////////////////////函数声明///////////////////////////////////////
template <typename T> ComplexListNode<T> *CreateNode(T value);
template <typename T> void ConnectNodes(ComplexListNode<T> *pNode, ComplexListNode<T> *pNext, ComplexListNode<T> *pSibling);
template <typename T> void PrintList(ComplexListNode<T> *pHead);
//建立四种典型的复杂链表
template <typename T> ComplexListNode<T> *BuildList1();
template <typename T> ComplexListNode<T> *BuildList2();
template <typename T> ComplexListNode<T> *BuildList3();
template <typename T> ComplexListNode<T> *BuildList4();
/////////////////////////////函数定义////////////////////////////////////////
template <typename T>
ComplexListNode<T> *CreateNode(T value){
    ComplexListNode<T> *pNode = new ComplexListNode<T>(value);
    return pNode;
}

template <typename T>
void ConnectNodes(ComplexListNode<T> *pNode, ComplexListNode<T> *pNext, ComplexListNode<T> *pSibling){
    if (pNode != nullptr){
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}

template <typename T>
void PrintList(ComplexListNode<T> *pHead){
    ComplexListNode<T> *pNode = pHead;
    while (pNode != nullptr){
        cout << pNode->m_nValue;
        if (pNode->m_pSibling != nullptr)
            cout << "(" << pNode->m_pSibling->m_nValue << ")";
        cout << " ";
        pNode = pNode->m_pNext;
    }
    cout << endl;
}

template <typename T>
ComplexListNode<T>* BuildList1(){
    ComplexListNode<T> *pNode1 = CreateNode<T>(1);
    ComplexListNode<T> *pNode2 = CreateNode<T>(2);
    ComplexListNode<T> *pNode3 = CreateNode<T>(3);
    ComplexListNode<T> *pNode4 = CreateNode<T>(4);
    ComplexListNode<T> *pNode5 = CreateNode<T>(5);

    ConnectNodes<T>(pNode1, pNode2, pNode3);
    ConnectNodes<T>(pNode2, pNode3, pNode5);
    ConnectNodes<T>(pNode3, pNode4, nullptr);
    ConnectNodes<T>(pNode4, pNode5, pNode2);

    return pNode1;
}

template <typename T>
ComplexListNode<T>* BuildList2(){
    ComplexListNode<T> *pNode1 = CreateNode<T>(1);
    ComplexListNode<T> *pNode2 = CreateNode<T>(2);
    ComplexListNode<T> *pNode3 = CreateNode<T>(3);
    ComplexListNode<T> *pNode4 = CreateNode<T>(4);
    ComplexListNode<T> *pNode5 = CreateNode<T>(5);

    ConnectNodes<T>(pNode1, pNode2, nullptr);
    ConnectNodes<T>(pNode2, pNode3, pNode5);
    ConnectNodes<T>(pNode3, pNode4, pNode3);
    ConnectNodes<T>(pNode4, pNode5, pNode2);

    return pNode1;
}

template <typename T>
ComplexListNode<T>* BuildList3(){
    ComplexListNode<T> *pNode1 = CreateNode<T>(1);
    ComplexListNode<T> *pNode2 = CreateNode<T>(2);
    ComplexListNode<T> *pNode3 = CreateNode<T>(3);
    ComplexListNode<T> *pNode4 = CreateNode<T>(4);
    ComplexListNode<T> *pNode5 = CreateNode<T>(5);

    ConnectNodes<T>(pNode1, pNode2, nullptr);
    ConnectNodes<T>(pNode2, pNode3, pNode4);
    ConnectNodes<T>(pNode3, pNode4, nullptr);
    ConnectNodes<T>(pNode4, pNode5, pNode2);

    return pNode1;
}

template <typename T>
ComplexListNode<T>* BuildList4(){
    return nullptr;
}


#endif // COMPLEXLIST_HPP
