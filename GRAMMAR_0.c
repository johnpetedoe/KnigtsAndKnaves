# include <stdbool.h>
# include <stdlib.h>

typedef struct    s_symbol {
    bool    is_terminal;
    char    *label;
}                 t_symbol;

typedef 
t_symbol  *new_symbol(bool is_terminal, char *label) { 
    t_symbol  *symbol;

    symbol = (symbol*)malloc(sizeof(t_symbol));
    symbol->is_terminal = is_terminal;
    symbol->label = label;
    return (symbol);
}

int main (void) {
    t_symbol *ABSTRACTION;
  
    ABSTRACTION = new_symbol(false, ABSTRACTION); 
    
    return (0);
}
