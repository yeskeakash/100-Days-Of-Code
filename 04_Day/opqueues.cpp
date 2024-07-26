#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    
    public:
        // parameterised constructor
        Queue(int size){
            this->size = size;
            front = rear = -1;
            Q = new int[size];
        }

        // destructor
        ~Queue(){
            delete [] Q;
        }

        //cheking if queue is empty
        bool empty(){
            if(front == rear)
                return 1;
            return 0;
        }

        //check if queue is full
        bool full(){
            if(rear == size-1)
                return 1;
            return 0;
        }

        //insert element in queue
        void enqueue(int x){
            if(full())
                cout<<"queue is full!!"<<endl;
            else{
                rear++;
                Q[rear] = x;
            }
        }

        //delete element from queue
        int dequeue(){
            int x = -1;
            if(empty())
                cout<<"queue is empty!!"<<endl;
            else{
                front++;
                x = Q[front];
            }
            return x;
        }

        void display(){
            for(int i = front+1; i<=rear; i++){
                cout<<Q[i];
                if (i < rear){
                    cout << " <- ";
                }
            }
            cout << endl;
        }
};


int main(){

    Queue q(5); // Create a queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}