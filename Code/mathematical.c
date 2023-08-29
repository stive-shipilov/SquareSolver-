#include <stdio.h>
#include <math.h>

#include "help_func.h"
#include "mathematical.h"
#include "test_module.h"

//The function of solving a linear equation. Returns the number of roots obtained. If an error occurs, returns -1.
//It takes as input a pointer to an array with coefficients and a pointer to an array to which the roots will be written.
int line_solver (double* coeff, double* roots) {

    //Checking for the correctness of pointers and for compliance with the type of array elements
    if (test_pointer  (coeff)           &&
        test_pointer  (roots)           && 
        test_elements (1, coeff)        &&
        test_elements (1, roots)) {       

        if(compare_eq (coeff[0], 0)) {

            if(compare_eq (coeff[1], 0)) {   

                roots[0] = INFINITY; 
                return ONE_ROOT;    

            }
            else {

                roots[0] = 0;                
                return NOT_ROOTS;

            }

        } 
        else {

            roots[0] = (-coeff[1])/(coeff[0]);
            return ONE_ROOT;

        }

    } 
    else {

        return ERROR;

    }

}

//The function solves quadratic equations. 
//It takes as input an equation type, a pointer to an array with coefficients, and a pointer to an array with roots. 
//Returns the number of roots. Returns -1 if an error occurs.
int square_solver (int type_eq, double* coeffs, double* roots) {
    
    ////Checking for the correctness of pointers and for compliance with the type of array elements
    if (test_pointer  (coeffs)          && 
        test_pointer  (roots)           &&
        test_elements (type_eq, coeffs) &&
        test_elements (type_eq, roots)) {  

        //If the equation being solved is in fact linear, then the linear equation solution function will run
        if(type_eq == FIRST_DEGREE || (type_eq == SECOND_DEGREE && compare_eq (coeffs[0], 0))) {

            return line_solver (coeffs, roots);   

        } 
        else {
            
            //We consider the discriminant
            double dis = 0;
            dis = coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2];
            
            double dis_sqrt = 0;
            dis_sqrt = sqrt (dis);

            if(compare_doubles (dis, 0) == COMP_MORE) {

                roots[0] = (-coeffs[1] + dis_sqrt) / (2 * coeffs[0]);
                roots[1] = (-coeffs[1] - dis_sqrt) / (2 * coeffs[0]);

                return TWO_ROOT;

            }
            else if (compare_eq (dis, 0)) {

                roots[0] = (-(coeffs[1])) / (2 * coeffs[0]);
                roots[1] = 0;

                return ONE_ROOT;

            }
            else {  

                roots[0] = 0;
                roots[1] = 0;

                return NOT_ROOTS;

            }
            
        }

    } 
    else {

        return ERROR;

    }

}