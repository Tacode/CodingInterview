#include <iostream>
#include <vector>
#include <chrono>
#include "mysort.hpp"
using namespace std;

void TestBubbleSort(vector<int> vec){
    chrono::steady_clock::time_point t1= chrono::steady_clock::now();
    BubbleSort<int>(vec);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    cout << "冒泡结果: ";
    for (auto &v:vec){
        cout << v << " ";
    }
    cout << endl;
    cout << "Cost Time: " << chrono::duration_cast<chrono::duration<double>>(t2-t1).count() << endl;
}

void TestCockTailSort(vector<int> vec){
    chrono::steady_clock::time_point t1= chrono::steady_clock::now();
    CockTailSort<int>(vec);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    cout << "来回结果: ";
    for (auto &v:vec){
        cout << v << " ";
    }
    cout << endl;
    cout << "Cost Time: " << chrono::duration_cast<chrono::duration<double>>(t2-t1).count() << endl;
}


void TestSelectSort(vector<int> vec){
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    SelectSort<int>(vec);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    cout << "选择结果: ";
    for (auto &v:vec){
        cout << v << " ";
    }
    cout << endl;
    cout << "Cost Time: " << chrono::duration_cast<chrono::duration<double>>(t2-t1).count() <<endl;
}

void TestInsertSort(vector<int> vec){
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    InserSort<int>(vec);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    cout << "插入结果: ";
    for (auto &v:vec){
        cout << v << " ";
    }
    cout << endl;
    cout << "Cost Time: " << chrono::duration_cast<chrono::duration<double>>(t2-t1).count() << endl;
}

void TestQuickSort(vector<int> vec){
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    QuickSort<int>(vec,0, vec.size()-1);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    cout << "快排结果: ";
    for (auto &v:vec){
        cout << v << " ";
    }
    cout << endl;
    cout << "Cost Time: " << chrono::duration_cast<chrono::duration<double>>(t2-t1).count() << endl;
}

void TestMergekSort(vector<int> vec){
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    MergeSort<int>(vec);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    cout << "归并结果: ";
    for (auto &v:vec){
        cout << v << " ";
    }
    cout << endl;
    cout << "Cost Time: " << chrono::duration_cast<chrono::duration<double>>(t2-t1).count() << endl;
}

void TestHeapSort(vector<int> vec){
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    HeapSort<int>(vec);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    cout << "堆排结果: ";
    for (auto &v:vec){
        cout << v << " ";
    }
    cout << endl;
    cout << "Cost Time: " << chrono::duration_cast<chrono::duration<double>>(t2-t1).count() << endl;
}

int main(int argc, char *argv[])
{
    vector<int> vec = {2,43,23,34,12,4,21,23,35,43,53,87,23,54,3,7,6,0,3};
    cout << "原序列: "<<endl;
    for (auto &v:vec){
        cout << v << " ";
    }
    cout << endl << endl;
    TestBubbleSort(vec);
    TestCockTailSort(vec);
    TestSelectSort(vec);
    TestInsertSort(vec);
    TestQuickSort(vec);
    TestMergekSort(vec);
    TestHeapSort(vec);
    cout << endl;
    return 0;
}
