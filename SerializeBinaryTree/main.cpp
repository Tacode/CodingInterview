#include <iostream>
#include <fstream>
#include "../utils/BinaryTree.h"

using namespace std;
bool ReadStream(istream &stream, int *num){
    if (stream.eof())
        return false;
    char buffer[30];
    char ch;
    stream >> ch;
    int i = 0;
    while (!stream.eof() && ch != ','){
        buffer[i++] = ch;
        stream >> ch;
    }

    bool isNum = false;
    if (i>0  && buffer[0] != '$'){
        *num = atoi(buffer);
        isNum = true;
    }
    return isNum;
}

void SerializeTree(BinaryTreeNode *pRoot, ostream &stream){
    if (pRoot == nullptr){
        stream << "$,";
        return;
    }

    stream << pRoot->m_nValue << ',';
    SerializeTree(pRoot->m_pLeft, stream);
    SerializeTree(pRoot->m_pRight, stream);
}

void DeSerializeTree(BinaryTreeNode **pRoot, istream &stream){
    int num;

    if (ReadStream(stream, &num)){
        *pRoot = CreateBinaryTree(num);
        DeSerializeTree(&(*pRoot)->m_pLeft, stream);
        DeSerializeTree(&(*pRoot)->m_pRight, stream);
    }

}

void Test(BinaryTreeNode *pRoot){
    const char *fileName = "../test.txt";
    ofstream fout;
    fout.open(fileName, ios::out | ios::trunc);
    SerializeTree(pRoot, fout);
    fout.close();

    // 从序列化文件中读取，重建二叉树
    ifstream fin;
    fin.open(fileName, ios::in);
    BinaryTreeNode *pNewRoot = nullptr;
    DeSerializeTree(&pNewRoot, fin);

//    int num = 0;
//    ReadStream(fin,&num);
    PrintTree(pNewRoot);
    fin.close();

}

int main(int argc, char *argv[])
{
    vector<int> vec = {1, 2, 3, 4, '#', 5, 6}; //其实这里就相当于序列化了，利用层次遍历的序列化
    BinaryTreeNode *pRoot = CreateBinaryTree(vec);
    cout << "----------------Original Tree-----------------" << endl;
    PrintTree(pRoot);
    cout << "----------------Rebuild Tree-----------------" << endl;
    Test(pRoot);
    return 0;
}
