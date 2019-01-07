/*
** EPITECH PROJECT, 2018
** pixel.c
** File description:
** make a pixel 
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/saver.h"

framebuffer_t   *framebuffer_create(int width, int height)
{
    int i = 0;
    int len_buf;
    framebuffer_t   *buffer;
    sfUint8 *pixels;

    buffer = malloc(sizeof(framebuffer_t));
    buffer->width = width;
    buffer->height = height;
    len_buf = width * height * 4;
    pixels = malloc(sizeof(sfUint8) * len_buf);
    buffer->pixels = pixels;
    while (i < len_buf) {
        buffer->pixels[i] = 0;
        buffer->pixels[i + 1] = 0;
        buffer->pixels[i + 2] = 0;
        buffer->pixels[i + 3] = 255;
        i = i + 4;
    }
    return buffer;
}

void    my_put_pixel(framebuffer_t *buff,  int x, int y, sfColor clr)
{
    if (x < 1920 && y < 1080 && x > 0 && y > 0) {
        x = x * 4;
        y = y *4;
        buff->pixels[buff->width * y + x] = clr.r;
        buff->pixels[buff->width * y + x + 1] = clr.g;
        buff->pixels[buff->width * y + x + 2] = clr.b;
        buff->pixels[buff->width * y + x + 3] = clr.a;
    }
}
