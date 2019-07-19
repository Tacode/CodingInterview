/*
 * 判断是否为平衡二叉树（任意节点左右子树的深度相差不超过1）
*/
#include <iostream>
#include <vector>
#include "../utils/BinaryTree.h"
using namespace std;

///////////////////////////////利用求解树深度程序来判断是否是平衡的 重复高/////////////////
//得到节点深度
int TreeDepth(BinaryTreeNode *pRoot){
    if (pRoot == nullptr)
        return 0;
    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);
    return max(left, right)+1;
}

bool IsBalance(BinaryTreeNode *pRoot){
    if (pRoot==nullptr)
        return true;
    int left = TreeDepth(pRoot->m_pLeft); //左子树深度
    int right = TreeDepth(pRoot->m_pRight);
    int distance = left-right;
    if (distance >1 || distance < -1)
        return false;
    return IsBalance(pRoot->m_pLeft) && IsBalance(pRoot->m_pRight);
}

///////////////////////////利用后序遍历来判断，遍历一个节点已经遍历了他的左右子树//////////////////
bool IsBalance(BinaryTreeNode *pRoot, int *pDepth){
    if (pRoot==nullptr){
        *pDepth = 0;
        return true;
    }
    int left, right;
    if (IsBalance(pRoot->m_pLeft, &left) && IsBalance(pRoot->m_pRight, &right)){
        int distance = left - right;
        if (distance <= 1 && distance >= -1){
            *pDepth = max(left, right)+1;
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    cout << "-------------------first method-------------------" << endl;
    vector<int> vec={1, 2, 3, 4, 5, '#', 6, '#', '#', 7};
    BinaryTreeNode *pRoot = CreateBinaryTree(vec);
    cout << IsBalance(pRoot) << endl;

    vector<int> vec2={1,2,3,4,'#','#','#','#',6};
    BinaryTreeNode *pRoot2 = CreateBinaryTree(vec2);
    cout << IsBalance(pRoot2) << endl;

    cout << "-------------------second method-------------------" << endl;
    int depth = 0;
    cout << IsBalance(pRoot, &depth) << endl;
    depth = 0;
    cout << IsBalance(pRoot2, &depth) << endl;
    return 0;
}
