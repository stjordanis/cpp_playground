// requires: C++14
#include <struct_magic.h>

#include <array>
#include <iostream>
#include <iterator>
#include <string>

struct get_type_size {
  template <typename T> int operator()(T &&) const { return sizeof(T); }
};

struct Data {
  double speed;
  double velocity;
  double acceleration;
  int some_integer;
};

template <typename T, size_t n>
std::ostream &operator<<(std::ostream &o, const std::array<T, n> &arr) {
  std::copy(arr.cbegin(), arr.cend(), std::ostream_iterator<T>(o, " "));
  return o;
}

int main() {
  using namespace boost::pfr::ops;

  Data v1{100., 11., 21., 3};
  Data v2{200., 12., 22., 5};

  auto v1_double =
      struct_magic::transform([](const auto &v) { return v * 2; }, v1);
  std::cout << "vi_double: " << v1_double << std::endl;

  // auto v3 = struct_magic::transform(
  //     [](const auto &v1, const auto &v2) { return v1 + v2; }, v1, v2);
  // std::cout << "v3: " << v3 << std::endl;

  // std::cout << res << std::endl;
}
