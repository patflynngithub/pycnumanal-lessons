/* Compute l2 vector norm and timing to do so */

/*
   - used gcc compiler

         gcc -o l2vecnorm l2vecnorm.c -std=gnu99 -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main( int argc, char *argv[]) {

    // get vector (array) size from command line argument
    int n = atoi(argv[1]);

    double u[n];

    // initialize vector (array) by incrementing by 1 from 0
    for (int i = 0; i < n; ++i) {
        u[i] = i;
    }

    clock_t start_ticks = clock(); // current CPU clock tick count

    // compute l2-norm of vector (array)
    double accum = 0.;
    for (int i = 0; i < n; ++i) {
        accum += u[i] * u[i];
    }
    double norm = sqrt(accum);

    // figure out timing
    clock_t end_ticks = clock();  // current CPU clock tick count
    clock_t cpu_ticks = end_ticks - start_ticks; // elapsed CPU clock ticks
    double cpu_time_used = ((double) cpu_ticks) / CLOCKS_PER_SEC; // converts to CPU time

    // printf("%ld\n", cpu_ticks);
    printf("%f\n", cpu_time_used);
}

