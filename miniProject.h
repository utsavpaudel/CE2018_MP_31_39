#define MaxCustomer 5
class Queue{
    public:
    Queue();
    ~Queue();
    void enqueue();
    void dequeue();
    bool isEmpty();
    bool isFull();
   
    private:
    int data[MaxCustomer];
    int front;
    int rear;
};