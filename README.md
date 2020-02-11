btrfs_exporter
==============
A Btrfs filesystem metrics exporter for [Prometheus](https://prometheus.io/).
Background information is [here](https://github.com/prometheus/node_exporter/issues/1100).

Status (2019-03-25)
-------------------
The initial skeleton is alive! Right now it only collects request counts but **no**
meaningful btrfs-specific values yet, since so far most of the work was around
initial scaffolding. However, filesystems that are mounted and unmounted while
the exporter is running are already properly detected and accounted for.

Dependencies
------------
Only [prometheus-cpp >= 0.8.0](https://github.com/jupp0r/prometheus-cpp) is required;
since it is still being stabilized it's best to install directly from master for now.

[Gentoo](https://www.gentoo.org) users can find an ebuild
[here](https://github.com/hhoffstaette/portage/tree/master/dev-cpp/prometheus-cpp);
an ebuild for this exporter will follow as soon as it does something useful.

Build
-----
Assuming [prometheus-cpp](https://github.com/jupp0r/prometheus-cpp) is installed:
```
$ git clone https://github.com/hhoffstaette/btrfs_exporter.git
$ cd btrfs_exporter
$ mkdir build && cd build && cmake ..
$ make -j4
```

Test
----
```
$ ./btrfs_exporter &
$ curl http://localhost:8080/metrics
```
