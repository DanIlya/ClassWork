#include <stdio.h>
#include <stdlib.h>

typedef struct list_element
{
    int a;
    int b;
    double c;
    struct list_element* next;
    struct list_element* prev;
} list_element;

list_element* create_list_element(int a, int b, double c)
{
    list_element* p= malloc(sizeof(list_element));
    p->a = a;
    p->b = b;
    p->c = c;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insert_into_list (list_element* a, list_element* b)
{
    list_element* c = a->next;
    a->next = b;
    b->prev = a;
    b->next = c;
    if (c!=NULL)
    {
        c->prev = b;
    }

}

void print_list (list_element* a)
{
    list_element* cel = a;
    while (cel!=NULL)
    {
        printf(" a= %d\n b= %d\n c= %f\n",cel->a,cel->b,cel->c);
        cel = cel->next;
    }


}

list_element* get_by_number(list_element* a, int n)
{
    int i;
    list_element* cur =a;
    for (i=0;i<n;i++)
    {
        if (cur == NULL)
        {
            printf("%d element does not exist",n);
            return NULL;
        }
        else
        {
            cur = cur->next;
        }

    }
    return cur;
}

int main()
{
    int i;
    int n;
    list_element* first = create_list_element(11,-11,456);
    list_element* el;

    for (i=0;i<10;i++)
    {
        el = create_list_element(i,-i,42);
        insert_into_list(first,el);
    }

    print_list(first);

    scanf("%d",&n);
    printf("%d", get_by_number(first,n)->a);


    return 0;
}
