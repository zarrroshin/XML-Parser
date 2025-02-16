#include "XMLParser.hpp"
#include "pugixml.hpp"
#include <stdexcept>

std::vector<XMLNode> XMLParser::parse(const std::string& filename) {
    pugi::xml_document doc;
    if (!doc.load_file(filename.c_str())) {
        throw std::runtime_error("خطا در بارگذاری فایل XML");
    }

    std::vector<XMLNode> nodes;
    for (pugi::xml_node node : doc.child("system").children("node")) {
        int id = node.child("id").text().as_int();
        std::string name = node.child("name").text().as_string();
        
        std::vector<int> ports;
        for (pugi::xml_node port : node.child("port").children("to")) {
            ports.push_back(port.text().as_int());
        }

        nodes.emplace_back(id, name, ports);
    }
    return nodes;
}
