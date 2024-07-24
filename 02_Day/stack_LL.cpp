/*
creating stack using Linked  Lists and performing operations on them 
*/

#include<bits/stdc++.h>
using namespace std;


class Node{
  public:
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr){}
};

class Stack{
  private:
    Node* top;
  
  public:
    Stack() : top(nullptr) {}

  // push using LL
  void push(int x){
    Node *t = new Node(x);
    if(t==NULL){
      cout<<"stack overflow\n";
      return;
    }
    t->data = x;
    t->next = top;
    top = t;
  }

  void Display(){
    struct Node *p;
    p=top;
    while(p!=nullptr){
      cout<<p->data<<" ";
      p = p->next;
    }
    cout<<endl;
  }

  // pop using LL
  int pop(){
    int x = -1;
    Node *p;
    if(top==nullptr){
      cout<<"stack is empty";
    }
    else{
      p=top;
      x = p->data;
      top = top->next;
      free(p);
    }
    return x;
  }
};

int main(){
  Stack st;
  st.push(10);
  st.push(11);
  st.push(12);
  st.push(13);
  st.push(14);
  st.Display();
  st.pop();
  st.Display();
}