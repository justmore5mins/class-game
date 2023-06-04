#include <cstdlib>
#include <iostream>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <map>
#include "src/command.h"
#include "src/json.hpp"

#define print std::cout

using namespace std;
Caesar caesarenc;
Time timeelem;
string caesar;

int main(int argc, char* argv[]){
    int option;
    bool chatFlag = false;
    string username;
    string chat;
    int shift;

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
        shift = caesarenc.random(1, 10);
        caesar = caesarenc.caesarencode(chat,shift);
    }

    int hoursraw,minutesraw,secondsraw,millisecondsraw;
    timeelem.gettime(hoursraw, minutesraw, secondsraw, millisecondsraw);  
    string hours = to_string(hoursraw);
    string minutes = to_string(minutesraw);
    string seconds = to_string(secondsraw);
    string milliseconds = to_string(millisecondsraw);

    map<string, string> chatdata;

    chatdata["username"] = username;
    chatdata["rawchat"] = chat;
    chatdata["encoded"] = caesar;
    chatdata["shift"] = shift;
    chatdata["hours"] = hours;
    chatdata["minutes"] = minutes;
    chatdata["seconds"] = seconds;
    chatdata["milliseconds"] = milliseconds;


    return 0;
}
