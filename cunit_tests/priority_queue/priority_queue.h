#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

  typedef struct node Node;
  typedef struct pqueue PriorityQueue;

  PriorityQueue* create_priority_queue();

  PriorityQueue* enqueue(PriorityQueue *pqueue, int item, int priority);

  int dequeue(PriorityQueue *pqueue);

  int maximum(PriorityQueue *pqueue);

  int is_empty(PriorityQueue *pqueue);

  void free_queue(PriorityQueue *pqueue);

#endif /* PRIORITY_QUEUE_H */
