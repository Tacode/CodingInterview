/*
 * 得到数组中超过或者等于一半的数字
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
#include <exception>
using namespace std;
bool isMoreHalf(vector<int> &nums, int number){
    int counts = 0;
    for (auto &v:nums){
        if (v == number)
            counts++;
    }

    if (counts*2<nums.size()){
        return false;
    }
    else
        return true;
}

//////////////////////////////////时间复杂度为O(n)/////////////////
int ObtainNumber1(vector<int> &nums){
    if (nums.empty()){
        cerr << "Vector is Empty" << endl;
        exit(0);
    }
    int result = nums[0];
    int counts = 1;
    for (size_t i=1; i<nums.size(); ++i){
        if (counts == 0){
            result = nums[i];
            counts = 1;
        }
        else if(nums[i] == result){
            counts++;
        }
        else{
            counts--;
        }
    }
    if (isMoreHalf(nums, result))
        return result;
    else{
        cerr << "Vector is InVliad" << endl;
        exit(0);
    }
}


//////////////////////////////////时间复杂度为O(n),空间换时间/////////////////
int ObtainNumber2(vector<int> &nums){
    if (nums.empty()){
        cerr << "Vector is Empty" << endl;
        exit(0);
    }
    unordered_map<int,int> dict;
    for (auto &v:nums){
        dict[v]++;
    }
    for (auto &item:dict){
        if (item.second * 2 >= (int)nums.size())
            return item.first;
    }
    cerr << "Not Find!" << endl;
    exit(0);
}

//////////////////////////////////时间复杂度为O(n),快排思想/////////////////
int RandomNumber(int start, int end){
    srand((int)time(0));
    int range = end-start+1;
    return rand() % range+start;

}

int Partition(vector<int> &nums, int start, int end){
    if (start > end || start<0 || end < 0 || nums.empty())
    {
        cerr << "Partition Error" << endl;
        exit(0);
    }

    int index = RandomNumber(start, end);
    swap(nums[index], nums[end]);
    int small = start-1;
    for (index = start; index<end; ++index){
        if (nums[index] < nums[end])
        {
            ++small;
            if (small != index)
                swap(nums[index], nums[small]);
        }
    }
    swap(nums[++small], nums[end]);
    return small;
}

int ObtainNumber3(vector<int> &nums){
    if (nums.empty()){
        cerr << "Vector is Empty" << endl;
        exit(0);
    }

    int middle = nums.size()>>1;
    int start = 0;
    int end = nums.size()-1;
    int index = Partition(nums, start, end);
    while (index != middle) {
       if (index > middle){
           index = Partition(nums, start, index-1);
       }
       else if (index < middle){
           index = Partition(nums,index+1, end);
       }
       else
           break;
    }
    if (isMoreHalf(nums, nums[index]))
        return nums[index];
    else{
        cerr << "Vector is InVliad" << endl;
        exit(0);
    }

}


int main(int argc, char *argv[])
{
    vector<int> nums = {3,1,5,3,2,3,2,4,3,6,3,3,3,2};
    cout << ObtainNumber1(nums) << endl;
    cout << ObtainNumber2(nums) << endl;
    cout << ObtainNumber3(nums) << endl;
    return 0;
}



