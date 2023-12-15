# Thermal Distribution Simulation

CPE Fall '23 Assignment 4

## Project Objective
This project simulates the temperature distribution across a thin metal plate bordered by constant (isothermal) temperatures as decided by User input. The code returns the resulting thermal distribution data stored in an image file once an acceptable thermal equilibrium, based on a tolerance value decided by the user, is achieved.

## User Manual
- To execute the program, compile and run the code found in the file named main.cpp 
- The user will be prompted to enter their desired menu option from a menu of six options.
- Once the user enters their desired menu option, the following will happen:
  - If the user entered (1):
    - The user will be prompted to enter the desired number of rows and columns to create a new thermal grid
      - If the input is valid, a dynamic 2D array will be created, and the program will print a message confirming its creation. Options 2-5 will only work once this has been done.
      - If the input is invalid, an error message will be displayed and the user will return to the main menu
  - If the user entered (2):
    - The program will check if a thermal grid has been created using option (1). If it hasn’t, the program will print a message warning the user to create a grid first, then return to menu
    - The user will be prompted to enter the initial temperatures of the top, bottom rows and left and right columns of the thermal grid. Once this has been done, the program will print a confirmation message
    - If the user has inputted a nonnegative salinity value after using option (1), then the output screen will show the salinity value’s corresponding calculated temperature value. The program will return to the main menu. 
  - If the user entered (3):
    - The program will check if a thermal grid has been created using option (1). If it hasn’t, the program will print a message warning the user to create a grid first, then return to menu
    - The program will prompt the user to enter the coordinates of the desired stimulation point.
      - If the coordinates do not point to an interior point, the program will print a message notifying the user that their input is invalid, then return to the main menu
    - The program will prompt the user to enter the temperature of the desired stimulation point, then print a confirmation message
  - If the user entered (4):
    - The program will check if a thermal grid has been created using option (1). If it hasn’t, the program will print a message warning the user to create a grid first, then return to menu
    - The program will prompt the user for a tolerance value
      - If the tolerance value is less than 0, the program will print a message notifying the user that their input is invalid, then return to the main menu
      - If the tolerance value is valid, the program will calculate the thermal dissipation using the tolerance value and print a confirmation message
  - If the user entered (5):
    - The program will check if a thermal grid has been created using option (1). If it hasn’t, the program will print a message warning the user to create a grid first, then return to menu
    - The program will print out the thermal grid on the output screen.
  - If the user entered (6):
    - The program will print a terminating message, and the program will terminate.
    - If the user entered a value besides 1, 2, 3, 4, 5, or 6:
      - The program will notify the user that they have entered an invalid menu option, then return to the main menu.


### Full Project Documentation: 
https://docs.google.com/document/d/1sL8iCxXlbgE_Gg8ZEpufybuF9yuy1DSCG33vMFojblE/edit?usp=sharing
