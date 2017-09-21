//
//  IntToRoman.c
//  
//
//  Created by Zachary Sedefian on 9/20/17.
//
//

#include "IntToRoman.h"

void intToRoman(unsigned int num, char *r);

/* int argc, char *argv[] */

int main(void){
    
    printf("\033c"); //clear terminal screen
    char *r; //output string
    int input = 1; //user prompted to enter this value. 1 so that enters while. 0 is exit.
    int running = 1; //set to 0 to end loop
    char q; //set this char to q to quit program.
    
    while( q != 'q' && q != 'Q' ){
        //Prompt user and store input
        printf("Enter a number to convert it to a Roman numeral: ");
        scanf("%d", &input);
        
        //Pass params to conversion function
        intToRoman(input, r);
        
        //Output formatting. Show the user the input, then print as many equal signs
        //as there is length of the roman numeral output (on each side).
        printf("%d in Roman numerals is...\n", input);
        int i;                                          //iterator
        for(i = 0; i < strlen(r); i++)                  //print separating symbols (top)
            printf("=");
        printf("\n%s\n", r);                            //show output string
        for(i = 0; i < strlen(r); i++)                  //print separating symbols (bottom)
            printf("=");
        printf("\n");
        
        //Stall program until enter key pressed. Then clear terminal window text.
        printf("Press enter to continue, type q to quit.\n");
        while ( getchar() != '\n') {
            //To be honest, I'm not sure why this empty loop works, but it does.
        }
        q = getchar();
        printf("\033c");
    }
    
    return 0;
}

void intToRoman(unsigned int num, char *r){
    
    //Arrays of strings to be referenced, as well as size the output string should
    //be for each string respectively.
    char *C[] = {"", "C", "CC", "CCC", "DC", "D", "DC", "DCC", "DCCC", "CM"};
    char *X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int size[] = {0,  1,    2,     3,    2,   1,    2,     3,      4,    2};
    
    //For each 1000 in the integer, print an M (and subtract 1000 from the input)
    while(num >= 1000){
        *r++ = 'M';
        num -= 1000;
    }

    /*
      Now the number has no thousands place. Divide the number by 100 to get
      the integer in its hundreds place, and use that digit as an index on the
      string array that holds the C (hundreds) values.  Add its size component
      to the output r (e.g. if II, then add 2 spots for each I). Finally remove 
      the hundreds place by using the modulus operator and setting num to its 
      new value (consisting of tens and ones places).
    */
    strcpy(r, C[num/100]);
    r += size[num/100];
    num %= 100;
    
    //Same process as above but with tens.
    strcpy(r, X[num/10]);
    r += size[num/10];
    num %= 10;
    
    //And again with ones place.
    strcpy(r, I[num/1]);
    r += size[num/1];
    
    //End string with null character.
    *r = '\0';
}
