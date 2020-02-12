
#include <iostream>

#include "BtrfsMetrics.h"
#include "btrfs.h"

namespace btrfs_exporter {

	using namespace btrfs;
	using namespace prometheus;
	using namespace std;

	BtrfsMetrics::BtrfsMetrics(const string& fsid):
		_registry(std::make_unique<Registry>()),
		_fsid(fsid),
		_clone_alignment(clone_alignment(fsid)),
		_nodesize(nodesize(_fsid)),
		_sectorsize(sectorsize(_fsid)) {
	}

	vector<MetricFamily> BtrfsMetrics::Collect() const {
		// TODO: protect all this with a mutex

		cout << "Collecting BtrfsMetrics for fs: " << _fsid << " label: " << label(_fsid) << "\n";

		// TODO: update counters

		return _registry->Collect();
	}

};

