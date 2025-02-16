#include "XMLNode.hpp"

XMLNode::XMLNode(int id, const std::string& name, const std::vector<int>& ports)
    : id(id), name(name), ports(ports) {}

bool XMLNode::isOrphan() const {
    return ports.size() == 1 && ports[0] == -1;
}
