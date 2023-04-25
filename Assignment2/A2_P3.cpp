//
//  main.cpp
//  p3
//
//  Created by Fatma Ahmed on 14/05/2022.
#include <iostream>
using namespace std;
template<class t>
class queue{
    struct node{
        t number;
        node*next;
    };
    node*head=NULL;
    
     int size=0;
   
public:
    int SIZE(){
        return size;
    }
    bool isempty(){
        return head==NULL;
    }

    void pushback(t value){
        size++;
        node*newnode;
        node*last;
        newnode=new node;
        newnode->number=value;
        
        if (head==NULL) {
            head=newnode;
            newnode->next=NULL;
        }
        else
        {
            last=head;
            while (last->next!=NULL) {
                last=last->next;
            }
            last->next=newnode;
            newnode->next=NULL;

        }
    }
    void pop(){
        if (head==NULL) {
            
            cout<<"linked list is empty";
        }
        else{
            
            size--;
            node*first;
            first=head;
            head=first->next;
            delete (first);
            

        }
    }
    t front(){
        if (isempty())
        {
            cout<<"linked list is empty";
            return -1;
        }
        else
        {
            return head->number;
        }
    }
    void display(){
        node*currentnode;
        if (head==NULL) {
            cout<<"linked list is empty";
            
        }
        else{
            currentnode=head;
            while (currentnode!=NULL) {
                cout<<currentnode->number<<endl;
                currentnode=currentnode->next;
            }
        }
    }

    
};
    //##########################################
    class Stack
    {
        queue<int>q;
    public:
        bool empty();
        void push(int val);
        int top();
        void pop();
        void dis();
        
    };
// Returns true if Stack is empty else false
bool Stack::empty(){
    return (q.isempty());
}
// Push operation
void Stack::push(int val)
{
    //  Get current size of queue
    
    // Push the  element
    int s = q.SIZE();
    q.pushback(val);
    
    // Pop (or Dequeue) all previous
    // elements and put them after current
    // element
    for (int i=0; i<s; i++)
    {
        //[1,2]-->[1,2,3]-->[]
        q.pushback(q.front());
                   /*awl element ha push it back*/
        //then delete element khales
        q.pop();
    }
}

// Returns top of stack
int  Stack::top()
{
    if (q.isempty()) {
        return -1;
    }
    else
        return q.front();
}
//pop element
void Stack::pop(){
    if (q.isempty()) {
        cout<<"there is no elements\n";
    }
    else
         q.pop();
}
void Stack::dis(){
    q.display();
}
int main() {
    Stack s;
        s.push(10);
        s.push(20);
        s.push(30);
    cout<<"element:";
    s.dis();
    cout<<"======================\n";
    //[30,20,10]
    cout<<"top:";
    cout << s.top() << endl;
    cout<<"======================\n";
    s.pop();//10,20
    cout<<"after pop element: "<<endl;
    s.dis();
    cout<<"======================\n";
    cout<<"element after push:\n";
        s.push(30);//30,10,20
        s.dis();
    cout<<"======================\n";
        s.pop();//10,20
        cout << s.top() << endl;
        
    return 0;
}
