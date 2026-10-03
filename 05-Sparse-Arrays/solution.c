#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003
#define MAX_LEN 21

typedef struct Node {
    char str[MAX_LEN];
    int count;
    struct Node *next;
} Node;

unsigned int hashFunction(char *str)
{
    unsigned int hash = 0;

    while (*str)
    {
        hash = (hash * 31 + *str) % TABLE_SIZE;
        str++;
    }

    return hash;
}

void insert(Node **table, char *str)
{
    unsigned int index = hashFunction(str);
    Node *current = table[index];

    while (current != NULL)
    {
        if (strcmp(current->str, str) == 0)
        {
            current->count++;
            return;
        }

        current = current->next;
    }

    Node *newNode = malloc(sizeof(Node));

    strcpy(newNode->str, str);
    newNode->count = 1;
    newNode->next = table[index];

    table[index] = newNode;
}

int search(Node **table, char *str)
{
    unsigned int index = hashFunction(str);
    Node *current = table[index];

    while (current != NULL)
    {
        if (strcmp(current->str, str) == 0)
        {
            return current->count;
        }

        current = current->next;
    }

    return 0;
}

int main()
{
    int n, q;

    scanf("%d", &n);

    Node *table[TABLE_SIZE] = {NULL};

    char str[MAX_LEN];

    for (int i = 0; i < n; i++)
    {
        scanf("%20s", str);
        insert(table, str);
    }

    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        scanf("%20s", str);
        printf("%d\n", search(table, str));
    }

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node *current = table[i];

        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
