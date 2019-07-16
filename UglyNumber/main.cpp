/*
 * 打印出第n个丑数(因子只含2,3,5)
*/
#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

//////////////////////////////传统做法,效率低///////////////////
bool IsUglyNum(int num){
    while(num % 2 == 0)
        num /= 2;
    while (num %3 == 0)
        num /= 3;
    while (num %5 == 0)
        num /= 5;
    return (num == 1)?true:false;
}

void PrintUglyNum(int index){
    if (index <=0 )
        return;
    int counts = 0, i = 1;
    long int result = 0;
    while(true){
        if (IsUglyNum(i))
            counts++;
        if (counts >= index){
            result = static_cast<long int>(i);
            break;
        }
        i++;
    }
    cout <<"第" << index <<"个丑数为: " << result << endl;
}

////////////////////////////空间换时间做法//////////////

int Compare(int value1, int value2, int value3){
    int minValue = value1 >= value2 ? value2:value1;
    return value3 >= minValue ? minValue: value3;
}

void PrintUglyNum2(int index){
    vector<int> uglyNum(index,0);
    uglyNum[0] = 1;
    int i = 1;
    int pos2 = 0;
    int pos3 = 0;
    int pos5 = 0;
    while(i < index){
        int minValue = Compare(uglyNum[pos2]*2,uglyNum[pos3]*3,uglyNum[pos5]*5);
        uglyNum[i] = minValue;
        while (uglyNum[pos2]*2 <= uglyNum[i]) {
            pos2++;
        }
        while (uglyNum[pos3]*3 <= uglyNum[i]) {
            pos3++;
        }
        while (uglyNum[pos5]*5 <= uglyNum[i]) {
            pos5++;
        }
        i++;
    }
    int result = uglyNum[i-1];
    cout <<"第" << index <<"个丑数为: " << result << endl;
}

int main(int argc, char *argv[])
{
    std::chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    PrintUglyNum(1200);
    std::chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    cout << "Cost Time: " << chrono::duration_cast<chrono::duration<double>>(t2-t1).count() << "s"<< endl;

    t1 = chrono::steady_clock::now();
    PrintUglyNum2(1200);
    t2 = chrono::steady_clock::now();
    cout << "Cost Time: " << chrono::duration_cast<chrono::duration<double>>(t2-t1).count() << "s"<< endl;

    return 0;
}
