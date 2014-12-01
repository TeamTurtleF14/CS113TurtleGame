#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	int x_dimension = 1280;
	int y_dimension = 768;
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Zeroth Law");

    sf::Texture background;
    if (!background.loadFromFile("src/Images/Blue_Background-wall.jpg"))
    		return -1;

    background.setRepeated(true);
    sf::Sprite BG;
    BG.setTexture(background);
    BG.setTextureRect(sf::IntRect(0, 0, 1080, 720));

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
//        window.draw(shape);
        window.draw(BG);
        window.draw(shape);
        window.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        	std::cout << "Left" << std::endl;
        }
    }

    return 0;
}
