/*
 * 判断是否为对称二叉数
*/
#include <iostream>
#include <vector>
#include "../utils/BinaryTree.cc"
using namespace std;

bool isSymemetric(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2){
    if (pRoot1 == nullptr && pRoot2 == nullptr)
        return true;
    if (pRoot1 == nullptr && pRoot2 != nullptr)
        return false;
    if (pRoot1 != nullptr && pRoot2 == nullptr)
        return false;

    if (pRoot1->m_nValue == pRoot2->m_nValue)
        return isSymemetric(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymemetric(pRoot1->m_pRight, pRoot2->m_pLeft);
    else
        return false;


}

bool SymemetricBinaryTree(BinaryTreeNode *pRoot){
    if (pRoot == nullptr)
        return true;
    return isSymemetric(pRoot->m_pLeft, pRoot->m_pRight);
}

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> value = {8,6,6,5,7,7,5};
    BinaryTreeNode *pRoot = CreateBinaryTree(value);
    cout << "Original Tree:" << endl;
    PrintTree(pRoot);
    cout << SymemetricBinaryTree(pRoot) << endl;
    return 0;
}
