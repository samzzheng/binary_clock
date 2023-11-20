#include <stdio.h>
#include "ncurses.h"
#include "unistd.h"

#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4


uint16_t pixel[8][8];


 

void draw_grid(uint16_t pixels[8][8]) {
    for(int y=0; y<8; y++) {
        move(y,0);
        for(int x=0; x<8; x++) {
            if(pixels[7-x][y]) {
                attron(COLOR_PAIR(pixels[7-x][y]));
                addch('#');
                attroff(COLOR_PAIR(pixels[7-x][y]));
            } else {
                addch(' ');
            }
        }
    }
    refresh();
}


void fill_pixels(uint16_t pixels[8][8], uint16_t color) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            pixels[i][j] = color;
        }
    }
}

int open_display(void){
    initscr();
    start_color();
    if(stdscr != NULL){
        fill_pixels(pixel, BLACK);
        return 1;
    }
    else{
        return 0;
    }
}

void display_colons(void){
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    pixel[2][5]=WHITE;
    pixel[2][4]=WHITE;
    pixel[2][2]=WHITE;
    pixel[2][1]=WHITE;

    pixel[3][5]=WHITE;
    pixel[3][2]=WHITE;
    pixel[3][1]=WHITE;
    pixel[3][4]=WHITE;


    pixel[5][5]=WHITE;
    pixel[5][4]=WHITE;
    pixel[5][2]=WHITE;
    pixel[5][1]=WHITE;


    pixel[6][5]=WHITE;
    pixel[6][4]=WHITE;
    pixel[6][2]=WHITE;
    pixel[6][1]=WHITE;
    

}

 /* 010111 = 23 */
void display_hours(int hours){
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    int x = 0;
while(hours > 0){
    if(hours % 2){
        pixel[1][x] = BLUE;
    }
    x++;
     hours /= 2;
  }
}


void display_minutes(int minutes){
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    int x = 0;
    
    while(minutes > 0){
        if(minutes % 2){
            pixel[4][x] = GREEN;
    }
    x++;
    minutes /= 2;
 }
}



void display_seconds(int seconds){
    init_pair(RED, COLOR_RED, COLOR_RED);
    int x = 0;
    while(seconds > 0){
        if(seconds % 2){
            pixel[7][x] = RED;
    }
     x++;
     seconds /= 2;
 }
}



void display_time(int hours, int minutes, int seconds){
    display_hours(hours);
    display_colons();
    display_minutes(minutes);
    display_seconds(seconds);
    draw_grid(pixel);
}


void close_display(void){
    endwin();
}
