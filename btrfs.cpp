
#include <filesystem>
#include <fstream>
#include "btrfs.h"

namespace btrfs {

using namespace std;
using namespace std::filesystem;

static const path BTRFS_SYSFS_ROOT = "/sys/fs/btrfs";

static string read_string(string &fsid, path &&attribute_path) {
	string value;
	getline(ifstream(BTRFS_SYSFS_ROOT / fsid / attribute_path, ios::binary), value);
	return value;
}

static long read_number(string &fsid, path &&attribute) {
	string value = read_string(fsid, move(attribute));
	return (value.empty() ? -1 : stol(value));
}

bool btrfs_is_available() {
	return directory_entry(BTRFS_SYSFS_ROOT).exists();
}

vector<std::string> mounted_filesystems() {
	vector<string> filesystems;

	if (btrfs_is_available()) {
		for (auto &entry: directory_iterator(BTRFS_SYSFS_ROOT)) {
			string fsid = entry.path().filename();
			if (fsid != "features") {
				filesystems.push_back(fsid);
			}
		}
	}

	return filesystems;
}

string label(string &fsid) {
	return read_string(fsid, "label");
}

long clone_alignment(string &fsid) {
	return read_number(fsid, "clone_alignment");
}

long nodesize(string &fsid) {
	return read_number(fsid, "nodesize");
}

long quota_override(string &fsid) {
	return read_number(fsid, "quota_override");
}

long sectorsize(string &fsid) {
	return read_number(fsid, "sectorsize");
}

vector<string> devices(string &fsid) {
	vector<string> devices;

	for (auto &entry: directory_iterator(BTRFS_SYSFS_ROOT / fsid / "devices")) {
		devices.push_back(entry.path().filename());
	}

	return devices;
}

vector<string> features(string &fsid) {
	vector<string> features;

	for (auto &entry: directory_iterator(BTRFS_SYSFS_ROOT / fsid / "features")) {
		features.push_back(entry.path().filename());
	}

	return features;
}

long allocation_global_rsv_size(string &fsid) {
	return read_number(fsid, "allocation/global_rsv_size");
}

long allocation_global_rsv_reserved(string &fsid) {
	return read_number(fsid, "allocation/global_rsv_reserved");
}

string allocation_system_profile(string &fsid) {
	return "single";
}

string allocation_metadata_profile(string &fsid) {
	return "single";
}

string allocation_data_profile(string &fsid) {
	return "single";
}

};

