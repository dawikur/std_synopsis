#include <compare>              // see compare.syn
#include <initializer_list>     // see initializer.list.syn
#include <iterator>             // see iterator.synopsis

namespace std::ranges {
  inline namespace @\unspec@ {
    // range.access, range access
    inline constexpr @\unspec@ begin = @\unspec@;
    inline constexpr @\unspec@ end = @\unspec@;
    inline constexpr @\unspec@ cbegin = @\unspec@;
    inline constexpr @\unspec@ cend = @\unspec@;
    inline constexpr @\unspec@ rbegin = @\unspec@;
    inline constexpr @\unspec@ rend = @\unspec@;
    inline constexpr @\unspec@ crbegin = @\unspec@;
    inline constexpr @\unspec@ crend = @\unspec@;

    inline constexpr @\unspec@ size = @\unspec@;
    inline constexpr @\unspec@ ssize = @\unspec@;
    inline constexpr @\unspec@ empty = @\unspec@;
    inline constexpr @\unspec@ data = @\unspec@;
    inline constexpr @\unspec@ cdata = @\unspec@;
  }

  // range.range, ranges
  template<class T>
    concept range = @\seebelow@;

  template<class T>
    inline constexpr bool enable_borrowed_range = false;

  template<class T>
    concept borrowed_range = @\seebelow@;

  template<class T>
    using iterator_t = decltype(ranges::begin(declval<T&>()));
  template<@range@ R>
    using sentinel_t = decltype(ranges::end(declval<R&>()));
  template<@range@ R>
    using range_difference_t = iter_difference_t<iterator_t<R>>;
  template<@sized_range@ R>
    using range_size_t = decltype(ranges::size(declval<R&>()));
  template<@range@ R>
    using range_value_t = iter_value_t<iterator_t<R>>;
  template<@range@ R>
    using range_reference_t = iter_reference_t<iterator_t<R>>;
  template<@range@ R>
    using range_rvalue_reference_t = iter_rvalue_reference_t<iterator_t<R>>;

  // range.sized, sized ranges
  template<class>
    inline constexpr bool disable_sized_range = false;

  template<class T>
    concept sized_range = @\seebelow@;

  // range.view, views
  template<class T>
    inline constexpr bool enable_view = @\seebelow@;

  struct view_base { };

  template<class T>
    concept view = @\seebelow@;

  // range.refinements, other range refinements
  template<class R, class T>
    concept output_range = @\seebelow@;

  template<class T>
    concept input_range = @\seebelow@;

  template<class T>
    concept forward_range = @\seebelow@;

  template<class T>
    concept bidirectional_range = @\seebelow@;

  template<class T>
    concept random_access_range = @\seebelow@;

  template<class T>
    concept contiguous_range = @\seebelow@;

  template<class T>
    concept common_range = @\seebelow@;

  template<class T>
    concept viewable_range = @\seebelow@;

  // view.interface, class template view_interface
  template<class D>
    requires is_class_v<D> && @same_as@<D, remove_cv_t<D>>
  class view_interface;

  // range.subrange, sub-ranges
  enum class subrange_kind : bool { unsized, sized };

  template<@input_or_output_iterator@ I, @sentinel_for@<I> S = I, subrange_kind K = @\seebelow@>
    requires (K == subrange_kind::sized || !@sized_sentinel_for@<S, I>)
  class subrange;

  template<input_or_output_iterator I, sentinel_for<I> S, subrange_kind K>
    inline constexpr bool enable_borrowed_range<subrange<I, S, K>> = true;

  // range.dangling, dangling iterator handling
  struct dangling;

  template<@range@ R>
    using borrowed_iterator_t = conditional_t<@borrowed_range@<R>, iterator_t<R>, dangling>;

  template<@range@ R>
    using borrowed_subrange_t =
      conditional_t<@borrowed_range@<R>, subrange<iterator_t<R>>, dangling>;

  // range.empty, empty view
  template<class T>
    requires is_object_v<T>
  class empty_view;

  template<class T>
    inline constexpr bool enable_borrowed_range<empty_view<T>> = true;

  namespace views {
    template<class T>
      inline constexpr empty_view<T> empty{};
  }

  // range.single, single view
  template<@copy_constructible@ T>
    requires is_object_v<T>
  class single_view;

  namespace views { inline constexpr @\unspec@ single = @\unspec@; }

  // range.iota, iota view
  template<@weakly_incrementable@ W, @semiregular@ Bound = unreachable_sentinel_t>
    requires @weakly-equality-comparable-with@<W, Bound>
  class iota_view;

  template<weakly_incrementable W, semiregular Bound>
    inline constexpr bool enable_borrowed_range<iota_view<W, Bound>> = true;

  namespace views { inline constexpr @\unspec@ iota = @\unspec@; }

