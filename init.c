/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "include/my.h"

void init_window(all_t *ALL)
{
    WIN.video_mode.height = 900;
    WIN.video_mode.width = 1600;
    WIN.video_mode.bitsPerPixel = 32;
    WIN.window = sfRenderWindow_create(WIN.video_mode, "MY HUNTER"
    , sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(WIN.window, 60);
}

void init_duck(all_t *ALL)
{
    DUCK.texture = sfTexture_createFromFile("./src/sprite_duck.png", NULL);
    DUCK.sprite = sfSprite_create();
    DUCK.scale.x = 1.0;
    DUCK.scale.y = 1.0;
    DUCK.position.x = -150;
    DUCK.position.y = 100.0;
    DUCK.rect.height = 110;
    DUCK.rect.left = 0;
    DUCK.rect.top = 0;
    DUCK.rect.width = 110;
    sfSprite_setTexture(DUCK.sprite, DUCK.texture, sfTrue);
    sfSprite_setPosition(DUCK.sprite, ALL->duck.position);
    sfSprite_setScale(DUCK.sprite, DUCK.scale);
    DUCK.speed = 10.0;
}

void init_score(all_t *ALL)
{
    SCORE.font = sfFont_createFromFile("./src/open-sans/ExtraBold.ttf");
    SCORE.text = sfText_create();
    SCORE.text_position.x = 680.0;
    SCORE.text_position.y = 50.0;
    sfText_setFont(SCORE.text, SCORE.font);
    sfText_setCharacterSize(SCORE.text, 50);
    sfText_setColor(SCORE.text, sfWhite);
    sfText_setPosition(SCORE.text, SCORE.text_position);
    sfText_setString(SCORE.text, "SCORE : ");
}

void init(all_t *ALL)
{
    init_window(ALL);
    init_background(ALL);
    init_button(ALL);
    init_duck(ALL);
    init_crosshair(ALL);
}
