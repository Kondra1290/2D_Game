#include <SFML/Graphics.hpp>
#include <thread>
#include <iostream>
#include "NPC.h"
#include "Player.h"
#include "Player.h"

using namespace sf;
using namespace std;

constexpr float windowXSize = 500.f, windowYSize = 500.f;
constexpr float speed = 4.f;

constexpr float ballRadius = 10.f;
constexpr float ballSpeed = 6.f;

constexpr float paddleXSize = 60.f;
constexpr float paddleYSize = 10.f;
constexpr float paddleSpeed = 6.f;

constexpr float blockXSize = 60.f, blockYSize = 20.f;
constexpr float outLineSize = 5.f;
constexpr int blocksXCount = 11;
constexpr int blocksYCount = 4;
float way = 0;
float distation;

void openMenu() {
    sf::RenderWindow menu(sf::VideoMode(windowXSize/2.f, windowYSize/2.f), "Menu");
    //window.setVerticalSyncEnabled(true);
    menu.setFramerateLimit(60);

    while (menu.isOpen())
    {
        sf::Event event;
        while (menu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || 
                (event.type == sf::Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Escape)))
                menu.close();
        }

        menu.clear();
        //window.draw();
        menu.display();
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowXSize, windowYSize), "F2DG");
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    vector<RectangleShape> inv;
    Player player(windowXSize / 2.f, windowYSize / 2.f, "sdfsd", 100, inv);

    Vector2i pixelPos = Mouse::getPosition(window);
    Vector2f pos = window.mapPixelToCoords(pixelPos);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Escape)) {
                openMenu();
            }
            /*else if (Mouse::isButtonPressed(Mouse::Left)) {
                thread attack(&Player::Attack, player);
                attack.join();
                this_thread::sleep_for(chrono::seconds(2));
            }*/
            //else if (Mouse::isButtonPressed(Mouse::Left)) {
            else if (event.type == Event::MouseMoved){
                pixelPos = Mouse::getPosition(window);
                pos = window.mapPixelToCoords(pixelPos);
                distation = sqrt((pos.x - player.x()) * (pos.x - player.x()) + (pos.y - player.y()) * (pos.y - player.y()));
                way = player.Rotare(pos);
            }
        }

        player.Move(distation, speed, way);

        window.clear();
        window.draw(player.getShape());
        window.display();
    }

    return 0;
}