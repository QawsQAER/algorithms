#include "absl/algorithm/container.h"
#include "absl/random/random.h"
#include "absl/time/time.h"
#include "absl/time/clock.h"
#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"
#include "glog/logging.h"
#include <vector> 

#include "sorting/merge_sort.h"

namespace algorithm {
namespace sorting {

using ::testing::ElementsAre;

TEST(SortTest, BasicTest) {
  std::vector<int> input1 = {2, 4, 3, 1};
  std::vector<int> input2 = {};
  std::vector<int> input3 = {1, 2, 3};
  std::vector<int> input4 = {3, 2, 1};

  MergeSort merge_sort;
  merge_sort.Run(&input1);
  EXPECT_THAT(input1, ElementsAre(1, 2, 3, 4));

  merge_sort.Run(&input2);
  EXPECT_EQ(input2.size(), 0);

  merge_sort.Run(&input3);
  EXPECT_THAT(input3, ElementsAre(1, 2, 3));

  merge_sort.Run(&input4);
  EXPECT_THAT(input4, ElementsAre(1, 2, 3));
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
  absl::Time t2 = absl::Now();
  merge_sort.Run(&input);
  LOG(INFO) << "merge_sort.Run took " << (absl::Now() - t2);

  EXPECT_EQ(input, expected_output);
}

}  // namespace sorting
}  // namespace algorithm

