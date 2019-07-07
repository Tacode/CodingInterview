/*
 * 输入一棵二叉树和一个整数， 打印出二叉树中节点值的和为输入整数的所有路径(根节点到叶子节点的路径)
*/
#include <iostream>
#include <vector>
#include "../utils/BinaryTree.h"

using namespace std;
// 利用前向遍历，记录当前路径和，递归返回上一个节点时要弹出当前路径节点，整个思想像深度优先搜索+回溯法
void SearchPath(BinaryTreeNode *pRoot, vector<int> &path, int expectedSum, int currentSum){
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);
    bool isLeafNode = pRoot->m_pRight == nullptr && pRoot->m_pLeft == nullptr; // 判断是不是叶子节点
    if (isLeafNode && currentSum == expectedSum){ //如果是叶子节点同时达到类期望的和
        //打印
        cout << "Path found" << endl;
        for (auto &v:path){
            cout << v << " ";
        }
        cout << endl;
    }
    if (pRoot->m_pLeft != nullptr){
        SearchPath(pRoot->m_pLeft, path, expectedSum, currentSum);
    }
    if (pRoot->m_pRight != nullptr){
        SearchPath(pRoot->m_pRight, path, expectedSum, currentSum);
    }
    path.pop_back();
}

void FindPath(BinaryTreeNode *pRoot, int expectedSum){
    if (pRoot == nullptr)
        return;
    int currentSum = 0;
    vector<int> path;
    SearchPath(pRoot, path, expectedSum, currentSum);
}

int main(int argc, char *argv[])
{
    vector<int> value = {10, 5, 12, 4, 7, '#', '#'};
    BinaryTreeNode *pRoot = CreateBinaryTree(value);
    FindPath(pRoot, 22);
    return 0;
}
