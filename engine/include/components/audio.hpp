#ifndef __ENGINE_COMPONENTS_AUDIO__
#define __ENGINE_COMPONENTS_AUDIO__

#include <string>

#include "sdl2include.h"
#include "components/component.hpp"

namespace engine {

class AudioComponent : public Component {
public:
    enum class AudioState {
        playing,
        paused,
        stopped
    };

    AudioComponent(std::string path, bool is_music=false,
                   bool play_on_start=true)
        : Component(), m_path(path), m_is_music(is_music),
          m_play_on_start(play_on_start), m_audio_state(AudioState::stopped),
          m_music(NULL), m_sound(NULL) {}

    bool init();
    bool shutdown();
    void update();

    void play(int loops=-1, int channel=-1);
    void stop(int channel=-1);
    void pause(int channel=-1);

    inline bool is_music() { return m_is_music; }

private:
    std::string m_path;
    bool m_is_music;
    bool m_play_on_start;
    AudioState m_audio_state;

    Mix_Music * m_music;
    Mix_Chunk * m_sound;
};

}

#endif