  // range.istream, istream view
  template<movable Val, class CharT, class Traits = char_traits<CharT>>
    requires @\seebelow@
  class basic_istream_view;
  template<class Val, class CharT, class Traits>
    basic_istream_view<Val, CharT, Traits> istream_view(basic_istream<CharT, Traits>& s);

  // range.all, all view
  namespace views {
    inline constexpr @\unspec@ all = @\unspec@;

    template<@viewable_range@ R>
      using all_t = decltype(all(declval<R>()));
  }

  template<@range@ R>
    requires is_object_v<R>
  class ref_view;

  template<class T>
    inline constexpr bool enable_borrowed_range<ref_view<T>> = true;

  // range.filter, filter view
  template<@input_range@ V, @indirect_unary_predicate@<iterator_t<V>> Pred>
    requires view<V> && is_object_v<Pred>
  class filter_view;

  namespace views { inline constexpr @\unspec@ filter = @\unspec@; }

  // range.transform, transform view
  template<@input_range@ V, @copy_constructible@ F>
    requires view<V> && is_object_v<F> &&
             regular_invocable<F&, range_reference_t<V>>
  class transform_view;

  namespace views { inline constexpr @\unspec@ transform = @\unspec@; }

  // range.take, take view
  template<@view@> class take_view;

  namespace views { inline constexpr @\unspec@ take = @\unspec@; }

  // range.take.while, take while view
  template<@view@ V, class Pred>
    requires @input_range@<V> && is_object_v<Pred> &&
             @indirect_unary_predicate@<const Pred, iterator_t<V>>
    class take_while_view;

  namespace views { inline constexpr @\unspec@ take_while = @\unspec@; }

  // range.drop, drop view
  template<@view@ V>
    class drop_view;

  namespace views { inline constexpr @\unspec@ drop = @\unspec@; }

  // range.drop.while, drop while view
  template<@view@ V, class Pred>
    requires @input_range@<V> && is_object_v<Pred> &&
             @indirect_unary_predicate@<const Pred, iterator_t<V>>
    class drop_while_view;

  namespace views { inline constexpr @\unspec@ drop_while = @\unspec@; }

  // range.join, join view
  template<@input_range@ V>
    requires view<V> && @input_range@<range_reference_t<V>> &&
             (is_reference_v<range_reference_t<V>> ||
              view<range_value_t<V>>)
  class join_view;

  namespace views { inline constexpr @\unspec@ join = @\unspec@; }

  // range.split, split view
  template<class R>
    concept @tiny-range@ = @\seebelow@;   // \expos

  template<@input_range@ V, @forward_range@ Pattern>
    requires view<V> && view<Pattern> &&
             @indirectly_comparable@<iterator_t<V>, iterator_t<Pattern>, ranges::equal_to> &&
             (@forward_range@<V> || @tiny-range@<Pattern>)
  class split_view;

  namespace views { inline constexpr @\unspec@ split = @\unspec@; }

  // range.counted, counted view
  namespace views { inline constexpr @\unspec@ counted = @\unspec@; }

  // range.common, common view
  template<@view@ V>
    requires (!common_range<V> && copyable<iterator_t<V>>)
  class common_view;

  namespace views { inline constexpr @\unspec@ common = @\unspec@; }

  // range.reverse, reverse view
  template<@view@ V>
    requires @bidirectional_range@<V>
  class reverse_view;

  namespace views { inline constexpr @\unspec@ reverse = @\unspec@; }

  // range.elements, elements view
  template<@input_range@ V, size_t N>
    requires @\seebelow@;
  class elements_view;

  template<class R>
    using keys_view = elements_view<views::all_t<R>, 0>;
  template<class R>
    using values_view = elements_view<views::all_t<R>, 1>;

  namespace views {
    template<size_t N>
      inline constexpr @\unspec@ elements = @\unspec@ ;
    inline constexpr auto keys = elements<0>;
    inline constexpr auto values = elements<1>;
  }
}

namespace std {
  namespace views = ranges::views;

  template<class I, class S, ranges::subrange_kind K>
  struct tuple_size<ranges::subrange<I, S, K>>
    : integral_constant<size_t, 2> {};
  template<class I, class S, ranges::subrange_kind K>
  struct tuple_element<0, ranges::subrange<I, S, K>> {
    using type = I;
  };
  template<class I, class S, ranges::subrange_kind K>
  struct tuple_element<1, ranges::subrange<I, S, K>> {
    using type = S;
  };
  template<class I, class S, ranges::subrange_kind K>
  struct tuple_element<0, const ranges::subrange<I, S, K>> {
    using type = I;
  };
  template<class I, class S, ranges::subrange_kind K>
  struct tuple_element<1, const ranges::subrange<I, S, K>> {
    using type = S;
  };
}
