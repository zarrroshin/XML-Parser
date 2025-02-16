#pragma once
#include <vector>
#include <string>

class XMLNode {
public:
    int id;
    std::string name;
    std::vector<int> ports;
    
    XMLNode(int id, std::string name, std::vector<int> ports)
        : id(id), name(name), ports(ports) {}
};
