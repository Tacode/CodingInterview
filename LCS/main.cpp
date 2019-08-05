/*
 * 最长公共子序列问题
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//动态规划解
/*
 * dp[i,j] = 0                          i==0 || j==0
 * dp[i,j] = dp[i-1,j-1]                sequence1[i] = sequence2[j]
 * dp[i,j] = max(dp[i-1,j], dp[i,j-1])  sequence1[i] != sequence2[j]
*/
int LengthOfLCS(string &str1, string &str2, string &sequence){
    int len1 = str1.length();
    int len2 = str2.length();
    if (len1 == 0 || len2 == 0)
        return 0;
    vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));

    //时间复杂度O(mn)
    for (int i=1; i<=len1; i++){
        for (int j=1; j<=len2; j++){
            int idx = i-1;
            int idy = j-1;
            if (str1[idx] == str2[idy])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // 倒序找出一个子序列 时间复杂度O(m+n)
    int i = len1;
    int j = len2;
    while (dp[i][j] != 0){
        if (str1[i-1] != str2[j-1]){
            if (dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
        else{
            sequence.push_back(str1[i-1]);
            i--;
            j--;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return dp[len1][len2];
}

int main(int argc, char *argv[])
{
    string str1 = "13456778";
    string str2 = "357486782";

//    string str1 = "13456778";
//    string str2 = "3568";
    string result; // 得到其中一个最长公共子序列

    cout << str1 << endl;
    cout << str2 << endl;
    cout << "最长公共子序列长度为: " << LengthOfLCS(str1, str2,result) << endl;
    cout << "其中一个最长公共子序列为: "<< result << endl;
    return 0;
}
