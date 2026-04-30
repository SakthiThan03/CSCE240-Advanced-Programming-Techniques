// Created by Sakthi Thanigai on 4/15/2025

#ifndef STREAMING_TRACK_H
#define STREAMING_TRACK_H

#include "SongRecording.h"

namespace csce240_programming_assignment_5 {

    class StreamingTrack : public SongRecording {
    private:
        int streams_;
        std::string* genres_;
        int num_genres_;

    public:
        StreamingTrack(std::string title = "untitled", std::string primary_artist = "unknown",
                       int track_length = 0, int num_artists = 1,
                       std::string primary_genre = "pop", int streams = 0);
        StreamingTrack(const StreamingTrack& other);
        StreamingTrack(const SongRecording& base, std::string genre = "pop", int streams = 0);
        StreamingTrack& operator=(const StreamingTrack& other);
        ~StreamingTrack();

        int GetStreams() const;
        void SetStreams(int count);
        void AddStreams(int count);

        int GetNumGenres() const;
        std::string GetGenre(int index = 1) const;
        bool IsGenre(std::string genre) const;
        void AddGenre(std::string genre);
        void RemoveGenre(std::string genre);
    };

}  // namespace csce240_programming_assignment_5

#endif