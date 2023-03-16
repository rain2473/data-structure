#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode
{
    struct listNode *next;
    int data;
}listNode;

listNode *init_list()
{
    listNode *head;
    head = (listNode *)malloc(sizeof(listNode));
    head->next = NULL;

    return (head);
}

listNode *find_end(listNode *h)
{
    listNode *cur;
    cur = h;

    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    return (cur);
}

int node_len(listNode *h)
{
    int cnt;
    listNode *cur;
    cur = h;

    cnt = 0;
    while (cur->next != NULL)
    {
        cnt++;
        cur = cur->next;
    }
    return (cnt);
}

listNode *read_node_idx(listNode *h, int num)
{
    int i;
    listNode *cur;
    cur = h;

    i = 0;

    if (num < 1 || num > node_len(h))
    {
        printf("wrong data\n");
        return (h);
    }
    while (i < num)
    {
        cur = cur->next;
        i++;
    }
    return (cur);
}

listNode *read_node_data(listNode *h, int data)
{
    listNode *cur;
    cur = h;

    while (cur->data != data && cur->next != NULL)
    {
        cur = cur->next;
    }
    if(cur->next == NULL)
    {
        printf("wrong data\n");
        return (h);
    }

    return (cur);
}

void add_first_node(listNode *h, int data)
{
    listNode *newNode;
    newNode = (listNode *) malloc(sizeof(listNode));
    newNode->data = data;
    newNode->next = h->next;
    h->next = newNode;
}

void add_last_node(listNode *h, int data)
{
    listNode *end;
    end = find_end(h);
    listNode *newNode;
    newNode = (listNode *) malloc(sizeof(listNode));
    newNode->data = data;
    end->next = newNode;
    newNode->next = NULL;

}

void insert_node(listNode *h, int n, int data)
{
    if (n == 1)
        add_first_node(h,data);
    else if (n == node_len(h))
        add_last_node(h, data);
    else if (n < 1 && n > node_len(h))
    {
        printf("wrong range\n");
        return ;
    }
    else
    {
        int i;
        listNode *prev;
        prev = h;
        i = 0;
        while (i < n - 1)
        {
            prev = prev->next;
            i++;
        }
        listNode *newNode;
        newNode = (listNode *) malloc(sizeof(listNode));
        newNode->data = data;
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

void edit_node(listNode *h, int search, int modify)
{
    listNode *s;
    s = read_node_idx(h, search);
    //s = read_node_data(search);
    if(s == h)
    {
        return ;
    }
    s->data = modify;
}

void delete_first_node(listNode *h)
{
    listNode *cur;
    cur = h->next;
    h->next = cur->next;
    cur->next = NULL;

    free(cur);
}

void delete_node(listNode *h, int n)
{
    if (n == 1)
        delete_first_node(h);
    else if (n < 1 && n > node_len(h))
    {
        printf("wrong range\n");
        return ;
    }
    else
    {
        int i;
        listNode *prev;
        prev = h;
        i = 0;
        while (i < n - 1)
        {
            prev = prev->next;
            i++;
        }
        listNode *cur;
        cur = prev->next;
        prev->next = cur->next;
        cur->next = NULL;

        free(cur);
    }
}

void delete_all_node(listNode *h)
{
    listNode *cur;
    cur = h;

    listNode *nxt;
    while(cur != NULL)
    {
        nxt = cur->next;

        free(cur);
        cur = nxt;
    }
    free(h);
}

void print_all_node(listNode *h)
{
    listNode *cur;
    cur = h->next;

    if(cur != NULL)
    {
        while (1)
        {
            printf("%d", cur->data);
            if (cur->next == NULL)
            {
                printf("\n");
                break;
            }
            else
                printf("->");
            cur = cur->next;
        }
    }
    else
    {
        printf("No data\n");
    }
}