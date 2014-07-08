/**
 * Operating System Layer - http://www.rosseti.eti.br/
 * Copyright 2009 rosseti.eti.br   - All rights reserved
 *
 * @author Andrei Rosseti <mdxico@gmail.com>
 */

#include <video.h>
#include <ioports.h>
#include <libc/stdio.h>

void text_attrib(unsigned char fg, unsigned char bg)
{
	screen.color = (bg << 4) | (fg & 0x0F);
}

static void screen_scroll()
{
	int i;
	unsigned short *video_memory = (unsigned short *) screen.video_memory;

	if (screen.cur_y >= screen.height)
	{

		for (i = 0; i < (screen.height - 1) * screen.width; i++)
			video_memory[i] = video_memory[screen.width + i];

		for (i = (screen.height - 1) * screen.width; i < (screen.height * screen.width); i++)
			video_memory[i] = screen.color;

		screen.cur_y = (screen.height - 1);
	}
}

static void update_cursor()
{
	unsigned short p = screen.cur_y * screen.width + screen.cur_x;

	outb(0x3d4, 14);
	outb(0x3d5, p >> 8);
	outb(0x3d4, 15);
	outb(0x3d5, p);
}

void move_cursor(int x, int y)
{
	screen.cur_x = x;
	screen.cur_y = y;

	update_cursor();
}

void putc(unsigned char c)
{
	unsigned int p;

	if (screen.cur_x >= screen.width)
	{
		screen.cur_x = 0; screen.cur_y++;
	}

	switch (c)
	{
		case '\n':
		    screen.cur_x = 0; screen.cur_y++;
		break;

		case '\r':
		    screen.cur_x = 0;
		break;

		default:
			p = (screen.cur_y * screen.width + screen.cur_x) * 2;
		    screen.video_memory[p]   = c;
		    screen.video_memory[p+1] = screen.color;
		    screen.cur_x++;
	}

	screen_scroll();
	update_cursor();
}

void puts(char *str)
{
	while(*str)  putc(*str++);
}

void screen_clear()
{
	unsigned char *video_memory = (unsigned char * ) screen.video_memory;
	int i;

	for (i = 0; i < (screen.width * screen.height * 2); i++)
	{
		*video_memory++ = ' ';
		*video_memory++ = screen.color;
	}


	screen.cur_x = 0;
	screen.cur_y = 0;

	update_cursor();
}

void screen_init()
{
	screen.video_memory = (unsigned char *) 0xb8000;

	screen.width		= 80;
	screen.height		= 25;

	text_attrib(WHITE_COLOR, BLACK_COLOR);

	screen_clear();

	printfln(
		"screen_init: inside color 0x%x"
		,
		screen.color);
}
