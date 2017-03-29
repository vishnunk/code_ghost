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
struct node *head1 = NULL;
struct node *head2 = NULL;

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

void print_list_ref(struct node *temp){
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
    head2 = prev;
}

struct node * get_middle_node(int count){
    int middle_count;
    int loop = 0;
    struct node *temp = head;
   
    if(count%2 == 0)
        middle_count = count/2;
    else
        middle_count = (count - 1)/2;
    
    printf("count %d middle %d\n", count, middle_count);
    while(loop != middle_count){
        temp = temp->next;
        loop++;
    }
    middle = temp;
    return middle;
}
void compare_list(struct node *temp1, struct node *temp2){
    int flag = 0;
    while(temp1 != NULL || temp2 != NULL){
        if(temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
            flag++;
        }
        else
        {
            flag = 0;
            break;
        }
    }    
    if(flag)
        printf("The given linked list is a perfect palindrome\n");
    else
        printf("The give linked list is not a palindrome\n");
}

int main(int argc, char **argv){
    int count, middle;

    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    insert_end(3);
    insert_end(2);
    insert_end(1);
    insert_end(4);
    print_list();
    
    count = list_length();
    printf("Length of the given linked list is %d\n", count);
    
    head1 = head;

    struct node *middle_node = get_middle_node(count);
    printf("Middle node is %d\n", middle_node->data);
        
    reverse_list(&middle_node);

    print_list_ref(head1);
    print_list_ref(head2);
    compare_list(head1, head2);
    return 0;
}
