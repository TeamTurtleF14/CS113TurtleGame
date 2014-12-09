#include <SFML/Graphics.hpp>
#include "ZeroGameEngine.hpp"
#include <iostream>

using namespace ZGE;
// Testing stuff will go in here, old references will go into the commented main()
int main(){
	ZeroGameEngine* game = new ZeroGameEngine();
	game->Start();
	delete game;
}

//int main()
//{
////	int x_dimension = 1280;
////	int y_dimension = 768;
//    sf::RenderWindow window(sf::VideoMode(1024, 768), "Zeroth Law");
//
//    sf::Texture background;
//    if (!background.loadFromFile("src/Images/Pause.jpg"))
//    		return -1;
//
//    background.setRepeated(true);
//    sf::Sprite BG;
//    BG.setTexture(background);
//    BG.setTextureRect(sf::IntRect(0, 0, 1024, 768));
//
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        window.clear();
////        window.draw(shape);
//        window.draw(BG);
//        window.draw(shape);
//        window.display();
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
//        	std::cout << "Left" << std::endl;
//        }
//    }
//
//    return 0;
//}
