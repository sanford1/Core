#ifndef _TitleState_hpp_
#define _TitleState_hpp_

#include "../System/State.hpp"
#include "../GUI/Menu.hpp"
#include <SFML/Graphics.hpp>

class TitleState : public State
{
    public:
    TitleState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

    private:
    sf::View world;

    sf::Sprite bg;
    sf::Text text;

    Menu menu;
};

#endif // _TitleState_hpp_

