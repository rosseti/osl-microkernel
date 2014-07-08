/**
 * Operating System Layer - http://www.rosseti.eti.br/
 * Copyright 2009 unsignal.com   - All rights reserved
 *
 * @author Andrei Rosseti <mdxico@gmail.com>
 */

#ifndef __VIDEO_H
#define __VIDEO_H

#define BLACK_COLOR   		 0x00
#define BLUE_COLOR    		 0x01
#define GREEN_COLOR   		 0x02
#define CYAN_COLOR    		 0x03
#define RED_COLOR     		 0x04
#define MAGENTA_COLOR 		 0x05
#define BROWN_COLOR   		 0x06
#define GRAY_COLOR    		 0x07
#define DARK_GREY_COLOR		 0x08
#define BRIGHT_BLUE_COLOR    0x09
#define BRIGHT_GREEN_COLOR   0x0a
#define BRIGHT_CYAN_COLOR 	 0x0b
#define PINK_COLOR  		 0x0c
#define BRIGHT_MAGENTA_COLOR 0x0d
#define WHITE_COLOR  		 0x0f

void putc(unsigned char c);
void puts(char *str);
void screen_clear();
void screen_init();
void move_cursor(int x, int y);

typedef struct {
	char 		   color;
	unsigned char *video_memory;
	int	width;
	int height;
	int cur_x;
	int cur_y;
} Screen;

Screen screen;

#endif
