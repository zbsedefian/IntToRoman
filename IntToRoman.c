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
    
    char *r; //output string
    int input = 1; //user prompted to enter this value. 1 so that enters while. 0 is exit.
    int running = 1; //to end loop
    
    while (running){
        
        //Prompt user and store input
        printf("Enter a number to convert it to a Roman numeral (0 to exit): ");
        scanf("%d", &input);
        
        //If user enters 0, end the loop (and the program)
        if(input == 0)
            break;
        
        //Pass params to conversion function
        intToRoman(input, r);
        
        //Output formatting. Show the user the input, then print as many equal signs
        //as there is length of the roman numeral output (on each side).
        printf("%d in Roman numerals is...\n", input);
        int i;
        for(i = 0; i < strlen(r); i++)
            printf("=");
        printf("\n%s\n", r);
        for(i = 0; i < strlen(r); i++)
            printf("=");
        printf("\n");
    }
    
    return 0;
}

void intToRoman(unsigned int num, char *r){
    
    char *C[] = {"", "C", "CC", "CCC", "DC", "D", "DC", "DCC", "DCCC", "CM"};
    char *X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int size[] = {0,  1,    2,     3,    2,   1,    2,     3,      4,    2};
    
    while(num >= 1000){
        *r++ = 'M';
        num -= 1000;
    }

    strcpy(r, C[num/100]);
    r += size[num/100];
    num %= 100;
    
    strcpy(r, X[num/10]);
    r += size[num/10];
    num %= 10;
    
    strcpy(r, I[num/1]);
    r += size[num/1];
    
    *r = '\0';
}
