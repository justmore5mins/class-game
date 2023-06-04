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

void Time::gettime(int &hours, int &minutes, int &seconds, int &milliseconds){
    auto now = chrono::system_clock::now();

    time_t current_time = chrono::system_clock::to_time_t(now);
    struct std::tm* local_time = std::localtime(&current_time);
    hours = local_time->tm_hour;
    minutes = local_time->tm_min;
    seconds = local_time->tm_sec;

    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() % 1000;
}