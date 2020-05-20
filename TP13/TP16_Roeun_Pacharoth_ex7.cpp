#include "MyQueue.h"
#include "MyStack.h"

//create multiple pop
void STACKmultiple(Stack *stackList,int k){
    for (int i = 0; i < k; i++) {
        pop(stackList);
    }
}

int main(int argc, char const *argv[]) {
    //declare the number they wanna pop
    int numberElment=2;
    Stack *stackList;
    stackList = isEmpty();

    push (stackList, 'A');
    push (stackList, 'B');
    push (stackList, 'C');
    displayStack (stackList);
    cout<<"We pop is "<<numberElment<<" element(s)"<<endl;
    STACKmultiple (stackList, numberElment);
    displayStack (stackList);
    return 0;
}
