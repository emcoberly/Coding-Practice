#include "Math.h"

int combination(int n, int choose) {
    int n_fact = factorial(n);
    int r_fact = 1;
    int nr_fact = 1;
    if (choose != 0) {
        r_fact = factorial(choose);
    }
    if ((n - choose) != 0) {
        nr_fact = factorial(n - choose);
    }

    return n_fact / (r_fact * nr_fact);
}