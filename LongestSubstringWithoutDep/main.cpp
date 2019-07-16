/*
 * 求最长不含重复字符的子字符串
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int LongestSubstrWithoutDep(const string &str){
    if (str.empty())
        return 0;
    int *position = new int[26];
    for (int i=0; i<26; ++i){
        position[i] = -1;
    }
    int curLen = 0;
    int maxLen = 0;
    for (size_t i=0; i<str.length(); ++i){
        int preIndex = position[str[i]-'a'];
        if (preIndex < 0 || i-preIndex > curLen)
            curLen++;
        else
            curLen = i-preIndex;
        position[str[i]-'a'] = i;
        if (curLen > maxLen)
                maxLen = curLen;
    }
    delete[] position;
    return maxLen;
}

int main()
{
    string str1 = "aaabbbccc"; //2
    string str2 = "abcdcba"; // 4
    string str3 = "abcdaef"; //6
    string str4 = "acfrarabc"; //4
    string str5 = "a"; //1
    string str6 = ""; //0
    cout << LongestSubstrWithoutDep(str1) << endl;
    cout << LongestSubstrWithoutDep(str2) << endl;
    cout << LongestSubstrWithoutDep(str3) << endl;
    cout << LongestSubstrWithoutDep(str4) << endl;
    cout << LongestSubstrWithoutDep(str5) << endl;
    return 0;
}
