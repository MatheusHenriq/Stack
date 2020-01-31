#include <iostream> 
#include <stdlib.h>
#include <exception>
#include <math.h>


struct Node{
    Node* next;
    int key;    
};

class Stack{
private:
    Node* top;
    int count;

public:
    Stack(){
        top = NULL;
        count = 0;
    }

    ~Stack(){
        DeleteStack();
    }

    int Push(int k){
        Node* n = new Node;
        Node* aux = top;

        n->key = k;
        n->next = top;
        top = n;
        count++;       

        return 1;    
    }

    int Pop(){
        Node* curr = top;
        Node* aux;
        int x;

        x = curr->key;
        aux = top->next;
        top = aux;
        delete curr;
        count--;
        
        if(IsEmpty()){
            char e[200] = "Cannot Delete an item in an empty stack";
            throw std::underflow_error(e);
        }

        return x;
    }

    void Show(){
        Node* curr = top;
        while(curr!=NULL){
            std::cout<<curr->key<<std::endl;
            curr=curr->next;
        }
        std::cout<<'\n';
    }

    int IsEmpty(){
        if(count == 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    void DeleteStack(){
        Node* curr = top;
        Node* aux;

        while(curr!=NULL){
            aux = curr->next;
            delete curr;
            curr = aux;
        }

        top = NULL;
        count = 0;   
    }

    int BinaryConversion(int n){
        Stack stack;
        int m;
        int c = -1;
        int i;
        int aux = n;
        while(aux != 0){
            i = aux%2;
            stack.Push(i);
            aux = aux/2;
            c++;
        }

        i = 0;

        while(!stack.IsEmpty()){
            m = pow(10,c);
            aux = stack.Pop();
            i += aux*m;
            c--;
        }

        return i;  

    }

};

int main(){
    Stack t;
    t.Push(1);
    t.Push(2);
    t.Push(3);
    t.Push(4);
    t.Show();
    t.Pop();
    t.Show();


    return 0;
}