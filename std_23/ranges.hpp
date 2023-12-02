#include <compare>              // see compare.syn
#include <initializer_list>     // see initializer.list.syn
#include <iterator>             // see iterator.synopsis

namespace std::ranges {
  inline namespace @\unspec@ {
    // range.access, range access
    inline constexpr @\unspec@ begin = @\unspec@;                               // freestanding
    inline constexpr @\unspec@ end = @\unspec@;                                 // freestanding
    inline constexpr @\unspec@ cbegin = @\unspec@;                              // freestanding
    inline constexpr @\unspec@ cend = @\unspec@;                                // freestanding
    inline constexpr @\unspec@ rbegin = @\unspec@;                              // freestanding
    inline constexpr @\unspec@ rend = @\unspec@;                                // freestanding
    inline constexpr @\unspec@ crbegin = @\unspec@;                             // freestanding
    inline constexpr @\unspec@ crend = @\unspec@;                               // freestanding

    inline constexpr @\unspec@ size = @\unspec@;                                // freestanding
    inline constexpr @\unspec@ ssize = @\unspec@;                               // freestanding
    inline constexpr @\unspec@ empty = @\unspec@;                               // freestanding
    inline constexpr @\unspec@ data = @\unspec@;                                // freestanding
    inline constexpr @\unspec@ cdata = @\unspec@;                               // freestanding
  }

  // range.range, ranges
  template<class T>
    concept range = @\seebelow@;                                                      // freestanding

  template<class T>
    constexpr bool enable_borrowed_range = false;                                   // freestanding

  template<class T>
    concept borrowed_range = @\seebelow@;                                             // freestanding

  template<class T>
    using iterator_t = decltype(ranges::begin(declval<T&>()));                      // freestanding
  template<@range@ R>
    using sentinel_t = decltype(ranges::end(declval<R&>()));                        // freestanding
  template<@range@ R>
    using const_iterator_t = const_iterator<iterator_t<R>>;                         // freestanding
  template<@range@ R>
    using const_sentinel_t = const_sentinel<sentinel_t<R>>;                         // freestanding
  template<@range@ R>
    using range_difference_t = iter_difference_t<iterator_t<R>>;                    // freestanding
  template<@sized_range@ R>
    using range_size_t = decltype(ranges::size(declval<R&>()));                     // freestanding
  template<@range@ R>
    using range_value_t = iter_value_t<iterator_t<R>>;                              // freestanding
  template<@range@ R>
    using range_reference_t = iter_reference_t<iterator_t<R>>;                      // freestanding
  template<@range@ R>
    using range_const_reference_t = iter_const_reference_t<iterator_t<R>>;          // freestanding
  template<@range@ R>
    using range_rvalue_reference_t = iter_rvalue_reference_t<iterator_t<R>>;        // freestanding
  template<@range@ R>
    using range_common_reference_t = iter_common_reference_t<iterator_t<R>>;        // freestanding

  // range.sized, sized ranges
  template<class>
    constexpr bool disable_sized_range = false;                                     // freestanding

  template<class T>
    concept sized_range = @\seebelow@;                                                // freestanding

  // range.view, views
  template<class T>
    constexpr bool enable_view = @\seebelow@;                                         // freestanding

  struct view_base {};                                                              // freestanding

  template<class T>
    concept view = @\seebelow@;                                                       // freestanding

  // range.refinements, other range refinements
  template<class R, class T>
    concept output_range = @\seebelow@;                                               // freestanding

  template<class T>
    concept input_range = @\seebelow@;                                                // freestanding

  template<class T>
    concept forward_range = @\seebelow@;                                              // freestanding

  template<class T>
    concept bidirectional_range = @\seebelow@;                                        // freestanding

  template<class T>
    concept random_access_range = @\seebelow@;                                        // freestanding

  template<class T>
    concept contiguous_range = @\seebelow@;                                           // freestanding

  template<class T>
    concept common_range = @\seebelow@;                                               // freestanding

  template<class T>
    concept viewable_range = @\seebelow@;                                             // freestanding

  template<class T>
    concept constant_range = @\seebelow@;                                             // freestanding

  // view.interface, class template view_interface
  template<class D>
    requires is_class_v<D> && @same_as@<D, remove_cv_t<D>>
  class view_interface;                                                             // freestanding

