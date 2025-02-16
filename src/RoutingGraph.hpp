#pragma once
#include <vector>
#include <unordered_map>
#include "XMLNode.hpp"

class RoutingGraph {
    std::unordered_map<int, std::vector<int>> adjacencyList;

public:
    void build(const std::vector<XMLNode>& nodes);
    std::vector<int> findPath(int start, int end) const;

private:
    std::vector<int> reconstructPath(const std::unordered_map<int, int>& predecessors, int end) const;
};
