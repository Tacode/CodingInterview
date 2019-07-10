/*
 * 八皇后问题 得到有多少中摆法
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
////////////////利用排列组合的方式///////////////////////
/// 这种方式效率不高
void Permutation(vector<vector<int>> &permute, vector<int> columnIndex, int from, int to){
    if (to < 1){
        return;
    }

    if (from == to){
        permute.emplace_back(columnIndex);
        return;
    }

    for (int i=from; i<to; ++i){
        swap(columnIndex[from], columnIndex[i]);
        Permutation(permute, columnIndex, from+1, to);
        swap(columnIndex[from], columnIndex[i]);
    }
}

int NumInEightQueen(vector<int> &columnIndex){
    vector<vector<int>> permute;
    Permutation(permute, columnIndex, 0, columnIndex.size());
    int counts = 0;
    for (auto &p:permute){
        bool flag = true;
        for (int i=0; i<p.size(); ++i){
            for (int j=0; j<p.size(); ++j){
                if (i == j)
                    continue;
                if (abs(i-j) == abs(p[i]-p[j]))
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
      if (flag)
          counts++;
    }
   return counts;
}

///////////////////////////////////////////////////////

///////////////////////////深度优先算法+回溯法///////////////
bool isValid(int i, int j, vector<vector<int>> &box){
    //判断行
    for (int m=0; m<8; ++m){
        if (box[i][m] == 1 && m != j)
            return false;
    }

    //判断列
    for (int m=0; m<8; ++m){
        if (box[m][j] == 1 && m != i)
            return false;
    }

    //判断左上
    for (int m=i,n=j; m>=0&&n>=0; --m,--n){
        if (box[m][n] == 1 && m != i && n !=j)
            return false;
    }

    //·判断右上
    for (int m=i,n=j; m>=0&&n<8; --m,++n){
        if (box[m][n] == 1 && m != i && n !=j)
            return false;
    }

    //判断左下
    for (int m=i,n=j; m<8&&n>=0; ++m,--n){
        if (box[m][n] == 1  && m != i && n !=j)
            return false;
    }

    //判断右下
    for (int m=i,n=j; m<8&&n<8; ++m,++n){
        if (box[m][n] == 1  && m != i && n !=j)
            return false;
    }

    return true;
}

void  Queue(int j, int &counts, vector<vector<int>> &box){
    if (box.empty() || box[0].empty())
        return;
    if (j == 8){
        counts++;
        return;
    }

    for (int i=0; i<8; ++i){
        if (isValid(i,j,box)){
            box[i][j] = 1;
            Queue(j+1,counts,box);
            box[i][j] = 0;
        }
    }

}
///////////////////////////////////////////////////////////////////////


////////////////////////////Test/////////////////////////////////////

void TestPermute(){
    vector<int> columnIndex = {0, 1, 2, 3, 4, 5, 6, 7};// 第i个数字表示，第i行的列号
    int counts = NumInEightQueen(columnIndex);
    cout << "共有： "<< counts << "种" << endl;
}

void TestBacktracking(){
    vector<vector<int>> box(8, vector<int>(8,0));

    int counts = 0;
    Queue(0, counts, box);
    cout << "共有： "<< counts << "种" << endl;
}

int main()
{
//    TestPermute();
    TestBacktracking();
    return 0;
}
