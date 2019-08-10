/*
 * 360笔试题目
 * 现在有q个询问，每次询问想问你在[l,r]区间内，k进制表示中，k-1的数量最多的数是哪个数。
 * 比如当k=2时，9的二进制就是1001，那么他就有2个1.
 *
 *
 * 第一行一个q，表示有q组询问。
 * 接下来q行，每行三个整数k,l,r,分别表示进制数,查询的数字,以及查询的范围.
 * 满足1<=q<=100000,2<=k<=16,1<=l<=r<=10^16
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> Transform(long long num, int k){
    vector<int> res;
    while(num){
        res.push_back(num % k);
        num /= k;
    }
    reverse(res.begin(), res.end());
    return res;
}

long long ReverseTransform(vector<int> num,int k){
    long long res = 0;
    for (int i=0; i< num.size(); i++){
        res += num[i]*pow(k,num.size()-1-i);
    }
    return res;
}

long long Func(int k, long long l, long long r){
    vector<int> end;
    end = Transform(r,k);
    int len = end.size();
    long long tmp = l;
    vector<int> start(len,0);
    int idx = 0;
    while(tmp){
        start[idx++] = tmp % k;
        tmp /= k;
    }
    reverse(start.begin(), start.end());

    for (auto &i:start){
        cout << i << "-";
    }
    cout << endl;

    for (auto &i:end){
        cout << i << "-";
    }
    cout << endl;
    long long pre_v = l;
    for (int i=start.size()-1; i>=0; i--){
        start[i] = k-1;
        long long v = ReverseTransform(start,k);
        if (v == r)
            return v;
        if ( v > r){
            break;
        }
        pre_v = v;
        if (v < l)
            cout << v << endl;
    }
    for (auto &i:start){
        cout << i << "-";
    }
    cout << endl;
    return pre_v;
}

int main()
{
    int n;
    int k;
    long long l, r;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> k >> l >> r;
        if (l == r){
            cout << l << endl;
        }
        else
            cout << Func(k, l, r) << endl;
    }
    return 0;
}
