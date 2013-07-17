#ifndef _MusicPlayer_hpp_
#define _MusicPlayer_hpp_

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

#include <map>
#include <string>


class MusicPlayer : private sf::NonCopyable
{
    public:
        MusicPlayer();

        void play(Music theme);
        void stop();

        void setPaused(bool paused);
        void setVolume(float volume);

    private:
        sf::Music mMusic;
        std::map<Music, std::string> mFilenames;
        float mVolume;
};

#endif // _MusicPlayer_hpp_
