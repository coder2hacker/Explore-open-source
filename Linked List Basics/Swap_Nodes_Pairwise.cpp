// C++ program to pairwise swap elements
// in a given linked list
#include <bits/stdc++.h>
using namespace std;

/* A linked list node */
class Node {
public:
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Function to pairwise swap elements of a linked list */
void pairWiseSwap(Node* head)
{
	Node* temp = head;

	/* Traverse further only if
	there are at-least two nodes left */
	while (temp != NULL && temp->next != NULL) {
		/* Swap data of node with
		its next node's data */
		swap(temp->data,
			temp->next->data);

		/* Move temp by 2 for the next pair */
		temp = temp->next->next;
	}
}

/* Function to pairwise swap elements
of a linked list. It returns head of
the modified list, so return value 
of this node must be assigned */
node* pairWiseSwap(node* head)
{
    // If linked list is empty or there is only one node in list
    if (head == NULL || head->next == NULL)
        return head;
   
    // Initialize previous and current pointers
    node* prev = head;
    node* curr = head->next;
   
    head = curr; // Change head before proceeding
   
    // Traverse the list
    while (true) {
        node* next = curr->next;
        curr->next = prev; // Change next of
        // current as previous node
   
        // If next NULL or next is the last node
        if (next == NULL || next->next == NULL) {
            prev->next = next;
            break;
        }
   
        // Change next of previous to next of next
        prev->next = next->next;
   
        // Update previous and curr
        prev = next;
        curr = prev->next;
    }
    return head;
}

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

int main()
{
	Node* start = NULL;

	/* The constructed linked list is:
	1->2->3->4->5 */
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	printList(start);
	pairWiseSwap(start);
	printList(start);

	return 0;
}