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


void insert_at_beg(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data: ");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}


void insert_at_end(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data: ");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}


void insert_at_pos(){
    struct node *temp;
    temp=head; 
    int pos;
    int i=1;
    printf("\nenter position: ");            //insert at 3
    scanf("%d",&pos);
    if(pos==1){
        insert_at_beg();
    }
    else{
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next=0;
        newnode->prev=0;
        printf("\nenter data: ");
        scanf("%d",&newnode->data);
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
    }
}


void insert_after_pos(){
    struct node *temp;
    temp=head; 
    int pos;
    int i=1;
    printf("\nenter position: ");            //insert after 2
    scanf("%d",&pos);
    
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=0;
    newnode->prev=0;
    printf("\nenter data: ");
    scanf("%d",&newnode->data);
    while(i<pos){                    //this changes only everything remains same
        temp=temp->next;
        i++;
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->next->prev=newnode;
}



void display(){
    struct node *temp;
    temp=head;
    printf("elements of linked list are\n");
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main()
{
    create();
    display();           // intial dispaly
    insert_at_beg();
    display();           //after insertion at beg 
    insert_at_end();
    display();           //after insertion at end
    insert_at_pos();
    display();          //after insertion at pos
    insert_after_pos();
    display();           //inisertion after a pos
    return 0;
}
