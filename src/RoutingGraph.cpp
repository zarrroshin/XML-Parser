#include "RoutingGraph.hpp"
#include <queue>
#include <algorithm>

void RoutingGraph::build(const std::vector<XMLNode>& nodes) {
    adjacencyList.clear();
    for (const auto& node : nodes) {
        adjacencyList[node.id] = {};
        for (int port : node.ports) {
            if (port != -1) {
                adjacencyList[node.id].push_back(port);
            }
        }
    }
}

std::vector<int> RoutingGraph::findPath(int start, int end) const {
    std::unordered_map<int, int> predecessors;
    std::queue<int> q;
    q.push(start);
    predecessors[start] = -1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjacencyList.at(current)) {
            if (predecessors.find(neighbor) == predecessors.end()) {
                predecessors[neighbor] = current;
                q.push(neighbor);
                if (neighbor == end) {
                    return reconstructPath(predecessors, end);
                }
            }
        }
    }
    return {};
}

std::vector<int> RoutingGraph::reconstructPath(const std::unordered_map<int, int>& predecessors, int end) const {
    std::vector<int> path;
    for (int at = end; at != -1; at = predecessors.at(at)) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());
    return path;
}
