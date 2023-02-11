load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "disk_manager",
    srcs = ["disk_manager.cpp"],
    hdrs = ["disk_manager.hpp"],
)

cc_test(
    name = "disk_manager_test",
    srcs = ["disk_manager_test.cpp"],
    deps = [
        ":disk_manager",
        "@mpresident14_cpplibs//src/testing:unit_test",
    ],
)
