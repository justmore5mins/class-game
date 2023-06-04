#include <cstdlib>
#include <iostream>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "src/command.h"

#define print std::cout

using namespace std;
Caesar caesarenc;

int main(int argc, char* argv[]){
    int option;
    bool chatFlag = false;
    string username;
    string chat;

//使用者的程式
    while((option = getopt(argc,argv,"u:r:")) != -1){
        switch (option){
        case 'u':
           if(optarg != nullptr){
            username = optarg;
           }
            break;
        case 'r':
            if(optarg != nullptr){
                chat = optarg;
            }
            break;
        default:
            break;
        }
    }

    if(!username.empty()){
        print << "username: "<< username << endl;
    }
    else{
        print << "no user loggin" << endl;
    }

    if(!chat.empty()){
        int shift = caesarenc.random(1, 10);
        string caesar = caesarenc.caesarencode(chat,shift);

        print << "shift" << shift << endl;
        print << "caesar" << caesar << endl;
        print << "raw" << chat << endl;
    }

    return 0;
}

string caesar(const string& raw, int shift){
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
}

int random(int min, int max){
    return rand() % (max - min + 1) + min;
}