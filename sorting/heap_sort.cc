#include "sorting/heap_sort.h"

namespace algorithm {
namespace sorting {

inline int LeftChild(int idx) {
  return idx * 2 + 1;
}

inline int RightChild(int idx) {
  return idx * 2 + 2;
}

// Make sure subtree with input[i] is a max-heap.
void Heapify(std::vector<int>* input, int i, int j) {
  int left = LeftChild(i);
  int right = RightChild(i);
  int max = (*input)[i];
  int next_idx = i;
  if (left <= j) {
    if (max < (*input)[left]) {
      max = (*input)[left];
      next_idx = left;
    }
  }
  if (right <= j) {
    if (max < (*input)[right]) {
      max = (*input)[right];
      next_idx = right;
    }
  }
  
  if (next_idx == i) {
    return ;
  }

  int num = (*input)[i];
  (*input)[i] = max;
  (*input)[next_idx] = num;
  Heapify(input, next_idx, j);
}

void HeapSort::Run(std::vector<int>* input) {
  for (int i = (input->size() - 1) / 2; i >= 0; i--) {
    Heapify(input, i, input->size() - 1);
  }
  
  for (int i = input->size() - 1; i >= 1; i--) {
    int max = (*input)[0];
    (*input)[0] = (*input)[i];
    (*input)[i] = max;
    Heapify(input, 0, i-1);
  }
  return ;
}

}  // namespace sorting
}  // namespace algorithm