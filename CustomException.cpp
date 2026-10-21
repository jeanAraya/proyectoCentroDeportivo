#include "CustomException.h"

CustomException::CustomException(const std::string& mensaje) {
    this->mensaje = mensaje;
}

CustomException::~CustomException() noexcept {
}

const char* CustomException::what() const noexcept {
    return mensaje.c_str();
}

std::string CustomException::getMensaje() const {
    return mensaje;
}