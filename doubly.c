#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *temp1=NULL,*temp2=NULL, *head=NULL, *newnode=NULL;

void insertion_big();
void insertion_data();
void insertion_end();
void delete_big();
void delete_data();
void delete_end();
void traversal();
void main(){
int a,b,c;

while(1)
{
menu:
printf("\n----------------LINKED LIST MENU----------------------\n");
printf("1. Traversal/Display\n");
printf("2. Insertion\n");
printf("3. Deletion\n");
printf("0. Exit\n");
printf("enter the operation do you to perform\n");
scanf("%d",&a);
switch(a)
        {

    case 1: traversal();
            break;
    case 2: while(1){

            printf(" \n--------------------INSERTION MENU-------------------\n");// insertion
            printf("1. Traversal \n");
            printf("2. Insertion at the beginning\n");
            printf("3. Insertion at the end\n");
            printf("4. Insertion after a particular element\n");
            printf("9. previous \n");
            printf("0. exit\n");
            printf("Enter the operation do you to perform:\n");
            scanf("%d",&b);
            switch(b){
                case 1: traversal();
                        break;
                case 2: insertion_big();
                        break;
                case 3: insertion_end();
                        break;
                case 4: insertion_data();
                        break;
                case 9: goto menu;
                case 0: exit(1);
                default: printf("invalid option\n");
                        break;
            }
    }
            break;
    case 3: while(1){
            printf(" \n--------------------DELETION MENU-------------------\n");
            printf("1. Traversal \n");
            printf("2. Deletion at the beginning\n");
            printf("3. Deletion at the end\n");
            printf("4. Deletion a particular element\n");
            printf("9. previous \n");
            printf("0. exit\n");
            printf("Enter the operation do you to perform\n");
            scanf("%d",&c);
            switch(c){
                case 1: traversal();
                        break;
                case 2: delete_big();
                        break;
                case 3: delete_end();
                        break;
                case 4: delete_data();
                        break;
                case 9: goto menu;
                case 0: exit(1);
                default: printf("invalid option\n");
                        break;
            }
    }
            break;
    case 0: exit(1);
    default:printf("Invalid option\n");
            break;
}
}
}
// traversal
void traversal(){
    struct node *temp1;
    temp1=head;
    if(head==NULL){
        printf("\nNO Element Found\n");

    }

    else{
        while(temp1!=NULL){
            printf("%d\t",temp1->data);
            temp1=temp1->next;
        }
    }

}

void insertion_big(){
    struct node *temp1=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the new element\n");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=newnode;
        head->prev=NULL;
        head->next=NULL;
    }
    else{
        newnode->next=head;
        head=newnode;
        newnode->prev=NULL;
        newnode->next->prev=newnode;
    }
    temp1=head;
    while(temp1!=NULL){
        printf("%d\t",temp1->data);
        temp1=temp1->next;
    }

}

void insertion_end(){
    struct node *temp1=head,*temp2;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the new element\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        head->prev=NULL;
        head->next=NULL;

    }
    else{
        while(temp1->next!=NULL){
            temp1=temp1->next;

        }
        newnode->prev=temp1;
        temp1->next=newnode;

        temp1=head;
        while(temp1!=NULL){
            printf("%d\t",temp1->data);
            temp1=temp1->next;

            }
    }

}

void insertion_data(){

    struct node *temp1=head;
    int d;
    newnode=(struct node *) malloc(sizeof(struct node));
    printf("Enter the element to be inserted:\n");
    scanf("%d",&newnode->data);
    printf("The data added to the front of the current data");
    scanf("%d",&d);
    if(head==NULL){
        printf("insert element in beginning or end");
        return 0;
    }
    else{
        while(temp1->next!=NULL){
            if(temp1->data==d){
                temp1->next->prev=newnode;
                newnode->prev=temp1;
                newnode->next=temp1->next;
                temp1->next=newnode;
            }
            temp1=temp1->next;
        }
    }
    temp1=head;
    while(temp1!=NULL){
        printf("%d\t",temp1->data);
        temp1=temp1->next;

        }
    }

void delete_big(){
    if(head==NULL){
        printf("deletion is not possible");
        return 0;
    }
    head->next->prev=NULL;
    head=head->next;
    temp2=head;
    while(temp1!=NULL){
        printf("%d\t",temp1->data);
        temp1=temp1->next;
        }

}

void delete_end(){
struct node *temp1=head;
if(head==NULL){
    printf("deletion is not possible\n");
    return 0;
}
else{
    while(temp1->next->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=NULL;
    temp1=head;
    while(temp1!=NULL){
    printf("%d\t",temp1->data);
    temp1=temp1->next;

}
}

void delete_data()
{
    struct node *temp1, *temp2;
    int val;
    printf("Enter the value");
    scanf("%d",&val);
    temp2 = head;
   if(head==NULL){
        printf("deletion is not possible\n");
        return 0;
    }
    else if(head->data==val){
        delete_big();

    }
    else{
        temp1=head;
        while(temp1->next->data!=val){
            temp1=temp1->next;
        }
        if(temp1->next->next==NULL){
            temp1->next=NULL;
            temp1=head;
            return 0;

        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        temp2->next->prev=temp1;
        free(temp2);

    }
    temp1=head;
    while(temp1!=NULL){
        printf("%d\t",temp1->data);
        temp1=temp1->next;
        }
}
