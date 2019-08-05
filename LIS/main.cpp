/*
 * 最长上升子序列，例：
 * [1,7,3,5,9,4,8] 最长上升子序列为[1,3,5,8],长度为4
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 动态规划解法, 时间复杂度O(N^2)
int LengthOfLIS1(vector<int> &data){
    if (data.empty())
        return 0;
    int result = 1;
    vector<int> dp(data.size(), 1);
    for (size_t i=0; i<data.size(); i++){
        for (size_t j=0; j<i; j++)
            if(data[j] < data[i])
                dp[i] = max(dp[i], dp[j]+1);
        result = max(result, dp[i]);
    }

    return result;
}


// 动态规划+二分查找法,时间复杂度O(NlogN)
/*新建数组 dp，用于保存最长上升子序列。
对原序列进行遍历，将每位元素二分插入 dp 中。
如果 dp 中元素都比它小，将它插到最后
否则，用它覆盖掉比它大的元素中最小的那个。
总之，思想就是让 dp 中存储比较小的元素。这样，dp 未必是真实的最长上升子序列，但长度是对的。
*/
int LengthOfLIS2(vector<int> &data){
    if (data.empty())
        return 0;
    vector<int> dp;
    dp.push_back(data[0]);
    for (size_t i=1; i<data.size(); i++){
        if (data[i] > dp[dp.size()-1]){
            dp.push_back(data[i]);
            continue;
        }

        int left = 0;
        int right = dp.size()-1;
        while (left < right){
            int mid = left + (right-left)/2;
            if (data[i] > dp[mid])
                left = mid+1;
            else
                right = mid;
        }
        dp[left] = data[i];
    }
    return dp.size();
}


//利用low_bound函数求解,其实就是用该函数替换二分查找第一个大于遍历原数组元素的值
//low_bound函数返回数组第一个大于或等于指定元素的迭代器 与upper_bound(返回第一个大于指定元素的迭代器)有所区别
int LengthOfLIS3(vector<int> &data){
    if (data.empty())
        return 0;
    vector<int> dp;
    for (size_t i=0; i<data.size(); i++){
        auto it = lower_bound(dp.begin(), dp.end(), data[i]);
        if (it != dp.end())
            *it = data[i];
        else
            dp.push_back(data[i]);
    }
    return dp.size();
}

int main(int argc, char *argv[])
{
    vector<int> data = {1,7,3,5,9,4,8};
    cout << LengthOfLIS1(data) << endl;
    cout << LengthOfLIS2(data) << endl;
    cout << LengthOfLIS3(data) << endl;
    return 0;
}
