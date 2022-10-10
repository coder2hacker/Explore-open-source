#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
 
class SGTNode
{
    public:
        SGTNode *right, *left, *parent;
        int value;
        SGTNode()
        {
            value = 0;
            right = NULL;
            left = NULL;
            parent = NULL;
        }
        SGTNode(int val)
        {
            value = val;
            right = NULL;
            left = NULL;
            parent = NULL;
        }
};
 
//creating class for scapegoattree
class ScapeGoatTree
{
    private:
        SGTNode *root;
        int n, q;
    public:
        ScapeGoatTree()
        {
            root = NULL;
            n = 0;
        }
 
        // Function to check if tree is empty
        bool isEmpty()
        {
            return root == NULL;
        }
 
        // clear  tree
        void makeEmpty()
        {
            root = NULL;
            n = 0;
        }
 
        //count number of nodes recursively
        int size(SGTNode *r)
        {
            if (r == NULL)
                return 0;
            else
            {
                int l = 1;
                l += size(r->left);
                l += size(r->right);
                return l;
            }
        }
 
        //search for an element
        bool search(int val)
        {
            return search(root, val);
        }
 
        //searching an element recursively
        bool search(SGTNode *r, int val)
        {
            bool found = false;
            while ((r != NULL) && !found)
            {
                int rval = r->value;
                if (val < rval)
                    r = r->left;
                else if (val > rval)
                    r = r->right;
                else
                {
                    found = true;
                    break;
                }
                found = search(r, val);
            }
            return found;
        }
 
        // return current size of tree
        int size()
        {
            return n;
        }
 
        
        void inorder()
        {
            inorder(root);
        }
        void inorder(SGTNode *r)
        {
            if (r != NULL)
            {
                inorder(r->left);
                cout<<r->value<<"   ";
                inorder(r->right);
            }
            else
                return;
        }
 
        
        void preorder()
        {
            preorder(root);
        }
        void preorder(SGTNode *r)
        {
            if (r != NULL)
            {
                cout<<r->value<<"   ";
                preorder(r->left);
                preorder(r->right);
            }
            else
                return;
        }
 
        
        void postorder()
        {
            postorder(root);
        }
        void postorder(SGTNode *r)
        {
            if (r != NULL)
            {
                postorder(r->left);
                postorder(r->right);
                cout<<r->value<<"   ";
            }
            else
                return;
        }
 
        static int const log32(int q)
        {
            double const log23 = 2.4663034623764317;
            return (int)ceil(log23 * log(q));
        }
 
        // Function to insert an element
        bool add(int x)
        {
           
            SGTNode *u = new SGTNode(x);
            int d = addWithDepth(u);
            if (d > log32(q))
            {
                
                SGTNode *w = u->parent;
                while (3 * size(w) <= 2 * size(w->parent))
                    w = w->parent;
                rebuild(w->parent);
            }
            return d >= 0;
        }
 
        
        void rebuild(SGTNode *u)
        {
            int ns = size(u);
            SGTNode *p = u->parent;
            SGTNode **a = new SGTNode* [ns];
            packIntoArray(u, a, 0);
            if (p == NULL)
            {
                root = buildBalanced(a, 0, ns);
                root->parent = NULL;
            }
            else if (p->right == u)
            {
                p->right = buildBalanced(a, 0, ns);
                p->right->parent = p;
            }
            else
            {
                p->left = buildBalanced(a, 0, ns);
                p->left->parent = p;
            }
        }
 
       
        int packIntoArray(SGTNode *u, SGTNode *a[], int i)
        {
            if (u == NULL)
            {
                return i;
            }
            i = packIntoArray(u->left, a, i);
            a[i++] = u;
            return packIntoArray(u->right, a, i);
        }
 
        
        SGTNode *buildBalanced(SGTNode **a, int i, int ns)
        {
            if (ns == 0)
                return NULL;
            int m = ns / 2;
            a[i + m]->left = buildBalanced(a, i, m);
            if (a[i + m]->left != NULL)
                a[i + m]->left->parent = a[i + m];
            a[i + m]->right = buildBalanced(a, i + m + 1, ns - m - 1);\
            if (a[i + m]->right != NULL)
                a[i + m]->right->parent = a[i + m];
            return a[i + m];
        }
 
        
        int addWithDepth(SGTNode *u)
        {
            SGTNode *w = root;
            if (w == NULL)
            {
                root = u;
                n++;
                q++;
                return 0;
            }
            bool done = false;
            int d = 0;
            do
            {
                if (u->value < w->value)
                {
                    if (w->left == NULL)
                    {
                        w->left = u;
                        u->parent = w;
                        done = true;
                    }
                    else
                    {
                        w = w->left;
                    }
                }
                else if (u->value > w->value)
                {
                    if (w->right == NULL)
                    {
                        w->right = u;
                        u->parent = w;
                        done = true;
                    }
                    else
                    {
                        w = w->right;
                    }
                }
                else
                    return -1;
                d++;
            }
            while (!done);
            n++;
            q++;
            return d;
        }
};
 
int main()
{
    ScapeGoatTree sgt;
    cout<<"ScapeGoat Tree Test"<<endl;
    char ch;
    int val;
    //Performing tree operations
    do
    {
        cout<<"\nScapeGoat Tree Operations\n";
        cout<<"1. Insert "<<endl;
        cout<<"2. Count nodes"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Check empty"<<endl;
        cout<<"5. Make empty"<<endl;
        int choice;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1 :
            cout<<"Enter integer element to insert: ";
            cin>>val;
            sgt.add(val);
            break;
        case 2 :
            cout<<"Nodes = " <<sgt.size()<<endl;
            break;
        case 3 :
            cout<<"Enter integer element to search: ";
            cin>>val;
            if (sgt.search(val))
                cout<<val<<" found in the tree"<<endl;
            else
                cout<<val<<" not found"<<endl;
            break;
        case 4 :
            cout<<"Empty status = ";
            if (sgt.isEmpty())
                cout<<"Tree is empty"<<endl;
            else
                cout<<"Tree is non - empty"<<endl;
            break;
        case 5 :
            cout<<"\nTree cleared\n";
            sgt.makeEmpty();
            break;
        default :
            cout<<"Wrong Entry \n ";
            break;
        }
 
        //Displaying Tree
        cout<<"\nPost order : ";
        sgt.postorder();
        cout<<"\nPre order : ";
        sgt.preorder();
        cout<<"\nIn order : ";
        sgt.inorder();
        cout<<"\nDo you want to continue (Type y or n) \n";
        cin>>ch;
    }
    while (ch == 'Y'|| ch == 'y');
    return 0;
}
