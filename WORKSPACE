workspace(name = "dbms")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "1e3a69bf2d5cd10c34b74f066054cd335d033d71",
    remote = "https://github.com/nelhage/rules_boost",
    shallow_since = "1591047380 -0700",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

boost_deps()

http_archive(
    name = "com_google_absl",
    strip_prefix = "abseil-cpp-cde2f0eaaed3fb8581511cb5719d39172a5a2d81",
    urls = ["https://github.com/abseil/abseil-cpp/archive/cde2f0eaaed3fb8581511cb5719d39172a5a2d81.zip"],
)

http_archive(
    name = "bazel_skylib",
    sha256 = "f7be3474d42aae265405a592bb7da8e171919d74c16f082a5457840f06054728",
    urls = ["https://github.com/bazelbuild/bazel-skylib/releases/download/1.2.1/bazel-skylib-1.2.1.tar.gz"],
)


git_repository(
    name = "mpresident14_cpplibs",
    branch = "main",
    remote = "https://github.com/mpresident14/cpplibs",
)
