#include <iostream>
#include <getopt.h>

#define print std::cout

using namespace std;

int main(int argc, char* argv[]){
    int option;
    bool chatFlag = false;
    string username;
    string chat;

//使用者的程式
    while((option = getopt(argc,argv,"ur:")) != -1){
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
        print << "Chat: " << chat << endl;
    }

    return 0;
}