/*
 * 判断一个序列是否为二叉搜索树的后序遍历序列
*/
#include <iostream>
#include <vector>
using namespace std;

// 例如序列[5 7 6 9 11 10 8] 后序遍历根节点为8,寻找左子树，都比根节点8小，寻找右子树，都比8大，否则不是后序遍历序列
// 得到左子树，右子树继续上述判断操作，直到左右序列只有一个值了
bool VerifyPostSequence(vector<int> &sequence){
    int length = sequence.size();
    if (sequence.empty())
        return false;
    if (sequence.size() == 1)
        return true;
    int root = sequence[length-1];
    vector<int> left_vec;
    vector<int> right_vec;
    int i, j;
    for (i=0; i<length-1; ++i){
        if (sequence[i] > root)
            break;
        left_vec.push_back(sequence[i]);
    }

    j = i;
    for (; j<length-1; ++j){
        if (sequence[j] < root)
            return false;
        right_vec.push_back(sequence[j]);
    }

    bool left = true;
    if (!left_vec.empty())
        left= VerifyPostSequence(left_vec);
    bool right = true;
    if (!right_vec.empty())
        right = VerifyPostSequence(right_vec);

    return (left && right);
}

int main(int argc, char *argv[])
{
    vector<int> f_vec1 = {5, 7, 6, 9, 11, 10, 8};
    cout << VerifyPostSequence(f_vec1) << endl;
    vector<int> f_vec2 = {7, 4, 6, 5};
    cout << VerifyPostSequence(f_vec2) << endl;
    return 0;
}
