
#pragma once

#include <string>
#include <vector>
#include <prometheus/registry.h>

namespace btrfs_exporter {

	class BtrfsMetrics : public prometheus::Collectable {

	private:
		std::unique_ptr<prometheus::Registry> _registry;
		std::string _fsid;
		long _clone_alignment;
		long _nodesize;
		long _sectorsize;

	public:
		explicit BtrfsMetrics(std::string &fsid);

		std::vector<prometheus::MetricFamily> Collect() override;
	};

};

