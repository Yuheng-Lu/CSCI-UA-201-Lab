#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

struct node1d {
    struct node1d *next;
    char *name;
};
struct node2d {
    struct node1d *first;
    char *name;
    struct node2d *down;
};

int getch(void);
void ungetch(int c);
int getword(char *word, int lim);
void insertFront2D(struct node2d *head, char *name);
void insertBefore2D(struct node2d *head, char *name, char *name2d);
void insertFront1D(struct node2d *head, char *name1d, char *name2d);
void insertBefore1D(struct node2d *head, char *name1d, char *name1dBefore);
void printAll(struct node2d *head);
void print1DList(struct node2d *head, char *name2d);
void find1D(struct node2d *head, char *name1d);
void find2D(struct node2d *head, char *name2d);
void instruction();

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many chars\n");
    else
        buf[bufp++] = c;
}

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch())) ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

void insertFront2D(struct node2d *head, char *name) {
    struct node2d *new;
    new = (struct node2d *)malloc(sizeof(struct node2d));
    new->down = head->down;
    new->name = (char *)malloc(sizeof(char) * strlen(name));
    strcpy(new->name, name);
    head->down = new;
}

void insertBefore2D(struct node2d *head, char *name, char *beforeName) {
    struct node2d *curr = head;
    curr = curr->down;
    if (curr == NULL) {
        printf("Error: No Node Found\n");
        return;
    }
    if (strcmp(curr->name, beforeName) == 0) {
        insertFront2D(head, name);
        return;
    };
    while (curr->down != NULL) {
        if (strcmp(curr->down->name, beforeName) == 0) {
            break;
        }
        curr = curr->down;
    }
    if (curr->down == NULL) {
        printf("Error: No Node Found\n");
        return;
    }
    struct node2d *new = (struct node2d *)malloc(sizeof(struct node2d));
    new->first = NULL;
    new->name = (char *)malloc(sizeof(char) * strlen(name));
    strcpy(new->name, name);
    new->down = curr->down;
    curr->down = new;
}

void insertFront1D(struct node2d *head, char *name, char *name2D) {
    struct node2d *curr = head;
    curr = curr->down;
    while (curr != NULL) {
        if (strcmp(curr->name, name2D) == 0) {
            break;
        }
        curr = curr->down;
    };
    if (curr == NULL) {
        printf("Error: No Node Found\n");
        return;
    }
    struct node1d *new = (struct node1d *)malloc(sizeof(struct node1d));
    new->name = (char *)malloc(sizeof(char) * strlen(name));
    strcpy(new->name, name);
    new->next = curr->first;
    curr->first = new;
}

void insertBefore1D(struct node2d *head, char *name, char *beforeName1D) {
    struct node2d *curr = head;
    curr = curr->down;
    while (curr != NULL) {
        struct node1d *curr_curr = curr->first;
        if (curr_curr == NULL) {
            curr = curr->down;
            continue;
        }
        if (strcmp(curr_curr->name, beforeName1D) == 0) {
            insertFront1D(head, name, curr->name);
            return;
        }
        while (curr_curr != NULL) {
            if (curr_curr->next != NULL) {
                if (strcmp(curr_curr->next->name, beforeName1D) == 0)
                {
                    struct node1d *new = (struct node1d *)malloc(sizeof(struct node1d));
                    new->name = (char *)malloc(sizeof(char) * strlen(name));
                    strcpy(new->name, name);
                    new->next = curr_curr->next;
                    curr_curr->next = new;
                    return;
                }
                curr_curr = curr_curr->next;
            } else {
                break;
            }
        }
        curr = curr->down;
    }
    printf("not found\n");
}

void printAll(struct node2d *head) {
    struct node2d *curr = head;
    curr = curr->down;
    while (curr != NULL)
    {
        printf("2d node name=%s\n", curr->name);
        if (curr->first != NULL)
        {
            struct node1d *curr_curr = curr->first;
            while (curr_curr != NULL)
            {
                printf("\t1d node name=%s\n", curr_curr->name);
                curr_curr = curr_curr->next;
            }
        }
        curr = curr->down;
    }
}

void print1DList(struct node2d *head, char *name2d) {
    struct node2d *curr = head;
    curr = curr->down;
    while (curr != NULL)
    {
        if (strcmp(curr->name, name2d) == 0)
        {
            break;
        }
        curr = curr->down;
    }
    if (curr == NULL) {
        printf("Error: No Node Found");
        return;
    }
    printf("2d node name=%s\n", name2d);
    struct node1d *curr_curr = curr->first;
    while (curr_curr != NULL) {
        printf("\t1d node name=%s\n", curr_curr->name);
        curr_curr = curr_curr -> next;
    }
}

