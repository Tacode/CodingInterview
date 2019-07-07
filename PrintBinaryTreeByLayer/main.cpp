/*
 * 各种分层打印二叉树:
 * 1. 按照从上到下，从左到右顺序打印（输出一个序列）
 * 2. 从上到下，从左到右打印每层的元素(输出多个序列)
 * 3. 从上到下，之字型打印
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../utils/BinaryTree.h"
#include "../utils/MyQueue.h"
#include "../utils/MyStack.h"

using namespace std;

// 层次遍历打印二叉数
void PrintByLayer(BinaryTreeNode *pRoot){
    MyQueue<BinaryTreeNode *> *myqueue = new MyQueue<BinaryTreeNode *>(100);
    myqueue->push(pRoot);
    while(!myqueue->empty()){
        BinaryTreeNode *p = myqueue->front();
        myqueue->pop();
        cout << p->m_nValue << " ";
        if (p->m_pLeft != nullptr)
            myqueue->push(p->m_pLeft);
        if (p->m_pRight != nullptr)
            myqueue->push(p->m_pRight);
    }
    cout << endl;
}

//打印每层的节点值
void PrintEveryLayer(BinaryTreeNode *pRoot){
    MyQueue<BinaryTreeNode *> *myqueue = new MyQueue<BinaryTreeNode *>(100);
    myqueue->push(pRoot);
    int nextlevel = 0;
    int print_counts =  1;
    while(!myqueue->empty()){
        BinaryTreeNode *p = myqueue->front();
        myqueue->pop();
        cout << p->m_nValue << " ";
        if (p->m_pLeft != nullptr){
            myqueue->push(p->m_pLeft);
            nextlevel++;
        }
        if (p->m_pRight != nullptr){
            myqueue->push(p->m_pRight);
            nextlevel++;
        }
        --print_counts;
        if (print_counts==0){
            cout << endl;
            print_counts = nextlevel;
            nextlevel = 0;
        }

    }
    cout << endl;
}

//之字型打印,利用了二维vector
void PrintByZigZag(BinaryTreeNode *pRoot){
    vector<vector<int>> results;
    vector<int> vec;
    MyQueue<BinaryTreeNode*> *myqueue = new MyQueue<BinaryTreeNode*>(100);
    myqueue->push(pRoot);
    int nextlevel = 0;
    int curlevel = 1;
    int numLayer = 1;
    while(!myqueue->empty()){
        BinaryTreeNode *p = myqueue->front();
        vec.push_back(p->m_nValue);
        myqueue->pop();
        if (p->m_pLeft != nullptr){
            myqueue->push(p->m_pLeft);
            nextlevel++;
        }
        if (p->m_pRight != nullptr){
            myqueue->push(p->m_pRight);
            nextlevel++;
        }
        curlevel--;
        if (curlevel == 0){
            if (numLayer % 2 == 0)
                reverse(vec.begin(),vec.end());
            results.push_back(vec);
            curlevel = nextlevel;
            nextlevel = 0;
            numLayer++;
            vec.clear();
        }
    }

    for (auto &v_vec:results){
        for (auto &v:v_vec){
            cout << v << " ";
        }
        cout << endl;
    }
}

//之字型打印,利用了二个栈
void PrintZigZagByStack(BinaryTreeNode *pRoot){
    MyStack<BinaryTreeNode*> mystack[2](100);
    int current = 0;
    int next = 1;
    mystack[current].push(pRoot);
    while (!mystack[current].empty() || !mystack[next].empty()){
        BinaryTreeNode *p = mystack[current].top();
        mystack[current].pop();
        cout << p->m_nValue << " ";
        if (current == 0){
            if (p->m_pLeft != nullptr){
                mystack[next].push(p->m_pLeft);
            }
            if (p->m_pRight != nullptr){
                mystack[next].push(p->m_pRight);
            }
        }
        else{
            if (p->m_pRight != nullptr){
                mystack[next].push(p->m_pRight);
            }
            if (p->m_pLeft != nullptr){
                mystack[next].push(p->m_pLeft);
            }
        }

        if (mystack[current].empty()){
            cout << endl;
            current = 1-current;
            next = 1-next;
        }

    }

}

int main(int argc, char *argv[])
{
    vector<int> value = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    BinaryTreeNode *pRoot = CreateBinaryTree(value);
    PrintByLayer(pRoot);
    cout << endl;
    PrintEveryLayer(pRoot);
    cout << endl;
    PrintByZigZag(pRoot);
    cout << endl;
    PrintZigZagByStack(pRoot);
    return 0;
}
