#include<iostream>
using namespace std;
//node class
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    //destructor
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory is free for"<<val<<endl;
    }
};
//print the list
void print(Node* &head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//insert at head
void insert_at_head(Node* &head,int d){
    Node *new_node=new Node(d);
    if(head==NULL){
        head=new_node;
    }
    else{
    new_node->next=head;
    head=new_node;
    }
    
}
//insert at tail
void insert_at_tail(Node*& tail,int d){
    Node *new_node=new Node(d);
    if(tail==NULL){
        tail=new_node;
    }
    else{
        tail->next=new_node;
        tail=new_node;
    }
}
//insert at any position in the list
void insert_at_any_position(Node *&tail,Node * &head,int d,int pos){
    if(pos==1){
        insert_at_head(head,d);
        return;
    }
    else{
        //at tail or any position
        Node *new_node=new Node(d);
        Node *temp=head;
        int count=1;
        while(count<pos-1){
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL){
            temp->next=new_node;
            temp=new_node;
            tail=new_node;
        }
        else{
        new_node->next=temp->next;
        temp->next=new_node;
        }
        

    }
}

//Delete a Node
void delete_a_node(Node*&head,Node*&tail,int pos){
    if(pos==1){
        Node * temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node*prev=NULL;
        Node*curr=head;
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }
        if(curr->next==NULL){
            prev->next=curr->next;
            tail=prev;
        }
        else{
            prev->next=curr->next;
        }
        curr->next=NULL;
        delete curr;
    }
}
//driver code
int main(){
    Node *node1=new Node(10);
    Node* head=node1;
    Node *tail=node1;
    print(head);
    insert_at_head(head,20);
    print(head);
    insert_at_tail(tail,30);
    print(head);
    insert_at_any_position(tail,head,40,4);
    print(head);
    delete_a_node(head,tail,4);
    print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    return 0;
}