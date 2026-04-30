// Copyright Sakthi Thanigai on 03/30/25

#ifndef WEIGHTRANGE_H
#define WEIGHTRANGE_H

#include "weight.h"

class WeightRange {
public:
  // Constructors
  WeightRange();
  WeightRange(const Weight& w1, const Weight& w2);

  // Accessors
  Weight GetSmallest() const;
  Weight GetLargest() const;

  // Mutators
  void SetSmallest(const Weight& w);
  void SetLargest(const Weight& w);

  bool InRange(const Weight& w, bool inclusive = true) const;
  Weight Width() const;

  friend std::ostream& operator<<(std::ostream& out, const WeightRange& wr);

private:
  Weight smallest_;
  Weight largest_;
};

#endif

