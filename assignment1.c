/*
Name:Ethan Crosbie, TU856/1, C22351646
Last date edited: 20/11/22

description: a bank system that allows a user to input their pin number and check to see if it is correct,
it also allows the user to change their pin,
it also allows the user to view how many times their pin was entered correctly or incorrectly
the program runs until the user decides to end the program
*/

# include <stdio.h>
# define SIZE 5


int main()
{
    int 
    //correct and incorrect are used in cases 1 and 3, they are used to know how many times the pin is inputed correctly or incorrectly
    correct = 0,
    incorrect = 0,

    run = 1,    // used in the do while loop to decide whether the program should be running, changes in case 4
    i,  // used in a for loop
    j,  // used in a for loop
    num_count = 0;  // this value is iterated when a valid character is inputed in case 2,

    char 
    choice,
    tpin[SIZE],  //temporary pin values
    cpin[SIZE], //pin values used in the changing of pins
    pin[SIZE] = {'1','2','3','4'};  // initial pin values


    do
    {
        printf("\n=== Welcome to TUB, would you like to: ===\n");
        printf("(1)Verify your pin\n");
        printf("(2)Change pin\n");
        printf("(3)Display the number of times the pin has been entered correctly and incorrectly\n");
        printf("(4)Exit\n");

        choice = getchar(); //reads in the choice for the switch statement

        switch(choice)
        {
            case '1'  :    //validates a pin entered by the user against the pin value stored
            {

                printf("Please enter your pin:\n");
                scanf("%4s",tpin); //I used a string here rather than a character array because that's all a character array is.

                //checks the temporarily stored pins against the pins and makes sure that they are all equal to their corresponding pin.
                if ((tpin[0] == pin[0]) && (tpin[1] == pin[1]) && (tpin[2] == pin[2]) && (tpin[3] == pin[3]))
                {
                    //the variable increments by 1 and can then be displayed in case 3 to show how many times the pin has been entered correctly
                    correct ++;
                    printf("you have entered the correct pin\n\n");
                }//end if

                //if any other value other than the correct value is entered it will return an error
                else
                {
                    /*the variable increments by 1 and can then be displayed in case 3 to show how many times the pin has been entered correctly*/
                    incorrect++;
                    printf("you have entered an incorrect pin\n\n");
                }//end else

                break;
            }//end case1



            case '2' :    // change pin
            {
                printf("Please enter your new 4 digit pin on on line and then press return:\n");
                
                num_count = 0;  // num_count is reset to zero

                while(getchar() != '\n');   // as long as the character isn't a return statement  

                scanf("%5s",tpin);    // reads in the temporary pin
                for (i = 0;i<SIZE;i++)  // this will loop through the elements of the array
                {

                    /* this checks if the inputed value is between 0 and 9, if so it will increase num_count, 
                    this is how I check to see if an invalid character is inputed */
                    if (tpin[i] == '0' || tpin[i] == '1' || tpin[i] == '2' || tpin[i] == '3' || tpin[i] == '4' || tpin[i] == '5' || tpin[i] == '6' || tpin[i] == '7' || tpin[i] == '8' || tpin[i] == '9' )
                    {
                        num_count++;
                    }// end if                      
                    
                }// end for
                
                // the following is where the user can re-enter a new pin.
                printf("Please re-enter your new pin:\n");

                while(getchar() != '\n');   // as long as the character isn't a return statement  

                scanf("%5s",cpin);    // reads in the temporary pin
                for (i = 0;i<SIZE;i++)
                {
                    /*this checks if the inputed value is between 0 and 9, if so it will increase num_count, 
                    this is how I check to see if an invalid character is inputed */                   
                    if ( cpin[i] == '0' || cpin[i] == '1' || cpin[i] == '2' || cpin[i] == '3' || cpin[i] == '4' || cpin[i] == '5' || cpin[i] == '6' || cpin[i] == '7' || cpin[i] == '8' || cpin[i] == '9' )
                    {
                        num_count++;
                    }
                }// end for loop
                

                if (num_count != 8)    // this will only be true if an invalid character is inputed
                {
                    printf("An invalid value has been entered, please make sure that each pin is 4 digit pin with numbers between 0 and 9.\n");
                    /*technically the user isn't entring an integer, 
                    but telling them to enter a character between 0 and 9 could cause confusion*/
                    
                }// end if
                
                else if (cpin[0] == tpin[0] && cpin[1] == tpin[1] && cpin[2] == tpin[2] && cpin[3] == tpin[3])//validation check
                {
                    /*This code only runs when the pins have been validated and proven to be equal to each other, 
                    this overwrites the current pin value and replaces it with a new value.*/
                    printf("pins match\n");

                    for(i = 0;i< SIZE;i++)  // this loop just changes the values of the main pin values to the new pin values
                    {
                        pin[i] = cpin[i];
                    }

                }// end else if

                else    // in case they enter valid values but the pins don't match
                {
                    printf("incorrect pin entered, please make sure the pins match and are 4 digits long.\n");
                }// end else
                break;
            }// end case2



            case '3' :    // incorrect + correct display
            {
                // these values are incremented by 1 in case 1 when a pin is entered either correctly or incorrectly.
                printf("Correct: %d\n",correct);
                printf("Incorrect %d\n",incorrect);

                break;
            }// end case3

            case '\n':
            {
                printf("invalid input"); 
                break;
            }

            case '4' :    // this case is for exiting the program
            {
                printf("program closed\n");
                run = 0;    // this closes the program
                break;
            }// end case4

            default :    // if any value other than 1 to 4 is entered an error message will be shown
            {
                printf("\nINPUT ERROR\nPlease enter a value between 1 and 4\n");
                break;
            }// end default

        }// switch end
    
    
    while (getchar() != '\n');
    }while(run == 1);   // the code only ends once run is set to 0 which only happens in case 4
 
}// end main