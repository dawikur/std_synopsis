#include <compare>              // see compare.syn
#include <initializer_list>     // see initializer.list.syn

namespace std {
  // flat.set, class template flat_set
  template<class Key, class Compare = less<Key>, class KeyContainer = vector<Key>>
    class flat_set;

  struct sorted_unique_t { explicit sorted_unique_t() = default; };
  inline constexpr sorted_unique_t sorted_unique{};

  template<class Key, class Compare, class KeyContainer, class Allocator>
    struct uses_allocator<flat_set<Key, Compare, KeyContainer>, Allocator>;

  // flat.set.erasure, erasure for flat_set
  template<class Key, class Compare, class KeyContainer, class Predicate>
    typename flat_set<Key, Compare, KeyContainer>::size_type
      erase_if(flat_set<Key, Compare, KeyContainer>& c, Predicate pred);

  // flat.multiset, class template flat_multiset
  template<class Key, class Compare = less<Key>, class KeyContainer = vector<Key>>
    class flat_multiset;

  struct sorted_equivalent_t { explicit sorted_equivalent_t() = default; };
  inline constexpr sorted_equivalent_t sorted_equivalent{};

  template<class Key, class Compare, class KeyContainer, class Allocator>
    struct uses_allocator<flat_multiset<Key, Compare, KeyContainer>, Allocator>;

  // flat.multiset.erasure, erasure for flat_multiset
  template<class Key, class Compare, class KeyContainer, class Predicate>
    typename flat_multiset<Key, Compare, KeyContainer>::size_type
      erase_if(flat_multiset<Key, Compare, KeyContainer>& c, Predicate pred);
}
