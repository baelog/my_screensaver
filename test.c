#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

typedef struct project_s
{
    sfRenderWindow* window;
    sfVideoMode mode;
    sfEvent event;
}project_t;

void my_event(project_t *project)
{
    while (sfRenderWindow_pollEvent(project->window, &project->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(project->window);
    }
}

void my_screensaver(void)
{
    int var = 100;
    float len = (float)200;
    float height = (float)860;
    sfVector2f pos = {958, height};
    sfVector2f vector = {4, len};
    sfVertexArray *array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(array, sfLines);
    sfVertex vertex1;
    sfVertex vertex2;
    vertex1.position.x = (float)960;
    vertex1.position.y = height - len;
    vertex1.color = sfWhite;
    vertex2.position.x = (float)960;
    vertex2.position.y = height;
    vertex2.color = sfWhite;
    sfVertexArray_append(array, vertex1);
    sfVertexArray_append(array, vertex2);
    /*sf::VertexArray array(sf::PrimitiveType::Lines); // chaque paire de vertex forme une ligne
    array.append(sf::Vertex(sf::Vector2f(x1, y1), sf::Color)); // point de départ de la ligne
    array.append(sf::Vertex(sf::Vector2f(x2, y2), sf::Color)); // point d'arrivée de la ligne
    array.append(sf::Vertex(sf::Vector2f(x3, y3), sf::Color)); // non affiché car pas de fin
    sf::VertexArray arrayStrip(sf::PrimitiveType::LineStrip); // vertex se succédant pour former des lignes
    arrayStrip.append(sf::Vertex(sf::Vector2f(x1, y1), sf::Color)); // point de départ de la ligne
    arrayStrip.append(sf::Vertex(sf::Vector2f(x2, y2), sf::Color)); // point intermédiaire de la ligne
    arrayStrip.append(sf::Vertex(sf::Vector2f(x3, y3), sf::Color)); // point d'arrivée de la ligne*/
    project_t project;
    sfVideoMode mode = {1920, 1080, 32};
    project.window = sfRenderWindow_create(mode, "MY_SCREENSAVER", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(project.window, 60);
    while (sfRenderWindow_isOpen(project.window)) {
        my_event(&project);
        sfRenderWindow_clear(project.window, sfBlack);
        sfRenderWindow_display(project.window);
        sfRenderWindow_drawVertexArray(project.window, array, NULL);
        sfRenderWindow_display(project.window);
    }
    sfRenderWindow_destroy(project.window);
}

int main(void)
{
    my_screensaver();
}