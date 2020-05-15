#include <iostream>
using namespace std;
struct Element{
    int data;
    Element *next;
    Element *prev;
};
typedef struct Element element;
struct Queue{
    int n;
    Element *front;
    Element *rear;
};
typedef struct Queue queue;
//create queue;
queue *createQueue();
//add enQueue
void enQueue(queue *q,int newData);
//delete queue
void deQueue(queue *q);
//show data
void showQueue(queue *q);

int main(){
    queue *q;
    q=createQueue();
    enQueue(q,1);
    enQueue(q,1);
    enQueue(q,1);
    enQueue(q,1);
    deQueue(q);
    showQueue(q);

}

queue *createQueue(){
    queue *q;
    q=new queue();
    q->n=0;
    q->front=NULL;
    q->rear=NULL;
    return q;
}

void enQueue(queue *q,int newData){
    element *e;
    if (q->n==0) {
        e=new element();
        e->data=newData;
        e->next=q->front;
        if (q->n==0) {
            q->rear=e;
        }
        if (q->n!=0) {
            q->rear->prev=e;
        }
        q->front=e;
        q->n++;
    }else{
        e=new element();
        e->data =newData;
        e->next =NULL;
        q->rear->next=e;
        e->prev =q->rear;
        q->rear=e;
        q->n++;
    }
}

void deQueue(queue *q){
    element *tmp;
    if (q->n==0) {
        cout<<"Cant delete\n";
    }
    else {
        tmp=q->front;
        q->front=q->front->next;
        if (q->n>=2) {
            q->front->prev=NULL;
        }
        delete tmp;
        if (q->n==1) {
            q->rear=NULL;
        }
        q->n--;
    }
}

void showQueue(queue *q){
    element *tmp;
    tmp = q->front;
    while (tmp!=NULL) {
        cout<<tmp->data<<"\t";
        tmp=tmp->next;
    }
}
