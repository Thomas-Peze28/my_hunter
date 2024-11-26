/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "include/my.h"

void mouse_pos(sfMouseButtonEvent event) {
        printf("MOUSE POS : x : %d; y : %d\n", event.x, event.y);
}

int is_button_touch(sfMouseButtonEvent event, sfVector2f button_position) {
    if ((event.x >= button_position.x && event.x <= button_position.x + 240) &&
        (event.y >= button_position.y && event.y <= button_position.y + 350)) {
        printf("BUTTON PRESSED\n");
        return 1;
    }
    return 0;
}

void analyse_events(sfRenderWindow *window, sfEvent event, sfVector2f button_position) {
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed) {
        mouse_pos(event.mouseButton);
        if (is_button_touch(event.mouseButton, button_position))
            play(window, event);
    }
}

int main(int ac, char **argv) {

    if (ac == 2 && argv[1][1] == 'h') {
        cat("./rules.txt");
        return 0;
    }

    //WINDOW
    sfRenderWindow *window;
    sfVideoMode video_mode = {1600, 900, 32};
    window = sfRenderWindow_create(video_mode, "MY HUNTER", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60); 

    //EVENT
    sfEvent event;

    //PLAY_BUTTON
    sfTexture* button_texture = sfTexture_createFromFile("./src/play_button.png", NULL);;
    sfSprite* button_sprite = sfSprite_create();
    sfSprite_setTexture(button_sprite, button_texture, sfTrue);
    sfVector2f button_position = {660.0, 300.0};
    sfVector2f button_scale = {0.3, 0.3};
    sfSprite_setPosition(button_sprite, button_position);
    sfSprite_setScale(button_sprite, button_scale);

    //MENU_BACKGROUND
    sfTexture* background_texture = sfTexture_createFromFile("./src/menu_background.png", NULL);;
    sfSprite* background_sprite = sfSprite_create();
    sfSprite_setTexture(background_sprite, background_texture, sfTrue);
    sfVector2f background_position = {0.0, 0.0};
    sfVector2f background_scale = {1.0, 1.0};
    sfSprite_setPosition(background_sprite, background_position);
    sfSprite_setScale(background_sprite, background_scale);

    //MUSIC
    sfMusic *music;
    music = sfMusic_createFromFile("./src/myhunter_music.ogg");
    sfMusic_play(music);
    sfMusic_getLoop(music);
    
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, button_position);
        }
        sfRenderWindow_clear(window, sfBlue);
        sfRenderWindow_drawSprite(window, background_sprite, NULL);
        sfRenderWindow_drawSprite(window, button_sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_stop(music);
    sfMusic_destroy(music);
    sfSprite_destroy(button_sprite);
    sfTexture_destroy(button_texture);
    sfSprite_destroy(background_sprite);
    sfTexture_destroy(background_texture);
    sfRenderWindow_destroy(window);
    return 0;
}
