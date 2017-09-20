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
    
    char *r;
    
    intToRoman(143, r);
    printf("%s\n", r);
    
    intToRoman(1229, r);
    printf("%s\n", r);
    
    intToRoman(9, r);
    printf("%s\n", r);
    
    intToRoman(3999, r);
    printf("%s\n", r);
    
    intToRoman(40, r);
    printf("%s\n", r);
    
    intToRoman(45, r);
    printf("%s\n", r);
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
