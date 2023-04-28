#include <stdio.h>
#include <stdint.h>

#include <libdstruct.h>

int 
main(void)
{
    StaticQueue *my_static_queue = static_queue_new(10);
    int32_t i;
    for (i = 0; i < 10; i++) {
        static_queue_insert(my_static_queue, i * 10);
    }
    static_queue_print(my_static_queue);

    return 0;
}
