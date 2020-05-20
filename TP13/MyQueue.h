#include <iostream>
using namespace std;

//create structure of Element
struct Element{
    char        newData_asCharacter;
    Element     *next;
};
typedef struct Element Element;

//Queue structure as linkList
struct Queue{
    int         init__element;
    Element     *front;
    Element     *rear;
};
typedef struct Queue Queue;


//delcare size of the array
const int sizeOfQueue = 2;
struct MyQueue{
    char        myqueue[sizeOfQueue];
    int         REAR,FRONT;
};
struct MyQueue queueFirst;

//create empty queue
Queue *createQueue(){
    Queue *queueList;               //create new queue
    queueList = new Queue();

    queueList->init__element = 0;
    queueList->front = NULL;
    queueList->rear = NULL;
    return queueList;
}

//start with add end of queue
void enqueue(Queue *queueList, int newData){
    //create new Element
    Element *newElement;

    if (queueList->init__element == 0) {
        newElement = new Element();

        newElement->newData_asCharacter = newData;
        newElement->next = queueList->front;
        queueList->front = newElement;

        if (queueList->init__element == 0)
            queueList->rear = newElement;
        queueList->init__element++;
    }else{
        newElement = new Element();

        newElement->newData_asCharacter = newData;
        newElement->next = NULL;

        queueList->rear->next = newElement;
        queueList->rear = newElement;
        queueList->init__element++;
    }
}

//create dequeue
void dequeue(Queue *queueList){
    //create temporary Element to delete front to reserve memory
    Element *temporary;
    temporary = queueList->front;

    if (queueList->init__element == 0) {        //check if there is no data in queue tell them u cant delete
        cout<<"you cant delete.There is no data"<<endl;
    }else{
        queueList->front = queueList->front->next;
        delete temporary;
        if (queueList->init__element == 1){
            queueList->rear = NULL;
        }
        queueList->init__element--;
    }
}

//create displayQueue
void displayQueue(Queue *queueList){
    Element *temporary;         //create temporary to store front;

    temporary = queueList->front;
    while (temporary != NULL) {
        cout<<temporary->newData_asCharacter<<"\t";
        temporary = temporary->next;
    }
    cout<<endl;
}

//create emty queue;
void isEmptyQueue(){
    queueFirst.FRONT = -1;
    queueFirst.REAR = -1;
}

//create enqueue
void enqueueAsArray(char newData){
    if (queueFirst.REAR == sizeOfQueue - 1) {
        cout<<"Data overflow"<<endl;
    }else if (queueFirst.FRONT == -1) {
        queueFirst.myqueue[0] = newData;
        queueFirst.FRONT = 0;
        queueFirst.REAR = 0;
    }else{
        queueFirst.REAR++;
        queueFirst.myqueue[queueFirst.REAR] = newData;
    }
}

//delete data from queue
void dequeueAsArray(){
    if (queueFirst.REAR >= 0 && queueFirst.FRONT <= queueFirst.REAR) {
        queueFirst.myqueue[queueFirst.FRONT] = -1;
        queueFirst.FRONT++;
    }else{
        cout<<"Data underflow"<<endl;
    }
}

//show display queue as array
void showMyQueue(){
    for (int i = queueFirst.FRONT; i <= queueFirst.REAR; i++) {
        cout<<queueFirst.myqueue[i]<<"\t";
    }
    cout<<endl;
}
