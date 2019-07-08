/*
 * 将一棵二叉搜索树转换为有序双向链表，不准新建节点
*/
#include <iostream>
#include "../utils/BinarySearchTree.h"

using namespace std;
template <typename T>
void ConvertHelper(BSTNode<T> *pCurNode, BSTNode<T> **preNode){
    if (pCurNode == nullptr)
        return ;
    ConvertHelper<T>(pCurNode->m_pLeft, preNode);
    pCurNode->m_pLeft = *preNode; //左指针指向前驱
    if (*preNode){
        (*preNode)->m_pRight = pCurNode; // 右指针指向后驱
    }
    *preNode = pCurNode;

    ConvertHelper(pCurNode->m_pRight, preNode);
}


template <typename T>
BSTNode<T> *Convert(BSTNode<T> *pRoot){
    if (pRoot == nullptr){
        return nullptr;
    }
    BSTNode<T> *preNode = nullptr;
    ConvertHelper(pRoot, &preNode);
    BSTNode<T> *pNode = pRoot; // 根节点 此时往前驱遍历(左指针)就能到双向链表的头节点
    while (pNode->m_pLeft != nullptr){
        pNode = pNode->m_pLeft;
    }

    return pNode;
}

template <typename T>
void PrintDoubleList(BSTNode<T> * pRoot){
    BSTNode<T> *pNode = pRoot;
    while (pNode != nullptr){
        cout << pNode->m_nValue << " ";
        if (pNode->m_pRight == nullptr)
            break;
        pNode = pNode->m_pRight;
    }
    cout << endl;

    while(pNode != nullptr){
        cout << pNode->m_nValue << " ";
        if (pNode->m_pLeft == nullptr)
            break;
        pNode = pNode->m_pLeft;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<int> vec1 = {5,4,3,2,1};
//    vector<int> vec2 = {10, 6 ,14, 4, 8, 12,16};
    BSTNode<int> *pRoot = CreateBinarySearchTree<int>(vec1);
    PrintTree(pRoot);
    BSTNode<int> *pRes = Convert<int>(pRoot);
    PrintDoubleList(pRes);
    DeleteTree(pRoot);
    return 0;
}
