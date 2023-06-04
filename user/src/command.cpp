#include "command.h"
#include <iostream>

using namespace std;

string Caesar::caesarencode(const string& raw, int shift){
    string encoded = "";
    int length = raw.length();
    for(int i = 0; i < length; i++){
        char ch = raw[i];
        if(isalpha(ch)){
            bool isUpperCase = isupper(ch);
            // 将字符转换为大写形式
            ch = toupper(ch);
            // 应用凯撒加密算法
            ch = ((ch - 'A' + shift) % 26) + 'A';
            // 根据原始字符的大小写重新设置字符
            if (!isUpperCase)
                ch = tolower(ch);
        }
        encoded += ch;
    }

    return encoded;
};

int Caesar::random(int min, int max){
    return rand() % (max - min + 1) + min;
};