void find1D(struct node2d *head, char *name1d) {
    struct node2d *curr = head;
    curr = curr->down;
    while (curr != NULL) {
        struct node1d *curr_curr = curr->first;
        while (curr_curr != NULL) {
            if (strcmp(curr_curr->name, name1d) == 0)
            {
                printf("found\n");
                return;
            }
            curr_curr = curr_curr -> next;
        }
        curr = curr->down;
    }
    printf("not found\n");
}

void find2D(struct node2d *head, char *name2d) {
    struct node2d *curr = head;
    curr = curr->down;
    while (curr != NULL)
    {
        if (strcmp(curr->name, name2d) == 0)
        {
            printf("found\n");
            return;
        }
        curr = curr->down;
    }
    printf("not found\n");
}

void instruction() {
    printf("This program implements 2D Linked List data structure.\n");
    printf("The following operations are supported with 0/1/2 required argument(s):\n");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-1s%-17s%-15s%-15s%-73s%-1s\n", "|", "Operation:", "Argument1:", "Argument2:", "What it can do?", "|");
    printf("%-1s%-17s%-15s%-15s%-73s%-1s\n", "|", "insertFront2D", "name", "", "Create a new node2D and insert it at the front", "|");
    printf("%-1s%-17s%-15s%-15s%-73s%-1s\n", "|", "insertBefore2D", "name", "beforeName", "Create a new node2D and insert it before an already present 2D node.", "|");
    printf("%-1s%-17s%-15s%-15s%-73s%-1s\n", "|", "insertFront1D", "name", "name2D", "Create a new node1D and insert it at the front of the specified 1D list.", "|");
    printf("%-1s%-17s%-15s%-15s%-73s%-1s\n", "|", "insertBefore1D", "name", "beforeName1D", "Create a new node1D and insert it before an already present 1D node.", "|");
    printf("%-1s%-17s%-15s%-15s%-73s%-1s\n", "|", "printAll", "", "", "Print the entire diagram in the style shown in class.", "|");
    printf("%-1s%-17s%-15s%-15s%-73s%-1s\n", "|", "print1DList", "name2D", "", "Print the 1D (horizontal) list headed by the node2D given in the command.", "|");
    printf("%-1s%-17s%-15s%-15s%-73s%-1s\n", "|", "find1D", "name1D", "", "Search for a 1D node with the name given in the command.", "|");
    printf("%-1s%-17s%-15s%-15s%-73s%-1s\n", "|", "find2D", "name2D", "Argument2", "Search for a 2D node with the name given in the command.", "|");
    printf("%-1s%-17s%-15s%-15s%-73s%-1s\n", "|", "break", "", "", "Terminate the program and everything will be deleted.", "|");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
}

int main() {
    instruction();
    struct node2d *head;
    int break_or_not = 0;
    head = (struct node2d *)malloc(sizeof(struct node2d));
    head->first = NULL;
    head->down = NULL;
    while (break_or_not == 0) {
        printf("Please type in your command:\n");
        char command[20];
        char arg1[20];
        char arg2[20];
        getword(command, 20);
        if (strcmp(command, "insertFront2D") == 0) {
            getword(arg1, 20);
            insertFront2D(head, arg1);
        } else if (strcmp(command, "insertBefore2D") == 0) {
            getword(arg1, 20);
            getword(arg2, 20);
            insertBefore2D(head, arg1, arg2);
        } else if (strcmp(command, "insertFront1D") == 0) {
            getword(arg1, 20);
            getword(arg2, 20);
            insertFront1D(head, arg1, arg2);
        } else if (strcmp(command, "insertBefore1D") == 0) {
            getword(arg1, 20);
            getword(arg2, 20);
            insertBefore1D(head, arg1, arg2);
        } else if (strcmp(command, "printAll") == 0) {
            printAll(head);
        } else if (strcmp(command, "print1DList") == 0) {
            getword(arg1, 20);
            print1DList(head, arg1);
        } else if (strcmp(command, "find1D") == 0) {
            getword(arg1, 20);
            find1D(head, arg1);
        } else if (strcmp(command, "find2D") == 0) {
            getword(arg1, 20);
            find2D(head, arg1);
        } else if (strcmp(command, "break") == 0) {
            break_or_not = 1;
        } else {
            printf("Wrong command\n");
        }
    }
    printf("The program has been terminated successfully\n");
    return 0;
}
