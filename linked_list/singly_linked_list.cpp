/*
 *   author: rohanraut
 *   created on: 29.03.2022 18:38:32
 */

#include <bits/stdc++.h>

using namespace std;

// Creating structure of a Node in linked list
struct Node
{
    int data;
    Node *next;
};

// Traversing in the linked list
void traverse(Node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}


// Insertion at the end of Linked List
void insertAtEnd(Node *head, int data){
    while(head->next!=NULL){
        head=head->next;
    }
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    head->next = new_node;

}

Node* insertAtBeginning(Node *head, int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

Node* insertAtIndex(Node *head, int data, int index){
    Node *new_node = new Node();
    new_node->data=data;
    int i=0;
    Node *p = head;
    while(i<index-1){
        p=p->next;
        i++;
    }
    new_node->next = p->next;
    p->next = new_node;
    return head;
}

Node* insertAfterNode(Node *head, int data, Node *preNode){
    Node *new_node = new Node();
    new_node->data=data;
    new_node->next=preNode->next;
    preNode->next=new_node;
    return head;
}


int main()
{
    // Declaring a Linked List
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *fifth = new Node();

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = fifth;
    fifth->data = 50;
    fifth->next = NULL;

    cout<<"Traversing in a Linked List: ";
    traverse(head);

    insertAtEnd(head,60);

    cout<<"After Insertion At the End of Linked List: ";
    traverse(head);

    head = insertAtBeginning(head,100);
    cout<<"After Insertion At the Beginning of Linked List: ";
    traverse(head);

    head = insertAtIndex(head,200,3);
    cout<<"After Insertion At the Index: ";
    traverse(head);

    head = insertAfterNode(head,300,fourth);
    cout<<"Insertion of Node after a specific Node: ";
    traverse(head);

    return 0;
}