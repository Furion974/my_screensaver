/*
** EPITECH PROJECT, 2018
** circle.c
** File description:
** modern circle painting
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "../include/my.h"
#include "../include/saver.h"

void    circle_splash(framebuffer_t *buffer, sfVector2i cntr, int rad)
{
    int i = cntr.y - rad;
    int j = cntr.x - rad;
    sfColor rgb;

    rgb.r = rand() % 255 + 1;
    rgb.g = rand() % 255 + 1;
    rgb.b = rand() % 255 + 1;
    rgb.a = 1;
    while (i <= cntr.y + rad) {
        while (j <= cntr.x + rad) {
            if (pow(j - cntr.x, 2) + pow(i - cntr.y, 2) <= pow(rad, 2))
                my_put_pixel(buffer, j, i, rgb);
            j++;
        }
        j = rad;
        i++;
    }
}

void    circle_draw(framebuffer_t *buffer, int rad)
{
    sfVector2i  center;

    center.x = rand() % 1920;
    center.y = rand() % 1080;
    circle_splash(buffer, center, rad);
}

void    circle(void)
{
    framebuffer_t   *buf = framebuffer_create(1920, 1080);
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "", sfClose, 0);
    sfEvent evt;
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfSprite *sprite = sfSprite_create();

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfTexture_updateFromPixels(texture, buf->pixels, 1920, 1080, 0, 0);
        sfSprite_setTexture(sprite, texture, sfTrue);
        while (sfRenderWindow_pollEvent(window, &evt)) {
            if (evt.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        circle_draw(buf, rand() % 26);
    }
    sfRenderWindow_destroy(window);
    free(buf);
}
