#ifndef MYSORT_HPP
#define MYSORT_HPP
#include <vector>
using namespace std;
//////////////////////////////////声明///////////////////////
template <typename T> void BubbleSort(vector<T> &vec);
template <typename T> void SelectSort(vector<T> &vec);
template <typename T> void InserSort(vector<T> &vec);
template <typename T> void QuickSort(vector<T> &vec,int left, int right);
template <typename T> void MergeSort(vector<T> &vec);
template <typename T> void HeapSort(vector<T> &vec);

///////////////////////////////////定义////////////////////
template <typename T> void BubbleSort(vector<T> &vec){
    if (vec.empty())
        return;
    for(size_t i=0; i<vec.size()-1; ++i){
        for (size_t j=0; j < vec.size()-1-i; j++){
            if (vec[j+1] < vec[j])
                swap(vec[j+1], vec[j]);
        }
    }
}


template <typename T> void SelectSort(vector<T> &vec){
    if (vec.empty())
        return;
    for (size_t i=0; i<vec.size(); ++i){
        int min_idx = i;
        for (int j=i+1; j<vec.size(); ++j){
            if (vec[j] < vec[min_idx])
                min_idx = j;
        }
        swap(vec[i],vec[min_idx]);
    }
}

template <typename T> void InserSort(vector<T> &vec){
    if (vec.empty())
        return;
    int j;
    for (size_t i=1; i<vec.size(); ++i){
        int value = vec[i];
        for (j=i-1; j>=0&&vec[j]>value; --j){
            vec[j+1] = vec[j];
        }
        vec[j+1] = value;
    }
}


template <typename T> void QuickSort(vector<T> &vec, int left, int right){
    if (left > right)
        return;
    int base = vec[left];
    int i,j;
    i = left;
    j = right;
    while (i < j){
        while(base <= vec[j] && i<j){
            j--;
        }

        while(base >= vec[i] && i<j){
            i++;
        }
        if (i < j)
            swap(vec[i],vec[j]);
    }
    swap(vec[i], vec[left]);
    QuickSort(vec,left, i-1);
    QuickSort(vec, i+1, right);
}


template <typename T> void MergeSort(vector<T> &vec){

}

template <typename T> void HeapSort(vector<T> &vec){

}

#endif // MYSORT_HPP
