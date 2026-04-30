// Copyright Sakthi Thanigai on 03/30/25

#include "weightrange.h"

#include <cmath>

//Constructor
WeightRange::WeightRange() : smallest_(0, "pounds"), largest_(0, "pounds") {}

WeightRange::WeightRange(const Weight& w1, const Weight& w2) {
  if (w1 <= w2) {
    smallest_ = w1;
    largest_ = w2;
  } else {
    smallest_ = w2;
    largest_ = w1;
  }
}

// Accessors
Weight WeightRange::GetSmallest() const {
  return smallest_;
}

Weight WeightRange::GetLargest() const {
  return largest_;
}

// Mutators
void WeightRange::SetSmallest(const Weight& w) {
  if (w <= largest_)
    smallest_ = w;
}

void WeightRange::SetLargest(const Weight& w) {
  if (smallest_ <= w)
    largest_ = w;
}

// InRange check
bool WeightRange::InRange(const Weight& w, bool inclusive) const {
  if (inclusive)
    return smallest_ <= w && w <= largest_;
  else
    return !(w <= smallest_) && !(largest_ <= w);
}

// Width = largest - smallest (in largest's units)
Weight WeightRange::Width() const {
  Weight temp = smallest_;
  temp.ConvertUnits(largest_.GetUnits());
  double diff = largest_.GetValue() - temp.GetValue();

  diff = std::round(diff * 10000.0) / 10000.0;

  if (diff < 0) diff = 0;

  return Weight(diff, largest_.GetUnits());
}

std::ostream& operator<<(std::ostream& out, const WeightRange& wr) {
  out << wr.smallest_ << " - " << wr.largest_;
  return out;
}

