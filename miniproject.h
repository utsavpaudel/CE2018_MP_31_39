class Node{
    public:
        int token_number;
        std::string customer_name;
        Node *next;
};

class Queue{
    public:
        Queue();
        ~Queue();
        
        void enqueue(std::string name);
        void dequeue();
        bool isEmpty();
    
    private:
    	Node* queue;
    	int token;
        
};

