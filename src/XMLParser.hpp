#pragma once
#include <vector>
#include <string>
#include "XMLNode.hpp"

class XMLParser {
public:
    std::vector<XMLNode> parse(const std::string& filename);
};
