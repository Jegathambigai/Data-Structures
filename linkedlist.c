#include<stdio.h>
#include<stdlib.h>

void beginsert();
void lastinsert();
void randominsert();
void begdelete();
void lastdelete();
void randomdelete();
void search();
void display();
 
 struct node{
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
                randominsert();
                break;
            case 4:
                begdelete();
                break;
            case 5:
                lastdelete();
                break;
            case 6:
                randomdelete();
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
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL){
        printf("OverFlow\n");
    }
    else{
        int value;
        printf("Enter the data:");
        scanf("%d",&value);
        if(head==NULL){
            newnode->data=value;
           
            newnode->next=NULL;
            head=newnode;
        }
        else{
            newnode->data=value;
            newnode->next=head;
            head=newnode;
            
        }
        printf("Node is Inserted\n");
    }
}
void lastinsert(){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("OverFlow\n");
    }
    else{
        int value;
        struct node* temp;
        printf("Enter the data:");
        scanf("%d",&value);
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newnode->data=value;
        temp->next=newnode;
        newnode->next=NULL;
        printf("Node is Inserted\n");
    }
}
void randominsert(){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("OverFlow\n");
    }
    else{
        int value,loc,i;
        struct node* temp,*ptr;
        
        printf("Enter the data:");
        scanf("%d",&value);
        printf("Enter the location where to insert:");
        scanf("%d",&loc);
        temp=head;
        for(i=1;i<loc;i++){
            if(temp==NULL){
                printf("Cannot insert\n");
                break;
            }
            ptr=temp;
            temp=temp->next;

        }
        newnode->data=value;
        newnode->next=temp;
        ptr->next=newnode;
        
        printf("Node is Inserted\n");
        }
}

void begdelete(){
    struct node* temp,*ptr;
    if(head==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        ptr=head;
        temp=head->next;
        head=temp;
        free(ptr);
        printf("Head Node is Deleted\n");
    }
}
 void lastdelete(){
    struct node* temp,*ptr;
    temp=head;
    while(temp->next!=NULL){
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=NULL;
    free(temp);
    printf("Node is Deleted\n");
 }

 void randomdelete(){
    struct node*temp,*ptr;
    int loc,i;
    printf("Enter the location to Delete:");
    scanf("%d",&loc);
    temp=head;
    for(i=0;i<loc;i++){
        if(temp==NULL){
            printf("Cannot Delete\n");
            break;
        }
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=temp->next;
    free(temp);

 }

 void search(){
    struct node* temp;
    int value,i=0;
    printf("Enter the data to search:");
    scanf("%d",&value);
    temp=head;
    while(temp->data!=value){
        temp=temp->next;
        i++;
        if(temp->next==NULL&&temp->data!=value){
            printf("The data is not present in the Linked List\n");
        }
    }
    if(temp->data==value){
        printf("Element is found at location: %d\n",i+1);
    }
 }

 void display(){
    struct node* temp;
    temp=head;
    if(head==NULL){
        printf("Linked List is Empty\n");
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