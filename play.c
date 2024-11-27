/*
** EPITECH PROJECT, 2024
** play.c
** File description:
** play for my_hunter
*/
#include "include/my.h"

int is_duck_touch(sfMouseButtonEvent event, all_t *ALL)
{
    int randomNumber = rand() % 800;

    srand(time(NULL));
    if ((event.x >= DUCKPOS.x && event.x <= DUCKPOS.x + DUCK.rect.width) &&
        (event.y >= DUCKPOS.y && event.y <= DUCKPOS.y + DUCK.rect.height)) {
        DUCK.speed += 2.5;
        DUCKPOS.y = randomNumber;
        return 1;
    }
    return 0;
}

void move_duck(all_t *ALL)
{
    int randomNumber = rand() % 800;

    srand(time(NULL));
    DUCKPOS.x += DUCK.speed;
    if (DUCKPOS.x > WIN.video_mode.width) {
        DUCKPOS.x = -DUCK.rect.width;
        DUCKPOS.y = randomNumber;
    }
}

void move_rect(all_t *ALL, int offset, int max_value)
{
    DUCK.rect.left = (DUCK.rect.left + offset) % max_value;
}

void analyse_events_game(all_t *ALL)
{
    if (WIN.event.type == sfEvtClosed)
        sfRenderWindow_close(WIN.window);
    if (WIN.event.type == sfEvtMouseMoved) {
        ALL->crosshair.position.x = WIN.event.mouseMove.x;
        ALL->crosshair.position.y = WIN.event.mouseMove.y;
    }
    if (WIN.event.type == sfEvtMouseButtonPressed) {
        if (is_duck_touch(WIN.event.mouseButton, ALL)) {
            DUCKPOS.x = -150;
        }
    }
}

void play(all_t *ALL)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;

    while (sfRenderWindow_isOpen(WIN.window)) {
        sfRenderWindow_setMouseCursorVisible(WIN.window, sfFalse);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0f;
        while (sfRenderWindow_pollEvent(WIN.window, &WIN.event)) {
            analyse_events_game(ALL);
        }
        if (seconds > 0.08f) {
            move_rect(ALL, 110, 330);
            move_duck(ALL);
            sfClock_restart(clock);
        }
        display(ALL);
    }
}
