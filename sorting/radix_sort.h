#ifndef ALGORITHMS_SORTING_RADIX_SORT_H
#define ALGORITHMS_SORTING_RADIX_SORT_H

#include <vector>
#include "sorting/sort.h"

namespace algorithm {
namespace sorting {

class RadixSort: public Sort {
 public:
    void Run(std::vector<int>* input);
};

}  // namespace sorting
}  // namespace algorithms
#endif