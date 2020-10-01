#ifndef ALGORITHMS_SORTING_MERGE_SORT_H
#define ALGORITHMS_SORTING_MERGE_SORT_H

#include "sorting/sort.h"

namespace algorithm {
namespace sorting {

class MergeSort: public Sort {
  public: 
    void Run(std::vector<int>* input);
};

} // sorting
} // algorithm

#endif
