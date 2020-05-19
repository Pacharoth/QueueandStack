#include "MyQueue.h"
#include "MyStack.h"
#include <cstring>

//create function checking
void checkingString(string checking){
    for (int i = 0; i < checking.length() ; i++) {
        if (checking[i] >= 'A' && checking[i] <= 'Z' || checking[i] >= 'a' && checking[i] <= 'z') {
            mypush(checking[i]);
            displayStackAsArray();
        }else if (checking[i] == '*') {
            mypop();
        }
    }

}

int main(int argc, char const *argv[]) {
    string initialize_string = "EAS*Y*QUE***ST***IO*N*****";
    stackFirst.top = -1;

    checkingString(initialize_string);
    return 0;
}
