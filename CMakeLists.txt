
cmake_minimum_required(VERSION 3.12)

project(btrfs-exporter)

set(CMAKE_CXX_STANDARD 20)

add_executable(btrfs_exporter
        btrfs.h btrfs.cpp
        BtrfsMetrics.h BtrfsMetrics.cpp
        BtrfsRegistry.h BtrfsRegistry.cpp
        main.cpp)

target_link_libraries(btrfs_exporter prometheus-cpp-core prometheus-cpp-pull stdc++fs)

install (TARGETS btrfs_exporter DESTINATION bin)

