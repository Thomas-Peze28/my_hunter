/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/
#include <stdio.h>
#include <stdlib.h>
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

typedef struct {
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
    sfTexture *texture;
    float speed;
} duck_t;

typedef struct {
    sfFont *font;
    sfText *text;
    sfVector2f text_position;
} TEXT_T;

typedef struct {
    int score;
    int life;
    sfVector2f crosshair_position;
} game_t;

typedef struct {
    game_t game;
    duck_t duck;
    TEXT_T text;
} ALL;

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_sort_int_array(int *tab, int size);
int check_lettre(const char *str, int i);
int check_number(const char *str, int i);
int my_getsign(char const *str);
int my_putnbr_base(int nbr, char const *base);
int mini_printf(const char *format, ...);
int cat(char *filepath);
void play(sfRenderWindow *window, sfEvent event);
void mouse_pos(sfMouseButtonEvent event);
#endif /* MY_ */
