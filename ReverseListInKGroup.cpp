#include<bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



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



ListNode* reverseLL(ListNode* start, ListNode* end){
    if(start == end){
        return start;
    }
    
    ListNode* newNode = reverseLL(start -> next,end);
    start -> next -> next = start;
    start -> next = NULL;
    return newNode;
}



ListNode* reverseKGroup(ListNode* head, int K) {
    if(head == NULL || head -> next == NULL || K == 0){
        return head;
    }
    
    int k = 0;
    ListNode* temp = head, *prev = NULL;
    while(temp != NULL && k < K){
        prev = temp;
        temp = temp -> next;
        k++;
    }
    ListNode* ans = head;
    if(k == K){
        //ListNode* next = temp -> next;
        ans = reverseLL(head, prev);
        head -> next = reverseKGroup(temp, K);
    }
    return ans;
}



int main(){
    ListNode* head = insertNode();
    printNode(head);
    int k;
    cin>>k;
    ListNode* newNode = reverseKGroup(head, k);
    printNode(newNode);
}
 