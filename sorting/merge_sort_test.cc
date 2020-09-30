#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"
#include "sorting/merge_sort.h"
#include <vector> 

namespace algorithm {
namespace sorting {

using ::testing::ElementsAre;

TEST(MergeSortTest, BasicTest) {
  std::vector<int> input1 = {2, 4, 3, 1};
  std::vector<int> input2 = {};
  std::vector<int> input3 = {1, 2, 3};
  std::vector<int> input4 = {3, 2, 1};
  MergeSort merge_sort;
  merge_sort.Run(input1);
  EXPECT_THAT(input1, ElementsAre(1, 2, 3, 4));

  merge_sort.Run(input2);
  EXPECT_EQ(input2.size(), 0);

  merge_sort.Run(input3);
  EXPECT_THAT(input3, ElementsAre(1, 2, 3));
  
  merge_sort.Run(input4);
  EXPECT_THAT(input4, ElementsAre(1, 2, 3));
}

}  // namespace sorting
}  // namespace algorithm

