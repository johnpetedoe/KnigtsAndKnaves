# include <stdbool.h>
# include <stdlib.h>

typedef struct     s_symbol {
    bool     is_terminal;
    char*    label;
}                 t_symbol;

typedef struct     s_grammar {
    t_symbol**    non_terminal_symbols;
    t_symbol**    terminal_symbols;
    t_rule**      production_rules;
}

t_symbol  *new_symbol(bool is_terminal, char *label) { 
    t_symbol  *symbol;

    symbol = (symbol*)malloc(sizeof(t_symbol));
    symbol->is_terminal = is_terminal;
    symbol->label = label;
    return (symbol);
}

t_grammar    *new_grammar(t_symbol **terminal_symbols, t_symbol **non_terminal_symbols, t_rule **production_rules) {
    t_grammar *grammar; 
        
    grammar = (t_grammar*)malloc(sizeof(t_grammar));

    grammar->terminal_symbols = terminal_symbols;
    grammar->non_terminal_symbols = non_terminal_symbols;
    grammar->production_rules = production_rules;

    return (grammar);
}

t_formula **produce_language(int breadth, int depth) {}
    
int main (void) {
    t_grammar *grammar_0;
    t_symbol *ABSTRACTION;

    ABSTRACTION = new_symbol(false, ABSTRACTION); 
    
    grammar = new_grammar({
        //TODO: define, instanciate, pass terminal symbols
    }, {
        ABSTRACTION,
        
    }, {
        //TODO: define, instanciate, pass production rules
    })

    produce_language(grammar);        
    return (0);
}
