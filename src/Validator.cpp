#include "Validator.hpp"
#include <unordered_set>

void Validator::validate(const std::vector<XMLNode>& nodes) {
    std::unordered_set<int> ids;
    
    // Check duplicate IDs
    for (const auto& node : nodes) {
        if (!ids.insert(node.id).second) {
            throw ValidationError("شناسه تکراری: " + std::to_string(node.id));
        }
    }

    // Check invalid port references
    for (const auto& node : nodes) {
        for (int port : node.ports) {
            if (port != -1 && !ids.count(port)) {
                throw ValidationError("ارجاع به گره ناموجود: " + std::to_string(port));
            }
        }
    }
}
