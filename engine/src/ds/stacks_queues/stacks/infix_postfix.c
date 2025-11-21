#include "dsa/stacks_queues.h"
#include <string.h>
#include <ctype.h>

static int prec(char c) {
    if (c == '^') return 3;
    if (c == '/' || c == '*') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void dsa_stack_infix_to_postfix(SimulationContext* ctx, char* infix, char* postfix) {
    Stack* s = dsa_stack_create(ctx, strlen(infix));
    int k = 0;
    
    dsa_log_info(ctx, "Converting Infix to Postfix");

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        
        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            dsa_stack_push(ctx, s, '(');
        } else if (c == ')') {
            while (!dsa_stack_isempty(s) && dsa_stack_peek(ctx, s) != '(') {
                postfix[k++] = (char)dsa_stack_pop(ctx, s);
            }
            dsa_stack_pop(ctx, s); // Pop '('
        } else {
            while (!dsa_stack_isempty(s) && prec(c) <= prec((char)dsa_stack_peek(ctx, s))) {
                postfix[k++] = (char)dsa_stack_pop(ctx, s);
            }
            dsa_stack_push(ctx, s, c);
        }
    }
    while (!dsa_stack_isempty(s)) {
        postfix[k++] = (char)dsa_stack_pop(ctx, s);
    }
    postfix[k] = '\0';
    dsa_log_info(ctx, postfix); // Log Result
}
