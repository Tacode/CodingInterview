/*二叉树构建h*/
#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include <vector>
using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

BinaryTreeNode *CreateBinaryTree(int value);
BinaryTreeNode *CreateBinaryTree(vector<int> &nums, int i=0);
void ConnectBinaryTree(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight);
void PrintTreeNode(const BinaryTreeNode *pNode);
void PrintTree(const BinaryTreeNode *pRoot);
void DestroyTree(BinaryTreeNode *pRoot);


#endif

BinaryTreeNode *CreateBinaryTree(int value)
{
    BinaryTreeNode *pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    return pNode;
}

// 层次遍历序列重建二叉树
BinaryTreeNode *CreateBinaryTree(vector<int> &nums, int i)
{
    BinaryTreeNode *root = new BinaryTreeNode();
    if (nums[i] == '#' || i >= nums.size()){
        return nullptr;
    }
    root->m_nValue = int(nums[i]);
    root->m_pLeft = CreateBinaryTree(nums, 2*i+1);
    root->m_pRight = CreateBinaryTree(nums, 2*i+2);
    return root;
}


void ConnectBinaryTree(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight)
{
    if (pParent != nullptr){
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void PrintTreeNode(const BinaryTreeNode *pNode)
{
    if (pNode != nullptr){
        printf("value of this node is: %d\n", pNode->m_nValue);
        if (pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is null\n");

        if (pNode->m_pRight != nullptr)
            printf("value of its right child is: %d\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is null\n");
    }
    else
    {
        printf("this nodes is null\n");
    }
    printf("\n");
}

void PrintTree(const BinaryTreeNode *pRoot)
{
    PrintTreeNode(pRoot);
    if (pRoot != nullptr){
        if (pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);
        if (pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode *pRoot)
{
    if (pRoot != nullptr){
        BinaryTreeNode *pLeft = pRoot->m_pLeft;
        BinaryTreeNode *pRight = pRoot->m_pRight;
        delete pRoot;
        pRoot = nullptr;
        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}
