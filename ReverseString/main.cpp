#include <iostream>
#include <string.h>

using namespace std;
void Reverse(char *pBegin, char *pEnd){
    if (pBegin == nullptr || pEnd == nullptr){
        return;
    }

    while (pBegin < pEnd){
        char tmp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = tmp;

        pBegin++;
        pEnd--;
    }

}


/*
 * 反转字符串，单词内字符顺序不变，如"I am a student." -->"student.a am I"
 * 一般采用两次旋转，先整体旋转，然后单词内旋转
*/
char *ReverseString(char *pStr){
    if (pStr == nullptr)
        return nullptr;
    char *pBegin = pStr;
    char *pEnd = pStr;
    while(*pEnd != '\0'){
        pEnd++;
    }
    pEnd--;
    Reverse(pBegin, pEnd);
    pBegin = pEnd = pStr;
    while (*pBegin != '\0'){
        if (*pBegin == ' '){
            pBegin++;
            pEnd++;
        }
        else if(*pEnd == ' ' || *pEnd=='\0'){
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else{
            pEnd++;
        }
    }
    return pStr;
}

/*
 * 左旋转字符串 把字符串前n位转移到字符串后面 如"abcdefg"左旋两位"cdefgab"
 * 一般采用旋转ab ,然后旋转cdefg，最后在统一旋转一次，完成三次旋转
*/
char *LeftRotateString(char *pStr, int n){
    if (pStr == nullptr)
        return nullptr;
    if (n >= strlen(pStr) || n <= 0){
        return pStr;
    }
    char *pBegin = pStr;
    char *pEnd = pStr;
    for (int i=0; i<n-1; ++i){
        pEnd++;
    }
    Reverse(pBegin, pEnd);
    pBegin = ++pEnd;
    while (*pEnd != '\0')
        pEnd++;
    pEnd--;
    Reverse(pBegin, pEnd);
    pBegin = pStr;
    Reverse(pBegin, pEnd);
    return pStr;
}


int main(int argc, char *argv[])
{
    char str[] = "I am a student.";
    cout << str << endl;

    cout << ReverseString(str) << endl;

    cout << "=================================" << endl;

    char str2[] = "abcdefg";
    cout << str2 << endl;
    cout << LeftRotateString(str2, 8) << endl;
    return 0;
}
