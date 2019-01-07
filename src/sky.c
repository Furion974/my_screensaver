/*
** EPITECH PROJECT, 2018
** sky.c
** File description:
** rainbow sky
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/saver.h"
#include "../include/my.h"

void    sky_draw(framebuffer_t *buffer)
{
    sfColor rgb;
    int x = rand() % 1920;
    int y = rand() % 1080;

    rgb.r = rand() % 255 + 1;
    rgb.g = rand() % 255 + 1;
    rgb.b = rand() % 255 + 1;
    rgb.a = 1;
    my_put_pixel(buffer, x, y, rgb);
}

void    sky(void)
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
        sky_draw(buf);
    }
    sfRenderWindow_destroy(window);
    free(buf);
}
