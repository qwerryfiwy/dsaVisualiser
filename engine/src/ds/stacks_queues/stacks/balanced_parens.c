#include "dsa/stacks_queues.h"

bool dsa_stack_balanced_parens(SimulationContext* ctx, char* expr) {
    Stack* s = dsa_stack_create(ctx, 20);
    dsa_log_info(ctx, "Checking Balanced Parentheses");

    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            dsa_stack_push(ctx, s, expr[i]);
            continue;
        }
        if (dsa_stack_isempty(s)) return false;

        char check;
        switch (expr[i]) {
        case ')':
            check = dsa_stack_pop(ctx, s);
            if (check == '{' || check == '[') return false;
            break;
        case '}':
            check = dsa_stack_pop(ctx, s);
            if (check == '(' || check == '[') return false;
            break;
        case ']':
            check = dsa_stack_pop(ctx, s);
            if (check == '(' || check == '{') return false;
            break;
        }
    }
    return dsa_stack_isempty(s);
}
