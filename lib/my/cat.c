/*
** EPITECH PROJECT, 2024
** cat
** File description:
** Create a new list from the command line arg
** my_cat
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int have_error(int fd)
{
    if (fd == -1) {
        my_putstr("Error with open\n");
        return 84;
    }
}

int cat(char *filepath)
{
    int fd;
    char buffer[30];
    int size;

    fd = open(filepath, O_RDONLY);
    size = read(fd, buffer, 29);
    my_putstr(buffer);
    while (have_error(fd) != 1 && size != 0) {
        size = read(fd, buffer, 29);
        buffer[size] = '\0';
        my_putstr(buffer);
    }
    my_putchar('\n');
    close(fd);
    return 0;
}
