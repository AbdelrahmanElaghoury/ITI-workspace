//
//  stack_implementation.cpp
//  data_structure_and_algorithms
//
//  Created by Abdelrahman Hassan on 30/12/2021.
//

#include "stack_implementation.hpp"
#include <iostream>
#include <string>

template <class dtype>

class stack{
    int top;
    dtype items[MAX_SIZE];
public:
    stack():top(-1){}
    
    void push(dtype element){
        if(top >= MAX_SIZE-1){
            std::cout << "Stack Is Full" << std::endl;
        }
        else{
            top++;
            items[top] = element;
        }
    }
    
    bool is_embty(){
        return top < 0;
    }
    
    void get_top(dtype&stackTop){
        if(is_embty()){
            std::cout << "Stack Is Empty" << std::endl;
        }
        else{
            stackTop = items[top];
            std::cout << stackTop << std::endl;
        }
    }
    
    void pop(dtype&Element){
        if(is_embty()){
            std::cout << "Stack Is Empty" << std::endl;
        }
        else{
            Element = items[top];
            top--;
        }
    }
    
    void print(){
        std::cout << "[";
        for(int i = top; i>=0; i--){
            std::cout << items[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
};

template <class dtype>
class stack_linked_list{
    struct node{
        dtype item;
        node * next;
    };
    node *top, *cur;
public:
    stack_linked_list(){
        top = NULL;
    }
    
    void push(dtype newItem){
        node *newElement = new struct node;
        if(newElement == NULL){
            std::cout << "Stack cannot allocate memory" << std::endl;
        }
        else{
            newElement->item = newItem;
            newElement->next = top;
            top = newElement;
        }
    }
    
    bool is_embty(){
        return top==NULL;
    }
    
    void pop(){
        if(is_embty()){
            std::cout << "Stack Is Empty" << std::endl;
        }
        else{
            node * temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }
    
    dtype get_top(){
        if(is_embty()){
            std::cout << "Stack Is Empty" << std::endl;
        }
        else{
            std::cout << top->item << std::endl;
            return top->item;
        }
        
    }
    
    void print(){
        cur = top;
        std::cout <<"[";
        while(cur != NULL){
            std::cout << cur->item << " ";
            cur = cur->next;
        }
        std::cout <<"]" << std::endl;
    }
};
