#include <iostream>
#include <fstream>
#include <cstdlib>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <map>
#include "src/jsoncpp/include/json/writer.h"
#include "src/command.h"

#define print std::cout

using namespace std;
using namespace Json;

Caesar caesarenc;
Time timeelem;
string caesar;

struct  Node
{
    string key,value;
    Node(const string& k, const string& v: key(k),value(v)){}
};
bool operator<(const Node& a, const Node&b){
    return  stoi(a.key) < stoi(b.key);
};

int main(int argc, char* argv[]){
    int option;
    bool chatFlag = false;
    string username;
    string chat;
    string shift;

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
        int shiftraw = caesarenc.random(1, 10);
        caesar = caesarenc.caesarencode(chat,shiftraw);
        shift = to_string(shiftraw);
    }

    int hoursraw,minutesraw,secondsraw,millisecondsraw;
    timeelem.gettime(hoursraw, minutesraw, secondsraw, millisecondsraw);  
    string hours = to_string(hoursraw);
    string minutes = to_string(minutesraw);
    string seconds = to_string(secondsraw);
    string milliseconds = to_string(millisecondsraw);

    map<string, Node, bool(*)(const Node&, const Node&)> chatdata(&operator<);

    chatdata["1"] = Node("username",username);
    chatdata["2"] = Node("rawchat",chat);
    chatdata["3"] = Node("caesar",caesar);
    chatdata["4"] = Node("shift",shift);
    chatdata["5"] = Node("hours",hours);
    chatdata["6"] = Node("minutes",minutes);
    chatdata["7"] = Node("seconds",seconds);
    chatdata["8"] = Node("milliseconds",milliseconds);

    Json chatdatajson;

    StyledWriter writer;
    string jsonString = writer.write(chatdatajson);

    ofstream outputFile("chat.json");
    if(outputFile.is_open()){
        outputFile << jsonString;
        outputFile.close();
    }
}

