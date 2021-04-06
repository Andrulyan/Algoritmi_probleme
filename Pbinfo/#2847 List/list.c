#include <stdio.h>
#include <stdlib.h>
struct node
{
    int a, b;
    struct node *next;
};
struct node *initializare(struct node *head)
{
    head = NULL;
    return head;
}
void afisare(struct node *head)
{
    FILE *outt = fopen("list.out", "w");
    struct node *temp;
    temp = head;

    // printf ("Headul listei este= %d , cu valorile a=%d, b=%d\n", head, head->a, head->b);

    while (temp != NULL)
    {
        fprintf(outt, "%d %d\n", temp->a, temp->b);
        temp = temp->next;
    }
}
struct node *create_node(int a, int b)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->a = a;
    new_node->b = b;
    new_node->next = NULL;
    return new_node;
}
struct node *assign_node(int a, int b)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->a = a;
    new_node->b = b;
    new_node->next = NULL;
    return new_node;
}
int main()
{
    FILE *f = fopen("list.in", "r");

    if (f == NULL)
    {
        printf("Error!The file can't be opened.");
        exit(0);
    }
    else
    {
        int n, a, b, i = 0;
        struct node *head, *current, *new_node, *add_node;
        head = NULL;
        head = initializare(head); ///initialize the head of list
        if (fscanf(f, "%d", &n) == 1)
        {
            while (i < n)
            {
                if (fscanf(f, "%d %d", &a, &b) == 2)
                {
                    new_node = create_node(a, b);
                    if (head == NULL)
                    {
                        new_node->next = NULL;
                        head = new_node;
                    }

                    if (a % 2 == 0 && b % 2 != 0)
                    {
                        add_node = assign_node((new_node->a + new_node->b) * 2,(new_node->a + new_node->b) * 2 - new_node->b);
                        current = head;

                        while (current->next != NULL)
                        {
                            current = current->next;
                        }

                        current->next = new_node;
                        current->next->next = add_node;
                    }
                    else if (a % 2 != 0 && b % 2 == 0)
                    {

                        add_node = assign_node((new_node->a + new_node->b) * 2 - new_node->a, (new_node->a + new_node->b) * 2);
                        if (head->next == NULL) //if we have just one node we have to move the head to add_node
                        {
                            add_node->next = head;
                            head = add_node;
                        }
                        else
                        {
                            current = head;

                            while (current->next != NULL)
                            {
                                current = current->next;
                            }

                            add_node->next = new_node;
                            current->next = add_node;
                        }
                    }
                    else if (a % 2 == 0 && b % 2 == 0)
                    {

                        add_node = assign_node((new_node->a + new_node->b) / 2, (new_node->a + new_node->b) / 2 + new_node->b);
                        current = head;

                        while (current->next != NULL)
                        {
                            current = current->next;
                        }

                        current->next = new_node;
                        current->next->next = add_node;
                    }
                    else if (a % 2 != 0 && b % 2 != 0)
                    {

                        add_node = assign_node((new_node->a + new_node->b) / 2 + new_node->a, (new_node->a + new_node->b) / 2);
                        if (head->next == NULL) //if we have just one node we have to move the head to add_node
                        {
                            add_node->next = head;
                            head = add_node;
                        }

                        current = head;

                        while (current->next != NULL)
                        {
                            current = current->next;
                        }

                        current->next = add_node;
                        add_node->next = new_node;
                    }
                }
                i++;
            }
            afisare(head);
        }

        return 0;
    }
}
