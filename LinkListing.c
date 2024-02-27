#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
NODE *head=NULL;

void create(int n)
{
    int i;
    NODE *newnode, *tail;
    for(i=1;i<=n;i++)
    {
        newnode = (NODE*)malloc(sizeof(NODE));
        printf("Enter Element: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
}

void display()
{
    NODE *temp;
    if(head==NULL)
    {
        printf("\nEmpty Linked List!!\n");
    }
    else
    {
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            printf("%d ",temp->data);
        }
    }
}

void search()
{
    int key;
    NODE *temp;
    if(head==NULL)
    {
        printf("Empty Linked List\n");
    }
    else
    {
        printf("Enter Key: ");
        scanf("%d",&key);
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            if(temp->data==key)
            {
                printf("Key Found!!\n");
                break;
            }
        }
        if(temp==NULL)
        {
            printf("Key Not Found!!");
        }
    }
}


int count()
{
    NODE *temp;
    int cnt=0;
    temp=head;
    while(temp!=NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insert()
{
    NODE *newnode, *temp;
    int i, pos, cnt;
    printf("Enter Position: ");
    scanf("%d", &pos);
    cnt=count();
    if(pos<1||pos>cnt+1)
    {
        printf("Invalid Position!!");
        return ;
    }
    newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter the element to be added :");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    if(pos==1)
    {
        newnode->next=head;
        head = newnode;
    }
    else
    {
        temp=head;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return;
}

void delete()
{
    NODE *temp, *ptr;
    int i, pos, cnt;
    printf("Enter Position to be delete: ");
    scanf("%d",&pos);
    cnt=count();
    if(pos<1||pos>cnt)
    {
        printf("\nInvalid Position!!");
        return ;
    }
    temp = head;
    if(pos==1)
    {
        printf("\nDeleted element: %d", temp->data);
        head = temp->next;
        free(temp);
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            ptr=temp;
            temp=temp->next;
        }
        printf("\nDeleted element: %d", temp->data);
        ptr->next=temp->next;
        free(temp);
    }
    
}

void sort()
{
    NODE *temp, *min, *current;
    int val;
    for(current=head;current->next!=NULL;current=current->next)
    {
        min=current;
        for(temp=current->next;temp!=NULL;temp=temp->next)
        {
            if(temp->data<min->data)
            {
                min=temp;
            }
            
        }
            val = current->data;
            current->data = min->data;
            min->data = val;
    }
}

void insertbyval()
{
    NODE *newnode, *temp, *prev;
    newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
printf("Enter the new value: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
if (head == NULL || newnode->data < head->data)
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    prev = NULL;
    for (temp = head; temp != NULL; temp = temp->next)
    { if (newnode->data < temp->data)
        {
            newnode->next = temp;
            if (prev != NULL)
                prev->next = newnode;
            else
                head = newnode;
            return;
        }
        prev = temp;
    }
    prev->next = newnode;
}

void main()
{
    int ch, n;
    printf("How Many Elements you want in the Link List: ");
    scanf("%d",&n);
    create(n);
    while(1)
    {
        printf("\n1.Insert \n2.Display \n3.Search \n4.Sort \n5.Delete \n6.Insert By Value \n7.Exit");
        printf("\nEnter the fuction you want to Run:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
            
        case 3:
            search();
            break;
            
        case 4:
            sort();
            break;
            
        case 5:
            delete();
            break;
            
        case 6:
            insertbyval();
            break;
            
        case 7:
            exit(0);
        }
    }
}