  // range.subrange, sub-ranges
  enum class @subrange_kind@ : bool { @unsized}{subrange_kind@, @sized}{subrange_kind@ };                               // freestanding

  template<@input_or_output_iterator@ I, @sentinel_for@<I> S = I, subrange_kind K = @\seebelow@>
    requires (K == subrange_kind::sized || !@sized_sentinel_for@<S, I>)
  class subrange;                                                                   // freestanding

  template<class I, class S, subrange_kind K>
    constexpr bool enable_borrowed_range<subrange<I, S, K>> = true;                 // freestanding

  template<size_t N, class I, class S, subrange_kind K>
    requires ((N == 0 && @copyable@<I>) || N == 1)
    constexpr auto get(const subrange<I, S, K>& r);                                 // freestanding

  template<size_t N, class I, class S, subrange_kind K>
    requires (N < 2)
    constexpr auto get(subrange<I, S, K>&& r);                                      // freestanding
}

namespace std {
  using ranges::get;                                                                // freestanding
}

namespace std::ranges {
  // range.dangling, dangling iterator handling
  struct dangling;                                                                  // freestanding

  // range.elementsof, class template elements_of
  template<@range@ R, class Allocator = allocator<byte>>
    struct elements_of;

  template<@range@ R>
    using borrowed_iterator_t = @\seebelow@;                                          // freestanding

  template<@range@ R>
    using borrowed_subrange_t = @\seebelow@;                                          // freestanding

  // range.utility.conv, range conversions
  template<class C, @input_range@ R, class... Args> requires (!@view@<C>)
    constexpr C to(R&& r, Args&&... args);                                          // freestanding
  template<template<class...> class C, @input_range@ R, class... Args>
    constexpr auto to(R&& r, Args&&... args);                                       // freestanding
  template<class C, class... Args> requires (!@view@<C>)
    constexpr auto to(Args&&... args);                                              // freestanding
  template<template<class...> class C, class... Args>
    constexpr auto to(Args&&... args);                                              // freestanding

  // range.empty, empty view
  template<class T>
    requires is_object_v<T>
  class empty_view;                                                                 // freestanding

  template<class T>
    constexpr bool enable_borrowed_range<empty_view<T>> = true;                     // freestanding

  namespace views {
    template<class T>
      constexpr empty_view<T> @empty}{views}@{;                                              // freestanding
  }

  // range.single, single view
  template<@move_constructible@ T>
    requires is_object_v<T>
  class single_view;                                                                // freestanding

  namespace views { inline constexpr @\unspecnc@ single = @\unspecnc@; }            // freestanding

  template<bool Const, class T>
    using @maybe-const@ = conditional_t<Const, const T, T>;   // \expos

  // range.iota, iota view
  template<@weakly_incrementable@ W, @semiregular@ Bound = unreachable_sentinel_t>
    requires @weakly-equality-comparable-with@<W, Bound> && @copyable@<W>
  class iota_view;                                                                  // freestanding

  template<class W, class Bound>
    constexpr bool enable_borrowed_range<iota_view<W, Bound>> = true;               // freestanding

  namespace views { inline constexpr @\unspecnc@ iota = @\unspecnc@; }              // freestanding

  // range.repeat, repeat view
  template<@move_constructible@ T, @semiregular@ Bound = unreachable_sentinel_t>
    requires @\seebelow@
  class repeat_view;                                                                // freestanding

  namespace views { inline constexpr @\unspecnc@ repeat = @\unspecnc@; }            // freestanding

  // range.istream, istream view
  template<@movable@ Val, class CharT, class Traits = char_traits<CharT>>
    requires @\seebelow@
  class basic_istream_view;
  template<class Val>
    using istream_view = basic_istream_view<Val, char>;
  template<class Val>
    using wistream_view = basic_istream_view<Val, wchar_t>;

  namespace views { template<class T> constexpr @\unspecnc@ istream = @\unspecnc@; }

  // range.adaptor.object, range adaptor objects
  template<class D>
    requires is_class_v<D> && @same_as@<D, remove_cv_t<D>>
  class range_adaptor_closure { };                                                  // freestanding

  // range.all, all view
  namespace views {
    inline constexpr @\unspecnc@ all = @\unspecnc@;                                 // freestanding

    template<@viewable_range@ R>
      using all_t = decltype(all(declval<R>()));                                    // freestanding
  }

