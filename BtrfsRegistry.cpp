
#include "BtrfsRegistry.h"
#include "btrfs.h"

namespace btrfs_exporter {

	using namespace btrfs;
	using namespace prometheus;
	using namespace std;

	vector<MetricFamily> BtrfsRegistry::Collect() const {
		// TODO: protect all this with a mutex

		// find mounted filesystems
		vector<string> fsids = mounted_filesystems();

		// purge stale entries from existing metrics
		erase_if(_metrics, [&fsids](auto& entry) {
			return find(fsids.begin(), fsids.end(), entry.first) == fsids.end();
		});

		// create metrics for new filesystems
		for (string& fsid: fsids) {
			_metrics.try_emplace(fsid, make_unique<BtrfsMetrics>(fsid));
		}

		// make room for all collected metrics
		vector<MetricFamily> allmetrics;
		allmetrics.reserve(_metrics.size() * 16);

		// collect all metrics
		for (auto& fs: _metrics) {
			vector<MetricFamily> fsmetrics = fs.second->Collect();
			allmetrics.insert(allmetrics.end(), fsmetrics.begin(), fsmetrics.end());
		}

		return allmetrics;
	}

};

