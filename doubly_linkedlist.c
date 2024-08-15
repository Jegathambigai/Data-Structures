#include<stdio.h>
#include<stdlib.h>

void beginsert();
void lastinsert();
void middleinsert();
void begdelete();
void lastdelete();
void middledelete();
void search();
void display();

struct node{
    struct node* prev;
    int data;
    struct node* next;
}Node;

struct node* head;

int main(){
    int ch;
    
    do{
    printf("\n1. Insert at the beginning\n2. Insert at the last\n3. Insert at the middle\n4. Delete at the beginning\n5. Delete at the last\n6. Delete at the middle\n7. Search\n8. Display\n9. Exit");
    printf("\nEnter your choice(0-9):");
    scanf("%d",&ch);
        switch(ch){
            case 1:
                beginsert();
                break;
            case 2:
                lastinsert();
                break;
            case 3:
                middleinsert();
                break;
            case 4:
                begdelete();
                break;
            case 5:
                lastdelete();
                break;
            case 6:
                middledelete();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Please enter the valid input!!!\n");
        }
    }while(ch!=9);
}

void beginsert(){
    int value;
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("OverFlow\n");
    }
    else{
        printf("Enter the data:");
        scanf("%d",&value);
        if(head==NULL){
            newnode->data=value;
            newnode->prev=NULL;
            newnode->next=NULL;
            head=newnode;
        }
        else{
            newnode->data=value;
            newnode->prev=NULL;
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        printf("Head node is Inserted\n");
    }
}

void lastinsert(){
    int value;
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("OverFlow\n");
    }
    else{
        struct node* temp;
        printf("Enter the data:");
        scanf("%d",&value);
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
        printf("Last Node is Inserted\n");
    }
}

void middleinsert(){
    int value,loc,i;
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("OverFlow");
    }
    else{
        struct node* temp,*ptr;
        printf("Enter the Data:");
        scanf("%d",&value);
        printf("Enter the location:");
        scanf("%d",&loc);
        temp=head;
        for(i=1;i<loc;i++){
            if(temp==NULL){
                printf("Cannot Insert\n");
                break;
            }
            else{
                ptr=temp;
                temp=temp->next;
            }
        }
        newnode->data=value;
        newnode->prev=ptr;
        newnode->next=ptr->next;
        ptr->next=newnode;
        temp->prev=newnode;
        printf("Node is Inserted\n");
    }
}

void begdelete(){
    if(head==NULL){
        printf("Doubly Linked List is Empyt\n");

    }
    else{
    struct node* temp;
    temp=head->next;
    temp->prev=NULL;
    free(head);
    head=temp;
    printf("Head node is Deleted\n");
    }
}

void lastdelete(){
    if(head==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        struct node* temp,*ptr;
        temp=head;
        while(temp->next!=NULL){
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=NULL;
        free(temp);
        printf("Last Node is Deleted\n");
    }
}

void middledelete(){
    if(head==NULL){
        printf("Doubly Linked List is Empty");
    }
    else{
        int loc,i;
        struct node* temp,*ptr1,*ptr2;
        printf("Enter the location to Delete:");
        scanf("%d",&loc);
        temp=head;
        for(i=1;i<=loc;i++){
            if(temp==NULL){
                printf("Cannot be Deleted\n");
            }
            ptr1=temp;
            ptr2=temp->prev;
            temp=temp->next;
        }
        ptr2->next=ptr1->next;
        temp->prev=ptr2;
        free(ptr1);
        printf("Node is Deleted\n");
}
}

void search(){
    int value,i=0,f=0;
    if(head==NULL){
        printf("Doubly Linked List is Empty\n");
    }
    else{
        struct node* temp;
        printf("Enter the data to Search:");
        scanf("%d",&value);
        temp=head;
        while(temp->data!=value){
            temp=temp->next;
            i++;
            if(temp->next==NULL&&temp->data!=value){
                printf("Data is not Present\n");
                f=1;
            }
        }
        if(f!=1){
        printf("Data is found at Location: %d\n",i+1);
        }
    }
}

void display(){
    struct node* temp;
    temp=head;
    if(head==NULL){
        printf("Doubly Linked List is Empty\n");
    }
    else{
        while(temp->next!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d->",temp->data);
        printf("NULL\n");
    }
}