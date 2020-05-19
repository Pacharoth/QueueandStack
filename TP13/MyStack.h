#include <iostream>
using namespace std;

//create structure stack
struct Stack{
    int          init__element;
    Element      *top;
};
typedef struct Stack Stack;

//create empty Stack
Stack *isEmpty(){
    Stack *stackList;           //create new stack
    stackList = new Stack();

    stackList->init__element = 0;
    stackList->top = NULL;
    return stackList;
}

//create push
void push(Stack *stackList, char newData){
    Element *newElement;            //create element to put data in stack;
    newElement = new Element();

    newElement->newData_asCharacter = newData;
    newElement->next = stackList->top;
    stackList->top = newElement;
    stackList->init__element++;
}

//create pop
void pop(Stack *stackList){
    if (stackList->init__element == 0) {        //check if there no data in stack
        cout<<"No Data cant pop more";
    }else{
        Element *temporary;
        temporary = stackList->top;

        stackList->top = stackList->top->next;
        delete temporary;
        stackList->init__element--;
    }
}

//create displayStack
void displayStack(Stack *stackList){
    Element *temporary;
    temporary = stackList->top;
    while (temporary != NULL) {
        cout<<temporary->newData_asCharacter<<"\t";
        temporary=temporary->next;
    }
    cout<<endl;
}
