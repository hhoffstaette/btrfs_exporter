
#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>
#include <prometheus/registry.h>

#include "BtrfsMetrics.h"

namespace btrfs_exporter {

	class BtrfsRegistry : public prometheus::Collectable {

	private:
		std::map<std::string, std::unique_ptr<BtrfsMetrics>> _metrics;

	public:
		std::vector<prometheus::MetricFamily> Collect() override;
	};

};

