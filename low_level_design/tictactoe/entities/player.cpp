#include <string>
#include "enums/symbol.h"
#include "exceptions/invalid_move_exception.h"


class Player {
private:
    const std::string name_;
    const Symbol symbol_;

public:
    Player (const std::string& name, Symbol symbol) 
        : name_(name), symbol_(symbol) {
            if (symbol == Symbol::EMPTY) {
                throw InvalidMoveException("Player cannot have EMPTY SYMBOL");
            }
        }
    
    const std::string& get_name() const {
        return name_;
    }
    Symbol get_symbold() const {
        return symbol_;
    }
    std::string to_string() const {
        return name_ + " (" + get_display_char(symbol_) + " )";
    }
};