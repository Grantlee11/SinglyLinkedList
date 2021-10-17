// In this Program, I'll be designing a Linked List with add, search, delete, and print functions

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

// We'll be inserting exclusively at the end of this linked list, I'll expand on it in the future
node* insert(node *head, int val)
{
    node *t;
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL)
        head = newNode;
    else
    {
        t = head;
        while(t->next != NULL)
            t = t->next;
        t->next = newNode;
    }


    printf("Insertion Sucessful.\n\n");

    return head;
}

// I created this function under the assumption that only a single unique value can exist in the list
void search(node *head, int val)
{
    int counter = 0;
    node *t;
    t = head;
    while(t != NULL)
    {
        counter++;
        if(t->data == val)
        {
            printf("Value %d is found at Node %d of the Linked List\n\n", val, counter);
            return;
        }
        t = t->next;
    }

    if(head == NULL)
        printf("The Linked List is currently empty.\n\n");
    else
        printf("Your value was not found in the Linked List.\n\n");
}

node* delete(node *head, int val)
{
    node *t;
    node *temp;

    if(head == NULL)
    {
        printf("The Linked List is currently Empty.\n\n");
        return head;
    }

    if(head->data == val)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Deletion Successful.\n\n");
        return head;
    }

    t = head;
    while((t->next != NULL) && (t->next->data != val))
        t = t->next;
    
    if(t->next == NULL)
    {
        printf("%d was not found in the Linked List\n\n", val);
        return head;
    }

    temp = t->next;
    t->next = t->next->next;
    free(temp);
    printf("Deletion Successful.\n\n");
    return head;
}

void printList(node *head)
{
    if(head != NULL)
        printf("Printing Linked List... ");
    else
    {
        printf("The Linked List is currently Empty.\n\n");
        return;
    }

    while(head != NULL)
    {
        printf("%d", head->data);
        if(head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n\n");
}

int main()
{
    node* head = NULL;
    int value;

    while(1)
    {
        int x;
        printf("1: Insert a Node to the Linked List\n");
        printf("2: Search for a Node in the Linked List\n");
        printf("3: Delete a Node in the Linked List\n");
        printf("4: Print values in List\n");
        printf("5: Exit the program\n");
        printf("Please Select Option 1, 2, 3, 4, or 5: ");
        scanf("%d", &x);

        switch(x)
        {
            case 1:
                printf("Give an integer value to load into the Linked List: ");
                scanf("%d", &value);
                head = insert(head, value);
                break;
            case 2:
                printf("What integer value would you like to search for: ");
                scanf("%d", &value);
                search(head, value);
                break;
            case 3:
                printf("What integer valued node would you like to delete:  ");
                scanf("%d", &value);
                head = delete(head, value);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                printf("Goodbye!");
                return(0);
            default:
                printf("Invalid entry.");
                break;
        }

    }

    return(0);
}