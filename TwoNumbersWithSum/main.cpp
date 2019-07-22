#include <iostream>
#include <vector>

using namespace std;

/*找出和为s的两个数字*/
bool FindNumbersWithSum(vector<int> &num, int target, pair<int, int> &results){
    if (num.empty())
        return false;
    int len = num.size();
    int left = 0;
    int right = len-1;
    while (left < right) {
        if (num[left] + num[right] == target){
            results = make_pair(num[left], num[right]);
            return true;
        }
        else if(num[left] + num[right] > target){
            right--;
        }
        else{
            left++;
        }

    }
    return false;
}

/*找出和为s的连续正数序列*/
void StorageSequence(int small, int big, vector<vector<int>> &result){
    vector<int> tmp;
    for (int i=small; i<=big; ++i){
        tmp.push_back(i);
    }
    result.push_back(tmp);
}

int GetSum(int small, int big){
    return (small+big)*(big-small+1)/2;
}

vector<vector<int>> FindeContinuousSequence(int sum){
    vector<vector<int>> result;
    if (sum < 3)
        return result;
    int small =1;
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;
    while (small < middle){
        if (curSum == sum)
            StorageSequence(small, big, result);
        while (curSum > sum && small < middle){
            small++;
            curSum = GetSum(small, big);
            if (curSum == sum)
                StorageSequence(small,big,result);
        }
        big++;
        curSum = GetSum(small, big);
    }
    return result;
}

int main(int argc, char *argv[])
{
    vector<int> num = {1, 2, 4, 7, 11, 15};
    int target = 15;
    pair<int,int> results;
    if (FindNumbersWithSum(num, target, results)){
        cout << results.first << " " << results.second << endl;
    }
    cout << "-------------------------------------" << endl;
    vector<vector<int>> result;
    result = FindeContinuousSequence(15);
    for (auto &r:result){
        for (auto &v:r){
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
