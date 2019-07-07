/*
 * 获取镜像二叉树
*/
#include <iostream>
#include <vector>
#include "../utils/BinaryTree.cc"
using namespace std;

void MirrorsBinaryTree(BinaryTreeNode *pRoot){
    if (pRoot == nullptr)
        return;
    if (pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr)
        return;
     BinaryTreeNode *pTemp = pRoot->m_pLeft;
     pRoot->m_pLeft = pRoot->m_pRight;
     pRoot->m_pRight = pTemp;

     if (pRoot->m_pLeft)
         MirrorsBinaryTree(pRoot->m_pLeft);
     if (pRoot->m_pRight)
         MirrorsBinaryTree(pRoot->m_pRight);
}

int main(int argc, char *argv[])
{
    vector<int> value = {8,6,10,5,7,9,11};
    BinaryTreeNode *pRoot = CreateBinaryTree(value);
    cout << "Original Tree:" << endl;
    PrintTree(pRoot);

    MirrorsBinaryTree(pRoot);
    cout << "Mirrors Tree:" << endl;
    PrintTree(pRoot);
    return 0;
}
