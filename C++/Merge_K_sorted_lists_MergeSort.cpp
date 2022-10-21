#define Node ListNode
ListNode* merge(ListNode* list1, ListNode* list2) {
    Node* nwhead = new Node(-1);
    Node* tmp = nwhead;
    Node* lst1 = list1;
    Node* lst2 = list2;
    while (lst1 != NULL and lst2 != NULL) {
        if (lst1->val <= lst2->val) {
            tmp->next = lst1;
            tmp = tmp->next;
            lst1 = lst1->next;
        } else {
            tmp->next = lst2;
            tmp = tmp->next;
            lst2 = lst2->next;
        }
    }
    if (lst1 == NULL)
        tmp->next = lst2;
    else
        tmp->next = lst1;
    return nwhead->next;
}

Node* mergeSort(vector<Node*> &a, int l, int h) {
    \
    if (l == h)
        return a[l];
    if (l < h) {
        int mid = l + (h - l) / 2;
        Node* left = mergeSort(a, l, mid); //returns the sorted list from l to mid as a single list
        Node* right = mergeSort(a, mid + 1, h); //returns the sorted list from mid+1 to h as a single list
        return merge(left, right); //merge both of them
    }
    return NULL;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    return mergeSort(lists, 0, lists.size() - 1); //this function returns a single sorted lists merged from l to h
}

//TC - O(n*k*logk) where k is the number of lists and n is the max size of each list
//SC - O(n*k)