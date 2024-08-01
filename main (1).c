#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 9
int A[MAX_SIZE];
int front = -1, rear = -1;

bool IsEmpty() { return front == -1 && rear == -1; }

bool IsFull() {

  return front > -1 && rear > -1 && (front == rear - 1 || rear == front - 1);
}

void Enqueue(int x) {
  if (IsEmpty()) {
    front = rear = 0;
    A[rear] = x;
  } else
    rear = (rear + 1) % MAX_SIZE;

  A[rear] = x;
}

void Dequeue() {
  if (IsEmpty()) {
    printf("Queue is Empty \n");
  } else if (front == rear)
    front = rear = -1;
  else
    front = (front + 1) % MAX_SIZE;
}

void Display() {
  if (IsEmpty()) {
    printf("Queue is Empty \n");
  } else {
    int i = front;
    while (i != rear+1) {
      if (i >= MAX_SIZE) {
        i = 0;
      }
      printf("%d \n", A[i]);
      i++;
    }
    printf("\n");
  }
}

int main(void) {
  Enqueue(3);
  Enqueue(4);
  Enqueue(5);
  Enqueue(1);
  Enqueue(15);
  Enqueue(125);
  Display();
  Dequeue();
  Dequeue();
  Display();

  return 0;
}