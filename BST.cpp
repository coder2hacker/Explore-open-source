#include<iostream>
#include<queue>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node*right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}

void inOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	inOrder(root->left);
	cout<< root->data <<" ";
	inOrder(root->right);
}

void preOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<< root->data <<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}
void buildfromOrderLevel(node* &root)
{
	queue<node*>q;
	cout<<"Enter data for root"<<endl;
	int data;
	cin>>data;
	root=new node(data);
	q.push(root);
	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();
		cout<<"Enter left node for "<<temp->data<<endl;
		int leftData;
		cin>>leftData;
		if(leftData!=-1)
		{
			temp->left=new node(leftData);
			q.push(temp->left);
		}
		cout<<"Enter right node for "<<temp->data<<endl;
		int rightData;
		cin>>rightData;
		if(rightData!=-1)
		{
			temp->right=new node(rightData);
			q.push(temp->right);
		}
	}
}
int main()
{
	node* root=NULL;
	buildfromOrderLevel(root);
	levelOrderTraversal(root);
	/*cout<<"....Creating a tree...."<<endl;
	root=buildTree(root);*/
	cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);
    cout << "inorder traversal is:  ";
    inOrder(root); 
    cout << endl << "preorder traversal is:  ";
    preOrder(root); 
    cout << endl << "postorder traversal is:  ";
    postorder(root); 
	return 0;
}
