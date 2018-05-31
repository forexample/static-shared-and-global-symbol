#include <A.hpp>

#include <stdexcept> // std::runtime_error

A::A(int v) {
  value_ = v;
  ++counter_;
}

A::~A() {
  --counter_;
}

A& A::operator= (const A& a) {
  if (&a == this) {
    return *this;
  }

  if(counter_ < 2) {
    throw std::runtime_error("Invalid counter");
  }

  this->value_ = a.value_;
  return *this;
}

int A::counter_ = 0;
