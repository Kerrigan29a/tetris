/*
 * A conio.h like implementation for VTANSI displays.
 *
 * Copyright (c) 2009, 2010 Joachim Nilsson <joachim.nilsson@vmlinux.org>
 * Copyright (c) 2014, 2015 Kerrigan29a <kerrigan29a@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __CONIO_H__
#define __CONIO_H__

#include <stdio.h>

/* Attributes */
#define RESETATTR    0
#define BRIGHT       1
#define DIM          2
#define UNDERSCORE   4
#define BLINK        5           /* May not work on all displays. */
#define REVERSE      7
#define HIDDEN       8

/* Colors for text and background */
#define RESETCOLOR      0x00
#define BLACK           0x00
#define RED             0x01
#define GREEN           0x02
#define YELLOW          0x03
#define BLUE            0x04
#define MAGENTA         0x05
#define CYAN            0x06
#define LIGHTGREY       0x07

#define DARKGREY        0x10
#define LIGHTBLACK      0x10
#define LIGHTRED        0x11
#define LIGHTGREEN      0x12
#define LIGHTYELLOW     0x13
#define LIGHTBLUE       0x14
#define LIGHTMAGENTA    0x15
#define LIGHTCYAN       0x16
#define WHITE           0x17

/* Esc[2JEsc[1;1H             - Clear screen and move cursor to 1,1 (upper left) pos. */
#define clrscr()              puts ("\e[2J\e[1;1H")
/* Esc[K                      - Erases from the current cursor position to the end of the current line. */
#define clreol()              puts ("\e[K")
/* Esc[2K                     - Erases the entire current line. */
#define delline()             puts ("\e[2K")
/* Esc[Line;ColumnH           - Moves the cursor to the specified position (coordinates) */
#define gotoxy(x,y)           printf("\e[%d;%dH", y, x)
/* Esc[?25l (lower case L)    - Hide Cursor */
#define hidecursor()          puts ("\e[?25l")
/* Esc[?25h (lower case H)    - Show Cursor */
#define showcursor()          puts ("\e[?25h")

/* Esc[Value;...;Valuem       - Set Graphics Mode */
#define __set_gm(attr, color, val) do {                                         \
    if (!color) {                                                               \
        printf("\e[%dm", attr);                                                 \
    } else {                                                                    \
        printf("\e[%d;%dm", ((color) & 0x10) ? 1 : 0, ((color) & 0xF) + (val)); \
    }                                                                           \
} while(0)
#define textattr(attr)        __set_gm(attr, 0, 0)
#define textcolor(color)      __set_gm(RESETATTR, color, 30)
#define textbackground(color) __set_gm(RESETATTR, color, 40)

#endif /* __CONIO_H__ */

/**
 * Local Variables:
 *  version-control: t
 *  c-file-style: "ellemtel"
 * End:
 */
