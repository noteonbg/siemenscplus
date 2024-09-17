#include <iostream>
#include <string>


#if 1
class MediaPlayer {
public:
    virtual void play(const std::string& fileName) {
        std::cout << "Playing audio file: " << fileName << std::endl;
    }
};

class VideoPlayer : public MediaPlayer {
public:
    void play(const std::string& fileName) override {
        // Check if the file is a video
        if (fileName.find(".mp4") != std::string::npos || fileName.find(".avi") != std::string::npos) {
            std::cout << "Playing video file: " << fileName << std::endl;
        } else {
            std::cerr << "Error: " << fileName << " is not a video file" << std::endl;
        }
    }
};

void playMedia(MediaPlayer& player, const std::string& fileName) {
    player.play(fileName);
}

int main() {
    MediaPlayer audioPlayer;
    VideoPlayer videoPlayer;

    playMedia(audioPlayer, "song.mp3");  // Works fine
    playMedia(videoPlayer, "movie.mp4"); // Works fine
    playMedia(videoPlayer, "song.mp3");  // Violates LSP, unexpected behavior

    return 0;
}

#endif

#if 1

#include <iostream>
#include <string>

// Base class
class MediaPlayer {
public:
    virtual void play(const std::string& fileName) {
        std::cout << "Playing media file: " << fileName << std::endl;
    }
    virtual ~MediaPlayer() = default;
};

// Derived class for audio player
class AudioPlayer : public MediaPlayer {
public:
    void play(const std::string& fileName) override {
        if (fileName.find(".mp3") != std::string::npos) {
            std::cout << "Playing audio file: " << fileName << std::endl;
        } else {
            std::cerr << "Error: " << fileName << " is not an audio file" << std::endl;
        }
    }
};

// Derived class for video player
class VideoPlayer : public MediaPlayer {
public:
    void play(const std::string& fileName) override {
        if (fileName.find(".mp4") != std::string::npos || fileName.find(".avi") != std::string::npos) {
            std::cout << "Playing video file: " << fileName << std::endl;
        } else {
            std::cerr << "Error: " << fileName << " is not a video file" << std::endl;
        }
    }
};

void playMedia(MediaPlayer& player, const std::string& fileName) {
    player.play(fileName);
}

int main() {
    AudioPlayer audioPlayer;
    VideoPlayer videoPlayer;

    playMedia(audioPlayer, "song.mp3");  // Works fine
    playMedia(videoPlayer, "movie.mp4"); // Works fine
    playMedia(videoPlayer, "song.mp3");  // Clear behavior, specific to video player

    return 0;
}


#endif
