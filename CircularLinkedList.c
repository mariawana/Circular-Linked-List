
#include "CircularLinkedList.h"

/* Create a new circular linked list */
CircularLinkedList* createNewCircularLinkedList(void)
{
    CircularLinkedList *list = malloc(sizeof(CircularLinkedList));

    if (list == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

/* Create a new node */
Node* createNewNode(int data)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

/* Insert at the end */
void insertAtEnd(CircularLinkedList *list, int data)
{
    if (list == NULL) return;

    Node *node = createNewNode(data);
    if (node == NULL) return;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        node->next = node;
    } else {
        node->next = list->head;
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;
}

/* Insert at the beginning */
void insertAtBeginning(CircularLinkedList *list, int data)
{
    if (list == NULL) return;

    Node *node = createNewNode(data);
    if (node == NULL) return;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        node->next = node;
    } else {
        node->next = list->head;
        list->head = node;
        list->tail->next = list->head;
    }

    list->size++;
}

/* Insert at a specified position (zero-based) */
void insertAtPosition(CircularLinkedList *list, int data, int position)
{
    if (list == NULL) return;

    if (position < 0 || position > list->size) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 0) {
        insertAtBeginning(list, data);
        return;
    }

    if (position == list->size) {
        insertAtEnd(list, data);
        return;
    }

    Node *node = createNewNode(data);
    if (node == NULL) return;

    Node *temp = list->head;

    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next = node;
    list->size++;
}

/* Delete the first node */
void deleteFirstNode(CircularLinkedList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = list->head;

    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->tail->next = list->head;
    }

    free(temp);
    list->size--;
}

/* Delete the last node */
void deleteLastNode(CircularLinkedList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (list->size == 1) {
        deleteFirstNode(list);
        return;
    }

    Node *temp = list->head;

    while (temp->next != list->tail) {
        temp = temp->next;
    }

    free(list->tail);

    list->tail = temp;
    list->tail->next = list->head;
    list->size--;
}

/* Delete a node at a specified position (zero-based) */
void deleteNodeAtPosition(CircularLinkedList *list, int position)
{
    if (list == NULL) return;

    if (position < 0 || position >= list->size) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 0) {
        deleteFirstNode(list);
        return;
    }

    if (position == list->size - 1) {
        deleteLastNode(list);
        return;
    }

    Node *temp = list->head;

    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }

    Node *toDelete = temp->next;
    temp->next = toDelete->next;

    free(toDelete);
    list->size--;
}

/* Search for a value */
bool search(CircularLinkedList *list, int data)
{
    if (list == NULL || list->head == NULL) {
        return false;
    }

    Node *temp = list->head;

    do {
        if (temp->data == data) {
            return true;
        }

        temp = temp->next;
    } while (temp != list->head);

    return false;
}

/* Print the list from beginning to end */
void printList(CircularLinkedList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = list->head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != list->head);

    printf("\n");
}

/* Print the list in reverse order */
void printListReverse(CircularLinkedList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("List is empty!\n");
        return;
    }

    int *values = malloc(list->size * sizeof(int));

    if (values == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    Node *temp = list->head;

    for (int i = 0; i < list->size; i++) {
        values[i] = temp->data;
        temp = temp->next;
    }

    for (int i = list->size - 1; i >= 0; i--) {
        printf("%d ", values[i]);
    }

    printf("\n");
    free(values);
}

