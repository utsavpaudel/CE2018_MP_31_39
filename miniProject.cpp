#include<iostream>
#include "miniProject.h"
using namespace std;
Queue::Queue(){
    front = -1;
    rear = -1;
}

bool Queue::isFull(){
    return rear>= MaxCustomer-1;
}
bool Queue::isEmpty(){
    return (front==rear);
}

void Queue::enqueue(){
    if(isFull()){
        cout << "***->->->Cannot Serve you today. Customer to be served is limited. Please contact Bank Manager <-<-<-***"<<endl <<endl <<endl;
    }
    else{
        rear+= 1;
        int CustomerNum = rear+1;
        data[rear] = CustomerNum;
        cout<< "***->->->Wait for your turn at " <<CustomerNum  <<" <-<-<-***" <<endl <<endl <<endl;
    }
}

void Queue::dequeue(){
    if (isEmpty()){
        cout<<"***->->-> No customer to be served <-<-<-***"<<endl <<endl <<endl;
    }
    else{
        front+=1;
        int CustomerCalled = data[front];
        cout <<"Customer "<<CustomerCalled <<" ,go to the counter"<<endl<<endl <<endl ;
    }
}
Queue::~Queue(){}

