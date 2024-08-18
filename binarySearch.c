#include<stdio.h>
int main(){
    int n,a[100],i,j,b,l,r,mid,key,f=0;
    printf("Enter the array size:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    l=0;
    r=n-1;
    printf("Enter the key to search:");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                b=a[i];
                a[i]=a[j];
                a[j]=b;
            }
        }
    }
    
    while(l<=r){
    mid=(l+r)/2;
    if(a[mid]==key){
        printf("%d is Found",key);
        f=1;
        break;
    }
    else{
        if(a[mid]>key){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    }
    if(f==0){
        printf("%d is not found",key);
    }
return 0;
}