/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/saver.h"
#include "../include/my.h"

int main(int ac, char **av)
{
    int i = 1;

    if (ac < 2)
        return bad_arg();
    else if (ac > 3)
        return 84;
    if (av[i][0] == '-' && av[i][1] == 'h')
        return usage();
    if (av[i][0] == '1')
        sky();
    if (av[i][0] == '-' && av[i][1] == 'd')
        return description_animation();
    if (av[i][0] == '2')
        circle();
    return 0;
}
