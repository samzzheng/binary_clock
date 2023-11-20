#include <stdio.h>
#include "display.h"

int main(void) {

     while (1){
        open_display();
        int hrs, min, sec;
        int values = scanf("%d:%d:%d", &hrs, &min, &sec); 
        display_time(hrs, min, sec);

        if (values != 3)
        {
            close_display();
            break;
        }
    }
    close_display();
    return 0;
}

