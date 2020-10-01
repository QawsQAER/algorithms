#ifndef ALGORITHMS_SORTING_SORT_H
#define ALGORITHMS_SORTING_SORT_H

namespace algorithm {
namespace sorting {
  
// The interface for running sorting algorithm.
class Sort {
  public:
    virtual void Run(std::vector<int>* input) = 0;
};

} // sorting
} // algorithm

#endif