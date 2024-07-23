/*
create display push pop peek isEmpty isFull operations on stack using array
*/

#include <iostream>
using namespace std;

class stack{
private:
    int size;
    int top;
    int *s;//pointer to an array

public:
    stack(int size){
        this->size = size;
        this->top = -1;
        this->s = new int[size];
    }

    ~stack(){
        delete[] s;
    }

    void display(){
        for(int i=top; i>=0; i--){
            cout<<s[i]<<" ";
        }
        cout<<"\n";
    }

    void push(int x){
        if(top == size-1){
            cout<<"stack overflow\n";
        }
        else{
            top++;
            s[top] = x;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"stack underflow\n";
        }
        else{
            top--;
        }
    }

    int peek(int pos){
        int x = -1;
        if(top-pos+1<0||pos==0){
            // return -1;
            cout<<"invalid";
        }
        else{
        x = s[top-pos+1];
        }
        return x;
    }

    bool isEmpty(){
        if(top<0){
            return 1;
        }
        else{
            return 0;
        }
    }

    int isFull() {
    if (top == size-1){
        return 1;
    }
    return 0;
}
};

int main(){
    int size = 4;
    stack st(size);

    st.push(10);
    // st.push(15);
    // st.push(8);
    // st.push(20);
    // st.push(50);

    st.display();
    // st.pop();
    // st.display();
    cout<<"element is: "<<st.peek(0)<<endl;
    cout<<"stack empty: "<<st.isEmpty()<<endl;
    cout<<"stack Full: "<<st.isFull()<<endl;
    return 0;
}
