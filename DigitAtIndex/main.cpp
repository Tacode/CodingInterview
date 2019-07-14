/*
 * 数组序列中的某一位数字
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int ObtainCountsNum(int layer){
    if (layer == 1)
        return 10;
    else
        return 9*pow(10,layer-1);
}

int ObtainResult(int index, int layer){
    int beginNumInLayer = layer == 1 ? 0 : pow(10, layer-1);
    int indexInLayer = index / layer;
    int indexInNum = index % layer;
    int num = beginNumInLayer+indexInLayer;
    return int(to_string(num)[indexInNum]-'0');
}

int DigitsAtIndex(int index){
    if (index < 0)
        return -1;
    int layer = 1;
    while(1){
        int countsNum = ObtainCountsNum(layer);
        if (index < countsNum*layer){
            return ObtainResult(index, layer);
        }
        index -= countsNum*layer;
        layer++;
    }
}

int main(int argc, char *argv[])
{
    string str = "";
    for (int i=0; i<10000; ++i)
        str += to_string(i);
    cout << DigitsAtIndex(1001) << endl;
    return 0;
}
