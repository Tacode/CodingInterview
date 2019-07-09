/*
 * 1.实现字符串的排列，组合。其中组合中ab和ba是同一种组合
 * 2. 深度优先搜索实现数字的排列组合
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
/////////////////////////////字符串排列组合///////////////////
void Permutation(char *str, int start, int end){
    if (end < 1)
        return;
    if (start == end){
        cout << str << endl;

    }
    for (int i=start; i<=end; ++i){
        swap(*(str+start), *(str+i));
        Permutation(str, start+1, end);
        swap(*(str+start), *(str+i));
    }
}
// 采用位运算可以实现，abc总共有3个元素，因此有2^3-1中组合方式(除去空),输出不按照字典序
void Combinations1(char *str){
    int len = strlen(str);
    int n = 1<<len;
    for (int i=1; i<n; ++i){
        for (int j=0; j<len; ++j){
            if ((i & (1<<j)) != 0){
               cout << str[j];
            }
        }
        cout << endl;
    }
}

void CombinationRecusion(char *str, int m, vector<char> &res){
    if (str == nullptr || *str == '\0'&& m!=0)
        return;
    if (m == 0){
        for (auto &v:res){
            cout << v;
        }
        cout << endl;
        return;
    }
    res.push_back(*str);
    CombinationRecusion(str+1, m-1, res);
    res.pop_back();
    CombinationRecusion(str+1, m, res);
}

void Combinations2(char *str){
    int len = strlen(str);
    for (int i=1; i<=len; ++i){
        vector<char> result;
        CombinationRecusion(str, i, result);
    }
}

////////////////////////////////////////////////////////////

/////////////////////////深度优先搜索排列组合//////////////////
void DFS_Permute(vector<vector<int>> &res, vector<int> &nums, size_t counts, vector<int> &flags, vector<int> tmp){
    if (counts == nums.size())
        res.push_back(tmp);
    else{
        for (size_t i=0; i<nums.size(); ++i){
            if (flags[i] == 0){
                flags[i] = 1;
                tmp.push_back(nums[i]);
                DFS_Permute(res, nums, counts+1, flags, tmp);
                tmp.pop_back();
                flags[i] = 0;
            }
        }
    }
}

void DFS_Subset(vector<vector<int>> &res, vector<int> &nums, vector<int> &flags, vector<int> tmp){
    res.push_back(tmp);
    for (size_t i=0; i<nums.size(); ++i){
        if (flags[i] == 0){
            flags[i] = 1;
            tmp.push_back(nums[i]);
            DFS_Subset(res, nums, flags, tmp);
            flags[i] = 0;
            tmp.pop_back();
        }
    }
}

vector<vector<int>> Permute(vector<int> &nums){
    vector<vector<int>> res;
    if (nums.empty())
        return res;
    vector<int> flags(nums.size(), 0); // 设置标记为，标记是否遍历过
    vector<int> tmp;
    DFS_Permute(res, nums, 0, flags, tmp);
    return res;
}


vector<vector<int>> Subset(vector<int> &nums){
    vector<vector<int>> res;
    if (nums.empty())
        return res;
    vector<int> flags(nums.size(), 0);
    vector<int> tmp;
    DFS_Subset(res, nums, flags, tmp);
    return res;
}
///////////////////////////////////////////////////////////////

/////////////////////////////////测试//////////////////////////////////////
void TestString(){
    char str[] ="abc";
    cout << "--------------------Permutation1-----------------"<< endl;
    Permutation(str, 0, strlen(str)-1);
    cout << "--------------------Combination1-----------------"<< endl;
    Combinations1(str);

    cout << "--------------------Combination2-----------------"<< endl;
    Combinations2(str);
}


void TestNum(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> res_permute = Permute(nums);
    vector<vector<int>> res_subset = Subset(nums);
    cout << "--------------------Number Permute Output--------------" << endl;
    for (auto &r:res_permute){
        for (auto &v:r){
            cout << v;
        }
        cout << endl;
    }
    cout << "--------------------Number Subset Output--------------" << endl;
    for (auto &r:res_subset){
        for (auto &v:r){
            cout << v;
        }
        cout << endl;
    }
}

int main()
{
    TestString();
//    TestNum();
    return 0;
}
