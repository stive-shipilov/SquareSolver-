#include <stdio.h>
#include <stdbool.h>

#include "mathematical.h"
#include "test_module.h"
#include "math.h"

//The function tests an array element for correctness.
//The function tests an array element for correctness. 
//Takes as input the degree of the equation and a pointer to the array to be checked
//Returns true if the test succeeds, and returns false if the test fails, printing an error.
int test_elements (int type_eq, double* coeffs) {

    for (int i = 0; i <= type_eq; i++) {

        if (isnan (coeffs[i])) {

            printf ("Invalid element of array");
            return false;

        }

    }

    return true;

}

//The function checks the pointer for correctness. Takes a pointer as input
//Returns true if the test succeeds, and returns false if the test fails, printing an error.
int test_pointer (double* pointer) {

    if(pointer == 0) {

        printf ("Invalid pointer");
        return false;

    } 
    else {

        return true;

    }

}

//Tests the correctness of the function for solving a quadratic equation. 
//It takes as input an equation type, a pointer to an array of constant coefficients, and a pointer to an array of constant roots of the equation.
// Returns "Ok" for each successful test and "Not ok" for failed
void test_one (int type, double*coeffs, double* roots) {

    double roots_tests[type] = {};
    double count_roots = 0;

    if (square_solver (type, coeffs, roots_tests) == 2) {

        if ((roots_tests[0] == roots[0] && roots_tests[1] == roots[1]) || 
            (roots_tests[1] == roots[0] && roots_tests[0] == roots[1])
            ) {

            printf("Ok\n");

        }
        else {

            printf("Not ok\n");

        }

    }
    else {

        if (roots_tests[0] == roots[0]) {

            printf("Ok\n");

        }
        else {

            printf("Not ok\n");

        }

    }
}