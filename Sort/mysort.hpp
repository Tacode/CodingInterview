#ifndef MYSORT_HPP
#define MYSORT_HPP
#include <vector>
using namespace std;
//////////////////////////////////声明///////////////////////
template <typename T> void BubbleSort(vector<T> &vec);
template <typename T> void CockTailSort(vector<T> &vec); //鸡尾酒排序，冒泡排序变种
template <typename T> void SelectSort(vector<T> &vec);
template <typename T> void InserSort(vector<T> &vec);
template <typename T> void QuickSort(vector<T> &vec,int left, int right);

template <typename T> void MergeSort(vector<T> &vec, int start, int end, vector<T> &tmp);
template <typename T> void MergeSort(vector<T> &vec);
template <typename T> void MergeArray(vector<T> &vec, int start, int end, int mid, vector<T> &tmp);

template <typename T> void HeapAdjust(vector<T> &vec, int parent, int end);
template <typename T> void HeapSort(vector<T> &vec);
///////////////////////////////////定义////////////////////

//------------------------冒泡排序------------------------
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

template<typename T> void CockTailSort(vector<T> &vec){
    int len = vec.size();
    int j, left = 0, right = len - 1;
    while (left < right) {
        for (j = left; j < right; j++)
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
        right--;
        for (j = right; j > left; j--)
            if (vec[j - 1] > vec[j])
                swap(vec[j - 1], vec[j]);
        left++;
    }
}

//------------------------选择排序------------------------
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

//------------------------插入排序------------------------
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

//------------------------快速排序------------------------
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

//------------------------归并排序------------------------
template <typename T> void MergeArray(vector<T> &vec, int start, int end, int mid, vector<T> &tmp){
    int i = start;
    int j = mid+1;
    int k =0;
    while (i <= mid && j<=end){
        if (vec[i] <= vec[j]){
            tmp[k++] = vec[i++];
        }
        else
            tmp[k++] = vec[j++];
    }
    while (i <= mid){
        tmp[k++] = vec[i++];
    }
    while (j <= end){
        tmp[k++] = vec[j++];
    }

    for (size_t i=0; i<k; ++i){
        vec[start+i] = tmp[i];
    }

}

template <typename T> void MergeSort(vector<T> &vec, int start, int end, vector<T> &tmp){
    if (start < end){
        int mid = start+(end-start)/2;
        MergeSort(vec, start, mid, tmp);
        MergeSort(vec, mid+1, end, tmp);
        MergeArray(vec, start, end, mid, tmp);
    }
}

template <typename T> void MergeSort(vector<T> &vec){
    if (vec.empty())
        return;
    int start = 0;
    int end = vec.size()-1;
    vector<int> tmp(vec.size(),0);
    MergeSort<T>(vec, start, end, tmp);
}


//------------------------堆排序------------------------
template <typename T> void HeapAdjust(vector<T> &vec, int parent, int end){
    int lchild = 2*parent+1;
    while (lchild <= end){
        int rchild = lchild+1;
        int maxNode = lchild;
        if (rchild <= end && vec[lchild] < vec[rchild]){
            maxNode = rchild;
        }
        if (vec[parent] > vec[maxNode])
            return;
        swap(vec[parent], vec[maxNode]);
        parent = maxNode;
        lchild = 2*parent+1;
    }
}

template <typename T> void HeapSort(vector<T> &vec){
    if (vec.empty())
        return;
    int len = vec.size();
    for (int i=len/2-1; i>=0; --i){ //建立起一个堆
        HeapAdjust(vec, i, len-1);
    }

    for (int i=len-1; i>=0; --i){
        swap(vec[i], vec[0]);
        HeapAdjust(vec, 0, i-1); // 从头调整堆
    }
}

#endif // MYSORT_HPP
