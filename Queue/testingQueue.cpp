#include <iostream>
using namespace std;
//size of the array
const int SIZE=10;
struct Queue{
    int front, rear;
    int Q[SIZE];
};
struct Queue q1;

void checkEmptyQueue(){
    q1.front=-1;
    q1.rear=-1;
}

void enQueue(int data){//insert data into Queue end
    if(q1.rear==SIZE-1){
        cout<<"Can not add data. Data overflow.\n";
    }
    else if (q1.front==-1) {
        q1.Q[0]=data;
        q1.front=0;
        q1.rear=0;
    }else {//at least one data in the queue
        q1.rear=q1.rear+1;
        int index=q1.rear;
        q1.Q[index]=data;
    }
}

void deQueue(){
    if (q1.rear>=0&&q1.front<=q1.rear) {
        q1.Q[q1.front]=0;//replace 0 to that data
        q1.front=q1.front+1;//increment one to run the front to next so first data will delete
    }else{
        cout<<"Can not deQueue. Data overflow.\n";
    }
}
void displayQ(struct Queue q){
    for (int i = q1.front; i <=q1.rear; i++) {
        cout<<q1.Q[i]<< " ";
    }
    cout<<endl;

}
int main(){
    checkEmptyQueue();
    enQueue(3);
    enQueue(5);
    enQueue(7);

    displayQ(q1);
    enQueue(0);
    displayQ(q1);
    deQueue();
    displayQ(q1);
    deQueue();
    displayQ(q1);
    deQueue();
    displayQ(q1);
    deQueue();
    displayQ(q1);
    deQueue();
}
