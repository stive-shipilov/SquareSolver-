#include <stdio.h>
#include <cassert>

#include "val_output.h"
#include "mathematical.h"
#include "test_module.h"
#include "control_function.h"
#include "help_func.h"

//Constant data for checking the program operation
struct ref_data arr[6] = {
                        {.type = 2, .coeffs = {1,-4,3}, .roots = {3,1}},
                        {.type = 2, .coeffs = {1,-4,3}, .roots = {1,3}},
                        {.type = 2, .coeffs = {1,-2,1}, .roots = {1,0}},
                        {.type = 2, .coeffs = {1,1,1},  .roots = {0,0}},
                        {.type = 2, .coeffs = {1,1,1},  .roots = {0,1}},
                        {.type = 2, .coeffs = {0,0,0},  .roots = {INFINITY,0}},
                        };

//The function solves equations if the mode of manual data entry is selected
void control_programm () {

    //choice a type of equation    
    int type_eq = 0;
    type_eq = choose_eq (); 

    //get a coefficients
    double coefficients[type_eq + 1] = {};
    get_coeff (type_eq, coefficients);

    //solve the equation
    double roots[type_eq] = {};
    int count_roots = 0;
    count_roots = square_solver (type_eq, coefficients, roots);

    //Output the roots of equation
    output_roots (count_roots, roots);

    //We consider the length of the data array for the program test
    int length_ar = 0;
    length_ar = sizeof (arr) / sizeof (arr[0]);

    //Displaying test results
    printf ("\nResults of Test \n"); 
    for (int i = 0; i < length_ar; ++i){

        test_one (arr[i].type, arr[i].coeffs, arr[i].roots);

    }
    
}

//The function solves equations if the mode of obtaining data from a file is selected
void control_file() { 

    //Get the name file
    char name_file[MAX_STRING_LENGTH] = "";
    printf ("Write a file name.\n");    
    input_string (name_file, "Incorrect file. Please write again.\n");

    //We open the file.
    struct square data_square = {};
    FILE * ptrFile;
    ptrFile = fopen (name_file, "r");

    //Checking if the file was successfully opened
    if (ptrFile == NULL) { 

        printf ("Failed to open file\n");
        fclose (ptrFile);

    }
    else {    

        //We receive data from the file and, based on them, derive the solution of the equation
        while (fscanf (ptrFile, "%d %lg %lg %lg", &data_square.type,
                                                  data_square.coeff, 
                                                  data_square.coeff+1, 
                                                  data_square.coeff+2) == 4) {
                                                    
            int count_roots = 0;
            double roots[data_square.type] = {};
            count_roots  = square_solver (data_square.type, data_square.coeff, roots);

            //File Output
            output_roots (count_roots, roots);

        } 
        fclose (ptrFile);

    }   
    
}