#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};

void print(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
         temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* head,int data){
    Node* temp=head;

    int length=0;

    while(temp!=NULL){
        length++;
        temp=temp->next;

    }
    return length;
}

void InsertAthead(Node* &head, int d){
    Node* temp=new Node(d);

    temp->next=head;
    head->prev=temp;
    head=temp;

}

void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);

    tail->next=temp;
    temp->prev=tail;
    tail=temp;

}

void insertAtposition(Node* tail, Node* head,int position, int data){
    
    if(position==1){
        InsertAthead(head,data);
        return;
    }

    Node* temp=head;

    int count=1;

    while(count<position-1){
        temp=temp->next;
        count++;
    }

    //insert at last position

    if(temp->next==NULL){
        insertAtTail(tail,data);
        return;
    }
  


    //insering at any position
    Node* nodeToInsert=new Node(data);

    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    nodeToInsert->prev=temp;
    temp->next=nodeToInsert;

}

int main(){
    Node* node1=new Node(10);
   
    Node* head=node1;
    Node* tail=node1;
     
    print(head);

    InsertAthead(head,13);
    print(head);

    InsertAthead(head,16);
    print(head);

    InsertAthead(head,21);
    print(head);

    insertAtTail(tail,29);
    print(head);

    insertAtposition(tail,head,2,110);
    print(head);

    insertAtposition(tail,head,5,125);
    print(head);


    return 0;
} 