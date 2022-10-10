#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    bool lFlag, rFlag;
};

Node *Insert(Node *dummy, Node *root) 
{

    Node *ptr;
    Node *parent_of_newnode = NULL;
    queue<Node *> q;
    int x;
    cout << "Enter the value of root : ";
    cin >> x;
    Node *temp = new Node;
    temp->data = x;
    temp->llink = true;
    temp->rlink = true;

    dummy->left = temp;
    root = temp;
    temp->left = dummy;
    temp->right = dummy;

    Node *t;
    q.push(root);
    while (!q.empty())
    {
        ptr = q.front();
        q.pop();
        cout << "Enter left child of node " << ptr->data << " / Enter -1 if no child " << " : ";
        cin >> x;
        if (x != -1)
        {
            //creating a new node
            t = new Node;
            t->data = x;
            //as the new node is leaf node so intially its links will be true
            t->llink = true;
            t->rlink = true;
    
            t->left = ptr->left;
            ptr->left = t;
            t->right = ptr;
            ptr->llink = false;
            q.push(t); //Enqueue the newly created node again into queue.
        }
        cout << "Enter right child of node " << ptr->data << " / Enter -1 if no child " << " : ";
        cin >> x;
        if (x != -1)
        {
            //creating a new node
            t = new Node;
            t->data = x;
            //as the new node is leaf node so intially its links will be true
            t->llink = true;
            t->rlink = true;
            t->right = ptr->right;
            ptr->right = t;
            t->left = ptr;
            ptr->rlink = false;
            q.push(t);
        }
    }
    return root;
}

Node *InorderSuccessor(struct Node *ptr) 
{
    if (ptr->rlink == true)
    {
        //true means that node does not have any child and it has a link to inorder successor
        return ptr->right;
    }
    //else return inorder successor
    ptr = ptr->right;
    while (ptr->llink == false)
        ptr = ptr->left;
    return ptr;   //this in inorder successor of ptr
}

void Inorder(Node *dummy, Node *root)
{
    Node *t = root;
    if (root == NULL)
    {
        cout << "EMPTY\n";
        return;
    }
    while (t->llink == false)
    {
        t = t->left;
    }
    while (t != dummy)
    {
        cout << t->data << " ";
        t = InorderSuccessor(t);
    }
}

void Preorder(Node *dummy, Node *root)
{
    Node *t = root;
    while (t != dummy)
    {
        cout << t->data << " ";
        if (t->llink == false)
            t = t->left;
        else
        {
            t = t->right;
            if ((t->rlink == true && t->llink == false) || (t->rlink == false && t->llink == false))
            {
                while (t->right != NULL && t->rlink != false)
                {
                    t = t->right;
                }
                t = t->right;
            }
        }
    }
}

int main()
{
    Node *dummy = new Node;
    dummy->right = dummy;
    Node *root = NULL;

    int choice, value;
    do
    {
        cout << '\n';
        cout << "1.Create a TBT\n";
        cout << "2.Inorder Traversal\n";
        cout << "3.Preorder Traversal\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            root = Insert(dummy, root);
            break;
        case 2:
            cout << "Inorder Traversal of the tree is : ";
            Inorder(dummy, root);
            cout << "\n";
            break;
        case 3:
            cout << "Preorder Traversal of the tree is : ";
            Preorder(dummy, root);
            cout << "\n";
            break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}
 