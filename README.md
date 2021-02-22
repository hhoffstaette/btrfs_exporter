btrfs_exporter
==============
A Btrfs filesystem metrics exporter for [Prometheus](https://prometheus.io/).
Background information is [here](https://github.com/prometheus/node_exporter/issues/1100).

Status: 2021-02-22
------------------
It's dead, Jim! I'm archiving this project since it's basically obsolete.
I started it before the Go-based collector in [node_exporter](https://github.com/prometheus/node_exporter) existed,
but never got around to finish it due to `$REASONS`. Since the stats in `node_exporter`
are perfectly fine, the only missing bit is the collection of filesystem errors.
For that I have written a [python-btrfs]()-based text collector, which can be found
here: [btrfs_error_exporter](https://github.com/hhoffstaette/python-btrfs/blob/prometheus-error-exporter/examples/prometheus/btrfs_error_exporter). It perfectly complements `node_exporter` since it does only the missing bits,
is very fast and should eventually [end up in python-btrfs](https://github.com/knorrie/python-btrfs/pull/26) for the good of all mankind.

Status: 2019-03-25
------------------
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
