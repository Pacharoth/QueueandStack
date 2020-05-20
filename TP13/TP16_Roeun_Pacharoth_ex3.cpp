#include "MyQueue.h"
#include <cstring>

//create checking string
void checkingString(Queue *queueList, string checking){
    for (int i = 0; i < checking.length(); i++) {
        if (checking[i] >= 'A' && checking[i] <= 'Z' || checking[i] >= 'a' && checking[i] <= 'z') {
            enqueue (queueList, checking[i]);
        }else if (checking[i] == '*') {
            dequeue (queueList);
        }
    }
}

int main(int argc, char const *argv[]) {
    //declare queue and checking string
    string initailizeString = "EAS*Y*QUE***ST***IO*N*****";
    Queue *queueList;
    queueList = createQueue();

    checkingString(queueList,initailizeString);
    return 0;
}
