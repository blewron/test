#include<stdio.h>

int arr[50];
int n, d, u;
int k = 10;

void insert(int n);
void delete(int d);
void update(int u);
void display();

int main()
{
    void insert(int n);
    void delete(int d);
    void update(int u);
    void display();

    printf("Enter the elements of array :\n");
    for(int i=0;i<k;i++)
    {
        scanf("%d",&arr[i]);
    }

    insert(n);
    display();
    delete(d);
    display();
    update(u);
    display();

    return 0;
}

void insert(int n)
{
    printf("Enter the value of element you want to insert:\n");
    scanf("%d",&n);
    printf("Enter the position you want to insert :\n");
    int pos;
    scanf("%d",&pos);
    if (pos < 1 || pos > 50)
    {
        printf("\nInvalid Position\n");
        return;
    }
    else
    {
        for (int i =49; i >= pos -1; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[pos-1]=n;
    }
    k++;
}

void delete(int d)
{
    printf("Enter the position of element you want to Delete: \n");
    scanf("%d", &d);
    if (d < 1 || d > 50)
    {
        printf("\n Invalid Position \n");
        return;
    }
    for (int j = d - 1; j < 49; j++)
    {
        arr[j] = arr[j + 1];
    }
    k--;
}

void update(int u)
{
    printf("Enter the position of element you want to Update :\n");
    int x;
    scanf("%d",&x);
    printf("Enter new Value : \n");
    scanf("%d",&u);
    if (x < 1 || x > 50)
    {
        printf("\n Invalid Position \n");
        return;
    }
    arr[x - 1] = u;
}

void display()
{
    for(int i=0;i<k;i++)
    {
        printf("Your new array : %d\n",arr[i]);
    }
}