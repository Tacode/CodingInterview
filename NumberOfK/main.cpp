#include <iostream>
#include <vector>
#include <map>
using namespace std;

//////////////////////////////////////O(logn)的解法，类似二分查找/////////////////
int GetFirstIndex(vector<int> &num, int start, int end, int k){
    if (start > end){
        return -1;
    }
    int midIndex = start + (end - start) / 2;
    int midValue = num[midIndex];

    if (midValue == k){
        if (midIndex>0 && num[midIndex-1] != k || midIndex == 0){
            return midIndex;
        }
        else
            end = midIndex-1;
    }
    else if (midValue > k){
        end = midIndex-1;
    }
    else{
        start = midIndex+1;
    }
    return GetFirstIndex(num, start, end, k);
}

int GetLastIndex(vector<int> &num, int start, int end, int k){
    if (start > end){
        return -1;
    }
    int midIndex = start + (end - start) / 2;
    int midValue = num[midIndex];

    if (midValue == k){
        if (midIndex<num.size()-1 && num[midIndex+1] != k || midIndex == num.size()-1){
            return midIndex;
        }
        else
            start = midIndex+1;
    }
    else if (midValue > k){
        end = midIndex-1;
    }
    else{
        start = midIndex+1;
    }
    return GetLastIndex(num, start, end, k);
}

int GetNumber(vector<int> &num, int k){
    if (num.empty())
        return 0;
    int len = num.size();
    int result = 0;
    int first = GetFirstIndex(num, 0, len-1, k);
    int end = GetLastIndex(num, 0, len-1, k);
    if (first>-1 && end > -1)
        result = end - first + 1;
    return result;

}
////////////////////////////////O(n)的解法，字典去存////////////////////////////
int GetNumber2(vector<int> &num, int k){
    map<int,int> m;
    for (auto &n:num){
        m[n]++;
    }
    return m[k];
}

int main(int argc, char *argv[])
{
    vector<int> vec = {1,2,3,3,3,4,5};
    int k = 3;
    cout << k << " 出现了 " << GetNumber(vec, k) << " 次" << endl;
    cout << k << " 出现了 " << GetNumber2(vec, k) << " 次" << endl;
    return 0;
}
