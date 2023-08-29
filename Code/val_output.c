#include <stdio.h>
#include <math.h>

#include "help_func.h"
#include "val_output.h"
#include "test_module.h"
#include "mathematical.h"
#include "control_function.h"

//Error text for incorrect character entry.
char *ERROR_INCORECT_SYMBOL = "Incorrect symbol. Please enter again\n";

//The function handles user input. 
//It takes as the first argument a variable into which the data will be written. 
//The second is the error text that will be displayed in case of unsuccessful data recording.
//Recorded numeric information
void input_data (int* data, char* message_error){

  while (scanf ("%d", data) != 1){

    printf ("%s", message_error);
    clear_buffer ();

  }  
  clear_buffer ();

}

//The function handles user input. 
//It takes as the first argument a variable into which the data will be written. 
//The second is the error text that will be displayed in case of unsuccessful data recording.
//Recorded string information
void input_string (char* data, char* message_error){

  while (scanf ("%s", data) != 1){

    printf ("%s", message_error);
    clear_buffer ();

  }
  clear_buffer ();

}

//The function prompts the user for the type of equation to be solved. 
//Returns the degree of an equation. First or second
int choose_eq (){

  int type_equation = 0;

  printf ("Enter the equations of which degree you want to solve (1 or 2). \n");
  input_data (&type_equation, ERROR_INCORECT_SYMBOL);  

  while (type_equation != 1 && type_equation != 2) {

      printf ("I can't find an equation of that degree. Enter degree again. \n");
      input_data (&type_equation, ERROR_INCORECT_SYMBOL); 

  }

  return type_equation;

}

//The function asks the user for the coefficients of the equation and writes them to an array. 
//It takes as arguments the degree of the equation, a pointer to an array of coefficients.
void get_coeff (int type_eq, double* coeff_arr) {

    if (test_pointer (coeff_arr)) {

      const char START_COEFF = 'A';

      for (int i = 0; i <= type_eq; i++) {  

        printf ("Enter the coefficient %c\n", START_COEFF + i);        

        while (scanf ("%lg", coeff_arr + i) != 1) {

            printf ("Input error,please enter coefficient %c again\n", START_COEFF + i);
            clear_buffer ();

        }
        clear_buffer ();

      } 
      
    }    

}

//The function displays the obtained roots of the equation. 
//The function argument takes the number of roots, and a pointer to an array of roots.
void output_roots (int count_roots, double* roots) {    

    if (test_pointer (roots) && test_elements (count_roots-1, roots)) {
      
      switch (count_roots) {    

        case NOT_ROOTS: 

                printf("The equation has not roots\n");
                break;

        case ONE_ROOT: 

                printf("Solution of the equation X = %lg \n", roots[0]);
                break;

        case TWO_ROOT:

                printf("Solution of the equation:\n X1 = %lg \n X2 = %lg \n", roots[0],roots[1]);
                break;

      }  

    }      

}