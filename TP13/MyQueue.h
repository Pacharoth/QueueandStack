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
        cout<<"you cant delete";
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
