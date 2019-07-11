/*
 * 求数组中k个最小的数字
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>


using namespace std;

void PrintVec(vector<int> &res){
    for (auto &v:res){
        cout << v << " ";
    }
    cout << endl;
}

//////////////////////O(NlogN) 排序之后在遍历////////////////////
vector<int> FindNumbers1(vector<int> &nums, int k){
    vector<int> res;
    if (nums.empty()|| k <= 0)
        return res;
    if (k > (int)nums.size()){
        cout << "K is InValid" << endl;
        return res;
    }

    sort(nums.begin(), nums.end());
    for (int i=0; i<k; ++i){
        res.push_back(nums[i]);
    }
    return res;
}

////////////////////O(N) 类似快排思路 ///////////////////////

int Partition(vector<int>& nums, int start, int end){
    if (nums.empty() || start < 0 || end < 0 || start > end){
        cerr << "Partition Error" << endl;
        exit(0);
    }
    srand((int)time(0));
    int index = rand() % (end-start+1) +start;
    swap(nums[index], nums[end]);
    int small = start-1;
    for (index = start; index < end; ++index){
        if (nums[index] < nums[end]){
            ++small;
            if (small != index)
                swap(nums[index], nums[small]);
        }
    }
    swap(nums[end], nums[++small]);
    return small;
}

vector<int> FindNumbers2(vector<int> &nums, int k){
    vector<int> res;
    if (nums.empty()|| k <= 0)
        return res;
    if (k > (int)nums.size()){
        cout << "K is InValid" << endl;
        return res;
    }
    int index = Partition(nums, 0, nums.size()-1);
    while (index != k-1){
        if (index > k-1){
            index = Partition(nums, 0, index-1);
        }
        else if(index < k-1){
            index = Partition(nums, index+1, nums.size()-1);
        }
        else
            break;
    }

    for (int i=0; i<k; ++i){
        res.push_back(nums[i]);
    }
    return res;
}


////////////////////O(NlogK) 最小堆 ///////////////////////
vector<int> FindNumbers3(vector<int> &nums, int k){
    vector<int> res;
    if (nums.empty()|| k <= 0)
        return res;
    if (k > (int)nums.size()){
        cout << "K is InValid" << endl;
        return res;
    }

    priority_queue<int,vector<int>, greater<int>> q; // 小堆
    for(size_t i=0; i<nums.size(); ++i)
    {
        q.push(nums[i]);
    }

    for (int i=0; i<k; ++i){
        res.push_back(q.top());
        q.pop();
    }
    return res;
}

int main()
{
    vector<int> nums = {3,2,4,7,4,8,1,5,0,9,3,10};
    int k = 7;
    vector<int> res1 = FindNumbers1(nums, k);
    PrintVec(res1);

    vector<int> res2 = FindNumbers2(nums, k);
    PrintVec(res2);

    nums = {3,2,4,7,4,8,1,5,0,9,3,10};

    vector<int> res3 = FindNumbers3(nums, k);
    PrintVec(res3);
    return 0;
}
