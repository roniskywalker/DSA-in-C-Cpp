// Using Array
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *sp, int i)
{
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));

    return 0;
}


// Using LL
// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *top = NULL;

// void linkedListTraversal(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }

// int isEmpty(struct Node *top)
// {
//     if (top == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isFull(struct Node *top)
// {
//     struct Node *p = (struct Node *)malloc(sizeof(struct Node));
//     if (p == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// struct Node *push(struct Node *top, int x)
// {
//     if (isFull(top))
//     {
//         printf("Stack Overflow\n");
//     }
//     else
//     {
//         struct Node *n = (struct Node *)malloc(sizeof(struct Node));
//         n->data = x;
//         n->next = top;
//         top = n;
//         return top;
//     }
// }

// int pop(struct Node *tp)
// {
//     if (isEmpty(tp))
//     {
//         printf("Stack Underflow\n");
//     }
//     else
//     {
//         struct Node *n = tp;
//         top = tp->next;
//         int x = n->data;
//         free(n);
//         return x;
//     }
// }

// int peek(int pos)
// {
//     struct Node *ptr = top;
//     for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
//     {
//         ptr = ptr->next;
//     }
//     if (ptr != NULL)
//     {
//         return ptr->data;
//     }
//     else
//     {
//         return -1;
//     }
// }

// int main()
// {
//     top = push(top, 28);
//     top = push(top, 18);
//     top = push(top, 15);
//     top = push(top, 7);
//     int z = pop(top);
//     printf("Popped element is %d\n", z);

//     linkedListTraversal(top);
//     for (int i = 1; i <= 4; i++)
//     {
//         printf("Value at position %d is : %d\n", i, peek(i));
//     }
//     return 0;
// }


// Infix to postfix
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct stack
// {
//     int size;
//     int top;
//     char *arr;
// };

// int stackTop(struct stack *sp)
// {
//     return sp->arr[sp->top];
// }

// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isFull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// void push(struct stack *ptr, char val)
// {
//     if (isFull(ptr))
//     {
//         printf("Stack Overflow! Cannot push %d to the stack\n", val);
//     }
//     else
//     {
//         ptr->top++;
//         ptr->arr[ptr->top] = val;
//     }
// }

// char pop(struct stack *ptr)
// {
//     if (isEmpty(ptr))
//     {
//         printf("Stack Underflow! Cannot pop from the stack\n");
//         return -1;
//     }
//     else
//     {
//         char val = ptr->arr[ptr->top];
//         ptr->top--;
//         return val;
//     }
// }
// int precedence(char ch)
// {
//     if (ch == '*' || ch == '/')
//         return 3;
//     else if (ch == '+' || ch == '-')
//         return 2;
//     else
//         return 0;
// }

// int isOperator(char ch)
// {
//     if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
//         return 1;
//     else
//         return 0;
// }
// char *infixToPostfix(char *infix)
// {
//     struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
//     sp->size = 10;
//     sp->top = -1;
//     sp->arr = (char *)malloc(sp->size * sizeof(char));
//     char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
//     int i = 0; // Track infix traversal
//     int j = 0; // Track postfix addition
//     while (infix[i] != '\0')
//     {
//         if (!isOperator(infix[i]))
//         {
//             postfix[j] = infix[i];
//             j++;
//             i++;
//         }
//         else
//         {
//             if (precedence(infix[i]) > precedence(stackTop(sp)))
//             {
//                 push(sp, infix[i]);
//                 i++;
//             }
//             else
//             {
//                 postfix[j] = pop(sp);
//                 j++;
//             }
//         }
//     }
//     while (!isEmpty(sp))
//     {
//         postfix[j] = pop(sp);
//         j++;
//     }
//     postfix[j] = '\0';
//     return postfix;
// }
// int main()
// {
//     char *infix = "x-y/z-k*d";
//     printf("postfix is %s", infixToPostfix(infix));
//     return 0;
// }
