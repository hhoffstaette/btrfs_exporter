
#include <memory>
#include <mutex>
#include <prometheus/exposer.h>
#include "BtrfsRegistry.h"

int main(int argc, char **argv) {

	using namespace btrfs_exporter;
	using namespace prometheus;
	using namespace std;

	// create a _metrics registry with component=main labels applied to all its metrics
	shared_ptr<BtrfsRegistry> registry = make_shared<BtrfsRegistry>();

	// create an http server running on port 8080
	Exposer exposer{"127.0.0.1:8080"};

	// ask the exposer to scrape the registry on incoming scrapes
	exposer.RegisterCollectable(registry);

	// wait forever (or SIGTERM)
	mutex m;
	m.lock();
	m.lock();

	return 0;
}

