// Created by Sakthi Thanigai on 4/15/2025
#ifndef SONGRECORDING_H
#define SONGRECORDING_H

#include <string>
#include <iostream>

namespace csce240_programming_assignment_5 {

class SongRecording {
  private:
    std::string title_;
    std::string* artists_;
    int num_artists_;
    int track_length_;

  public:
    SongRecording(std::string title = "untitled", std::string
    primary_artist = "unknown", int track_length = 0, int num_artists = 1);

    SongRecording(const SongRecording& other);
    SongRecording& operator=(const SongRecording& other);
    ~SongRecording();

    std::string GetTitle() const;
    void SetTitle(std::string title);

    int GetNumArtists() const;
    void SetNumArtists(int num);

    void SetArtist(std::string name, int index = 1);
    std::string GetArtist(int index = 1) const;

    int GetTrackLength() const;
    void SetTrackLength(int length);
};

}

#endif