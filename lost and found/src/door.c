/*
** EPITECH PROJECT, 2021
** lost and found
** File description:
** door
*/

#include "my.h"
#include "build.h"

gameobj_t *door_1(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = 4800;
    spike->pos.y = 205;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 589;
    spike->rect.height = 636;
    spike->texture = sfTexture_createFromFile("texture/door.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    spike->box = sfSprite_getGlobalBounds(spike->sprite);
    return (spike);
}

gameobj_t *alpha_mouse(void)
{
    gameobj_t *alpha = malloc(sizeof(gameobj_t));
    alpha->pos.x = 7800;
    alpha->pos.y = 500;
    alpha->rect.top = 0;
    alpha->rect.left = 0;
    alpha->rect.width = 10;
    alpha->rect.height = 10;
    alpha->texture = sfTexture_createFromFile("texture/bleu100.png", NULL);
    alpha->sprite = sfSprite_create();
    sfSprite_setTexture(alpha->sprite, alpha->texture, sfTrue);
    sfSprite_setPosition(alpha->sprite, alpha->pos);
    sfSprite_setTextureRect(alpha->sprite, alpha->rect);
    alpha->box = sfSprite_getGlobalBounds(alpha->sprite);
    return (alpha);
}

gameobj_t *green(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = 6720;
    spike->pos.y = 0;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/green_room.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *blue(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = -960;
    spike->pos.y = 0;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/blue_room.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *red(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = -960;
    spike->pos.y = 0;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/red_room.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *purple(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = -960;
    spike->pos.y = 0;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/purple_room.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *obj_1(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = 7340;
    spike->pos.y = 335;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/pedestalgreen.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *obj_2(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = 7520;
    spike->pos.y = 335;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/pedestalblue.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *obj_3(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = 7690;
    spike->pos.y = 335;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/pedestalred.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *solve(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = 6720;
    spike->pos.y = 0;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/solve.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *obj_4(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = 7865;
    spike->pos.y = 335;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/pedestalpurple.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *purple_vic(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = -960;
    spike->pos.y = 0;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/purple_v.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *green_vic(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = 6720;
    spike->pos.y = 0;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/green_v.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *blue_vic(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = -960;
    spike->pos.y = 0;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/blue_v.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *red_vic(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = -960;
    spike->pos.y = 0;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 1920;
    spike->rect.height = 1080;
    spike->texture = sfTexture_createFromFile("texture/red_v.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    return (spike);
}

gameobj_t *door_2(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = 200;
    spike->pos.y = 205;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 589;
    spike->rect.height = 636;
    spike->texture = sfTexture_createFromFile("texture/door.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    spike->box = sfSprite_getGlobalBounds(spike->sprite);
    return (spike);
}

gameobj_t *door_3(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = 9700;
    spike->pos.y = 205;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 589;
    spike->rect.height = 636;
    spike->texture = sfTexture_createFromFile("texture/door.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    spike->box = sfSprite_getGlobalBounds(spike->sprite);
    return (spike);
    
}

gameobj_t *door_4(void)
{
    gameobj_t *spike = malloc(sizeof(gameobj_t));
    spike->pos.x = 14500;
    spike->pos.y = 205;
    spike->rect.top = 0;
    spike->rect.left = 0;
    spike->rect.width = 589;
    spike->rect.height = 636;
    spike->texture = sfTexture_createFromFile("texture/door.png", NULL);
    spike->sprite = sfSprite_create();
    sfSprite_setTexture(spike->sprite, spike->texture, sfTrue);
    sfSprite_setPosition(spike->sprite, spike->pos);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    spike->box = sfSprite_getGlobalBounds(spike->sprite);
    return (spike);
}