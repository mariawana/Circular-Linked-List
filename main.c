#include "CircularLinkedList.h"

int main(void)
{
    CircularLinkedList *list = createNewCircularLinkedList();

    if (list == NULL) {
        return 1;
    }

    insertAtBeginning(list, 1);
    insertAtBeginning(list, 2);
    insertAtBeginning(list, 3);
    insertAtBeginning(list, 4);
    insertAtBeginning(list, 5);

    printf("Initial list:\n");
    printList(list);

    insertAtEnd(list, 6);

    printf("After inserting at the end:\n");
    printList(list);

    /* Insert a node at position 3 */
    insertAtPosition(list, 7, 3);

    printf("After inserting at position 3:\n");
    printList(list);

    reverseList(list);

    printf("After reversing the list:\n");
    printList(list);

    /* Reverse the list recursively */
    /* reverseListRecursive(list); */

    printf("Current list:\n");
    printList(list);

    deleteFirstNode(list);

    printf("After deleting the first node:\n");
    printList(list);

    deleteLastNode(list);

    printf("After deleting the last node:\n");
    printList(list);

    deleteNodeAtPosition(list, 3);

    printf("After deleting the node at position 3:\n");
    printList(list);

    printf("Search for 3: %s\n",
           search(list, 3) ? "true" : "false");

    printf("List in reverse order:\n");
    printListReverse(list);

    deleteList(list);

    printf("After deleting the list:\n");
    printList(list);

    /* Free the list structure */
    freeList(list);

    return 0;
}
