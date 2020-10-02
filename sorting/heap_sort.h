#ifndef ALGORITHMS_SORTING_HEAP_SORT_H
#define ALGORITHMS_SORTING_HEAP_SORT_H

#include "sorting/sort.h"

namespace algorithm {
namespace sorting {

class HeapSort: public Sort {
 public: 
    void Run(std::vector<int>* input);
};

} // sorting
} // algorithm

#endif
