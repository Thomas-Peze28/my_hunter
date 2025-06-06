/*
** EPITECH PROJECT, 2024
** window.c
** File description:
** window for my_hunter
*/
#include "include/my.h"

void display(all_t *ALL)
{
    sfRenderWindow_clear(WIN.window, sfBlue);
    sfRenderWindow_drawSprite(WIN.window, ALL->background.sprite, NULL);
    sfSprite_setPosition(DUCK.sprite, DUCKPOS);
    sfSprite_setTextureRect(DUCK.sprite, DUCK.rect);
    sfRenderWindow_drawSprite(WIN.window, DUCK.sprite, NULL);
    sfSprite_setPosition(ALL->crosshair.sprite, ALL->crosshair.position);
    sfRenderWindow_drawSprite(WIN.window, ALL->crosshair.sprite, NULL);
    sfRenderWindow_display(WIN.window);
}

void destroy(all_t *ALL)
{
    sfText_destroy(ALL->score.text);
    sfFont_destroy(ALL->score.font);
    sfSprite_destroy(ALL->background.sprite);
    sfTexture_destroy(ALL->background.texture);
    sfSprite_destroy(ALL->crosshair.sprite);
    sfTexture_destroy(ALL->crosshair.texture);
}

void analyse_events_over(all_t *ALL)
{
    if (WIN.event.type == sfEvtClosed)
        sfRenderWindow_close(WIN.window);
}

void game_over(all_t *ALL)
{
    sfRenderWindow_setMouseCursorVisible(WIN.window, sfTrue);
    while (sfRenderWindow_isOpen(WIN.window)) {
        while (sfRenderWindow_pollEvent(WIN.window, &WIN.event)) {
        analyse_events_over(ALL);
        }
        sfRenderWindow_clear(WIN.window, sfBlack);
        sfRenderWindow_drawSprite(WIN.window, ALL->over.sprite, NULL);
        sfRenderWindow_display(WIN.window);
    }
}
