#pragma once
#include <vector>
#include <string>

class XMLNode {
public:
    int id;
    std::string name;
    std::vector<int> ports;

    XMLNode(int id, const std::string& name, const std::vector<int>& ports);
    bool isOrphan() const;
};
