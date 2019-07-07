/*
 * 判断一个二叉树是否包含另一个二叉树
*/
#include <iostream>
#include <vector>
#include "../utils/BinaryTree.cc"

using namespace std;

bool DoesTree1HasTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2){
    if (pRoot2 == nullptr)
        return true;
    if (pRoot1 == nullptr)
        return false;

    if (pRoot1->m_nValue != pRoot2->m_nValue)
        return false;

    return DoesTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft)
           && DoesTree1HasTree2(pRoot1->m_pRight,pRoot2->m_pRight);
}

bool HasSubStruct(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2){
    bool result = false;
    if (pRoot1 != nullptr && pRoot2 != nullptr){
        if (pRoot1->m_nValue == pRoot2->m_nValue) // 前序遍历
            result = DoesTree1HasTree2(pRoot1, pRoot2);
        if (!result)
            result = HasSubStruct(pRoot1->m_pLeft, pRoot2);
        if (!result)
            result = HasSubStruct(pRoot1->m_pRight, pRoot2);
    }
    return result;
}

int main(int argc, char *argv[])
{
    vector<int> value1 = {8,8,7,9,2,'#','#','#','#',4,7};
    vector<int> value2 = {8,9,2};
    BinaryTreeNode *tree1 = CreateBinaryTree(value1);
    BinaryTreeNode *tree2 = CreateBinaryTree(value2);

    cout << HasSubStruct(tree1, tree2) << endl;
    return 0;
}