  // range.ref.view, ref view
  template<@range@ R>
    requires is_object_v<R>
  class ref_view;                                                                   // freestanding

  template<class T>
    constexpr bool enable_borrowed_range<ref_view<T>> = true;                       // freestanding

  // range.owning.view, owning view
  template<@range@ R>
    requires @\seebelow@
  class owning_view;                                                                // freestanding

  template<class T>
    constexpr bool enable_borrowed_range<owning_view<T>> =                          // freestanding
      enable_borrowed_range<T>;

  // range.as.rvalue, as rvalue view
  template<@view@ V>
    requires @input_range@<V>
  class as_rvalue_view;                                                             // freestanding

  template<class T>
    constexpr bool enable_borrowed_range<as_rvalue_view<T>> =                       // freestanding
      enable_borrowed_range<T>;

  namespace views { inline constexpr @\unspecnc@ as_rvalue = @\unspecnc@; }         // freestanding

  // range.filter, filter view
  template<@input_range@ V, @indirect_unary_predicate@<iterator_t<V>> Pred>
    requires @view@<V> && is_object_v<Pred>
  class filter_view;                                                                // freestanding

  namespace views { inline constexpr @\unspecnc@ filter = @\unspecnc@; }            // freestanding

  // range.transform, transform view
  template<@input_range@ V, @move_constructible@ F>
    requires @view@<V> && is_object_v<F> &&
             @regular_invocable@<F&, range_reference_t<V>> &&
             @can-reference@<invoke_result_t<F&, range_reference_t<V>>>
  class transform_view;                                                             // freestanding

  namespace views { inline constexpr @\unspecnc@ transform = @\unspecnc@; }         // freestanding

  // range.take, take view
  template<@view@> class take_view;                                                   // freestanding

  template<class T>
    constexpr bool enable_borrowed_range<take_view<T>> =                            // freestanding
      enable_borrowed_range<T>;

  namespace views { inline constexpr @\unspecnc@ take = @\unspecnc@; }              // freestanding

  // range.take.while, take while view
  template<@view@ V, class Pred>
    requires @input_range@<V> && is_object_v<Pred> &&
             @indirect_unary_predicate@<const Pred, iterator_t<V>>
    class take_while_view;                                                          // freestanding

  namespace views { inline constexpr @\unspecnc@ take_while = @\unspecnc@; }        // freestanding

  // range.drop, drop view
  template<@view@ V>
    class drop_view;                                                                // freestanding

  template<class T>
    constexpr bool enable_borrowed_range<drop_view<T>> =                            // freestanding
      enable_borrowed_range<T>;

  namespace views { inline constexpr @\unspecnc@ drop = @\unspecnc@; }              // freestanding

  // range.drop.while, drop while view
  template<@view@ V, class Pred>
    requires @input_range@<V> && is_object_v<Pred> &&
             @indirect_unary_predicate@<const Pred, iterator_t<V>>
    class drop_while_view;                                                          // freestanding

  template<class T, class Pred>
    constexpr bool enable_borrowed_range<drop_while_view<T, Pred>> =                // freestanding
      enable_borrowed_range<T>;

  namespace views { inline constexpr @\unspecnc@ drop_while = @\unspecnc@; }        // freestanding

  // range.join, join view
  template<@input_range@ V>
    requires @view@<V> && @input_range@<range_reference_t<V>>
  class join_view;                                                                  // freestanding

  namespace views { inline constexpr @\unspecnc@ join = @\unspecnc@; }              // freestanding

  // range.join.with, join with view
  template<class R, class P>
    concept @compatible-joinable-ranges@ = @\seebelow@; // \expos

  template<@input_range@ V, @forward_range@ Pattern>
    requires @view@<V> && @input_range@<range_reference_t<V>>
          && @view@<Pattern>
          && @compatible-joinable-ranges@<range_reference_t<V>, Pattern>
  class join_with_view;                                                             // freestanding

  namespace views { inline constexpr @\unspecnc@ join_with = @\unspecnc@; }         // freestanding

  // range.lazy.split, lazy split view
  template<class R>
    concept @tiny-range@ = @\seebelow@;   // \expos

  template<@input_range@ V, @forward_range@ Pattern>
    requires @view@<V> && @view@<Pattern> &&
             @indirectly_comparable@<iterator_t<V>, iterator_t<Pattern>, ranges::equal_to> &&
             (@forward_range@<V> || @tiny-range@<Pattern>)
  class lazy_split_view;                                                            // freestanding

