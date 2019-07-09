/*
 * 输入八个数字的数组，将这八个数放入正方体上，判断是否存在一种排列使得正方体上三组相对的面上的顶点的和相等
*/
#include <iostream>
#include <vector>

using namespace std;

void Permutation(vector<vector<int>> &res, vector<int> &vec, int from, int to){
    if (to < 1)
        return;
    if (from == to){
        res.push_back(vec);
        return;
    }
    for (int i=from; i<=to; ++i){
        swap(vec[i],vec[from]);
        Permutation(res, vec, from+1, to);
        swap(vec[i],vec[from]);
    }

}

void ObtainPermute(vector<vector<int>> &res, vector<int> &vec){
    if (vec.empty())
        return;
    Permutation(res, vec, 0, vec.size()-1);
}

bool isExit(vector<int> &vec){
    if (vec.size() < 8)
        return false;
    vector<vector<int>> res;
    ObtainPermute(res, vec);
    for (auto &v:res){
        if (v[0]+v[1]+v[2]+v[3] == v[4]+v[5]+v[6]+v[7] &&
            v[0]+v[3]+v[4]+v[6] == v[1]+v[3]+v[6]+v[7] &&
            v[0]+v[1]+v[4]+v[5] == v[2]+v[3]+v[6]+v[7]){
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    vector<int> vec = {1,2,3,4,5,6,7,8};
    cout << isExit(vec) << endl;
    return 0;
}
