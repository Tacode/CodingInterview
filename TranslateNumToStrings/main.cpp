/*
 * 计算出数字翻译成字符串的翻译种类数
 * 其中0翻译为‘a’, 1翻译为'b'...25翻译为‘z’
*/
#include <iostream>
#include <string>
using namespace std;

/////////////////////////////////递归做法从上至下/////////////////
int RecusionFunc(const string& numStr, int i, int len){

    if (i >= len-1)
        return 1;
    int counts1 = RecusionFunc(numStr, i+1, len);
    int counts2 = 0;
    if (i+1 < len){
        int combineNum = (numStr[i]-'0')*10+(numStr[i+1]-'0');
        if (combineNum<=25 && combineNum >=0)
            counts2 = RecusionFunc(numStr, i+2, len);
    }
    return counts1+counts2;
}

int GetTranslateCounts1(int number){
    if (number<0)
        return 0;
    string numStr = to_string(number);
    int len = numStr.length();
    return RecusionFunc(numStr,0, len);
}


/////////////////////////////////动态规划，避免了重复运算/////////////////
int GetTranslateCounts2(int number){
    if (number<0)
        return 0;
    string numStr = to_string(number);
    int len = numStr.length();
    int *counts = new int[len]; // 记录当前位的种数

    for (int i=len-1; i>=0; --i){
        int tmpCount = 0;
        if (i<len-1)
            tmpCount = counts[i+1];
        else
            tmpCount = 1;

        if (i<len-1){
            int combineNum = (numStr[i]-'0')*10+(numStr[i+1]-'0');
            if (combineNum<=25 && combineNum >=0){
                if (i < len-2)
                    tmpCount += counts[i+2];
                else
                    tmpCount += 1;
            }

        }
        counts[i] = tmpCount;
    }
    int result = counts[0];
    delete[] counts;
    return result;

}

int main()
{
    int num = 12258;
    cout << GetTranslateCounts1(num) << endl;
    cout << GetTranslateCounts2(num) << endl;
    return 0;
}
