#include "exception.hpp"

Exception::Exception(ExType type) : type(type) {}

ExType Exception::GetType() {
    return type;
}