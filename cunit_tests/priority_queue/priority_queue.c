#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

struct node {
  int item;
  int priority;
  Node *next_node;
};

struct pqueue {
  Node *first;
};

PriorityQueue* create_priority_queue() {
  PriorityQueue *pqueue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
  pqueue->first = NULL;

  return pqueue;
}

int is_empty(PriorityQueue *pqueue) {
  return (pqueue->first == NULL);
}

PriorityQueue* enqueue(PriorityQueue *pqueue, int item, int priority) {
  Node *new_node = (Node*) malloc(sizeof(Node));
  new_node->item = item;
  new_node->priority = priority;

  if (is_empty(pqueue) || (priority > pqueue->first->priority)) {
    new_node->next_node = pqueue->first;
    pqueue->first = new_node;
  } else {
    Node *current = pqueue->first;

    while ((current->next_node != NULL) && (current->next_node->priority > priority)) {
      current = current->next_node;
    }

    new_node->next_node = current->next_node;
    current->next_node = new_node;
  }

  return pqueue;
}

int dequeue(PriorityQueue *pqueue) {
  if (!is_empty(pqueue)) {
    Node *dequeued = pqueue->first;
    int dequeued_item = dequeued->item;

    pqueue->first = dequeued->next_node;
    free(dequeued);

    return dequeued_item;
  } else {
    return -1;
  }
}

int maximum(PriorityQueue *pqueue) {
  if(!is_empty(pqueue)) {
    return pqueue->first->item;
  } else {
    return -1;
  }
}

void free_list(Node *node) {
  if(node == NULL) return;

  free_list(node->next_node);

  free(node);
}

void free_queue(PriorityQueue *pq) {
  free_list(pq->first);

  free(pq);
}
