#include "miniProject.cpp"

int main(){
    int a;
    Queue q;

    loop:
    cout<<"Please enter 0 for getting a token"<<endl;
    cout<<"Please enter 1 to call a customer" <<endl;
    cout<<"Please enter 9 to terminate the program (For Bank administrator only)"<<endl;
    cin>>a;
    if (a==0){
        q.enqueue();
        goto loop;
    }
        else if(a==1){
        q.dequeue();
        goto loop;
        }
        else if(a==9){
        goto loop2;
        }
            else{
                cout<<"Enter correct command,sir"<<endl <<endl;
                goto loop;
            }
loop2:
cout<<"***->->-> The token service is currently off. Any inconvinience caused is highly regretted. <-<-<-***" <<endl <<endl <<endl;

}