#include <iostream>

using namespace std;

class Caesar{
    public:
        string caesarencode(const string& raw, int shift);
        int random(int min, int max);
};

class Time{
    public:
    void gettime(int& hours, int& minutes, int& seconds, int& milliseconds);
};