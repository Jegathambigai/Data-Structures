#include<stdio.h>
#include<stdlib.h>
#define max 8

int front=-1,rear=-1,queue[100];

void enqueue();
void dequeue();
void search();
void display();
int isempty();
int isfull();

int main(){
    int ch;
    do{
    printf("\n1. Push\n2. Pop\n3. Search\n4. Display\n5. Exit");
    printf("\nEnter your choice(0-5):");
    scanf("%d",&ch);
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Please enter the valid input!!!\n");
        }
    }while(ch!=5);
}

int isempty(){
    if(front==rear){
        return 1;
    }
    return 0;
}

int isfull(){
    if(rear==max-1){
        return 1;
    }
    return 0;
}

void enqueue(){
    if(isfull()==0){
        int data;
        printf("Enter the data to Enqueue:");
        scanf("%d",&data);
        rear=rear+1;
        queue[rear]=data;
        printf("%d is Enqueued\n",data);
    }
    else{
        printf("Queue is Full\n");
    }
}

void dequeue(){
    if(isempty()==0){
        front=front+1;
        printf("%d is Dequeued\n",queue[front]);
    }
    else{
        printf("Queue is Empty\n");
    }
}

void search(){
    if(isempty()==0){
        int data,i,f=0;
        printf("Enter the data to Search:");
        scanf("%d",&data);
        for(i=front+1;i<=rear;i++){
            if(queue[i]==data){
                printf("%d is Found\n",data);
                f=1;
                break;
            }
        }
        if(f==0){
            printf("%d is not Found\n",data);
        }
    }
}

void display(){
    if(isempty()==0){
        int i;
        printf("Queue Elements are: ");
        for(i=front+1;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        
    }
    else{
        printf("Queue is Empty\n");
    }
}