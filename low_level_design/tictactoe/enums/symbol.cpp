enum class Symbol {
    X,
    O,
    EMPTY
};

char get_display_char(Symbol symbol) {
    switch(symbol) {
        case Symbol::X: return 'X';
        case Symbol::O: return 'O';
        case Symbol::EMPTY: return '-';
        default: return '?';
    }
}