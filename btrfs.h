
#pragma once

#include <string>
#include <vector>

namespace btrfs {
    bool btrfs_is_available();
    std::vector<std::string> mounted_filesystems();
    std::string label(const std::string& uuid);
    long clone_alignment(const std::string& fsid);
    long nodesize(const std::string& fsid);
    long quota_override(const std::string& fsid);
    long sectorsize(const std::string& fsid);
    std::vector<std::string> devices(const std::string& fsid);
    std::vector<std::string> features(const std::string& fsid);
    long allocation_global_rsv_size(const std::string& fsid);
    long allocation_global_rsv_reserved(const std::string& fsid);
    std::string allocation_system_profile(const std::string& fsid);
    std::string allocation_metadata_profile(const std::string& fsid);
    std::string allocation_data_profile(const std::string& fsid);
};

