#include "sorting/quick_sort.h"

#include "glog/logging.h"
#include "glog/stl_logging.h"

namespace algorithm {
namespace sorting {

int Partition(std::vector<int>* input, int p, int r) {
  int pivot = (*input)[r];
  int left_end = p - 1;
  int right_end = p - 1;
  for(int i = p; i < r; i++) {
    if ((*input)[i] >= pivot) {
      right_end++;
    } else {
      int num = (*input)[left_end + 1];
      (*input)[left_end + 1] = (*input)[i];
      (*input)[i] = num;
      left_end++;
    }
  }
  int num = (*input)[r];
  (*input)[r] = (*input)[left_end + 1];
  (*input)[left_end + 1] = num;
  return (left_end + 1);
}

int QuickSort::RandomPartition(std::vector<int>* input, int p, int r) {
  int pivot_idx = absl::Uniform(bitgen, p, r);
  int num = (*input)[pivot_idx];
  (*input)[pivot_idx] = (*input)[r];
  (*input)[r] = num;
  return Partition(input, p, r);
}

void QuickSort::InternalQuickSort(std::vector<int>* input, int p, int r) {
  LOG(INFO) << (*input) << ", p:" << p << ", r:" << r;
  if (p >= r) {
    return;
  }
  int q = RandomPartition(input, p, r);
  InternalQuickSort(input, p, q - 1);
  InternalQuickSort(input, q + 1, r);
}

void QuickSort::Run(std::vector<int>* input) {
  InternalQuickSort(input, 0, input->size() - 1);
  return;
}

}  // namespace sorting
}  // namespace algorithm