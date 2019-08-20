#ifndef STACK_H__
#define STACK_H__

#include<iostream>

using namespace std;

template<typename T>
struct Node{
    T element;
    Node<T> *next;
};

template<typename T>
class Stack{
    Node<T> *head;
    int sz;

    public :
        Stack():head(nullptr), sz(0){}
        ~Stack();
        
        bool is_empty();
        int size();
        T top();
        void pop();
        void push(T);
        void clean();
};

template<typename T>
Stack<T>::~Stack(){
    if ( head ) clean();
}

template<typename T>
int Stack<T>::size(){
    return sz;
}

template<typename T>
bool Stack<T>::is_empty(){
        return (head == nullptr) ? true : false;
}

template<typename T>
T Stack<T>::top(){
    if ( head == nullptr){
        // throw error ...
        throw(string("Cannot see top of empty stack"));
    }else {
        return head -> element;
    }
}

template<typename T>
void Stack<T>::pop(){
    if ( head == nullptr ){
        // throw error
        throw(string("Cannot pop empty stack"));
    }else {
        Node<T> *tmp = head ;
        head = head -> next;
        delete tmp;
        sz--;
    }
}

template<typename T>
void Stack<T>::push(T val){
    Node<T> *tmp = new Node<T>();
    tmp -> element = val;
    tmp -> next = head;
    head = tmp;
    sz++;
}

template<typename T>
void Stack<T>::clean(){
    Node<T> *tmp;
    while( head ){
        tmp = head;
        head = head -> next;
        delete tmp;
        sz--;
    }
}

// Miscellaneous functions for stack.. 

template<typename T>
void displayStackStats(Stack<T> &st){
    cout << endl << "------------------------------" << endl;
    cout << "Showing Stack basic Stats ...  " << endl;
    cout << "Stack is empty : " << (st.is_empty() ? "true" : "false") << endl;
    cout << "Stack size :" << st.size() << endl;
    cout << "--------------------------------" << endl << endl;
}

#endif
