#include <iostream>
#include <getopt.h>

#define print std::cout

using namespace std;

int main(int argc, char* argv[]){
    int option;
    string username;

    while((option = getopt(argc,argv,"u:")) != -1){
        switch (option){
        case 'u':
            username = optarg;
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

    return 0;
}