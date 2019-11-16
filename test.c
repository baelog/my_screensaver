#include <SFML/Audio.h>
#include <SFML/Graphics.h>

int main()
{
    const char* frag;
    sfShader* shader;
    sfRenderWindow* win;
    sfImage* fg;
    sfTexture* fgt;
    sfSprite* fgs;
    sfRenderStates state;
    sfEvent event;
    sfVideoMode mode = {800, 600, 32};

    win = sfRenderWindow_create(mode, "SFML Test", sfDefaultStyle, NULL);

    fg = sfImage_createFromColor(400, 300, sfGreen);
    fgt = sfTexture_createFromImage(fg, NULL);
    fgs = sfSprite_create();
    sfSprite_setTexture(fgs, fgt, 0);
    
    frag = "void main() {gl_FragColor = vec4(1,0,0,1);}";
    shader = sfShader_createFromMemory(NULL, frag);

    state.shader = shader;
    state.blendMode = sfBlendAlpha;
    state.transform = sfTransform_Identity;
    state.texture = NULL;

    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &event)) {
            switch (event.type) {
                case sfEvtClosed:
                    sfRenderWindow_close(win);
                    continue;
            }
        }
        sfRenderWindow_clear(win, sfBlack);

        sfRenderWindow_drawSprite(win, fgs, &state); 
        //sfRenderWindow_drawSprite(win, fgs, NULL);

        sfRenderWindow_display(win);
    }

    return 0;
}