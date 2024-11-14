PriorityQueueItem* removeHighestPriorityNode(PriorityQueueItem** head) {
    if (*head == NULL) {
        return NULL;
    }
    PriorityQueueItem* highestPriorityNode = *head;
    *head = (*head)->next;
    return highestPriorityNode;
}