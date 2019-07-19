#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

////////////////////////////////////////////////////////////////
//1.一个数组中只有一个数出现一次，其他出现两次，要求空间复杂度为O(1)
int NumberAppearOnce1(vector<int> &num){
    if (num.empty())
        return -1;
    int n = 0;
    for (auto &v:num){
        n ^= v;
    }
    return n;
}

///////////////////////////////////////////////////////////////
//2.一个数组只有两个数出现一次，其他出现两次，要求空间复杂度为O(1)
// 所有数字相异或得到一个结果，利用这个结果的二进制数得到其从右往左第一次出现1的索引，然后判断所有数在该索引位下是否为1
// 为1的分一组，为0的分一组，分别异或，就能得到只出现一次的两个数
int FindFirstBit(int n){
    int index = 0;
    while((n&1) == 0 && index < 8*sizeof(int)){
        n = n>>1;
        index++;
    }
    return index;
}

bool IsBitof1(int n, int index){
    n = n >> index;
    return (n&1);
}

pair<int,int> NumberAppearOnce2(vector<int> &num){
    if (num.empty())
        return make_pair(-1,-1);
    int n = 0;
    for (auto &v:num){
        n ^= v;
    }
    int index = FindFirstBit(n);
    int n1 = 0;
    int n2 = 0;
    for (auto &v:num){
        if (IsBitof1(v, index))
            n1 ^= v;
        else
            n2 ^= v;
    }
    return make_pair(n1, n2);
}

///////////////////////////////////////////////////////////////
//3.一个数组只有一个数出现一次，其他出现三次，空间复杂度为O(1)
// 判断所有数字每位的和，如果该位和能被3整除，则置为0，否则置为1,得到就是出现一次的数字
int NumberAppearOnce3(vector<int> &num){
    int bitSum[32] = {0};
    for (int i=0; i<32; i++){
        for (auto &n:num){
            int bitN = n>>i;
            bitSum[i] += bitN&1;
        }
    }

    int result = 0;
    for (int i=0; i<32; i++){
        result += pow(2,i)*(bitSum[i]%3);
    }
    return result;
}


int main(int argc, char *argv[])
{
    vector<int> num1 = {2, 4, 3, 6, 3, 4, 2, 5, 5};
    vector<int> num2 = {2, 4, 3, 6, 3, 2, 5, 5};
    vector<int> num3 = {2, 4, 2, 6, 2, 4, 5, 5, 4, 5};
    cout << NumberAppearOnce1(num1) << endl;

    pair<int,int> result = NumberAppearOnce2(num2);
    cout << "First Num: " << result.first << " Second Num: " << result.second << endl;

    cout << NumberAppearOnce3(num3) << endl;
    return 0;
}
