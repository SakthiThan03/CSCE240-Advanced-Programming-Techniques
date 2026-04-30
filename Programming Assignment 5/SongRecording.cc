// Created by Sakthi Thanigai on 4/15/2025

#include "SongRecording.h"

namespace csce240_programming_assignment_5 {

SongRecording::SongRecording(std::string title, std::string primary_artist,
                             int track_length, int num_artists)
    : title_(title), num_artists_(num_artists), track_length_(track_length) {
  if (num_artists_ < 1) num_artists_ = 1;
  if (track_length_ < 0) track_length_ = 0;

  artists_ = new std::string[num_artists_];
  artists_[0] = (primary_artist.empty() ? "unknown" : primary_artist);
  for (int i = 1; i < num_artists_; ++i)
    artists_[i] = "";
}

SongRecording::SongRecording(const SongRecording& other)
    : title_(other.title_), num_artists_(other.num_artists_),
      track_length_(other.track_length_) {
  artists_ = new std::string[num_artists_];
  for (int i = 0; i < num_artists_; ++i)
    artists_[i] = other.artists_[i];
}

SongRecording& SongRecording::operator=(const SongRecording& other) {
  if (this != &other) {
    delete[] artists_;
    title_ = other.title_;
    num_artists_ = other.num_artists_;
    track_length_ = other.track_length_;
    artists_ = new std::string[num_artists_];
    for (int i = 0; i < num_artists_; ++i)
      artists_[i] = other.artists_[i];
  }
  return *this;
}

SongRecording::~SongRecording() {
  delete[] artists_;
}

std::string SongRecording::GetTitle() const {
  return title_;
}

void SongRecording::SetTitle(std::string title) {
  if (!title.empty()) title_ = title;
}

int SongRecording::GetNumArtists() const {
  return num_artists_;
}

void SongRecording::SetNumArtists(int num) {
  if (num < 1) return;
  std::string* new_artists = new std::string[num];
  for (int i = 0; i < num && i < num_artists_; ++i)
    new_artists[i] = artists_[i];
  delete[] artists_;
  artists_ = new_artists;
  num_artists_ = num;
}

void SongRecording::SetArtist(std::string name, int index) {
  if (!name.empty() && index >= 1 && index <= num_artists_)
    artists_[index - 1] = name;
}

std::string SongRecording::GetArtist(int index) const {
  if (index >= 1 && index <= num_artists_)
    return artists_[index - 1];
  return "out of bounds";
}

int SongRecording::GetTrackLength() const {
  return track_length_;
}

void SongRecording::SetTrackLength(int len) {
  if (len >= 0)
    track_length_ = len;
}

}