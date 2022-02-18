#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeElements(ListNode* head, int val) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr != NULL){
        if(curr -> val == val){
            ListNode* deleteNode = curr;
            if(prev == NULL){
                curr = curr -> next;
                head = curr;
                continue;
            }else{
                prev -> next = curr -> next;
            }
            delete deleteNode;
        }
        prev = curr;
        curr = curr -> next;
    }
    return head;
}

ListNode* insertNode(){
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int data;
    cin>>data;
    while(data != -1){
        ListNode* curr = new ListNode(data);
        if(head == NULL)
        {
            head = curr;
            tail = curr;
        }else{
            tail -> next = curr;
            tail = curr;
        }
        cin>>data;
        delete curr;
    }
    return head;
}

void printNode(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp -> val<< " ";
        temp = temp -> next;
    }
    cout<<endl;
}


int main(){
    ListNode* head = insertNode();
    printNode(head);
    int val;
    cin>>val;
    ListNode* newHead = removeElements(head,val);
}