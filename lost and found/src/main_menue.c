/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** main_menue
*/

#include "my.h"
#include "build.h"

void main_menue(g_t *g)
{
    sfEvent event;
    sfVector2i mpos;

    sprite_t *first = malloc(sizeof(sprite_t));
    sprite_t *second = malloc(sizeof(sprite_t));
    first->texture = sfTexture_createFromFile("texture/manu.png", NULL);
    first->sprite = sfSprite_create();
    sfSprite_setTexture(first->sprite, first->texture, sfTrue);
    second->texture = sfTexture_createFromFile("texture/howtoplay.png", NULL);
    second->sprite = sfSprite_create();
    sfSprite_setTexture(second->sprite, second->texture, sfTrue);
    while (sfRenderWindow_isOpen(g->window) && g->menu2 == 0) {
        sfRenderWindow_display(g->window);
        if (g->menu1 == 0)
            sfRenderWindow_drawSprite(g->window, first->sprite, NULL);
        else
            sfRenderWindow_drawSprite(g->window, second->sprite, NULL);
        while (sfRenderWindow_pollEvent(g->window, &event)) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                mpos = sfMouse_getPositionRenderWindow(g->window);
                printf("%d, %d \n", mpos.x, mpos.y);
                if (mpos.x >= 653 && mpos.x <= 1277) {
                    if (mpos.y >= 600 && mpos.y <= 800)
                    g->menu1 = 1;
                }
            }
            if (sfKeyboard_isKeyPressed(sfKeyEnter))
                g->menu2 = 1;
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(g->window);
            }
        }
    }
}