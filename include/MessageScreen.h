#ifndef MESSAGESCREEN_H
#define MESSAGESCREEN_H

#include <Scene.h>
#include<SFML/Audio.hpp>
#include<SFMl/Network.hpp>
#include<TextBox.h>
#define MAX_MESSAGES 22
extern sf::TcpSocket socket;
class MessageScreen : public Scene
{
    public:
        MessageScreen();
        virtual ~MessageScreen();
        virtual Scene* Run(sf::RenderWindow& Wind);
        void DrawText(sf::RenderWindow& Wind);
        void ScrollToLastMessage();
        void SENDER();
        void RECEIVER();
    protected:

    private:
        sf::Texture bg_texture;
        sf::Sprite bg_sprite;
        sf::SoundBuffer EntrySndBuf;
        sf::Font textFont;
        sf::Text m_messages;
        std::vector<std::string> MessageRows;
        TextBox* inputBox;
        int firstRow,lastRow;
        int number_of_messages;
        bool scrollEnabled;
};

#endif // MESSAGESCREEN_H