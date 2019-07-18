/*
 * 求二叉树最大深度
*/
#include <iostream>
#include "../utils/BinaryTree.h"

using namespace std;

////////////////////////////////////自底向上//////////////////////////
int TreeDepth(BinaryTreeNode *pRoot){
    if (pRoot == nullptr)
        return 0;
    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);

    return max(left, right)+1;
}
//////////////////////////////////////////////////////////////////////

///////////////////////////////////自顶向下/////////////////////////////
int depth = 0;
void TreeDepth2(BinaryTreeNode *pRoot, int d){
    if (pRoot == nullptr)
        return ;
    if (pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr) // 叶子节点
        depth = max(depth, d);
    TreeDepth2(pRoot->m_pLeft, d+1);
    TreeDepth2(pRoot->m_pRight, d+1);
}
int TreeDepth2(BinaryTreeNode *pRoot){
    TreeDepth2(pRoot, 1);
    return depth;
}
/////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    vector<int> vec = {1,2,3,4,5,'#',6,'#','#',7};
    BinaryTreeNode *pRoot = CreateBinaryTree(vec);
    cout << "Tree Depth: " << TreeDepth(pRoot) << endl;
    cout << "Tree Depth: " << TreeDepth2(pRoot) << endl;
    return 0;
}
