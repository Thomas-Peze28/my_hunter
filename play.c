#include "include/my.h"


duck_t create_duck(const char *texture_path, sfVector2f position, sfIntRect rect) {
    duck_t duck;
    duck.texture = sfTexture_createFromFile(texture_path, NULL);
    duck.sprite = sfSprite_create();
    duck.position = position;
    duck.rect = rect;
    sfSprite_setTexture(duck.sprite, duck.texture, sfTrue);
    sfSprite_setTextureRect(duck.sprite, duck.rect);
    sfSprite_setPosition(duck.sprite, duck.position);
    duck.speed = 10.0f;
    return duck;
}

int is_duck_touch(sfMouseButtonEvent event, duck_t *duck) {
    int randomNumber = rand() % 800;
    srand(time(NULL));
    
    if ((event.x >= duck->position.x && event.x <= duck->position.x + duck->rect.width) &&
        (event.y >= duck->position.y && event.y <= duck->position.y + duck->rect.height)) {
        printf("DUCK TOUCH\n");
        duck->speed += 2.5;
        duck->position.y = randomNumber;
        return 1;
    }
    return 0;
}

void move_duck(duck_t *duck, int screen_width, game_t *game) {
    int randomNumber = rand() % 800;
    srand(time(NULL));
    duck->position.x += duck->speed;
    if (duck->position.x > screen_width) {
        duck->position.x = -duck->rect.width;
        duck->position.y = randomNumber;
        game->life -= 1;
        printf("LIFE : %d\n", game->life);
    }
}

void game_over(game_t *game) {
    printf("LIFE : %d\n", game->life);
}

void move_rect(sfIntRect *rect, int offset, int max_value) {
    rect->left = (rect->left + offset) % max_value;
}

void analyse_events_game(sfRenderWindow *window, sfEvent event, duck_t *duck, game_t *game) {
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseMoved) {
        game->crosshair_position.x = event.mouseMove.x;
        game->crosshair_position.y = event.mouseMove.y;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        mouse_pos(event.mouseButton);
        if (is_duck_touch(event.mouseButton, duck)) {
            duck->position.x = -150;
            game->score += 1;
            printf("SCORE : %d\n", game->score);
        }
    if (event.type == sfEvtMouseButtonPressed) {
        game->crosshair_position.x = event.mouseButton.x;
        game->crosshair_position.y = event.mouseButton.y;
    }
    }
}

void play(sfRenderWindow *window, sfEvent event) {

    //TEXT
    sfFont *font = sfFont_createFromFile("./src/open-sans/OpenSans-ExtraBold.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setColor(text, sfWhite);
    sfVector2f text_position = {680.0f, 50.0f};
    sfText_setPosition(text, text_position);

    //GAME_BACKGROUND
    sfTexture* background_texture = sfTexture_createFromFile("./src/menu_background.png", NULL);
    sfSprite* background_sprite = sfSprite_create();
    sfSprite_setTexture(background_sprite, background_texture, sfTrue);
    sfVector2f background_position = {0.0, 0.0};
    sfVector2f background_scale = {1.0, 1.0};
    sfSprite_setPosition(background_sprite, background_position);
    sfSprite_setScale(background_sprite, background_scale);

    //DUCK
    sfClock *clock = sfClock_create(); 
    sfIntRect duck_rect = {0, 0, 110, 110};
    duck_t duck01;
    duck01 = create_duck("./src/sprite_duck.png", (sfVector2f){-110.0f, 100.0f}, duck_rect);

    //GAME
    game_t game;
    game.score = 0;
    game.life = 2;

    //CROSSHAIR
    sfTexture* crosshair_texture = sfTexture_createFromFile("./src/crosshair.png", NULL);
    sfSprite* crosshair_sprite = sfSprite_create();
    sfSprite_setTexture(crosshair_sprite, crosshair_texture, sfTrue);
    sfVector2f crosshair_origin = {256.0f, 256.0f};
    sfSprite_setOrigin(crosshair_sprite,crosshair_origin);
    game.crosshair_position = (sfVector2f){0.0f, 0.0f};
    printf("CROSS %f\n", game.crosshair_position.x);
    sfVector2f crosshair_scale = {0.1, 0.1};
    sfSprite_setPosition(crosshair_sprite, game.crosshair_position);
    sfSprite_setScale(crosshair_sprite, crosshair_scale);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        sfText_setString(text, "SCORE : ");
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events_game(window, event, &duck01, &game);
        }

        sfTime time = sfClock_getElapsedTime(clock);
        float seconds = time.microseconds / 1000000.0f;

        if (seconds > 0.08f) {
            move_rect(&duck01.rect, 110, 330);
            move_duck(&duck01, 1600, &game);
            sfClock_restart(clock);
        }

        sfRenderWindow_clear(window, sfBlue);
    
        sfRenderWindow_drawSprite(window, background_sprite, NULL);
    
        sfSprite_setPosition(duck01.sprite, duck01.position);
        sfSprite_setTextureRect(duck01.sprite, duck01.rect);
        sfRenderWindow_drawSprite(window, duck01.sprite, NULL);

        sfSprite_setPosition(crosshair_sprite, game.crosshair_position);
        sfRenderWindow_drawSprite(window, crosshair_sprite, NULL);
    
        sfRenderWindow_drawText(window, text, NULL);

        sfRenderWindow_display(window);
    }
    sfText_destroy(text);
    sfFont_destroy(font);
    sfSprite_destroy(background_sprite);
    sfTexture_destroy(background_texture);
    sfSprite_destroy(crosshair_sprite);
    sfTexture_destroy(crosshair_texture);
    sfRenderWindow_destroy(window);
}
