namespace std {
  // cmp.categories, comparison category types
  class partial_ordering;
  class weak_ordering;
  class strong_ordering;

  // named comparison functions
  constexpr bool is_eq  (partial_ordering cmp) noexcept { return cmp == 0; }
  constexpr bool is_neq (partial_ordering cmp) noexcept { return cmp != 0; }
  constexpr bool is_lt  (partial_ordering cmp) noexcept { return cmp < 0; }
  constexpr bool is_lteq(partial_ordering cmp) noexcept { return cmp <= 0; }
  constexpr bool is_gt  (partial_ordering cmp) noexcept { return cmp > 0; }
  constexpr bool is_gteq(partial_ordering cmp) noexcept { return cmp >= 0; }

  // cmp.common, common comparison category type
  template<class... Ts>
  struct common_comparison_category {
    using type = @\seebelow@;
  };
  template<class... Ts>
    using common_comparison_category_t = typename common_comparison_category<Ts...>::type;

  // cmp.concept, concept three_way_comparable
  template<class T, class Cat = partial_ordering>
    concept three_way_comparable = @\seebelow@;
  template<class T, class U, class Cat = partial_ordering>
    concept three_way_comparable_with = @\seebelow@;

  // cmp.result, result of three-way comparison
  template<class T, class U = T> struct compare_three_way_result;

  template<class T, class U = T>
    using compare_three_way_result_t = typename compare_three_way_result<T, U>::type;

  // comparisons.three.way, class compare_three_way
  struct compare_three_way;

  // cmp.alg, comparison algorithms
  inline namespace @\unspec@ {
    inline constexpr @\unspec@ strong_order = @\unspec@;
    inline constexpr @\unspec@ weak_order = @\unspec@;
    inline constexpr @\unspec@ partial_order = @\unspec@;
    inline constexpr @\unspec@ compare_strong_order_fallback = @\unspec@;
    inline constexpr @\unspec@ compare_weak_order_fallback = @\unspec@;
    inline constexpr @\unspec@ compare_partial_order_fallback = @\unspec@;
  }
}
