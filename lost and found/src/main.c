/*
** EPITECH PROJECT, 2021
** lost and found
** File description:
** main
*/

#include "build.h"
#include "my.h"

gameobj_t *back(void)
{
    gameobj_t *obj = malloc(sizeof(gameobj_t));
    obj->texture = sfTexture_createFromFile("texture/hall.png", NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    return (obj);
}

gameobj_t *create_cursor(void)
{
    gameobj_t *obj = malloc(sizeof(gameobj_t));
    sfVector2f scale_cursor = {2, 2};
    sfTexture *cible = sfTexture_createFromFile("texture/lampsprite.png", NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, cible, sfTrue);
    //sfSprite_setScale(obj->sprite, scale_cursor);
    return (obj);
}

int scrolling(g_t *g)
{
    if (g->pos_cam.x < 1100) {
        g->move = 0;
        g->pos_cam.x = 1100;
        sfView_setCenter(g->cam, g->pos_cam);
    }
    if (g->pos_cam.x > 14200) {
        g->move = 0;
        g->pos_cam.x = 14200;
        sfView_setCenter(g->cam, g->pos_cam);
    }
    if (g->move == 1 && (g->pos_cam.x < (g->pos.x + 300))) {
        if(g->second > 0.01) {
            g->pos_cam.x += 10;
            sfView_setCenter(g->cam, g->pos_cam);
            sfClock_restart(g->clock);
        }
    } else if (g->move == 1) {
        g->move = 0;
    }
    if (g->move == 2 && (g->pos_cam.x > (g->pos.x - 300))) {
        if(g->second > 0.01) {
            g->pos_cam.x -= 10;
            sfView_setCenter(g->cam, g->pos_cam);
            sfClock_restart(g->clock);
        }
    } else if (g->move == 2) {
        g->move = 0;
    }
}

void init_g(g_t *g)
{
    g->dead = 0;
    g->obj1 = 0;
    g->obj2 = 0;
    g->obj3 = 0;
    g->obj4 = 0;
    g->menu1 = 0;
    g->menu2 = 0;
    g->door1 = 0;
    g->door2 = 0;
    g->door3 = 0;
    g->door4 = 0;
    g->clock = sfClock_create();
    g->pos_cam.x = 7680;
    g->pos_cam.y = 540;
}

void music(g_t *g)
{
    g->door_sound = sfSound_create();
    g->breath_sound = sfSound_create();
    g->gem_sound = sfSound_create();
    g->andgry_sound = sfSound_create();
    g->d_buffer = sfSoundBuffer_createFromFile("sounds/door_sound.ogg");
    g->b_buffer = sfSoundBuffer_createFromFile("sounds/fantome.ogg");
    g->g_buffer = sfSoundBuffer_createFromFile("sounds/gemme.ogg");
    sfSound_setBuffer(g->door_sound, g->d_buffer);
    sfSound_setBuffer(g->breath_sound, g->b_buffer);
    sfSound_setBuffer(g->gem_sound, g->g_buffer);
    g->music = sfMusic_createFromFile("sounds/sound.ogg");
    sfMusic_play(g->music);
}

int main(int ac, char **av)
{
    sfVector2f pos;
    g_t *g = malloc(sizeof(g_t));
    init_g(g);
    gameobj_t *obj = malloc(sizeof(gameobj_t));
    gameobj_t *end = solve();
    gameobj_t *door1 = door_1();
    gameobj_t *door2 = door_2();
    gameobj_t *door3 = door_3();
    gameobj_t *door4 = door_4();
    gameobj_t *obj1 = obj_1();
    gameobj_t *obj2 = obj_2();
    gameobj_t *obj3 = obj_3();
    gameobj_t *obj4 = obj_4();
    gameobj_t *green_r = green();
    gameobj_t *green_v = green_vic();
    gameobj_t *blue_r = blue();
    gameobj_t *blue_v = blue_vic();
    gameobj_t *red_r = red();
    gameobj_t *red_v = red_vic();
    gameobj_t *purple_r = purple();
    gameobj_t *purple_v = purple_vic();
    gameobj_t *alpha = alpha_mouse();
    gameobj_t *cursor = malloc(sizeof(gameobj_t));
    sfEvent event;
    g->game = 0;
    sfFloatRect view;
    view.height = 1080;
    view.width = 1920;
    sfVideoMode mode;
    mode.width = 1920;
    mode.height = 1080;
    sfVector2f pos_curs;
    sfVector2i poss;
    g->cam = sfView_createFromRect(view);
    sfView_setCenter(g->cam, g->pos_cam);
    g->window = sfRenderWindow_create(mode, "My Window", sfClose | sfResize, NULL);
    obj = back();
    g->win = 0;
    music(g);
    sfVector2f pos_lamp;
    cursor = create_cursor();
    main_menue(g);
    while (sfRenderWindow_isOpen(g->window)) {
        if (g->obj1 == 0 || g->obj2 == 0 || g->obj3 == 0 || g->obj4 == 0) {
            if (g->door1 == 1 && g->obj1 == 0) {
                sfRenderWindow_display(g->window);
                sfVector2f gem;
                gem.x = 7660;
                gem.y = 510;
                // sfSprite_setPosition(cursor->sprite, pos_lamp);
                sfRenderWindow_setView(g->window, g->cam);
                sfRenderWindow_drawSprite(g->window, green_r->sprite, NULL);
                if (g->win == 0)
                sfRenderWindow_drawSprite(g->window, cursor->sprite, NULL);
                if (g->win == 1)
                sfRenderWindow_drawSprite(g->window, green_v->sprite, NULL);
                if (g->dead > 2) {
                    sfSound_play(g->gem_sound);
                    g->door1 = 0;
                    g->game = 0;
                }
                sfSprite_setPosition(alpha->sprite, pos_curs);
                while (sfRenderWindow_pollEvent(g->window, &event)) {
                    pos_lamp.x = sfMouse_getPositionRenderWindow(g->window).x + 3880;
                    pos_lamp.y = sfMouse_getPositionRenderWindow(g->window).y - 1620;
                    sfSprite_setPosition(cursor->sprite, pos_lamp);
                    if ((event).type == sfEvtMouseButtonPressed) {
                        pos_curs.x = sfMouse_getPositionRenderWindow(g->window).x;
                        pos_curs.y = sfMouse_getPositionRenderWindow(g->window).y;
                        if (g->win == 1) {
                            g->door1 = 0;
                            g->game = 0;
                            g->obj1 = 1;
                            break;
                        }
                        if (pos_curs.x >= 918
                            && pos_curs.x <= 968
                            && pos_curs.y >= 473
                            && pos_curs.y <= 523) {
                                sfSound_play(g->gem_sound);
                                g->win = 1;
                        } else  if (g->dead <= 2) {
                            sfSound_play(g->breath_sound);
                            g->dead += 1;
                        }
                    }
                    if ((event).type == sfEvtClosed) {
                        sfRenderWindow_close(g->window);
                    }
                }
            }
            if (g->door2 == 1) {
                sfRenderWindow_display(g->window);
                sfVector2f gem;
                gem.x = 7660;
                gem.y = 510;
                // sfSprite_setPosition(cursor->sprite, pos_lamp);
                sfRenderWindow_setView(g->window, g->cam);
                sfRenderWindow_drawSprite(g->window, blue_r->sprite, NULL);
                if (g->win == 0)
                sfRenderWindow_drawSprite(g->window, cursor->sprite, NULL);
                if (g->win == 1)
                sfRenderWindow_drawSprite(g->window, blue_v->sprite, NULL);
                sfSprite_setPosition(alpha->sprite, pos_curs);
                while (sfRenderWindow_pollEvent(g->window, &event)) {
                    pos_lamp.x = sfMouse_getPositionRenderWindow(g->window).x - 3840;
                    pos_lamp.y = sfMouse_getPositionRenderWindow(g->window).y - 1610;
                    sfSprite_setPosition(cursor->sprite, pos_lamp);
                    if ((event).type == sfEvtMouseButtonPressed) {
                        pos_curs.x = sfMouse_getPositionRenderWindow(g->window).x;
                        pos_curs.y = sfMouse_getPositionRenderWindow(g->window).y;
                        if (g->win == 1) {
                            g->door2 = 0;
                            g->game = 0;
                            g->obj2 = 1;
                            g->pos_cam.x = 7680;
                            break;
                        }
                        if (pos_curs.x >= 1760
                            && pos_curs.x <= 1810
                            && pos_curs.y >= 380
                            && pos_curs.y <= 430) {
                                sfSound_play(g->gem_sound);
                                g->win = 1;
                        }
                        else  if (g->dead <= 2) {
                            sfSound_play(g->breath_sound);
                            g->dead += 1;
                        }
                    }
                    if ((event).type == sfEvtClosed) {
                        sfRenderWindow_close(g->window);
                    }
                }
            }
            if (g->door3 == 1) {
                sfRenderWindow_display(g->window);
                sfVector2f gem;
                gem.x = 7660;
                gem.y = 510;
                // sfSprite_setPosition(cursor->sprite, pos_lamp);
                sfRenderWindow_setView(g->window, g->cam);
                sfRenderWindow_drawSprite(g->window, red_r->sprite, NULL);
                if (g->win == 0)
                sfRenderWindow_drawSprite(g->window, cursor->sprite, NULL);
                if (g->win == 1)
                sfRenderWindow_drawSprite(g->window, red_v->sprite, NULL);
                sfSprite_setPosition(alpha->sprite, pos_curs);
                while (sfRenderWindow_pollEvent(g->window, &event)) {
                    pos_lamp.x = sfMouse_getPositionRenderWindow(g->window).x - 3840;
                    pos_lamp.y = sfMouse_getPositionRenderWindow(g->window).y - 1610;
                    sfSprite_setPosition(cursor->sprite, pos_lamp);
                    if ((event).type == sfEvtMouseButtonPressed) {
                        pos_curs.x = sfMouse_getPositionRenderWindow(g->window).x;
                        pos_curs.y = sfMouse_getPositionRenderWindow(g->window).y;
                        if (g->win == 1) {
                            g->door3 = 0;
                            g->game = 0;
                            g->obj3 = 1;
                            g->pos_cam.x = 7680;
                            break;
                        }
                        if (pos_curs.x >= 1570
                            && pos_curs.x <= 1620
                            && pos_curs.y >= 408
                            && pos_curs.y <= 458) {
                                sfSound_play(g->gem_sound);
                                g->win = 1;
                            }
                            else  if (g->dead <= 2) {
                            sfSound_play(g->breath_sound);
                            g->dead += 1;
                        }
                    }
                    if ((event).type == sfEvtClosed) {
                        sfRenderWindow_close(g->window);
                    }
                }
            }
            if (g->door4 == 1) {
                sfRenderWindow_display(g->window);
                sfVector2f gem;
                gem.x = 7660;
                gem.y = 510;
                // sfSprite_setPosition(cursor->sprite, pos_lamp);
                sfRenderWindow_setView(g->window, g->cam);
                sfRenderWindow_drawSprite(g->window, purple_r->sprite, NULL);
                if (g->win == 0)
                sfRenderWindow_drawSprite(g->window, cursor->sprite, NULL);
                if (g->win == 1)
                sfRenderWindow_drawSprite(g->window, purple_v->sprite, NULL);
                if (g->dead > 2) {
                    g->door4 = 0;
                    g->game = 0;
                    g->pos_cam.x = 7680;
                }
                sfSprite_setPosition(alpha->sprite, pos_curs);
                while (sfRenderWindow_pollEvent(g->window, &event)) {
                    pos_lamp.x = sfMouse_getPositionRenderWindow(g->window).x - 3880;
                    pos_lamp.y = sfMouse_getPositionRenderWindow(g->window).y - 1610;
                    sfSprite_setPosition(cursor->sprite, pos_lamp);
                    if ((event).type == sfEvtMouseButtonPressed) {
                        pos_curs.x = sfMouse_getPositionRenderWindow(g->window).x;
                        pos_curs.y = sfMouse_getPositionRenderWindow(g->window).y;
                        if (g->win == 1) {
                            g->door4 = 0;
                            g->game = 0;
                            g->obj4 = 1;
                            g->pos_cam.x = 7680;
                            break;
                        }
                        if (pos_curs.x >= 200
                            && pos_curs.x <= 300
                            && pos_curs.y >= 650
                            && pos_curs.y <= 700) {
                                sfSound_play(g->gem_sound);
                                g->win = 1;
                        } else  if (g->dead <= 2) {
                            sfSound_play(g->breath_sound);
                            g->dead += 1;
                        }
                    }
                    if ((event).type == sfEvtClosed) {
                        sfRenderWindow_close(g->window);
                    }
                }
            }
            if (g->game == 0) {
                g->win = 0;
                g->dead = 0;
                sfRenderWindow_display(g->window);
                sfRenderWindow_setView(g->window, g->cam);
                g->time = sfClock_getElapsedTime(g->clock);
                g->second = g->time.microseconds / 1000000.0;
                sfView_move(g->cam, g->pos_cam);
                sfView_setCenter(g->cam, g->pos_cam);
                sfRenderWindow_drawSprite(g->window, obj->sprite, NULL);
                if (g->obj1 == 1) {
                    sfRenderWindow_drawSprite(g->window, obj1->sprite, NULL);
                }
                if (g->obj2 == 1)
                    sfRenderWindow_drawSprite(g->window, obj2->sprite, NULL);
                if (g->obj3 == 1)
                    sfRenderWindow_drawSprite(g->window, obj3->sprite, NULL);
                if (g->obj4 == 1)
                    sfRenderWindow_drawSprite(g->window, obj4->sprite, NULL);
                scrolling(g);
                while (sfRenderWindow_pollEvent(g->window, &event)) {
                    poss.x = sfMouse_getPositionRenderWindow(g->window).x;
                    poss.y = sfMouse_getPositionRenderWindow(g->window).y;
                    pos_curs = sfRenderWindow_mapPixelToCoords(g->window, poss, g->cam);
                    sfSprite_setPosition(alpha->sprite, pos_curs);
                    if ((event).type == sfEvtMouseButtonPressed) {
                        if ((pos_curs.x >= door1->pos.x 
                        && pos_curs.x <= door1->pos.x + 589
                        && pos_curs.y >= door1->pos.y 
                        && pos_curs.y <= door1->pos.y + 636) && g->obj1 == 0) {
                            g->pos_cam.x = 7680;
                            g->pos_cam.y = 540;
                            sfView_setCenter(g->cam, g->pos_cam);
                            g->door1 = 1;
                            g->game = 1;
                            sfSound_play(g->door_sound);
                        }
                        if ((pos_curs.x >= door2->pos.x 
                        && pos_curs.x <= door2->pos.x + 589
                        && pos_curs.y >= door2->pos.y 
                        && pos_curs.y <= door2->pos.y + 636) && g->obj2 == 0)  {
                            g->pos_cam.x = 0;
                            g->pos_cam.y = 540;
                            sfView_setCenter(g->cam, g->pos_cam);
                            g->game = 1;
                            g->door2 = 1;
                            sfSound_play(g->door_sound);
                        }
                        if ((pos_curs.x >= door3->pos.x 
                        && pos_curs.x <= door3->pos.x + 589
                        && pos_curs.y >= door3->pos.y 
                        && pos_curs.y <= door3->pos.y + 636) && g->obj3 == 0)  {
                            g->pos_cam.x = 0;
                            g->pos_cam.y = 540;
                            sfView_setCenter(g->cam, g->pos_cam);
                            g->game = 1;
                            g->door3 = 1;
                            sfSound_play(g->door_sound);
                        }
                        if ((pos_curs.x >= door4->pos.x 
                        && pos_curs.x <= door4->pos.x + 589
                        && pos_curs.y >= door4->pos.y 
                        && pos_curs.y <= door4->pos.y + 636) && g->obj4 == 0)  {
                            g->pos_cam.x = 0;
                            g->pos_cam.y = 540;
                            sfView_setCenter(g->cam, g->pos_cam);
                            g->game = 1;
                            g->door4 = 1;
                            sfSound_play(g->door_sound);
                        }
                    }
                    if ((event).type == sfEvtClosed)
                        sfRenderWindow_close(g->window);
                    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
                        g->move = 1;
                        g->pos = sfView_getCenter(g->cam);
                    }
                    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
                        g->move = 2;
                        g->pos = sfView_getCenter(g->cam);
                    }
                }
            }
        }
        else {
            g->pos_cam.x = 7680;
            g->pos_cam.y = 540;
            sfView_setCenter(g->cam, g->pos_cam);
            sfRenderWindow_setView(g->window, g->cam);
            sfRenderWindow_drawSprite(g->window, end->sprite, NULL);
            sfRenderWindow_display(g->window);
            while (sfRenderWindow_pollEvent(g->window, &event)) {
                if (event.type == sfEvtClosed) {
                    sfRenderWindow_close(g->window);
                }
            }
        }
    }
    sfRenderWindow_destroy(g->window);
}   