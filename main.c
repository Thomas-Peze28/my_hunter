/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "include/my.h"

int is_button_touch(sfMouseButtonEvent event, sfVector2f button_position)
{
    if ((event.x >= button_position.x && event.x <= button_position.x + 240) &&
        (event.y >= button_position.y && event.y <= button_position.y + 350)) {
        return 1;
    }
    return 0;
}

void analyse_events(all_t *ALL)
{
    if (WIN.event.type == sfEvtClosed)
        sfRenderWindow_close(WIN.window);
    if (WIN.event.type == sfEvtMouseButtonPressed) {
        if (is_button_touch(WIN.event.mouseButton, ALL->button.position))
            play(ALL);
    }
}

void game(all_t *ALL)
{
    while (sfRenderWindow_isOpen(WIN.window)) {
        while (sfRenderWindow_pollEvent(WIN.window, &WIN.event)) {
            analyse_events(ALL);
        }
        sfRenderWindow_clear(WIN.window, sfBlue);
        sfRenderWindow_drawSprite(WIN.window, ALL->background.sprite, NULL);
        sfRenderWindow_drawSprite(WIN.window, ALL->button.sprite, NULL);
        sfRenderWindow_display(WIN.window);
    }
}

int main(int ac, char **argv)
{
    sfMusic *music;
    all_t ALL;

    if (ac == 2 && argv[1][1] == 'h') {
        cat("./rules.txt");
        return 0;
    }
    init(&ALL);
    music = sfMusic_createFromFile("./src/myhunter_music.ogg");
    sfMusic_play(music);
    sfMusic_getLoop(music);
    game(&ALL);
    return 0;
}
