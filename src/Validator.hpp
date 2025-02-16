#pragma once
#include "XMLNode.hpp"
#include <vector>

class Validator {
public:
    static bool hasDuplicateIDs(const std::vector<XMLNode>& nodes);
    static bool validatePorts(const std::vector<XMLNode>& nodes);
    static std::vector<XMLNode> findOrphans(const std::vector<XMLNode>& nodes);
};
