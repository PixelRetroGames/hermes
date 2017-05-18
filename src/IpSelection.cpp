#include "IpSelection.h"

IpSelection::IpSelection()
{
    //ctor
    //ipBox=TextBox("res/fonts/micross.ttf",12,sf::Color::White);
}

IpSelection::~IpSelection()
{
    //dtor
}
Scene* IpSelection::Run(sf::RenderWindow& Wind)
{
    sf::Event ev;
    while(Wind.isOpen())
    {
        while(Wind.pollEvent(ev))
        {
            if(ev.type==sf::Event::Closed)
            {
                Wind.close();
                return NULL;
            }
            if(ev.type==sf::Event::TextEntered)
            {
                if(ev.text.unicode=='\b')
                {
                    ipBox.Backspace();
                }
                else if(ev.text.unicode==13)
                {
                    ipBox.Enter();
                }
                else
                {
                    ipBox.AddChar((char) ev.text.unicode);
                }
            }
            ipBox.UpdateCursor(ev);
        }
        Wind.clear(sf::Color::Black);
        ipBox.Draw(Wind);
        Wind.display();
    }
    return NULL;
}