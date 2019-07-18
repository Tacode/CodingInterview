/*
 * 求二叉搜索树的第k个节点， 中序遍历
*/
#include <iostream>
#include <vector>
#include "../utils/BinarySearchTree.h"
using namespace std;

BSTNode<int> *Inorder(BSTNode<int> *pRoot, int &k){
    BSTNode<int> *pTarget = nullptr;

    if (pRoot->m_pLeft != nullptr)
        pTarget = Inorder(pRoot->m_pLeft, k);

    if (pTarget == nullptr){
        if (k == 1)
            pTarget = pRoot;
        k--;
    }

    if (pTarget == nullptr && pRoot->m_pRight != nullptr)
        pTarget = Inorder(pRoot->m_pRight, k);
    return pTarget;
}

BSTNode<int> *GetKthNode(BSTNode<int> *pRoot, int k){
    if (pRoot == nullptr || k<=0)
        return nullptr;
    return Inorder(pRoot,k);

}

int main(int argc, char *argv[])
{
    vector<int> vec = {5,3,7,2,4,6,8};
    BSTNode<int> *pRoot = CreateBinarySearchTree<int>(vec);
    BSTNode<int> *pNode = GetKthNode(pRoot,4);
    PrintTreeNode(pNode);
    return 0;
}
