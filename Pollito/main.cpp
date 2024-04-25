#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(400, 400), "Pollito SFML");

    sf::Vector2u windowSize = window.getSize();
    float windowWidth = windowSize.x;
    float windowHeight = windowSize.y;

    float chickenSize = 200;

    float bodyPosX = (windowWidth - chickenSize) / 2;
    float bodyPosY = (windowHeight - chickenSize) / 2;
    float headPosX = bodyPosX + -70;
    float headPosY = bodyPosY + -70;
    float eye1PosX = headPosX + 20;
    float eye1PosY = headPosY + 20;
    float eye2PosX = headPosX + 70;
    float eye2PosY = headPosY + 20;
    float beakPosX = headPosX + 30;
    float beakPosY = headPosY + 70;

    sf::CircleShape body(chickenSize / 2);
    body.setFillColor(sf::Color(255, 255, 0));
    body.setPosition(bodyPosX, bodyPosY);

    sf::CircleShape head(chickenSize / 2 * 0.8);
    head.setFillColor(sf::Color(255, 255, 0));
    head.setPosition(headPosX, headPosY);

    sf::CircleShape eye1(10);
    eye1.setFillColor(sf::Color::Black);
    eye1.setPosition(eye1PosX, eye1PosY);

    sf::CircleShape eye2(10);
    eye2.setFillColor(sf::Color::Black);
    eye2.setPosition(eye2PosX, eye2PosY);

    sf::ConvexShape beak(3);
    beak.setFillColor(sf::Color(255, 165, 0));
    beak.setPoint(0, sf::Vector2f(beakPosX, beakPosY));
    beak.setPoint(1, sf::Vector2f(beakPosX + 20, beakPosY + 30));
    beak.setPoint(2, sf::Vector2f(beakPosX - 20, beakPosY + 30)); 

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        window.draw(body);
        window.draw(head);
        window.draw(eye1);
        window.draw(eye2);
        window.draw(beak);

        window.display();
    }

    return 0;
}