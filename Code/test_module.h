#include "math.h"

struct ref_data {
    int    type;
    double coeffs[3];
    double roots[2];
};

void test_one     (int type, double*coeffs, double* roots);
int test_elements (int type_eq, double* coeffs);
int test_pointer  (double* pointer);