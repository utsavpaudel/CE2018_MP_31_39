#include <iostream>
#include "miniproject.h"

/*
	CONSTRUCTOR FOR CLASS QUEUE
	here initially the queue is initialized to NULL and token is initialized to 0 i.e. there is no customers
*/
Queue::Queue(){
    queue=NULL;
    token=0;
}

/*
	DECONSTRUCTOR OF CLASS QUEUE
*/
Queue::~Queue(){
    
}

/*
	If the queue is NULL i.e. there is no customer then it returns true otherwise it returns false
*/
bool Queue::isEmpty(){
    if(queue==NULL){
        return true;
    }
    else{
        return false;
    }
}

//Inserting the customer's name, token number of the customer into the queue
void Queue::enqueue(std::string name){
    token+=1;
	Node* newNode= new Node(); 																//Creating a new node
	newNode->token_number=token;															//Assigning the token number to the node
    newNode->customer_name=name;															//Assigning the customer's name to the node
    /*
    	If the customer is the first to arrive
	*/
	if(isEmpty()){
        newNode->next=newNode;																//The node points to itself and is assigned as queue
        queue=newNode;
    }
    else{
        newNode->next=queue->next;															//The last entered node points to the first entered node
        queue->next=newNode;																
        queue=newNode;
    }   
    std::cout<<"Your Token Number is "<<token<<". Have a good day. THANK YOU"<<std::endl;	//Displays the respective token number assigned to the customer
}

/*
Displaying the customer's name, token number of the customer from the queue
*/
void Queue::dequeue(){
    int data;
    std::string n;
    
    //If there are no customers's
    if(isEmpty()){
    	/*If true then displays there are no customers to be served*/
        std::cout<<"No customers to be served."<<std::endl;
    }
    else{
    	/*If false then stores the token number in data variable and customers name in n variable and removes the current node from the queue*/
    	Node* f=queue->next;
        data=f->token_number;
        n=f->customer_name;
        queue->next=f->next;
        if(f==queue){
            queue=NULL;
        }
		std::cout<<"***->->-> Token No.:"<<data<<". Mr. "<<n<<", Please proceed. <-<-<-***"<<std::endl;	 	//Displays the customer's name and their corresponding token number 
    }
    
}

int main(){
	char choice;
    int a;
    Queue q;

    do{
    	int pin=0;																							//Stored the security pin iven to Bank Staffs and Bank Administrator 
		/*
			Displays the options for the customers Bank Staff and Bank Administrator and takes the input from the user
		*/
		std::cout<<std::endl;
		std::cout<<"\t******************************"<<std::endl;
    	std::cout<<std::endl<<"Please enter 0 for getting a token(For Customers Only)"<<std::endl;
    	std::cout<<"Please enter 1 to call a customer(For Bank Purpose Only)" <<std::endl;
    	std::cout<<"Please enter 9 to terminate the program (For Bank administrator Only)"<<std::endl;
   		std::cin>>a;
   		
   		/*
   			Serlects the case to be executed according to the input given the user
   		*/
   		switch(a){
   			/*
   				For the Customers. If given input is 0, then the customers name is asked and is assigned a particular token number
   			*/
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
        	/*
        		For the Bank staff. Tf  the given input is 1, then the customers name and their corresponding token number are callled out on basis of First Come First serve
        	*/
        	case 1:
        	{
        		std::cout<<"Enter the pin code\t";
        		std::cin>>pin;																		//Asks for the security pin
        		/*
        			if the pin is correct then the function is executed, else error is displayed
				*/
				if(pin==1111){
        			q.dequeue();																	//customers name and their corresponding token number are callled out on basis of First Come First serve		
				}
        		else{
        			std::cout<<"***->->->Invalid Pin Number. Please Try Again<-<-<-***"<<std::endl;	//Error Displayed
				}
        		choice='y';
        		break;
        	}
        	
        	
        	/*
        		For the Bank Administrator. if the given input is 9, then the program terminates
        	*/
        	
        	case 9:
        	{
        		
        		std::cout<<"Enter the pin code\t";
        		std::cin>>pin;																				//Asks for the security pin
        		/*
        			if the pin is correct then the program terminates, else error is displayed and the program doesnot terminates
				*/
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
        	/*
        	If given input doesnot match any of the above cases then default case is executed where the user is asked to give correct input as per the above option
        	*/
        	default:
        		{
        		std::cout<<"\tEnter correct command,sir"<<std::endl <<std::endl;
        		choice='y';
        		break;
			}
			
		}
    	}while(choice=='y');
}
    



