// Created by Sakthi Thanigai on 4/15/2025

#include "StreamingTrack.h"

namespace csce240_programming_assignment_5 {

StreamingTrack::StreamingTrack(std::string title, std::string primary_artist, int track_length,
                               int num_artists, std::string primary_genre, int streams)
    : SongRecording(title, primary_artist, track_length, num_artists), streams_(streams) {
  if (streams_ < 0) streams_ = 0;
  genres_ = new std::string[1];
  genres_[0] = primary_genre;
  num_genres_ = 1;
}

StreamingTrack::StreamingTrack(const StreamingTrack& other)
    : SongRecording(other), streams_(other.streams_), num_genres_(other.num_genres_) {
  genres_ = new std::string[num_genres_];
  for (int i = 0; i < num_genres_; ++i)
    genres_[i] = other.genres_[i];
}

StreamingTrack::StreamingTrack(const SongRecording& base, std::string genre, int streams)
    : SongRecording(base), streams_(streams) {
  if (streams_ < 0) streams_ = 0;
  genres_ = new std::string[1];
  genres_[0] = genre;
  num_genres_ = 1;
}

StreamingTrack& StreamingTrack::operator=(const StreamingTrack& other) {
  if (this != &other) {
    SongRecording::operator=(other);
    delete[] genres_;
    streams_ = other.streams_;
    num_genres_ = other.num_genres_;
    genres_ = new std::string[num_genres_];
    for (int i = 0; i < num_genres_; ++i)
      genres_[i] = other.genres_[i];
  }
  return *this;
}

StreamingTrack::~StreamingTrack() {
  delete[] genres_;
}

int StreamingTrack::GetStreams() const {
  return streams_;
}

void StreamingTrack::SetStreams(int count) {
  if (count >= 0)
    streams_ = count;
}

void StreamingTrack::AddStreams(int count) {
  if (count >= 0)
    streams_ += count;
}

int StreamingTrack::GetNumGenres() const {
  return num_genres_;
}

std::string StreamingTrack::GetGenre(int index) const {
  if (index >= 1 && index <= num_genres_)
    return genres_[index - 1];
  return "out of bounds";
}

bool StreamingTrack::IsGenre(std::string genre) const {
  for (int i = 0; i < num_genres_; ++i) {
    if (genres_[i] == genre) return true;
  }
  return false;
}

void StreamingTrack::AddGenre(std::string genre) {
  if (IsGenre(genre)) return;
  std::string* new_genres = new std::string[num_genres_ + 1];
  for (int i = 0; i < num_genres_; ++i)
    new_genres[i] = genres_[i];
  new_genres[num_genres_++] = genre;
  delete[] genres_;
  genres_ = new_genres;
}

void StreamingTrack::RemoveGenre(std::string genre) {
  int index = -1;
  for (int i = 0; i < num_genres_; ++i) {
    if (genres_[i] == genre) {
      index = i;
      break;
    }
  }
  if (index == -1) return;
  std::string* new_genres = new std::string[num_genres_ - 1];
  for (int i = 0, j = 0; i < num_genres_; ++i) {
    if (i != index) new_genres[j++] = genres_[i];
  }
  delete[] genres_;
  genres_ = new_genres;
}

}
