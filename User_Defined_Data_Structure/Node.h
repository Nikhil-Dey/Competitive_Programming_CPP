class Node{
    int val;
    Node* next;

public:

    Node(){
        val = 0;
        next = nullptr;
    }

    Node(int val){
        this -> val = val;
        this -> next = nullptr;
    }

    Node(int val, Node* next){
        this -> val = val;
        this -> next = next;
    }

};