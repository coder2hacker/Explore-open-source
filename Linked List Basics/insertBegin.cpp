//Given a Linked List and an Integer x, we need to insert a new node with value x at start of the linked list...

Node *insertBegin(Node *head, int x) {
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

int main()
{
    Node *head = NULL;
    head = insertBegin(head, 30);
    head = insertBegin(head, 20);
    head = insertBegin(head, 10);
  
    return 0;
}
