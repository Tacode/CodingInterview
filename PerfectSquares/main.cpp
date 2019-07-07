#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution{
public:
    // 贪心算法不行
//    int PerfectSquares(int n){
//        if (n==0)
//            return 0;
//        else
//            return 1 + PerfectSquares(n-pow(static_cast<int>(sqrt(n)),2));
//    }

    // 动态规划
    int PerfectSquares(int n){
        vector<int> dp(n+1,n);
        dp[0] = 0;
        for (int i=1; i<=n; ++i){
            for (int j=sqrt(i); j>0; --j)
                dp[i] = min(dp[i],dp[i-j*j]+1);
        }
        return dp[n];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.PerfectSquares(12) << endl;
    return 0;
}
