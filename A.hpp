#ifndef A_HPP_
#define A_HPP_

class A {
  int value_;

 public:
  static int counter_;

  A(int v);
  ~A();

  A(const A&) =delete;
  A(A&&) =delete;

  A& operator= (const A&);
  A& operator= (A&&) =delete;
};

#endif // A_HPP_
