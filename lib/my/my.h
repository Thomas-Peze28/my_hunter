/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>

#ifndef MY_
    #define MY_

    #define WIN ALL->parameters
    #define BUTTON ALL->button
    #define BG ALL->background
    #define BGOVER ALL->over
    #define CROSS ALL->crosshair
    #define DUCK ALL->duck
    #define DUCKPOS ALL->duck.position
    #define SCORE ALL->score

typedef struct parameter_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    int life;
} parameter_t;

typedef struct image_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
} image_t;

typedef struct button_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
} button_t;

typedef struct background_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
} background_t;

typedef struct game_over_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
} game_over_t;

typedef struct duck_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    float speed;
} duck_t;

typedef struct crosshair_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    sfVector2f origin;
} crosshair_t;

typedef struct score_s {
    sfFont *font;
    sfText *text;
    sfVector2f text_position;
} score_t;

typedef struct all_s {
    parameter_t parameters;
    image_t image;
    button_t button;
    background_t background;
    duck_t duck;
    crosshair_t crosshair;
    score_t score;
    game_over_t over;
} all_t;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int cat(char *filepath);
void mouse_pos(sfMouseButtonEvent event);
void init(all_t *all);
void game(all_t *all);
void play(all_t *all);
void init_button(all_t *ALL);
void init_background(all_t *ALL);
void init_crosshair(all_t *ALL);
void init_over(all_t *ALL);
void display(all_t *ALL);
void destroy(all_t *ALL);
void game_over(all_t *ALL);

#endif /* MY_ */
