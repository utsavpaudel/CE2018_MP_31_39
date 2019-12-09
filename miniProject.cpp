#include<iostream>
using namespace std;

void newCustomer(){
    //push();
    cout<< "***->->->Wait for your turn<-<-<-***" <<endl <<endl <<endl;
}

void callCustomer(){
    //pop();
    cout << /*pop()*/ ",go to the counter"<<endl<<endl <<endl ;
}
int main(){
    int a;
    loop:
    cout<<"Enter 0 for getting a token"<<endl;
    cout<<"Enter 1 to call a customer" <<endl;
    cout<<"Enter 9 to terminate the program "<<endl;
    cin>>a;
    if (a==0){
        newCustomer();
        goto loop;
    }
        else if(a==1){
        callCustomer();
        goto loop;
        }
        else if(a==9){
        goto loop2;
        }
            else{
                cout<<"Enter correct command"<<endl;
                goto loop;
            }
loop2:
cout<<"The token service is currently off" <<endl;



}