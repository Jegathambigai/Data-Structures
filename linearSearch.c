#include<stdio.h>
int main(){
    int n,a[100],i,j,mid,key,f=0;
    printf("Enter the array size:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the key to search:");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(a[i]==key){
            printf("%d is found");
            f=1;
        }
    }
    if(f==0){
        printf("%d is not found",key);
    }
    return 0;
}