#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "help_func.h"

//The function compares double numbers for equality. Returns true if they are equal and false if not
bool compare_eq (double first, double second) {

    if (fabs (first - second) < EPS) {

        return true;

    } 
    else {

        return false;

    }

}

//The function clears the input buffer
void clear_buffer () {

    while (getchar () != '\n');

}

//The function compares two double numbers. 
//It takes two doubles as input. 
//If the numbers are equal returns 0, if the first is greater than the second 1, if the first is less than the second -1
int compare_doubles (double first, double second) {    

    if (fabs (first - second) < EPS) {

        return COMP_EQ;

    }
    else if ((first - second) > EPS) {

        return COMP_MORE;

    }
    else {

        return COMP_LESS;

    }

}
