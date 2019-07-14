/*
 * 求一个数组的子数组最大的和
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int MaxSumInArray(vector<int> &vec){
    if (vec.empty())
        return 0;
    int maxSum = INT8_MIN;
    int curSum = 0;
    for (size_t i=0; i<vec.size(); ++i){
        if (curSum < 0)
            curSum = vec[i];
        else {
            curSum += vec[i];
        }
        if (curSum > maxSum)
            maxSum = curSum;
    }
    return maxSum;
}

int main(int argc, char *argv[])
{
    vector<int> vec = {1,-2,-3,10,-4,7,2,-5};
    cout << MaxSumInArray(vec) << endl;
    return 0;
}
