#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <ProtocolSelection.h>
using namespace std;

void runTcpServer(unsigned short port);
void runTcpClient(unsigned short port);
void runUdpServer(unsigned short port);
void runUdpClient(unsigned short port);
void initWindow();
sf::RenderWindow Wind;
int main()
{
    initWindow();
    ProtocolSelection protselect;
    Scene* currScene=&protselect;
    while(currScene!=NULL)
    {
        currScene=currScene->Run(Wind);
    }
    /*sf::Thread RenderEngine(&Render);
    RenderEngine.launch();*/
    const unsigned short port = 50001;

    char protocol;
    std::cout << "Do you want to use TCP (t) or UDP (u)? ";
    std::cin  >> protocol;

    // Client or server ?
    char who;
    std::cout << "Do you want to be a server (s) or a client (c)? ";
    std::cin  >> who;

    if (protocol == 't')
    {
        // Test the TCP protocol
        if (who == 's')
            runTcpServer(port);
        else
            runTcpClient(port);
    }
    else
    {
        if(who=='s')
            runUdpServer(port);
        else
            runUdpClient(port);
    }

    // Wait until the user presses 'enter' key
    std::cout << "Press enter to exit..." << std::endl;
    std::cin.ignore(10000, '\n');
    std::cin.ignore(10000, '\n');

    return EXIT_SUCCESS;
}
void initWindow()
{
    Wind.create(sf::VideoMode(640, 480),"Hermes", sf::Style::Close);
    Wind.setFramerateLimit(60);
    sf::Image icon;
    icon.loadFromFile("res/icons/ico.png");
    Wind.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
}