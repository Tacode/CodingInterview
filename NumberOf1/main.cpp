/*
 * 1到n整数中1出现的个数
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
using namespace std;

int NumberOf1ByRecusion(char *str){
   if (*str == '\0' || !str || *str < '0' || *str > '9')
       return 0;
   int numsOfFirst = 0;
   int length = strlen(str);
   int firtsNum = (int)(str[0]-'0');
   if (firtsNum == 0 && length == 1)
       return 0;
   if (firtsNum == 1 && length == 1)
       return 1;

   if (firtsNum > 1){
       numsOfFirst = pow(10,length-1);
   }
   else if (firtsNum == 1){
        numsOfFirst = atoi(str+1) + 1;
   }

   int numsOfOther = firtsNum * (length-1) * pow(10, length-2);
   int numsOfLast = NumberOf1ByRecusion(str+1);

   return numsOfFirst + numsOfOther + numsOfLast;
}

int NumberOf1(int n){
    int numbers = 0;
    while (n){
        if (n % 10 == 1)
            numbers++;
        n = n/10;
    }
    return numbers;
}
int NumberOf1ByNormal(char *str){
     int n = atoi(str);
     int numbers = 0;
     for (int i=1; i<=n; ++i)
     {
         numbers += NumberOf1(i);
     }
     return numbers;
}

int main(){
    char str[30];
    printf("Input str1: ");
    scanf("%s", str);

    cout << NumberOf1ByRecusion(str) << endl;
    cout << NumberOf1ByNormal(str) << endl;
    return 0;
}
