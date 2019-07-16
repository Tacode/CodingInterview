/*
 * 礼物的最大值 m×n棋盘的每一格放有一个礼物，每个礼物有一定的价值，从棋盘的左上角开始拿格子里的礼物，每次向左或者向下移动一格
 * 直到右下角，计算最多能拿到多少价值的礼物
*/
#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////递归法，有重复运算，效率不行//////////////
int Recusion(vector<vector<int>> &board, int i, int j){
    if (i == 0 && j == 0)
        return board[i][j];
    int value1 = 0;
    if (i>0)
        value1 = Recusion(board, i-1, j);
    int value2 = 0;
    if (j>0)
        value2 = Recusion(board, i, j-1);
    return max(value1, value2)+board[i][j];
}


int GetMaxValue1(vector<vector<int>> &board){
    if (board.empty() || board[0].empty())
        return 0;
    return Recusion(board, board.size()-1, board[0].size()-1);

}

//////////////////////////////////////动态规划////////////////////////////
int GetMaxValue2(vector<vector<int>> &board){
    if (board.empty() || board[0].empty())
        return 0;
    vector<vector<int>> storage(board.size(), vector<int>(board[0].size(), 0));

    for (size_t i=0; i<board.size(); ++i){
        for (size_t j=0; j<board[0].size(); ++j){
            int value1 = 0;
            int value2 = 0;
            if (i>0)
                value1 = storage[i-1][j];
            if (j>0)
                value2 = storage[i][j-1];
            storage[i][j] = max(value1, value2)+board[i][j];
        }
    }
    int result = storage[board.size()-1][board[0].size()-1];
    return result;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> board = {{1, 10, 3, 8}, {12, 2, 9, 6}, {5, 7, 4, 11}, {3, 7, 16, 5}};
    vector<vector<int>> board2 = {{1,2,3}, {4,5,6}, {7,8,9}};
    cout << "第一种方法" << endl;
    cout << GetMaxValue1(board) << endl;
    cout << GetMaxValue1(board2) << endl;

    cout << "第二种方法" << endl;
    cout << GetMaxValue2(board) << endl;
    cout << GetMaxValue2(board2) << endl;

    return 0;
}
