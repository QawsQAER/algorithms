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
  name = "heap_sort",
  srcs = ["heap_sort.cc"],
  hdrs = ["heap_sort.h"],
  deps = [
    ":sort",       
    "@glog//:glog",
  ],
)

cc_library(
  name = "radix_sort",
  srcs = ["radix_sort.cc"],
  hdrs = ["radix_sort.h"],
  deps = [
    ":sort", 
  ],
)

cc_library(
  name = "sort",
  hdrs = ["sort.h"],
)

cc_test(
  name = "sort_test",
  srcs = ["sort_test.cc"],
  copts = ["-Iexternal/gtest/include"],
  deps = [
      ":merge_sort",
      ":heap_sort",
      "@gtest//:gtest_main",
      "@com_google_absl//absl/random",
      "@com_google_absl//absl/time",
      "@com_google_absl//absl/algorithm:container",
      "@glog//:glog",
  ],
)