  // range.split, split view
 template<@forward_range@ V, @forward_range@ Pattern>
   requires @view@<V> && @view@<Pattern> &&
            @indirectly_comparable@<iterator_t<V>, iterator_t<Pattern>, ranges::equal_to>
  class split_view;                                                                 // freestanding

  namespace views {
    inline constexpr @\unspecnc@ lazy_split = @\unspecnc@;                          // freestanding
    inline constexpr @\unspecnc@ split = @\unspecnc@;                               // freestanding
  }

  // range.counted, counted view
  namespace views { inline constexpr @\unspecnc@ counted = @\unspecnc@; }           // freestanding

  // range.common, common view
  template<@view@ V>
    requires (!@common_range@<V> && @copyable@<iterator_t<V>>)
  class common_view;                                                                // freestanding

  template<class T>
    constexpr bool enable_borrowed_range<common_view<T>> =                          // freestanding
      enable_borrowed_range<T>;

  namespace views { inline constexpr @\unspecnc@ common = @\unspecnc@; }            // freestanding

  // range.reverse, reverse view
  template<@view@ V>
    requires @bidirectional_range@<V>
  class reverse_view;                                                               // freestanding

  template<class T>
    constexpr bool enable_borrowed_range<reverse_view<T>> =                         // freestanding
      enable_borrowed_range<T>;

  namespace views { inline constexpr @\unspecnc@ reverse = @\unspecnc@; }           // freestanding

  // range.as.const, as const view
  template<@input_range@ R>
    constexpr auto& @possibly-const-range@(R& r) {          // \expos
      if constexpr (@constant_range@<const R> && !@constant_range@<R>) {
        return const_cast<const R&>(r);
      } else {
        return r;
      }
    }

  template<@view@ V>
    requires @input_range@<V>
  class as_const_view;                                                              // freestanding

  template<class T>
    constexpr bool enable_borrowed_range<as_const_view<T>> =                        // freestanding
      enable_borrowed_range<T>;

  namespace views { inline constexpr @\unspecnc@ as_const = @\unspecnc@; }          // freestanding

  // range.elements, elements view
  template<@input_range@ V, size_t N>
    requires @\seebelow@
  class elements_view;                                                              // freestanding

  template<class T, size_t N>
    constexpr bool enable_borrowed_range<elements_view<T, N>> =                     // freestanding
      enable_borrowed_range<T>;

  template<class R>
    using @keys_view@ = elements_view<R, 0>;                                          // freestanding
  template<class R>
    using @values_view@ = elements_view<R, 1>;                                        // freestanding

  namespace views {
    template<size_t N>
      constexpr @\unspecnc@ elements = @\unspecnc@;                                 // freestanding
    inline constexpr auto @keys}{views@ = elements<0>;                                       // freestanding
    inline constexpr auto @values}{views@ = elements<1>;                                     // freestanding
  }

  // range.enumerate, enumerate view
  template<@input_range@ View>
    requires @view@<View>
  class enumerate_view;                                                             // freestanding

  template<class View>
    constexpr bool enable_borrowed_range<enumerate_view<View>> =                    // freestanding
      enable_borrowed_range<View>;

  namespace views { inline constexpr @\unspecnc@ enumerate = @\unspecnc@; }         // freestanding

  // range.zip, zip view
  template<@input_range@... Views>
    requires (@view@<Views> && ...) && (sizeof...(Views) > 0)
  class zip_view;                                                                   // freestanding

  template<class... Views>
    constexpr bool enable_borrowed_range<zip_view<Views...>> =                      // freestanding
      (enable_borrowed_range<Views> && ...);

  namespace views { inline constexpr @\unspecnc@ zip = @\unspecnc@; }               // freestanding

  // range.zip.transform, zip transform view
  template<@move_constructible@ F, @input_range@... Views>
    requires (@view@<Views> && ...) && (sizeof...(Views) > 0) && is_object_v<F> &&
             @regular_invocable@<F&, range_reference_t<Views>...> &&
             @can-reference@<invoke_result_t<F&, range_reference_t<Views>...>>
  class zip_transform_view;                                                         // freestanding

  namespace views { inline constexpr @\unspecnc@ zip_transform = @\unspecnc@; }     // freestanding

