//
// Created by Andrew Hayman on 2021-11-30.
//

#include "Banner.h"
#include <iostream>

void Banner::init() {
    if(!font.loadFromFile("../assets/fonts/arial.ttf")) {
        std::cout << "FONT LOAD ERROR " << std::endl;
        exit(1);
    }
    banner.setFont(font);
    banner.setString("");
    banner.setFillColor(sf::Color::Blue);
    banner.setPosition(sf::Vector2f(50, 40));
    banner.setStyle(sf::Text::Bold);
    banner.setCharacterSize(28);
}


void Banner::update(int health, int money, int level) {
    bannerText = "Health: " + std::to_string(health) + "\tMoney: " + std::to_string(money) + "\tLevel: " + std::to_string(level);
    banner.setString(bannerText);

    sf::FloatRect bannerBounds = banner.getGlobalBounds();
    background = sf::RectangleShape(sf::Vector2f(bannerBounds.width+50,bannerBounds.height+35));
    background.setPosition(banner.getPosition().x-20, banner.getPosition().y-15);
}
void Banner::renderAll(sf::RenderWindow* gameScreen) {
    gameScreen->draw(background);
    gameScreen->draw(banner);
}