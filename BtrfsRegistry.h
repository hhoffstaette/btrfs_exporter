
#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <prometheus/registry.h>

#include "BtrfsMetrics.h"

namespace btrfs_exporter {

	class BtrfsRegistry : public prometheus::Collectable {

	private:
		mutable std::unordered_map<std::string, std::unique_ptr<BtrfsMetrics>> _metrics;

	public:
		std::vector<prometheus::MetricFamily> Collect() const;
	};

};

