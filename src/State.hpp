#ifndef _State_hpp_
#define _State_hpp_

#include "StateIdentifiers.hpp"
#include "ResourceIdentifiers.hpp"
#include "MusicPlayer.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>

namespace sf
{
    class RenderWindow;
}

class StateStack;

class State
{
    public:
    typedef std::unique_ptr<State> Ptr;

    struct Context
    {
        Context(sf::RenderWindow& window,
                TextureHolder& textures,
                FontHolder& fonts,
                MusicPlayer& music);

        sf::RenderWindow* window;
        TextureHolder* textures;
        FontHolder* fonts;
        MusicPlayer* music;
    };


    public:
    State(StateStack& stack, Context context);
    virtual ~State();

    virtual void draw() = 0;
    virtual bool update(sf::Time dt) = 0;
    virtual bool handleEvent(const sf::Event& event) = 0;

    protected:
    void requestStackPush(States::ID stateID);
    void requestStackPop();
    void requestStateClear();

    Context getContext() const;

    private:
    StateStack* stack;
    Context context;
};

#endif // _State_hpp_
