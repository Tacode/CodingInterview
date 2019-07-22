/*
 * 不用乘除法，for ，while, if else, switch case等关键字以及判断语句实现1+2...+n
*/
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////
// 1.利用构造函数
class Temp{
public:
    Temp(){++N;sums+=N;}

    static void Reset(){
        sums = 0;
        N = 0;
    }

    static int GetSum(){
        return sums;
    }
private:
    static int N;
    static int sums;
};

int Temp::N = 0;
int Temp::sums = 0;

int GetSum1(int n){
    Temp::Reset();

    Temp *a = new Temp[n];
    delete []a;
    a = nullptr;
    return Temp::GetSum();
}
////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
// 2.利用虚函数
class A;
A *Array[2];

class A{
public:
    virtual int Sum(int n){
        return 0;
    }
};

class B: public A{
public:
    virtual int Sum(int n){
        return Array[!!n]->Sum(n-1)+n;
    }
};


int GetSum2(int n){
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;
    return Array[1]->Sum(n);
}
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// 3.利用函数指针
typedef int (*func)(int);
int Temp3(int n){
    return 0;
}

int GetSum3(int n){
    func f[2] = {Temp3, GetSum3};
    return n+f[!!n](n-1);
}
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// 3.利用函数模板

template <int n> struct GetSum4{
    enum Value{N = GetSum4<n-1>::N+n};
};

template <> struct GetSum4<1>{
    enum Value{N=1};
};

////////////////////////////////////////////////////////////////////////
/// \brief main
/// \param argc
/// \param argv
/// \return
///
int main(int argc, char *argv[])
{
    cout << GetSum1(100) << endl;
    cout << GetSum2(100) << endl;
    cout << GetSum3(100) << endl;
    cout << GetSum4<100>::N << endl;
    return 0;
}
