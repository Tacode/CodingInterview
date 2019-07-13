#include <iostream>
#include <vector>
#include <algorithm>
#include "dynamicArray.hpp"
using namespace std;



///////////////////////////堆算法操作///////////////////////////////////////
void print_ivec(vector<int>::iterator begin, vector<int>::iterator end)
{
    for(;begin != end; ++begin)
        cout << *begin << '\t';
    cout << endl;
}

// STL堆算法操作
void TestHeapAlgorithm(){
    int a[] = {2,1,3,5,4};
    vector<int> ivec(a, a + sizeof(a) / sizeof(a[0]));
    cout << "原数组: " << endl;
    print_ivec(ivec.begin(), ivec.end());

    make_heap(ivec.begin(), ivec.end(), less<int>()); // 将vector变成堆结构
    cout << "完成堆结构: " << endl;
    print_ivec(ivec.begin(), ivec.end());
    cout << "是否为堆: "  << is_heap(ivec.begin(), ivec.end()) << endl << endl; //判断是否是堆结构

    pop_heap(ivec.begin(), ivec.end()); // 将最顶端的元素和最后元素置换，同时保证最后元素之前的为堆结构，但是整个不是堆结构
    int maxValue = ivec.back();
    cout << "最大值: " << maxValue << endl;
    cout << "pop_heap之后，弹出之前: " << endl;
    print_ivec(ivec.begin(), ivec.end());
    cout << "是否为堆: "  << is_heap(ivec.begin(), ivec.end()) << endl;;
    ivec.pop_back();// 弹掉最后一个元素，此时剩余的元素为堆结构
    cout << "弹出之后: " << endl;
    print_ivec(ivec.begin(), ivec.end());
    cout << "是否为堆: "  << is_heap(ivec.begin(), ivec.end()) << endl << endl;


    ivec.push_back(9);//vector中添加元素
    cout << "添加新元素之后: " << endl;
    print_ivec(ivec.begin(), ivec.end());
    cout << "是否为堆: "  << is_heap(ivec.begin(), ivec.end()) << endl;
    push_heap(ivec.begin(), ivec.end());//如果之前vector是个堆结构，那麽此时添加的新元素添加到堆中
    cout << "push_heap之后: " << endl;
    print_ivec(ivec.begin(), ivec.end());
    cout << "是否为堆: "  << is_heap(ivec.begin(), ivec.end()) << endl << endl;

    if (is_heap(ivec.begin(),ivec.end())){
        cout << "完成堆排序之后: " << endl;
        sort_heap(ivec.begin(), ivec.end());//堆排序，一定的确保整个数组为堆结构
        print_ivec(ivec.begin(), ivec.end());
    }
}
/////////////////////////////////////////////////////////////////////////////


int main(int argc, char* argv[])
{
//    TestHeapAlgorithm();
    DynamicArray<int> darray;
    vector<int> vec = {9,4,3,5,6,1,2,2};
    cout << "中位数依次为: ";
    for (auto &v:vec){
        darray.Insert(v);
        cout  << darray.GetMedian() << " ";
    }

    cout << endl;
    return 0;
}
