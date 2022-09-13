//for deletion in linked list
//first make the linked list and then go for deletion


#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*prev;
    struct node*next;
};

struct node *head,*newnode,*tail ;

void create(){                 
    head=0;
    int ch ;
    printf("enter choice: ");
    scanf("%d",&ch);
    while(ch!=0){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0){
            tail=head=newnode;
        }
        else{
            tail->next=newnode;           //here tail works as temp only
            newnode->prev=tail;
            tail=newnode;
        }
        printf("do u want to continue (1/0): ");
        scanf("%d",&ch);
    }
}


void delete_at_beg(){
    struct node *temp;
    if(head==0){
        printf("list is empty");
    }
    else{
        temp=head;
        head=temp->next;
        head->prev=0;
        free(temp);
    }
}


void delete_from_end(){
    struct node *temp;
    temp=tail;
    tail->prev->next=0;
    tail=tail->prev;
    free(temp);
}


void delete_from_pos(){
    struct node *temp;
    temp=head;
    int i=1;
    int pos;
    printf("\nenter pos: ");
    scanf("%d",&pos);
    while(i<pos){
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}


void display(){
    struct node *temp;
    temp=head;
    printf("\nelements of linked list are\n");
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main(){
    create();
    display();                 //intial display
    delete_at_beg();
    display();               //after deleting from beg
    delete_from_end();
    display();              //after deleting from end
    delete_from_pos();
    display();              //delete fromo paticular pos
}