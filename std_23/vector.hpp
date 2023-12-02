#include <compare>              // see compare.syn
#include <initializer_list>     // see initializer.list.syn

namespace std {
  // vector, class template vector
  template<class T, class Allocator = allocator<T>> class vector;

  template<class T, class Allocator>
    constexpr bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
  template<class T, class Allocator>
    constexpr @synth-three-way-result@<T> operator<=>(const vector<T, Allocator>& x,
              @\itcorr@                                      const vector<T, Allocator>& y);

  template<class T, class Allocator>
    constexpr void swap(vector<T, Allocator>& x, vector<T, Allocator>& y)
      noexcept(noexcept(x.swap(y)));

  // vector.erasure, erasure
  template<class T, class Allocator, class U>
    constexpr typename vector<T, Allocator>::size_type
      erase(vector<T, Allocator>& c, const U& value);
  template<class T, class Allocator, class Predicate>
    constexpr typename vector<T, Allocator>::size_type
      erase_if(vector<T, Allocator>& c, Predicate pred);

  namespace pmr {
    template<class T>
      using vector = std::vector<T, polymorphic_allocator<T>>;
  }

  // vector.bool, specialization of vector for bool
  // vector.bool.pspc, partial class template specialization \tcode{vector<bool, Allocator>}
  template<class Allocator>
    class vector<bool, Allocator>;

  template<class T>
    constexpr bool @is-vector-bool-reference@ = @\seebelow@;          // \expos

  // hash support
  template<class T> struct hash;
  template<class Allocator> struct hash<vector<bool, Allocator>>;

  // vector.bool.fmt, formatter specialization for vector<bool>
  template<class T, class charT> requires @is-vector-bool-reference@<T>
    struct formatter<T, charT>;
}
