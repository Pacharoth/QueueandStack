#include "MyQueue.h"
#include "MyStack.h"
#include <cstring>

//create reverseString with display
void reverse_string(Stack *stackList, string checking){
    Element *temporary;
    temporary = stackList->top;
    int i;

    //input into stack
    for (i = 0; i < checking.length(); i++) {
        push(stackList, checking[i]);
    }

    //reverse string
    cout<<"\nAfter reverse"<<endl;
    displayStack(stackList);

}


int main(int argc, char const *argv[]) {
    //declare variablle to check reverse of string
    string checkingString = "Hello";
    string reverseString;
    Stack *stackList;
    stackList = isEmpty();


    cout<<"Before resverse"<<endl;
    cout<<checkingString;
    reverse_string(stackList, checkingString);

    return 0;
}
