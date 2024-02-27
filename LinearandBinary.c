#include<stdio.h>
#include<stdlib.h>
int linse(int *arr, int key, int n);
int binse(int *arr, int key, int n);
int main()
{
    int *arr, n, key, i, c;
    printf("Enter the limit number: ");
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int)*n);
    printf("Enter %d elements: ", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    printf("Choose \n 1. Linear search \n 2. Binary search \n 3. Exit \n Your Choice:");
    scanf("%d",&c);
    switch(c)
    {
        case 1: i = linse(arr,key,n);
        break;
        case 2: i = binse(arr,key,n);
        break;
        case 3: free(arr); return 0;
    }
    if(i!=-1)
    {
        printf("%d was found at %d!!", key,i);
    }
    else
    {
        printf("%d was not found!!", key);
    }
    free(arr);
    return 0;
}

int binse(int *arr, int key, int n)
{
    int i, f=0, l=n-1, m;
    for(i=0;i<n;i++)
    {
        m = (f+l)/2;
        if(arr[m]==key)
        {
            return m;
        }
        else if(key<arr[m])
        {
            l = m-1;
        }
        else
        {
            f = m+1;
        }
    }
    return -1;
}

int linse(int *arr, int key, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}
