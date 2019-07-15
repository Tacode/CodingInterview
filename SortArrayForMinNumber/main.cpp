/*
 * 把数组排成最小的数
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void PrintMinNumber(vector<int> &num){
    if (num.empty())
        return;

    string str = "";
    for (auto &v:num){
        str += to_string(v);
    }
    sort(str.begin(), str.end());
    cout << str << endl;
}

int main(int argc, char *argv[])
{
    vector<int> num = {2, 3, 4, 2, 3,9, 5, 4};
    PrintMinNumber(num);
    return 0;
}
