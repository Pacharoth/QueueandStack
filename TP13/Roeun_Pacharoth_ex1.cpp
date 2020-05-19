#include "MyQueue.h"
#include "MyStack.h"

int main(int argc, char const *argv[]) {
    Queue *queueList;
    queueList = createQueue();
    Stack *stackList;
    stackList = isEmpty();

    //initailize queue
    enqueue(queueList,'A');
    enqueue(queueList,'P');
    enqueue(queueList,'P');
    enqueue(queueList,'L');
    enqueue(queueList,'E');
    cout<<"The result of queue"<<endl;
    displayQueue(queueList);
    dequeue(queueList);
    displayQueue(queueList);

    //initailize stack;
    push(stackList,'H');
    push(stackList,'A');
    push(stackList,'P');
    push(stackList,'P');
    push(stackList,'Y');
    cout<<"The result of stack"<<endl;
    displayStack(stackList);
    pop(stackList);
    displayStack(stackList);

    return 0;
}
