cc_library(
  name = "merge_sort",
  srcs = ["merge_sort.cc"],
  hdrs = ["merge_sort.h"],
  deps = [
    ":sort",       
    "@glog//:glog",
  ],
)

cc_library(
  name = "sort",
  hdrs = ["sort.h"],
)

cc_test(
  name = "merge_sort_test",
  srcs = ["merge_sort_test.cc"],
  copts = ["-Iexternal/gtest/include"],
  deps = [
      "@gtest//:gtest_main",
      ":merge_sort",
  ],
)

