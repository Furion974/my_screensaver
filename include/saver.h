/*
** EPITECH PROJECT, 2018
** saver.h
** File description:
** include 
*/

#ifndef SAVER_H_
#define SAVER_H_

typedef struct framebuffer_s
{
    int width;
    int height;
    sfUint8 *pixels;
}framebuffer_t;

int usage(void);
int description_animation(void);
int bad_arg(void);
framebuffer_t   *framebuffer_create(int width, int height);
void    my_put_pixel(framebuffer_t *buffer, int x, int y, sfColor color);
void    sky_draw(framebuffer_t *buffer);
void    sky(void);
void    circle_splash(framebuffer_t *buffer, sfVector2i center, int radian);
void    circle_draw(framebuffer_t *buffer, int rad);
void    circle(void);

typedef struct  color_s
{
    int red;
    int green;
    int blue;
}color_t;

#endif
