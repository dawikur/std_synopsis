#include <compare>              // see compare.syn
#include <initializer_list>     // see initializer.list.syn

namespace std {
  // flat.map, class template flat_map
  template<class Key, class T, class Compare = less<Key>,
           class KeyContainer = vector<Key>, class MappedContainer = vector<T>>
    class flat_map;

  struct sorted_unique_t { explicit sorted_unique_t() = default; };
  inline constexpr sorted_unique_t sorted_unique{};

  template<class Key, class T, class Compare, class KeyContainer, class MappedContainer,
           class Allocator>
    struct uses_allocator<flat_map<Key, T, Compare, KeyContainer, MappedContainer>,
                          Allocator>;

  // flat.map.erasure, erasure for flat_map
  template<class Key, class T, class Compare, class KeyContainer, class MappedContainer,
           class Predicate>
    typename flat_map<Key, T, Compare, KeyContainer, MappedContainer>::size_type
      erase_if(flat_map<Key, T, Compare, KeyContainer, MappedContainer>& c, Predicate pred);

  // flat.multimap, class template flat_multimap
  template<class Key, class T, class Compare = less<Key>,
           class KeyContainer = vector<Key>, class MappedContainer = vector<T>>
    class flat_multimap;

  struct sorted_equivalent_t { explicit sorted_equivalent_t() = default; };
  inline constexpr sorted_equivalent_t sorted_equivalent{};

  template<class Key, class T, class Compare, class KeyContainer, class MappedContainer,
           class Allocator>
    struct uses_allocator<flat_multimap<Key, T, Compare, KeyContainer, MappedContainer>,
                          Allocator>;

  // flat.multimap.erasure, erasure for flat_multimap
  template<class Key, class T, class Compare, class KeyContainer, class MappedContainer,
           class Predicate>
    typename flat_multimap<Key, T, Compare, KeyContainer, MappedContainer>::size_type
      erase_if(flat_multimap<Key, T, Compare, KeyContainer, MappedContainer>& c, Predicate pred);
}
