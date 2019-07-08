#pragma once
#include <iostream>
#include <vector>
using namespace std;
///////////////////////定义二叉搜索树/////////////////////////////
template <typename T>
class BSTNode{
public:
    BSTNode(const T value):m_nValue(value),m_pLeft(nullptr), m_pRight(nullptr){}
public:
    T m_nValue;
    BSTNode<T> *m_pLeft;
    BSTNode<T> *m_pRight;
};

/////////////////////函数声明////////////////////////////////
template<typename T> bool Insert(BSTNode<T>* &pRoot, const T key);
template<typename T> BSTNode<T> *CreateBinarySearchTree(vector<T> &vec);
template<typename T> void PrintTreeNode(const BSTNode<T> *pNode);
template<typename T> void PrintTree(const BSTNode<T> *pRoot);
template<typename T> void InOrderTraverse(const BSTNode<T> *pRoot);
template<typename T> void PreOrderTraverse(const BSTNode<T> *pRoot);
template<typename T> void PostOrderTraverse(const BSTNode<T> *pRoot);
template<typename T> bool Search(const BSTNode<T> *pRoot, const T key);
template<typename T> bool DeleteNode(BSTNode<T> *pRoot, const T key); //待实现
template<typename T> bool DeleteTree(BSTNode<T> *pRoot, const T key);


/////////////////////////////函数定义/////////////////////////
template<typename T>
bool Insert(BSTNode<T>* &pRoot, const T key){
    BSTNode<T> *pNode = new BSTNode<T>(key);
    if (!pNode){
        cout << "Node creating Fail" << endl;
        return false;
    }
    if (pRoot == nullptr){
        pRoot = pNode;
        return true;
    }
    if (key == pRoot->m_nValue){
        cout << "The equal value, insert fail" << endl;
        return false;
    }
    else if (key < pRoot->m_nValue){
        return Insert<T>(pRoot->m_pLeft, key);
    }
    else{
        return Insert<T>(pRoot->m_pRight, key);
    }
}

// 创建二叉搜索树
template<typename T>
BSTNode<T> *CreateBinarySearchTree(vector<T> &vec){
    if (vec.empty())
        return nullptr;
    BSTNode<T> *pRoot = new BSTNode<T>(vec[0]);
    for (size_t i=1; i<vec.size(); ++i){
        if(!Insert<T>(pRoot, vec[i])){
            cout << "Create Fail" << endl;
            exit(0);
        }
    }
    return pRoot;
}

// 打印单个节点
template<typename T>
void PrintTreeNode(const BSTNode<T> *pNode)
{
    if (pNode != nullptr){
        cout << "value of this node is: " << pNode->m_nValue << endl;
        if (pNode->m_pLeft != nullptr)
            cout <<"value of its left child is: " << pNode->m_pLeft->m_nValue << endl;
        else
            cout << "left child is null" << endl;

        if (pNode->m_pRight != nullptr)
            cout << "value of its right child is: " << pNode->m_pRight->m_nValue << endl;
        else
            cout << "right child is null\n" << endl;
    }
    else
    {
        cout << "this nodes is null" << endl;
    }
    cout << endl;
}

//打印整个树
template<typename T>
void PrintTree(const BSTNode<T> *pRoot)
{
    PrintTreeNode<T>(pRoot);
    if (pRoot != nullptr){
        if (pRoot->m_pLeft != nullptr)
            PrintTree<T>(pRoot->m_pLeft);
        if (pRoot->m_pRight != nullptr)
            PrintTree<T>(pRoot->m_pRight);
    }
}

// 中序遍历
template<typename T> void InOrderTraverse(const BSTNode<T> *pRoot){
    if (pRoot == nullptr)
        return;
    InOrderTraverse<T>(pRoot->m_pLeft);
    cout << pRoot->m_nValue << " ";
    InOrderTraverse<T>(pRoot->m_pRight);
}

// 前序遍历
template<typename T> void PreOrderTraverse(const BSTNode<T> *pRoot){
    if (pRoot == nullptr)
        return;
    cout << pRoot->m_nValue << " ";
    PreOrderTraverse<T>(pRoot->m_pLeft);
    PreOrderTraverse<T>(pRoot->m_pRight);
}

// 后序遍历
template<typename T> void PostOrderTraverse(const BSTNode<T> *pRoot){
    if (pRoot == nullptr)
        return;
    PostOrderTraverse<T>(pRoot->m_pLeft);
    PostOrderTraverse<T>(pRoot->m_pRight);
    cout << pRoot->m_nValue << " ";
}

template<typename T> bool Search(const BSTNode<T> *pRoot, const T key){
    if (pRoot == nullptr)
        return false;
    if (pRoot->m_nValue == key)
        return true;
    else if (pRoot->m_nValue > key)
        return Search(pRoot->m_pLeft, key);
    else
        return Search(pRoot->m_pRight, key);
}

template<typename T> bool DeleteTree(BSTNode<T> *pRoot){
    if (pRoot != nullptr){
        BSTNode<T> *pLeft= pRoot->m_pLeft;
        BSTNode<T> *pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;
        DeleteTree<T>(pLeft);
        DeleteTree<T>(pRight);
    }
}
