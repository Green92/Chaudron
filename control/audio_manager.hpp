#ifndef AUDIO_MANAGER_HPP
#define AUDIO_MANAGER_HPP

#include <sifteo/audio.h>

static const unsigned char UNDEFINED_CHANNEL = 8;
static const unsigned char CHANNEL_NUMBER = 8;
static const unsigned char MIN_CHANNEL = 0;

class AudioManager {

	private:
		unsigned char musicChannelNumber = 8;
 
	public:
		bool playMusic(const AssetAudio &music) {
			if (musicChannelNumber != UNDEFINED_CHANNEL) {
				return Sifteo::AudioChannel(musicChannelNumber).play(music, Sifteo::AudioChannel::REPEAT);
			}

			for (unsigned int i = MIN_CHANNEL; i<CHANNEL_NUMBER; i++) {
				if (!Sifteo::AudioChannel(i).isPlaying()) {
					musicChannelNumber = i;
					return Sifteo::AudioChannel(musicChannelNumber).play(music, Sifteo::AudioChannel::REPEAT);
				}
			}

			return false;
		}

		void stopMusic() {
			if (musicChannelNumber != UNDEFINED_CHANNEL) {
				Sifteo::AudioChannel(musicChannelNumber).stop();
				musicChannelNumber = UNDEFINED_CHANNEL;
			}
		}

		bool playSound(const AssetAudio &music) {
			for (unsigned int i = MIN_CHANNEL; i<CHANNEL_NUMBER; i++) {
				if (!Sifteo::AudioChannel(i).isPlaying()) {
					return Sifteo::AudioChannel(i).play(music, Sifteo::AudioChannel::ONCE);
				}
			}

			return false;
		}
};

#endif