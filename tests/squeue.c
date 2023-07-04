/*#include <stdlib.h>
#include <stdint.h>

#include <libdstruct.h>

int main(void) {
    SNode *squeue = NULL;

    int32_t i;
    for (i = 0; i < 6; i++) {
        squeue_enqueue(&squeue, snode_new(i * 10));
    }

     0 -> 10 -> 20 -> 30 -> 40 -> 50 
    squeue_print(squeue);

     20 -> 30 -> 40 -> 50 
    squeue_dequeue(&squeue);
    squeue_dequeue(&squeue);
    squeue_print(squeue);

     20 -> 30 -> 40 -> 50 -> 60 -> 70 
    squeue_enqueue(&squeue, snode_new(60));
    squeue_enqueue(&squeue, snode_new(70));
    squeue_print(squeue);

    return 0;
}
*/