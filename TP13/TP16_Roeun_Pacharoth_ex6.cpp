#include "MyQueue.h"
#include "MyStack.h"

//convert nummber to character
char convertToCharacter(int number){
    char convert;
    if (number == 1) {
        convert = '1';
    }else if (number == 0) {
        convert = '0';
    }
    return convert;
}

int main(int argc, char const *argv[]) {
    int remainder,number=10;
    char convertNumber;
    Stack *stackList;
    stackList = isEmpty();

    cout<<"Before push"<<endl;
    while (number != 0) {
        remainder = number % 2;
        number /= 2;
        convertNumber = convertToCharacter(remainder);
        cout<<remainder;
        push(stackList, convertNumber);
    }
    cout<<endl;
    cout<<"After push"<<endl;
    displayStack(stackList);
    return 0;
}
