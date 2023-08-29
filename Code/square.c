#include <stdio.h>
#include <string.h>

#include "help_func.h"
#include "control_function.h"
#include "val_output.h"

//Constants for starting or terminating a program
const int EXIT = 0;
const int CONT = 1;

//Declaration of constants for program mode selection
char *FILE_MODE     = "file";
char *PROGRAMM_MODE = "programm";  

//Constants for Printing Input Errors
char *ERROR_START_INPUT   = "Incorrect symbol. Please enter again\n Enter \"1\" if you want to start solving the equation."
                            "If you want to end the program enter \"0\"\n";
char *ERROR_STRING_INPUT  = "Incorrect string.\n";

int main (void) {

  //Printing program information
  printf ("# Square Solution\n");
  printf ("# Shipilov Stepan 2023\n");

  //Program launch menu
  int flag = CONT;

  while (flag == CONT) { 

    printf ("\nEnter \"1\" if you want to start solving the equation. "
    "If you want to end the program enter \"0\"\n"); 

    //We get the user's response. End the program or continue. 
    input_data (&flag, ERROR_START_INPUT);
    
    while (flag != CONT && flag != EXIT) {      

      input_data (&flag, ERROR_START_INPUT); 

    }

    //If the user decides to run the program, then you will need to select the data acquisition mode.
    //If the user decides to end the program, then the application will exit.  
    if (flag != EXIT) {

      //Choosing a data source for solving an equation
      char type_input[MAX_STRING_LENGTH] = "";

      printf ("If you want to use data from a file, write \"file\".\n"
      "If you want to enter the data yourself, write to \"programm\".\n");

      //Getting data about the selected mode
      input_string (type_input, ERROR_STRING_INPUT);
      
      while (strcmp (type_input, PROGRAMM_MODE) != 0 && strcmp (type_input, FILE_MODE) != 0) {

        printf ("%s", "Incorrect string. Please write \"file\" or \"programm\" \n");

        input_string (type_input,ERROR_STRING_INPUT);

      }

      //Starting the program depending on the selected mode
      //If the manual input mode is selected, the "control_programm()"" function will start. 
      //If the data is read from the file, then "control_file()" will start
      if (strcmp (type_input, PROGRAMM_MODE) == 0) {

        control_programm (); 
         
      } 
      else {

        control_file ();

      } 

    } 
    else { 

      break;

    }
    
  }

  return 0;

} 
