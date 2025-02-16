#pragma once
#include "XMLNode.hpp"
#include <vector>
#include <stdexcept>

class ValidationError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class Validator {
public:
    static void validate(const std::vector<XMLNode>& nodes);
};
