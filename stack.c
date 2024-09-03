#include<stdio.h>
#include<stdlib.h>
#define max 8

int top=-1,stack[100];

void push();
void pop();
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
                push();
                break;
            case 2:
                pop();
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
    if(top==-1){
        return 1;
    }
    return 0;
}

int isfull(){
    if(top==max-1){
        return 1;
    }
    return 0;
}

void push(){
    if(isfull()==0){
        int data;
        printf("Enter the data to Push:");
        scanf("%d",&data);
        top=top+1;
        stack[top]=data;
        printf("%d is pushed\n",data);
    }
    else{
        printf("Stack is Full\n");
    }
}

void pop(){
    if(isempty()==0){
        printf("%d is poped\n",stack[top]);
        top=top-1;;
    }
    else{
        printf("Stack is Empty\n");
    }
}

void search(){
    if(isempty()==0){
        int data,i,f=0;
        printf("Enter the data to Search:");
        scanf("%d",&data);
        for(i=0;i<=top;i++){
            if(stack[i]==data){
                printf("Data is Found at Location: %d\n",i+1);
                f=0;
                break;
            }
            else{
                f=1;
            }
        }
        if(f==1){
            printf("Data is not Found\n");
        }
    }
    else{
        printf("Stack is Empty\n");
    }
}

void display(){
    if(isempty()==0){
        int i;
        printf("Stack elements are:\n");
        for(i=0;i<=top;i++){
            printf("%d ",stack[i]);
        }
    }
    else{
        printf("Stack is Empty\n");
    }
}