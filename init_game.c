/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "include/my.h"

void init_button(all_t *ALL)
{
    BUTTON.texture = sfTexture_createFromFile("./src/play_button.png", NULL);
    BUTTON.sprite = sfSprite_create();
    BUTTON.scale.x = 0.3;
    BUTTON.scale.y = 0.3;
    BUTTON.position.x = 660.0;
    BUTTON.position.y = 300.0;
    sfSprite_setTexture(BUTTON.sprite, BUTTON.texture, sfTrue);
    sfSprite_setPosition(BUTTON.sprite, BUTTON.position);
    sfSprite_setScale(BUTTON.sprite, BUTTON.scale);
}

void init_background(all_t *ALL)
{
    BG.texture = sfTexture_createFromFile("./src/menu_background.png", NULL);
    BG.sprite = sfSprite_create();
    BG.scale.x = 1.0;
    BG.scale.y = 1.0;
    BG.position.x = 0.0;
    BG.position.y = 0.0;
    sfSprite_setTexture(BG.sprite, BG.texture, sfTrue);
    sfSprite_setPosition(BG.sprite, BG.position);
    sfSprite_setScale(BG.sprite, BG.scale);
}

void init_crosshair(all_t *ALL)
{
    CROSS.texture = sfTexture_createFromFile("./src/crosshair.png", NULL);
    CROSS.sprite = sfSprite_create();
    CROSS.scale.x = 0.1;
    CROSS.scale.y = 0.1;
    CROSS.position.x = -50.0;
    CROSS.position.y = 0.0;
    CROSS.origin.x = 256.0;
    CROSS.origin.y = 256.0;
    sfSprite_setTexture(CROSS.sprite, CROSS.texture, sfTrue);
    sfSprite_setOrigin(CROSS.sprite, CROSS.origin);
    sfSprite_setPosition(CROSS.sprite, CROSS.position);
    sfSprite_setScale(CROSS.sprite, CROSS.scale);
}

void init_over(all_t *ALL)
{
    BGOVER.texture = sfTexture_createFromFile("./src/game_over.png", NULL);
    BGOVER.sprite = sfSprite_create();
    BGOVER.scale.x = 1.1;
    BGOVER.scale.y = 1.08;
    BGOVER.position.x = 0.0;
    BGOVER.position.y = -10.0;
    sfSprite_setTexture(BGOVER.sprite, BGOVER.texture, sfTrue);
    sfSprite_setPosition(BGOVER.sprite, BGOVER.position);
    sfSprite_setScale(BGOVER.sprite, BGOVER.scale);
}
