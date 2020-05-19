#include <iostream>
using namespace std;

const int sizeOfStack = 10;

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

//create struct stack using array
struct MyStack{
    char        mystack[sizeOfStack];
    int         top;
};
struct MyStack stackFirst;


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
        temporary = temporary->next;
    }
    cout<<endl;
}
//create stack isEmpty

void push(char newData){
    if (stackFirst.top > sizeOfStack-1) {
        cout<<"Data overflow"<<endl;
    }else{
        stackFirst.top = stackFirst.top+1;
        stackFirst.mystack[stackFirst.top] = newData;
    }
}

void pop(){
    if (stackFirst.top>=0) {
        stackFirst.mystack[stackFirst.top] = -1;
        stackFirst.top--;
    }else{
        cout<<"Data underflow"<<endl;
    }
}
