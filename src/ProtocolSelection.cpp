#include "ProtocolSelection.h"
ProtocolSelection::ProtocolSelection()
{
    //ctor
    bg_texture.loadFromFile("res/1.png");
    bg_sprite.setTexture(bg_texture);
    TCP=Button("res/buttons/idle.png","res/buttons/hover.png","res/buttons/clicked.png",sf::Vector2f(261,286));
    UDP=Button("res/buttons/idle.png","res/buttons/hover.png","res/buttons/clicked.png",sf::Vector2f(261,305));
    Next=Button("res/buttons/next_idle.png","res/buttons/next_idle.png","res/buttons/next_clicked.png",sf::Vector2f(352,339));
    protocol='t';
    TCP.Click(1);
    CurrentClicked=&TCP;
}

ProtocolSelection::~ProtocolSelection()
{
    //dtor
}
Scene* ProtocolSelection::Run(sf::RenderWindow& Wind)
{
    sf::Event ev;
    bool ok=false;
    while(Wind.isOpen())
    {
        Wind.clear();
        while(Wind.pollEvent(ev))
        {
            if(ev.type==sf::Event::Closed)
            {
                Wind.close();
                return NULL;
            }
            if(ev.type==sf::Event::MouseButtonPressed)
            {
                if(ev.mouseButton.button==sf::Mouse::Left)
                {
                    if(TCP.MouseInside(Wind))
                    {
                        CurrentClicked->Click(0);
                        CurrentClicked=&TCP;
                        CurrentClicked->Click(1);
                        protocol='t';
                    }
                    if(UDP.MouseInside(Wind))
                    {
                        CurrentClicked->Click(0);
                        CurrentClicked=&UDP;
                        CurrentClicked->Click(1);
                        protocol='u';
                    }
                    if(Next.MouseInside(Wind))
                    {
                        ok=true;
                    }
                }
            }
            if(ev.type==sf::Event::MouseButtonReleased)
            {
                if(ev.mouseButton.button==sf::Mouse::Left)
                {
                    if(Next.MouseInside(Wind)&& ok)
                    {
                        if(sideselect==NULL)
                        {
                            sideselect=new SideSelection;
                        }
                        return sideselect;
                    }
                    else
                    {
                        ok=0;
                    }
                }
            }
        }
        Next.Click(Next.MouseInside(Wind) && ok);
        Wind.draw(bg_sprite);
        TCP.Update(Wind);
        TCP.Draw(Wind);
        UDP.Update(Wind);
        UDP.Draw(Wind);
        //Next.Update(Wind);
        Next.Draw(Wind);
        Wind.display();
    }
    return NULL;
}
