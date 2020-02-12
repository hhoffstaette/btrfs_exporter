
#pragma once

#include <string>
#include <vector>
#include <prometheus/registry.h>

namespace btrfs_exporter {

	class BtrfsMetrics : public prometheus::Collectable {

	private:
		const std::unique_ptr<prometheus::Registry> _registry;
		const std::string _fsid;
		const long _clone_alignment;
		const long _nodesize;
		const long _sectorsize;

	public:
		BtrfsMetrics(const std::string& fsid);

		std::vector<prometheus::MetricFamily> Collect() const;
	};

};

