load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    data = glob(["testfiles/*"]),
    deps = ["//src/disk:disk_manager"],
)
