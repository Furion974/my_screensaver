/*
** EPITECH PROJECT, 2018
** usage.c
** File description:
** display usage
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

int usage(void)
{
    int fd = open("src/usage.txt", O_RDONLY);
    int size = 0;
    char buff[277];

    if (fd < 0)
        return 84;
    size = read(fd, buff, 277);
    write(1, buff, size);
    close (fd);
    return 0;
}

int bad_arg(void)
{
    int fd = open("src/bad_arg.txt", O_RDONLY);
    int size = 0;
    char buff[73];

    size = read(fd, buff, 73);
    write(1, buff, size);
    close(fd);
    return 84;
}

int description_animation(void)
{
    int fd = open("src/description_animation.txt", O_RDONLY);
    int size = 0;
    char buff[79];

    size = read(fd, buff, 79);
    write(1, buff, size);
    close(fd);
    return 0;
}
