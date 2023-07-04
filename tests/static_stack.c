/*#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include <libdstruct.h>

int
main(void) {
    StaticStack *my_static_stack = static_stack_new(10);
    int32_t i;
    for (i = 0; i < 10; i++) {
        static_stack_insert(my_static_stack, i * 5);
    }
    printf("%d\n", static_stack_extract(my_static_stack));
    static_stack_print(my_static_stack);
}
*/