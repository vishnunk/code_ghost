/*
 * Implement a function to check whether a linked list is palindrome or not.
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insert_begin(int n){
    struct node *temp;
    if(head == NULL){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        head = tail =  temp;
    }
    else{
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        temp->next = head;
        head = temp;
    }
}

void insert_end(int n){
    struct node *temp;
    if(head == NULL){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        head = tail = temp;
    }
    else{
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

void delete_node(int n){
    struct node *prev = NULL;
    struct node *curr = head;
    while(curr != NULL){
        //Delete head.
        if(prev == NULL && curr->data == n){
            head = curr = curr->next;
        }
        else if(curr->data == n && prev != NULL){
            prev->next = curr->next;
            curr = curr->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
}

void print_list(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv){
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(3);
    insert_end(2);
    insert_end(1);
    print_list();
    return 0;
}
