#include "dsa/stacks_queues.h"
#include <ctype.h>

int dsa_stack_eval_postfix(SimulationContext* ctx, char* postfix) {
    Stack* s = dsa_stack_create(ctx, 20);
    dsa_log_info(ctx, "Evaluating Postfix");

    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            dsa_stack_push(ctx, s, c - '0');
        } else {
            int val1 = dsa_stack_pop(ctx, s);
            int val2 = dsa_stack_pop(ctx, s);
            int res = 0;
            
            switch(c) {
                case '+': res = val2 + val1; break;
                case '-': res = val2 - val1; break;
                case '*': res = val2 * val1; break;
                case '/': res = val2 / val1; break;
            }
            dsa_stack_push(ctx, s, res);
        }
    }
    return dsa_stack_pop(ctx, s);
}
