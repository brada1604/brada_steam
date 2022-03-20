// PEMANGGILAN LIBRARY 
#include <stdio.h> 
// PEMANGGILAN LIBRARY - END

// MODUL YANG BERFUNGSI UNTUK MEBANDINGKAN ANTARA 2 VARIABEL
int stringcompare(char *a,char *b)  
{  
    int flag = 0;  
    while(*a != '\0' && *b != '\0')  // while loop  
    {  
        if(*a != *b)  
        {  
            flag = 1;  
        }  
        a++;  
        b++;  
    }  

    if(flag == 0) {     // APABILA DATANYA DINYATAKAN SAMA
        return 0;  
    } 
    else {              // APABILA DATANYA DINYATAKAN TIDAK SAMA
        return 1;  
    }
} 
// MODUL YANG BERFUNGSI UNTUK MEBANDINGKAN ANTARA 2 VARIABEL - END
