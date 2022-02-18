#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    ListNode* newNode = NULL;
    ListNode* newTemp = NULL;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1 -> val >= temp2 -> val){
            cout<<temp1 -> val <<endl;
            ListNode* node = new ListNode(temp2 -> val);
            if(newNode == NULL){
                newNode = node;
                newTemp = newNode;
            }else{
                newTemp -> next = node;
                newTemp = newTemp -> next;
            }
            temp2 = temp2 -> next;
        }else{
            cout<<temp2 -> val<<endl;
            ListNode* node = new ListNode(temp1-> val);
            if(newNode == NULL){
                newNode = node;
                newTemp = newNode;
            }else{
                newTemp -> next = node;
                newTemp = newTemp -> next;
            }
            temp1 = temp1 -> next;
        }
    }
    
    if(temp1 != NULL){
        newTemp -> next = temp1;
    }else if(temp2 != NULL){
        newTemp -> next = temp2;
    }
    
    return newNode;
}

ListNode* input(){
    ListNode* head = NULL;
    ListNode* temp = NULL;
    int x;
    cin>>x;
    while(x != -1){
        ListNode* newNode = new ListNode(x);
        if(head == NULL){
            head = newNode;
        }else{
            temp -> next = newNode;
        }
        temp = newNode;
        cin>>x;
    }
    return head;
}

void print(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    ListNode* list1 = input();
    ListNode* list2 = input();
    ListNode* head = mergeTwoLists(list1,list2);
    print(head);
}