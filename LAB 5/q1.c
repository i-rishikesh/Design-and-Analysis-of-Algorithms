#include <stdio.h>
#include <stdlib.h>

struct person {
  int id;
  char *name;
  int age;
  int height;
  int weight;
};

void swap(struct person *a, struct person *b) {
  struct person temp = *a;
  *a = *b;
  *b = temp;
}

int parent(int i) {
  return (i - 1) / 2;
}

int left(int i) {
  return 2 * i + 1;
}

int right(int i) {
  return 2 * i + 2;
}

void min_heapify(struct person *heap, int n, int i) {
  int smallest = i;
  int l = left(i);
  int r = right(i);

  if (l < n && heap[l].weight < heap[smallest].weight) {
    smallest = l;
  }

  if (r < n && heap[r].weight < heap[smallest].weight) {
    smallest = r;
  }

  if (smallest != i) {
    swap(&heap[i], &heap[smallest]);
    min_heapify(heap, n, smallest);
  }
}

void build_min_heap(struct person *heap, int n) {
  for (int i = n / 2; i >= 0; i--) {
    min_heapify(heap, n, i);
  }
}

void print_heap(struct person *heap, int n) {
  for (int i = 0; i < n; i++) {
    printf("Id: %d, Name: %s, Weight: %d\n", heap[i].id, heap[i].name, heap[i].weight);
  }
}

int main() {
  int n;
  printf("Enter the number of students: ");
  scanf("%d", &n);

  struct person *heap = (struct person *)malloc(sizeof(struct person) * n);

  for (int i = 0; i < n; i++) {
    printf("Enter the id of student %d: ", i + 1);
    scanf("%d", &heap[i].id);
    printf("Enter the name of student %d: ", i + 1);
    scanf("%s", heap[i].name);
    printf("Enter the age of student %d: ", i + 1);
    scanf("%d", &heap[i].age);
    printf("Enter the height of student %d: ", i + 1);
    scanf("%d", &heap[i].height);
    printf("Enter the weight of student %d: ", i + 1);
    scanf("%d", &heap[i].weight);
  }

  build_min_heap(heap, n);

  print_heap(heap, n);

  return 0;
}
