#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T>
class DynamicArray{
public:
    void Insert(T num);
    T GetMedian();
protected:
    vector<T> minHeap;
    vector<T> maxHeap;
};

#endif // DYNAMICARRAY_HPP


template<typename T>
void DynamicArray<T>::Insert(T num)
{
    if ((minHeap.size()+maxHeap.size()) % 2 == 0){
        if(!minHeap.empty() && num > minHeap[0]){ // 如果这个数大于了最小堆的数
            minHeap.push_back(num);
            push_heap(minHeap.begin(),minHeap.end(),greater<T>()); //小顶堆结构
            num = minHeap[0];
            pop_heap(minHeap.begin(), minHeap.end(),greater<T>());
            minHeap.pop_back();
        }
        maxHeap.push_back(num);
        push_heap(maxHeap.begin(),maxHeap.end()); // 完成大顶堆结构，默认为最大顶堆(less<T>)
    }
    else{
        if(!maxHeap.empty() && num < maxHeap[0]){ // 如果这个数小于了最大堆的数
            maxHeap.push_back(num);
            push_heap(maxHeap.begin(),maxHeap.end());
            num = maxHeap[0];
            pop_heap(maxHeap.begin(), maxHeap.end());
            maxHeap.pop_back();
        }
        minHeap.push_back(num);
        push_heap(minHeap.begin(),minHeap.end(),greater<T>()); // 完成小顶堆结构
    }
}

template<typename T>
T DynamicArray<T>::GetMedian()
{
    int sizes = minHeap.size()+maxHeap.size();
    if (sizes == 0){
        cout << "Empty Array" << endl;
        exit(0);
    }
    if (sizes == 1)
        return maxHeap[0];

    if (sizes % 2 == 0)
        return (minHeap[0] + maxHeap[0])/2;
    else
        return maxHeap[0];
}
