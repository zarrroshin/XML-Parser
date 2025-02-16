#pragma once
#include "XMLNode.hpp"
#include <vector>
#include <stdexcept>

class XMLParser {
public:
    std::vector<XMLNode> parse(const std::string& filename);
};
