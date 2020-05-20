#include "MyQueue.h"
#include "MyStack.h"

const int sizeChecking = 5;
int leftNumber[sizeChecking];
int rightNumber[sizeChecking];

//push those symbol
void leftPush(Stack *stackList, string checking){
    leftNumber[0] = 0;
    leftNumber[1] = 0;
    for (int i = 0; i < checking.length(); i++) {
        if (checking[i] == '(') {
            push(stackList, checking[i]);
            leftNumber[0]++;
        }else if (checking[i] == '{') {
            push(stackList, checking[i]);
            leftNumber[1]++;
        }
    }
}

//checking the right
void checkingStack(string checking){
    rightNumber[0] = 0;
    rightNumber[1] = 0;
    for (int i = 0; i < checking.length(); i++) {
        if (checking[i] == ')') {
            rightNumber[0]++;
        }else if (checking[i] == '}') {
            rightNumber[1]++;
        }
    }
}

//we check the symbol and pop
void rightpopAndcheck(Stack *stackList, string checking){
    //run function left push and check
    int notEqual = 1;
    leftPush(stackList, checking);
    checkingStack(checking);

    //checking
    for (int i = 0; i < checking.length(); i++) {
        if (rightNumber[0] == leftNumber[0]&& checking[i] == ')') {
            pop(stackList);
            notEqual = 0;
        }else if (rightNumber[1] == leftNumber[1] && checking[i] == '}') {
            pop(stackList);
            notEqual = 0;
        }else{
            notEqual = 1;
        }
    }
    cout<<"The result after checking and pop"<<endl;
    if (notEqual == 1) {
        cout<<"Unbalance"<<endl;
    }else{
        cout<<"Balance"<<endl;
    }
    displayStack(stackList);
}


int main(int argc, char const *argv[]) {
    string initailizeString = "{()}{}()";
    Stack *stackList;
    stackList = isEmpty();

    cout<<"Before checking push and pop"<<endl<<initailizeString<<endl;
    rightpopAndcheck(stackList, initailizeString);


    return 0;
}
