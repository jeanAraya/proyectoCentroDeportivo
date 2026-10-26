#ifndef CENTRODEPORTIVO_CUSTOMEXCEPTION_H
#define CENTRODEPORTIVO_CUSTOMEXCEPTION_H

#include <exception>
#include <string>
class CustomException : public std::exception {
    std::string mensaje;

public:
    explicit CustomException(const std::string& mensaje);
    ~CustomException() noexcept override;

    const char* what() const noexcept override;
    std::string getMensaje() const;
};

#endif