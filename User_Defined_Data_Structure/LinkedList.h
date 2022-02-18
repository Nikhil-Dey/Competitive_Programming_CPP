#include<Node.h>

class LinkedList{
    Node* head;
    Node* tail;
    int size;

    public:

    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertNode(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
        size++;
    }

    void deleteNode(int x){
        if(head == NULL || x > size){
            return;
        }

        int i = 0;
        Node* prev = NULL, *temp = head;
        if(x == 1){
            prev = head; 
            head = head -> next;
            delete prev;
        }else{
            while
        }
    }
}