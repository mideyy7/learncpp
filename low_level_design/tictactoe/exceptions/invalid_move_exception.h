#include <stdexcept>
#include <string>

class InvalidMoveException : public std::runtime_error {
    public:
        explicit InvalidMoveException( const std::string& message): runtime_error(message) {}
};