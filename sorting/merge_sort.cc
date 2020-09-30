#include <vector>
#include "sorting/merge_sort.h"
#include "glog/logging.h"
#include "glog/stl_logging.h"

namespace algorithm {
namespace sorting {

// Merge two sorted array input[i, j] and input[j+1,k]
void Merge(std::vector<int>& input, int i, int j, int k) {
  std::vector<int> array1;
  std::vector<int> array2;
  for (int idx = 0; idx < (j - i) + 1; idx++) {
    array1.push_back(input[i+idx]);
  }
  for (int idx = 0; idx < k - (j + 1) + 1; idx++) {
    array2.push_back(input[j+1+idx]);
  }
  int idx1 = 0;
  int idx2 = 0;
  for (int current = i; current <= k; current++) {
    if (idx1 > j - i) {
      // LOG(INFO) << "Merging leftover for array2";
      // LOG(INFO) << "current: " << current << ", idx2: " << idx2;
      input[current] = array2[idx2++];
      continue;
    } 
    if (idx2 > (k - (j + 1))) {
      // LOG(INFO) << "Merging leftover for array1";
      // LOG(INFO) << "current: " << current << ", idx1: " << idx1;
      input[current] = array1[idx1++];
      continue;
    }
    if (array1[idx1] <= array2[idx2]) {
      input[current] = array1[idx1++];
    } else {
      input[current] = array2[idx2++];
    }
  }
}

// Run a recursive MergeSort on input[i, j]
void Recursive(std::vector<int>& input, int i, int j) {
  // LOG(INFO) << "Running Recursive for " << i << ", " << j;
  if (i == j) {
    return ;
  }
  int mid = (j + i) / 2;
  Recursive(input, i, mid);
  Recursive(input, mid+1, j);
  Merge(input, i, mid, j);
}

void MergeSort::Run(std::vector<int>& input) {
  LOG(INFO) << "input: " << input;
  if (input.size() <= 1) {
    return ;
  }

  Recursive(input, 0, input.size()-1);
}

} // namespace sorting
} // namespace algorithm