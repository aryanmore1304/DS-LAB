#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;

    printf("Inserted successfully!\n");
}

void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("1. Insert 2.Delete 3. Display 4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