  // range.adjacent, adjacent view
  template<@forward_range@ V, size_t N>
    requires @view@<V> && (N > 0)
  class adjacent_view;                                                              // freestanding

  template<class V, size_t N>
    constexpr bool enable_borrowed_range<adjacent_view<V, N>> =                     // freestanding
      enable_borrowed_range<V>;

  namespace views {
    template<size_t N>
      constexpr @\unspecnc@ adjacent = @\unspecnc@;                                 // freestanding
    inline constexpr auto @pairwise}{views@ = adjacent<2>;                                   // freestanding
  }

  // range.adjacent.transform, adjacent transform view
  template<@forward_range@ V, @move_constructible@ F, size_t N>
    requires @\seebelow@
  class adjacent_transform_view;                                                    // freestanding

  namespace views {
    template<size_t N>
      constexpr @\unspecnc@ adjacent_transform = @\unspecnc@;                       // freestanding
    inline constexpr auto @pairwise_transform}{views@ = adjacent_transform<2>;               // freestanding
  }

  // range.chunk, chunk view
  template<@view@ V>
    requires @input_range@<V>
  class chunk_view;                                                                 // freestanding

  template<@view@ V>
    requires @forward_range@<V>
  class chunk_view<V>;                                                              // freestanding

  template<class V>
    constexpr bool enable_borrowed_range<chunk_view<V>> =                           // freestanding
      @forward_range@<V> && enable_borrowed_range<V>;

  namespace views { inline constexpr @\unspecnc@ chunk = @\unspecnc@; }             // freestanding

  // range.slide, slide view
  template<@forward_range@ V>
    requires @view@<V>
  class slide_view;                                                                 // freestanding

  template<class V>
    constexpr bool enable_borrowed_range<slide_view<V>> =
      enable_borrowed_range<V>;                                                     // freestanding

  namespace views { inline constexpr @\unspecnc@ slide = @\unspecnc@; }             // freestanding

  // range.chunk.by, chunk by view
  template<@forward_range@ V, @indirect_binary_predicate@<iterator_t<V>, iterator_t<V>> Pred>
    requires @view@<V> && is_object_v<Pred>
  class chunk_by_view;                                                              // freestanding

  namespace views { inline constexpr @\unspecnc@ chunk_by = @\unspecnc@; }          // freestanding

  // range.stride, stride view
  template<@input_range@ V>
    requires @view@<V>
  class stride_view;                                                                // freestanding

  template<class V>
    constexpr bool enable_borrowed_range<stride_view<V>> =                          // freestanding
      enable_borrowed_range<V>;

  namespace views { inline constexpr @\unspecnc@ stride = @\unspecnc@; }            // freestanding

  // range.cartesian, cartesian product view
  template<@input_range@ First, @forward_range@... Vs>
    requires (@view@<First> && ... && @view@<Vs>)
  class cartesian_product_view;                                                     // freestanding

  namespace views { inline constexpr @\unspecnc@ cartesian_product = @\unspecnc@; } // freestanding
}

namespace std {
  namespace views = ranges::views;                                                  // freestanding

  template<class T> struct tuple_size;                                              // freestanding
  template<size_t I, class T> struct tuple_element;                                 // freestanding

  template<class I, class S, ranges::subrange_kind K>
  struct tuple_size<ranges::subrange<I, S, K>>                                      // freestanding
    : integral_constant<size_t, 2> {};
  template<class I, class S, ranges::subrange_kind K>
  struct tuple_element<0, ranges::subrange<I, S, K>> {                              // freestanding
    using type = I;                                                                 // freestanding
  };
  template<class I, class S, ranges::subrange_kind K>
  struct tuple_element<1, ranges::subrange<I, S, K>> {                              // freestanding
    using type = S;                                                                 // freestanding
  };
  template<class I, class S, ranges::subrange_kind K>
  struct tuple_element<0, const ranges::subrange<I, S, K>> {                        // freestanding
    using type = I;                                                                 // freestanding
  };
  template<class I, class S, ranges::subrange_kind K>
  struct tuple_element<1, const ranges::subrange<I, S, K>> {                        // freestanding
    using type = S;                                                                 // freestanding
  };

  struct from_range_t { explicit from_range_t() = default; };                       // freestanding
  inline constexpr from_range_t from_range{};                                       // freestanding
}
