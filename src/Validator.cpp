#include "Validator.hpp"
#include <unordered_set>

bool Validator::hasDuplicateIDs(const std::vector<XMLNode>& nodes) {
    std::unordered_set<int> ids;
    for (const auto& node : nodes) {
        if (ids.count(node.id)) return true;
        ids.insert(node.id);
    }
    return false;
}

bool Validator::validatePorts(const std::vector<XMLNode>& nodes) {
    std::unordered_set<int> validIds;
    for (const auto& node : nodes) validIds.insert(node.id);

    for (const auto& node : nodes) {
        for (int port : node.ports) {
            if (port != -1 && !validIds.count(port)) return false;
        }
    }
    return true;
}

std::vector<XMLNode> Validator::findOrphans(const std::vector<XMLNode>& nodes) {
    std::vector<XMLNode> orphans;
    for (const auto& node : nodes) {
        if (node.ports.size() == 1 && node.ports[0] == -1) {
            orphans.push_back(node);
        }
    }
    return orphans;
}
