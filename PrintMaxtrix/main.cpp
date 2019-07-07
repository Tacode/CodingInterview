#include <iostream>

using namespace std;
void PrintNumber(int num){
    cout << num << " ";
}

void PrintMatrixInCircle(int **numbers, int cols, int rows, int start){
    int endX = cols-start-1;
    int endY = rows-start-1;

    //从左到右
    for (int i=start; i<=endX; ++i){
        PrintNumber(numbers[start][i]);
    }

    //从上到下
    if (start<endY){
        for (int i=start+1; i<=endY; ++i){
            PrintNumber(numbers[i][endX]);
        }
    }

    //从右到左
   if (start<endY && start<endX){
       for (int i=endX-1; i>=start; --i){
           PrintNumber(numbers[endY][i]);
       }
   }

   //从下往上
   if (start<endX && start<endY-1){
       for(int i=endY-1; i>=start+1; --i){
           PrintNumber(numbers[i][start]);
       }
   }


}

void PrintMatrixClockwisely(int **numbers, int cols, int rows){
    if (numbers == nullptr || cols<=0 || rows<=0)
        return;
    int start = 0;
    while (cols > start*2 && rows > start*2){
        PrintMatrixInCircle(numbers, cols, rows, start);
        start++;
    }
}

int main(int argc, char *argv[])
{
    int cols = 3;
    int rows = 5;
    int **numbers = new int*[rows];
    for (int i=0; i<rows; ++i){
        numbers[i] = new int[cols];
        for (int j=0; j<cols; ++j){
            numbers[i][j] = i * cols + j + 1;
        }
    }

    PrintMatrixClockwisely(numbers, cols, rows);
//    PrintMatrixClockwisely(numbers, 4, 4);
    cout << endl;
    return 0;
}
