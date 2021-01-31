/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** project
*/

#ifndef BUILD_H
#define BUILD_H

#include "my.h"
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>

typedef struct score_init_s {
    int score_nbr;
    sfFont *font;
    sfText *score_txt;
    sfText *score_num;
    sfVector2f my_pos2;
} score_init_t;

typedef struct gameobj_s {
    sfVector2f pos;
    sfIntRect rect;
    float friction;
    int jump;
    float gravity;
    sfTexture *texture;
    sfSprite *sprite;
    sfFloatRect box;
} gameobj_t;

typedef struct clockanim_s {
    float seconds;
    sfClock *clock;
    sfTime time;
} clockanim_t;

typedef struct config_s {
    int i;
    int j;
    sfVector2f velocity;
} config_t;

typedef struct back_s {
    sfVector2f pos;
    sfSprite *background;
    sfTexture *texture;
} back_t;

typedef struct body_s {
    gameobj_t *obj;
    gameobj_t *obj2;
    gameobj_t *obj3;
    gameobj_t *obj4;
    gameobj_t *bunny;
    back_t *back;
    config_t *config;
    score_init_t *score;
    gameobj_t *wolf;
    back_t *back2;
    back_t *play;
    back_t *logo;
    score_init_t *pause_score;
    back_t *back_loose;
    score_init_t *score_loose;
    score_init_t *score_win;
    int nb_wolf;
    sfEvent event;
    sfSound *sound;
    int continue_game;
    clockanim_t *clock_wolf;
    clockanim_t *clock;
    clockanim_t *clock_b;
    clockanim_t *clock_map;
    char *map;
    sfSoundBuffer *buffer;
    sfSound *sound_jump;
    sfMusic *music;
} body_t;

typedef struct global_s {
    int dead;
    int menu1;
    int menu2;
    int door1;
    int door2;
    int door3;
    int door4;
    int obj1;
    int obj2;
    int obj3;
    int obj4;
    int move;
    int game;
    int win;
    float second;
    sfSoundBuffer *d_buffer;
    sfSoundBuffer *b_buffer;
    sfSoundBuffer *g_buffer;
    sfSoundBuffer *a_buffer;
    sfSound *door_sound;
    sfSound *breath_sound;
    sfSound *gem_sound;
    sfSound *andgry_sound;
    sfMusic *music;
    sfTime time;
    sfRenderWindow *window;
    sfVector2f pos_cam;
    sfVector2f pos;
    sfView *cam;
    sfClock *clock;
} g_t;

typedef struct sprite_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
} sprite_t;

gameobj_t *door_1(void);
gameobj_t *door_2(void);
gameobj_t *door_3(void);
gameobj_t *door_4(void);
gameobj_t *obj_1(void);
gameobj_t *obj_2(void);
gameobj_t *obj_3(void);
gameobj_t *obj_4(void);
gameobj_t *green(void);
gameobj_t *green_vic(void);
void main_menue(g_t *g);
gameobj_t *life(void);
gameobj_t *alpha_mouse(void);
gameobj_t *blue(void);
gameobj_t *blue_vic(void);
gameobj_t *red(void);
gameobj_t *red_vic(void);
gameobj_t *purple_vic(void);
gameobj_t *purple(void);
gameobj_t *solve(void);

#endif
