/*
 *  Implement Linked List in C.
 *  Insert, Delete, Print
 */

#include <stdio.h>

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

void print_list(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv){
    insert_begin(4);   
    insert_begin(5);   
    insert_begin(6);
    insert_end(1);
    insert_end(2);
    print_list();
    return 0;
}
