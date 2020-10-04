#include "absl/algorithm/container.h"
#include "absl/random/random.h"
#include "absl/time/time.h"
#include "absl/time/clock.h"
#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"
#include "glog/logging.h"
#include <vector> 

#include "sorting/merge_sort.h"
#include "sorting/heap_sort.h"
#include "sorting/quick_sort.h"

namespace algorithm {
namespace sorting {

using ::testing::ElementsAre;

TEST(SortTest, BasicTest) {

  MergeSort merge_sort;
  HeapSort heap_sort;
  QuickSort quick_sort;

  // Test case 1
  std::vector<int> input1 = {2, 4, 3, 1};
  std::vector<int> merge_input1(input1);
  merge_sort.Run(&merge_input1);
  EXPECT_THAT(merge_input1, ElementsAre(1, 2, 3, 4));

  std::vector<int> heap_input1(input1);
  heap_sort.Run(&heap_input1);
  EXPECT_THAT(heap_input1, ElementsAre(1, 2, 3, 4));

  std::vector<int> quick_input1(input1);
  quick_sort.Run(&quick_input1);
  EXPECT_THAT(quick_input1, ElementsAre(1, 2, 3, 4));

  // Test case 2
  std::vector<int> input2 = {};

  std::vector<int> merge_input2(input2);
  merge_sort.Run(&merge_input2);
  EXPECT_EQ(merge_input2.size(), 0);

  std::vector<int> heap_input2(input2);
  heap_sort.Run(&heap_input2);
  EXPECT_EQ(heap_input2.size(), 0);

  std::vector<int> quick_input2(input2);
  quick_sort.Run(&quick_input2);
  EXPECT_EQ(quick_input2.size(), 0);

  // Test case 3
  std::vector<int> input3 = {1, 2, 3};

  std::vector<int> merge_input3(input3);
  merge_sort.Run(&input3);
  EXPECT_THAT(input3, ElementsAre(1, 2, 3));

  std::vector<int> heap_input3(input3);
  heap_sort.Run(&heap_input3);
  EXPECT_THAT(heap_input3, ElementsAre(1, 2, 3));

  std::vector<int> quick_input3(input3);
  quick_sort.Run(&quick_input3);
  EXPECT_THAT(quick_input3, ElementsAre(1, 2, 3));

  // Test case 4
  std::vector<int> input4 = {3, 2, 1};

  std::vector<int> merge_input4(input4);
  merge_sort.Run(&merge_input4);
  EXPECT_THAT(merge_input4, ElementsAre(1, 2, 3));

  std::vector<int> heap_input4(input4);
  heap_sort.Run(&heap_input4);
  EXPECT_THAT(heap_input4, ElementsAre(1, 2, 3));

  std::vector<int> quick_input4(input4);
  quick_sort.Run(&quick_input4);
  EXPECT_THAT(quick_input4, ElementsAre(1, 2, 3));
}

TEST(SortTest, RandomTest) {
  int test_size = 1000000;
  absl::BitGen bitgen;
  std::vector<int> input;
  for (int i = 0; i < test_size; i++) {
    input.push_back(absl::Uniform(bitgen, -test_size, test_size));
  }

  std::vector<int> expected_output(input);
  absl::Time t1 = absl::Now();
  absl::c_sort<std::vector<int> >(expected_output);
  LOG(INFO) << "absl::c_sort() took " << (absl::Now() - t1);

  MergeSort merge_sort;
  std::vector<int> merge_sort_output(input);
  absl::Time merge_sort_start_time = absl::Now();
  merge_sort.Run(&merge_sort_output);
  LOG(INFO) << "merge_sort.Run took " << (absl::Now() - merge_sort_start_time);
  EXPECT_EQ(merge_sort_output, expected_output);

  HeapSort heap_sort;
  std::vector<int> heap_sort_output(input);
  absl::Time heap_sort_start_time = absl::Now();
  heap_sort.Run(&heap_sort_output);
  LOG(INFO) << "heap_sort.Run took " << (absl::Now() - heap_sort_start_time);
  EXPECT_EQ(heap_sort_output, expected_output);

  QuickSort quick_sort;
  std::vector<int> quick_sort_output(input);
  absl::Time quick_sort_start_time = absl::Now();
  heap_sort.Run(&quick_sort_output);
  LOG(INFO) << "quick_sort.Run took " << (absl::Now() - quick_sort_start_time);
  EXPECT_EQ(quick_sort_output, expected_output);
}

}  // namespace sorting
}  // namespace algorithm

