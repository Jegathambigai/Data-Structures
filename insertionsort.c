#include<stdio.h>
int main(){
    int n,a[100],i,j,b,key;
    printf("Enter the array size:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    printf("After Sorting:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}