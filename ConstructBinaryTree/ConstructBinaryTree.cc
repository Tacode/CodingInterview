/**********************************
 面试题7：重建二叉树
 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
 入的前序遍历和中序遍历的结果中都不含重复的数字。
 附加: 输入层次遍历序列重建二叉树
***********************************/
#include <iostream>
#include <vector>
#include <string>
#include "../utils/BinaryTree.h"
#include "../utils/BinaryTree.cc"
using namespace std;

BinaryTreeNode *BuildTree(vector<int> &inorder, vector<int> &preoder)
{
    if (preoder.size() == 0){
        return nullptr;
    }
    vector<int> in_left;
    vector<int> in_right;
    vector<int> pre_left;
    vector<int> pre_right;
    int i, j;
    int middle = preoder[0];

    for (i = 0; i < inorder.size(); ++i){
        if (inorder[i] != middle)
            in_left.push_back(inorder[i]);
        else
            break;
    }
    i += 1;
    for (; i < inorder.size(); ++i)
        in_right.push_back(inorder[i]);

    for (j = 1; j < in_left.size()+1; ++j)
        pre_left.push_back(preoder[j]);    
    for (; j < preoder.size(); ++j)
        pre_right.push_back(preoder[j]);
    
    BinaryTreeNode *T = new BinaryTreeNode();
    T->m_nValue = middle;
    T->m_pLeft = BuildTree(in_left, pre_left);
    T->m_pRight = BuildTree(in_right, pre_right);
    return T;
}

void Test(string &testName, vector<int> &preorder, vector<int> &inorder)
{
    // if(!testName.empty())
    //     cout << testName << endl;
    printf("The preorder sequence is: ");
    for(int i = 0; i < preorder.size(); ++i)
        cout << preorder[i] << " ";
    cout << endl;

    printf("The inorder sequence is: ");
    for(int i = 0; i < inorder.size(); ++i)
        cout << inorder[i] << " ";
    cout << endl;

    try
    {
        BinaryTreeNode* root = BuildTree(inorder, preorder);
        cout << "build ok" << endl;
        PrintTree(root);
        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        cout << "Invalid Input" << endl;
    }
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    vector<int> preorder{1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> inorder{4, 7, 2, 1, 5, 3, 8, 6};
    string test_name = "Test1";
    Test(test_name, preorder, inorder);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    vector<int> preorder{1, 2, 3, 4, 5};
    vector<int> inorder{5, 4, 3, 2, 1};
    string test_name = "Test2";
    Test(test_name, preorder, inorder);
}


// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    vector<int> preorder{1, 2, 3, 4, 5};
    vector<int> inorder{1, 2, 3, 4, 5};
    string test_name = "Test3";
    Test(test_name, preorder, inorder);
}

// 树中只有一个结点
void Test4()
{
    vector<int> preorder{1};
    vector<int> inorder{1};
    string test_name = "Test4";
    Test(test_name, preorder, inorder);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    vector<int> preorder{1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder{4, 2, 5, 1, 6, 3, 7};
    string test_name = "Test5";
    Test(test_name, preorder, inorder);
}

// 输入的两个序列不匹配
void Test7()
{
    vector<int> preorder{1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder{4, 2, 8, 1, 6, 3, 7};
    string test_name = "Test7: for unmatched input";
    Test(test_name, preorder, inorder);
}

//层次遍历序列重建二叉树
void Test8()
{
//    vector<char> sequence{'1','2','3','4','#','5','6'};
    vector<int> sequence{1, 2, 3, 4, '#', 5, 6};
    cout << "Test8" << endl;
    BinaryTreeNode *tree;
    tree = CreateBinaryTree(sequence);
    PrintTree(tree);
    DestroyTree(tree);
}


int main(int argc, char *argv[])
{
    Test8();
    return 0;
}
