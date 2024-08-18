#include<stdio.h>
int main(){
    int n,a[100],i,j,b,min_index;
    printf("Enter the array size:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        min_index=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min_index]){
                b=a[min_index];
                a[min_index]=a[j];
                a[j]=b;
            }
        }
    }
    printf("After Sorting:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}