/*
 * Implement a function to check whether a linked list is palindrome or not.
 *
 *  1. Get middle node of the linked list.
 *  2. Reverse the second half of the linked list.
 *  3. Check if both halves are identical or not.
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *middle = NULL;

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

int list_length(){
    int count = 0;
    struct node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void reverse_list(struct node **temp){
    struct node *prev = NULL;
    struct node *curr = *temp;
    struct node *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *temp = prev;
}

struct node * get_middle_node(int count){
    int middle_count;
    int loop = 0;
    struct node *temp = head;
    
    if(count/2 == 0)
        middle_count = count/2 + 1;
    else
        middle_count = count/2 - 1;
    
    while(loop != middle_count){
        temp = temp->next;
        loop++;
    }
    middle = temp;
    return middle;
}

int main(int argc, char **argv){
    int count, middle;

    insert_end(1);
    insert_end(2);
    insert_end(3);
    //insert_end(5);
    insert_end(3);
    insert_end(2);
    insert_end(1);
    print_list();
    
    count = list_length();
    printf("Length of the given linked list is %d\n", count);
    
    struct node *middle_node = get_middle_node(count);
    printf("Middle node is %d\n", middle_node->data);
    
    reverse_list(&middle_node);
    print_list();
    return 0;
}
