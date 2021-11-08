#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode {
    struct queueNode *next;
    char value;
} QueueNode;

void insertVal(QueueNode **Q);
QueueNode* removeVal(QueueNode* Q);

int main() {
    char choice;
    QueueNode *Q = NULL;

    do {
        printf("Enter \"i\" to insert a new element, \"r\" to remove an element, \"q\" to quit: ");
        scanf("%s", &choice);

        if (choice == 'i') {
            fputc('\n', stdout);
            insertVal(&Q);
        } else if (choice == 'r') {
            Q = removeVal(Q);
        } else if (choice == 'q') {
            fputc('~', stdout);
            fputc('\n', stdout);
        }
        else
            printf("That was an invalid entry. Please try again.\n");
    }
    while (choice != 'q');
    return 0;
}

void insertVal(QueueNode **Q) {
    char value;
    QueueNode *new;

    fputs("Enter character to be enqueued (inserted): ", stdout);
    scanf("%s", &value);
    fputc('\n', stdout);
    if ((*Q)->next == NULL) {
        (new) = (QueueNode*)malloc(sizeof(QueueNode));
        new->value = value;
        new->next = new;
        (*Q) = new;
        fputc('\n', stdout);
    }
    else if (*Q == (*Q)->next) {
        new = (QueueNode*)malloc(sizeof(QueueNode));
        new->value = value;
        new->next = *Q;
        (*Q)->next = new;
        fputc('\n', stdout);
    }
    else {
        new = (QueueNode*)malloc(sizeof(QueueNode));
        new->value = value;
        *Q = (*Q)->next;
        new->next = (*Q)->next;
        (*Q)->next = new;
    }
    fputc('\n', stdout);

}

QueueNode* removeVal(QueueNode* Q) {
    QueueNode *temp = Q;
    if (Q == NULL) {
        printf("Nothing to remove; the queue is empty.\n");
    }
    else {
        if (Q->next == Q) {
            printf("The character removed was a \"%c\"\n", Q->value);
            Q = NULL;
        } else if (Q->next->next == Q) {
            Q = Q->next;
            printf("The character removed was a \"%c\"\n", Q->next->value);
            Q->next = Q;
        } else if (Q->next->next->next == Q) {
            printf("The character removed was a \"%c\"\n", Q->next->next->value);
            Q->next->next = Q;
            free(temp->next->next);
        } else {
            printf("The character removed was a \"%c\"\n", Q->next->next->value);
            Q->next->next = Q->next->next->next;
            free(temp->next->next);
        }
    }
    fputc('\n', stdout);

    return Q;
}

/*
 * else if (*Q == (*Q)->next) {
        new = (QueueNode*)malloc(sizeof(QueueNode));
        new->value = value;
        new->next = *Q;
        (*Q)->next = new;
        fputc('\n', stdout);
    }
    else {
        new = (QueueNode*)malloc(sizeof(QueueNode));
        new->value = value;
        *Q = (*Q)->next;
        new->next = (*Q)->next;
        (*Q)->next = new;
    }
 */