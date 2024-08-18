#include<stdio.h>
int main(){
    int n,a[100],i,j,b;
    printf("Enter the array size:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                b=a[j];
                a[j]=a[j+1];
                a[j+1]=b;
            }
        }
    }
    printf("After sorting:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}