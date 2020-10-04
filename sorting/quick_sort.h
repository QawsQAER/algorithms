#ifndef ALGORITHMS_SORTING_QUICK_SORT_H
#define ALGORITHMS_SORTING_QUICK_SORT_H

#include "sorting/sort.h"

#include "absl/random/random.h"

namespace algorithm {
namespace sorting {

class QuickSort: public Sort {
 public:
  void Run(std::vector<int>* input);
 private:
  void InternalQuickSort(std::vector<int>* input, int p, int r);
  int RandomPartition(std::vector<int>* input, int p, int r);
  absl::BitGen bitgen;
};

} // sorting
} // algorithm

#endif
