
#pragma once

#include <string>
#include <vector>

namespace btrfs {

bool btrfs_is_available();

std::vector<std::string> mounted_filesystems();

std::string label(std::string &uuid);

long clone_alignment(std::string &fsid);

long nodesize(std::string &fsid);

long quota_override(std::string &fsid);

long sectorsize(std::string &fsid);

std::vector<std::string> devices(std::string &fsid);

std::vector<std::string> features(std::string &fsid);

long allocation_global_rsv_size(std::string &fsid);

long allocation_global_rsv_reserved(std::string &fsid);

std::string allocation_system_profile(std::string &fsid);

std::string allocation_metadata_profile(std::string &fsid);

std::string allocation_data_profile(std::string &fsid);

};
