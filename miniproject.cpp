#include <iostream>
#include "miniproject.h"

Queue::Queue(){
    queue=NULL;
    token=0;
}

Queue::~Queue(){
    
}

bool Queue::isEmpty(){
    if(queue==NULL){
        return true;
    }
    else{
        return false;
    }
}


void Queue::enqueue(std::string name){
    token+=1;
	Node* newNode= new Node();
	newNode->token_number=token;
    newNode->customer_name=name;
    if(isEmpty()){
        newNode->next=newNode;
        queue=newNode;
    }
    else{
        newNode->next=queue->next;
        queue->next=newNode;
        queue=newNode;
    }   
    std::cout<<"Your Token Number is "<<token<<". Have a good day. THANK YOU"<<std::endl;
}

void Queue::dequeue(){
    int data;
    std::string n;
    if(isEmpty()){
        std::cout<<"No customers to be served."<<std::endl;
    }
    else{
    	Node* f=queue->next;
        data=f->token_number;
        n=f->customer_name;
        queue->next=f->next;
        if(f==queue){
            queue=NULL;
        }
		std::cout<<"***->->-> Token No.:"<<data<<". Mr. "<<n<<", Please proceed. <-<-<-***"<<std::endl;
    }
    
}

int main(){
	char choice;
    int a;
    Queue q;

    do{
    	int pin=0;
		std::cout<<std::endl;
		std::cout<<"\t******************************"<<std::endl;
    	std::cout<<std::endl<<"Please enter 0 for getting a token(For Customers Only)"<<std::endl;
    	std::cout<<"Please enter 1 to call a customer(For Bank Purpose Only)" <<std::endl;
    	std::cout<<"Please enter 9 to terminate the program (For Bank administrator Only)"<<std::endl;
   		std::cin>>a;
   		switch(a){
   			case 0:
   				{
   				std::cin.ignore();
   				std::string N;
        		std::cout<<std::endl<<"What should we call you?"<<std::endl;
        		std::getline(std::cin, N);
        		q.enqueue(N);
        		choice='y';
        		break;
        	}
        	case 1:
        	{
        		std::cout<<"Enter the pin code\t";
        		std::cin>>pin;
        		if(pin==1111){
        			q.dequeue();
				}
        		else{
        			std::cout<<"***->->->Invalid Pin Number. Please Try Again<-<-<-***"<<std::endl;
				}
        		choice='y';
        		break;
        	}
        	case 9:
        	{
        		
        		std::cout<<"Enter the pin code\t";
        		std::cin>>pin;
        		if(pin==20562056){
        			std::cout<<"***->->-> The token service is currently shut down. Any inconvinience caused is highly regretted. <-<-<-***" <<std::endl <<std::endl <<std::endl;
					choice='n';
				}
        		else{
        			std::cout<<"***->->->Invalid Pin Number. Please Try Again<-<-<-***"<<std::endl;
					choice='y';
				}
        		break;
        	}
        	default:
        		{
        		std::cout<<"\tEnter correct command,sir"<<std::endl <<std::endl;
        		choice='y';
        		break;
			}
			
		}
    	}while(choice=='y'||choice=='Y');
}
    



