#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<int> MaxInWindow(vector<int> &nums, int window_size){
    vector<int> result;
    if (window_size < 1 || nums.size() < window_size)
        return result;
    deque<int> my_deque;
    for (int i=0; i<window_size; ++i){
        if (!my_deque.empty() && nums[i] > nums[my_deque.back()])
            my_deque.pop_back();
        my_deque.push_back(i);
    }

    for (int i=window_size; i<nums.size(); ++i){
        result.push_back(nums[my_deque.front()]);
        if (!my_deque.empty() && nums[i] > nums[my_deque.back()])
            my_deque.pop_back();
        if (!my_deque.empty() && my_deque.front() <= (int)(i-window_size))
            my_deque.pop_front();
        my_deque.push_back(i);
    }
    result.push_back(nums[my_deque.front()  ]);
    return result;
}

int main(int argc, char *argv[])
{
    vector<int> num = {2, 3, 4, 2, 6, 2, 5, 1};
    int window_size = 3;
    vector<int> result = MaxInWindow(num, window_size);
    for (auto v:result){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
