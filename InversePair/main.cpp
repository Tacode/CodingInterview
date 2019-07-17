#include <iostream>
#include <vector>

using namespace std;


int MergeProcess(vector<int> &data, vector<int> &tmp, int start, int end){
    if (start == end){
        tmp[start] = data[start];
        return 0;
    }
    int len = (end - start)/2;
    int left = MergeProcess(tmp, data, start, start+len);
    int right = MergeProcess(tmp, data, start+len+1, end);
    int i = start+len; //前半段最后坐标
    int j = end; // 后半段最后坐标
    int k = end; //tmp的坐标
    int counts = 0;
    while (i>=start && j>=start+len+1){
        if (data[i] > data[j]){
            tmp[k--] = data[i--];
            counts += j-start-len;
        }
        else{
            tmp[k--] = data[j--];
        }
    }

    for (; i>=start; --i){
        tmp[k--] = data[i];
    }
    for (; j>=start+len+1; --j){
        tmp[k--] = data[j];
    }

    return counts+left+right;
}

int InversPairs(vector<int> &data){
    if (data.empty()){
        return 0;
    }
    vector<int> tmp=data;
    int result = MergeProcess(data, tmp, 0, data.size()-1);
    return result;
}

int main()
{
    vector<int> vec = {7,5,6,4};
    cout << InversPairs(vec) << endl;
    return 0;
}
