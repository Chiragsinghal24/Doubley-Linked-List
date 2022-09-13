// #include <stdio.h>
// #include <stdlib.h>

// struct node{
//     int data;
//     struct node*prev;
//     struct node*next;
// };

// struct node *head,*newnode;

// void create(){
//     struct node *temp;
//     head=0;
//     int ch ;
//     printf("enter choice: ");
//     scanf("%d",&ch);
//     while(ch!=0){
//         newnode=(struct node*)malloc(sizeof(struct node));
//         printf("enter data: ");
//         scanf("%d",&newnode->data);
//         newnode->prev=0;
//         newnode->next=0;
//         if(head==0){
//             temp=head=newnode;
//         }
//         else{
//             temp->next=newnode;
//             newnode->prev=temp;
//             temp=newnode;
//         }
//         printf("do u want to continue (1/0): ");
//         scanf("%d",&ch);
//     }
// }

// void display(){
//     struct node *temp;
//     temp=head;
//     printf("elements of linked list are\n");
//     while(temp!=0){
//         printf("%d ",temp->data);
//         temp=temp->next;
//     }
// }

// int main()
// {
//     create();
//     display();
// }
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


void display(){
    struct node *temp;
    temp=head;
    printf("elements of linked list are\n");
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main(){
    create();
    display();
}