/* Reverse the circular linked list iteratively */
void reverseList(CircularLinkedList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *oldHead = list->head;
    Node *current = list->head;
    Node *prev = list->tail;

    for (int i = 0; i < list->size; i++) {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head = prev;
    list->tail = oldHead;
    list->tail->next = list->head;
}

/* Helper for recursively reversing a linear chain */
void reverseListRecursiveHelper(Node *node)
{
    if (node == NULL || node->next == NULL) {
        return;
    }

    reverseListRecursiveHelper(node->next);

    node->next->next = node;
    node->next = NULL;
}

/* Reverse the circular linked list recursively */
void reverseListRecursive(CircularLinkedList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (list->size == 1) {
        return;
    }

    Node *oldHead = list->head;

    /* Temporarily make the list linear */
    list->tail->next = NULL;

    reverseListRecursiveHelper(list->head);

    list->head = list->tail;
    list->tail = oldHead;

    /* Restore the circular connection */
    list->tail->next = list->head;
}

/* Delete all nodes but keep the list structure */
void deleteList(CircularLinkedList *list)
{
    if (list == NULL) return;

    Node *current = list->head;
    int count = list->size;

    for (int i = 0; i < count; i++) {
        Node *toDelete = current;
        current = current->next;
        free(toDelete);
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/* Find the middle node */
Node* findMiddleNode(CircularLinkedList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    Node *slow = list->head;
    Node *fast = list->head;

    while (fast->next != list->head &&
           fast->next->next != list->head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/* Find the node with the maximum value */
Node* findMaximumNode(CircularLinkedList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    Node *maximum = list->head;
    Node *temp = list->head->next;

    while (temp != list->head) {
        if (temp->data > maximum->data) {
            maximum = temp;
        }

        temp = temp->next;
    }

    return maximum;
}

/* Find the node with the minimum value */
Node* findMinimumNode(CircularLinkedList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    Node *minimum = list->head;
    Node *temp = list->head->next;

    while (temp != list->head) {
        if (temp->data < minimum->data) {
            minimum = temp;
        }

        temp = temp->next;
    }

    return minimum;
}

/* Merge two lists by copying their values into a new list */
CircularLinkedList* mergeTwoLists(
    CircularLinkedList *list1,
    CircularLinkedList *list2)
{
    CircularLinkedList *merged = createNewCircularLinkedList();

    if (merged == NULL) return NULL;

    if (list1 != NULL && list1->head != NULL) {
        Node *temp = list1->head;

        for (int i = 0; i < list1->size; i++) {
            insertAtEnd(merged, temp->data);
            temp = temp->next;
        }
    }

    if (list2 != NULL && list2->head != NULL) {
        Node *temp = list2->head;

        for (int i = 0; i < list2->size; i++) {
            insertAtEnd(merged, temp->data);
            temp = temp->next;
        }
    }

    return merged;
}

/* Sort the list in ascending order */
void sortLinkedList(CircularLinkedList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *current = list->head;

    for (int i = 0; i < list->size - 1; i++) {
        Node *next = current->next;

        for (int j = i + 1; j < list->size; j++) {
            if (current->data > next->data) {
                int temp = current->data;
                current->data = next->data;
                next->data = temp;
            }

            next = next->next;
        }

        current = current->next;
    }
}

/* Merge two sorted lists into a new sorted list */
CircularLinkedList* mergeTwoSortedLists(
    CircularLinkedList *list1,
    CircularLinkedList *list2)
{
    CircularLinkedList *merged = createNewCircularLinkedList();

    if (merged == NULL) return NULL;

    Node *temp1 = (list1 != NULL) ? list1->head : NULL;
    Node *temp2 = (list2 != NULL) ? list2->head : NULL;

    int count1 = (list1 != NULL) ? list1->size : 0;
    int count2 = (list2 != NULL) ? list2->size : 0;
    int i = 0;
    int j = 0;

    while (i < count1 && j < count2) {
        if (temp1->data <= temp2->data) {
            insertAtEnd(merged, temp1->data);
            temp1 = temp1->next;
            i++;
        } else {
            insertAtEnd(merged, temp2->data);
            temp2 = temp2->next;
            j++;
        }
    }

    while (i < count1) {
        insertAtEnd(merged, temp1->data);
        temp1 = temp1->next;
        i++;
    }

    while (j < count2) {
        insertAtEnd(merged, temp2->data);
        temp2 = temp2->next;
        j++;
    }

    return merged;
}

/* Free the nodes and the list structure */
void freeList(CircularLinkedList *list)
{
    if (list == NULL) return;

    deleteList(list);
    free(list);
}
