namespace std {
  // func.invoke, invoke
  template<class F, class... Args>
    constexpr invoke_result_t<F, Args...> invoke(F&& f, Args&&... args)             // freestanding
      noexcept(is_nothrow_invocable_v<F, Args...>);

  template<class R, class F, class... Args>
    constexpr R invoke_r(F&& f, Args&&... args)                                     // freestanding
      noexcept(is_nothrow_invocable_r_v<R, F, Args...>);

  // refwrap, reference_wrapper
  template<class T> class reference_wrapper;                                        // freestanding

  template<class T> constexpr reference_wrapper<T> ref(T&) noexcept;                // freestanding
  template<class T> constexpr reference_wrapper<const T> cref(const T&) noexcept;   // freestanding
  template<class T> void ref(const T&&) = delete;                                   // freestanding
  template<class T> void cref(const T&&) = delete;                                  // freestanding

  template<class T>
    constexpr reference_wrapper<T> ref(reference_wrapper<T>) noexcept;              // freestanding
  template<class T>
    constexpr reference_wrapper<const T> cref(reference_wrapper<T>) noexcept;       // freestanding

  // refwrap.common.ref, common_reference related specializations
  template<class R, class T, template<class> class RQual, template<class> class TQual>
    requires @\seebelow@
  struct basic_common_reference<R, T, RQual, TQual>;

  template<class T, class R, template<class> class TQual, template<class> class RQual>
    requires @\seebelow@
  struct basic_common_reference<T, R, TQual, RQual>;

  // arithmetic.operations, arithmetic operations
  template<class T = void> struct plus;                                             // freestanding
  template<class T = void> struct minus;                                            // freestanding
  template<class T = void> struct multiplies;                                       // freestanding
  template<class T = void> struct divides;                                          // freestanding
  template<class T = void> struct modulus;                                          // freestanding
  template<class T = void> struct negate;                                           // freestanding
  template<> struct plus<void>;                                                     // freestanding
  template<> struct minus<void>;                                                    // freestanding
  template<> struct multiplies<void>;                                               // freestanding
  template<> struct divides<void>;                                                  // freestanding
  template<> struct modulus<void>;                                                  // freestanding
  template<> struct negate<void>;                                                   // freestanding

  // comparisons, comparisons
  template<class T = void> struct equal_to;                                         // freestanding
  template<class T = void> struct not_equal_to;                                     // freestanding
  template<class T = void> struct greater;                                          // freestanding
  template<class T = void> struct less;                                             // freestanding
  template<class T = void> struct greater_equal;                                    // freestanding
  template<class T = void> struct less_equal;                                       // freestanding
  template<> struct equal_to<void>;                                                 // freestanding
  template<> struct not_equal_to<void>;                                             // freestanding
  template<> struct greater<void>;                                                  // freestanding
  template<> struct less<void>;                                                     // freestanding
  template<> struct greater_equal<void>;                                            // freestanding
  template<> struct less_equal<void>;                                               // freestanding

  // comparisons.three.way, class compare_three_way
  struct compare_three_way;                                                         // freestanding

  // logical.operations, logical operations
  template<class T = void> struct logical_and;                                      // freestanding
  template<class T = void> struct logical_or;                                       // freestanding
  template<class T = void> struct logical_not;                                      // freestanding
  template<> struct logical_and<void>;                                              // freestanding
  template<> struct logical_or<void>;                                               // freestanding
  template<> struct logical_not<void>;                                              // freestanding

  // bitwise.operations, bitwise operations
  template<class T = void> struct bit_and;                                          // freestanding
  template<class T = void> struct bit_or;                                           // freestanding
  template<class T = void> struct bit_xor;                                          // freestanding
  template<class T = void> struct bit_not;                                          // freestanding
  template<> struct bit_and<void>;                                                  // freestanding
  template<> struct bit_or<void>;                                                   // freestanding
  template<> struct bit_xor<void>;                                                  // freestanding
  template<> struct bit_not<void>;                                                  // freestanding

  // func.identity, identity
  struct identity;                                                                  // freestanding

  // func.not.fn, function template not_fn
  template<class F> constexpr @\unspec@ not_fn(F&& f);                            // freestanding

  // func.bind.partial, function templates bind_front and bind_back
  template<class F, class... Args>
    constexpr @\unspec@ bind_front(F&&, Args&&...);                               // freestanding
  template<class F, class... Args>
    constexpr @\unspec@ bind_back(F&&, Args&&...);                                // freestanding

  // func.bind, bind
  template<class T> struct is_bind_expression;                                      // freestanding
  template<class T>
    constexpr bool @is_bind_expression_v@ =                                           // freestanding
      is_bind_expression<T>::value;
  template<class T> struct is_placeholder;                                          // freestanding
  template<class T>
    constexpr int @is_placeholder_v@ =                                                // freestanding
      is_placeholder<T>::value;

  template<class F, class... BoundArgs>
    constexpr @\unspec@ bind(F&&, BoundArgs&&...);                                // freestanding
  template<class R, class F, class... BoundArgs>
    constexpr @\unspec@ bind(F&&, BoundArgs&&...);                                // freestanding

  namespace placeholders {
    // \placeholder{M} is the \impldef{number of placeholders for bind expressions} number of placeholders
    @\seebelownc@ _1;                                                                   // freestanding
    @\seebelownc@ _2;                                                                   // freestanding
               .
               .
               .
    @\seebelownc@ _@M@;                                                                   // freestanding
  }

  // func.memfn, member function adaptors
  template<class R, class T>
    constexpr @\unspec@ mem_fn(R T::*) noexcept;                                  // freestanding

  // func.wrap, polymorphic function wrappers
  class bad_function_call;

  template<class> class function;       // \notdef
  template<class R, class... ArgTypes> class function<R(ArgTypes...)>;

  // func.wrap.func.alg, specialized algorithms
  template<class R, class... ArgTypes>
    void swap(function<R(ArgTypes...)>&, function<R(ArgTypes...)>&) noexcept;

  // func.wrap.func.nullptr, null pointer comparison operator functions
  template<class R, class... ArgTypes>
    bool operator==(const function<R(ArgTypes...)>&, nullptr_t) noexcept;

  // func.wrap.move, move only wrapper
  template<class... S> class move_only_function;        // \notdef
  template<class R, class... ArgTypes>
    class move_only_function<R(ArgTypes...) @@ @ref@ noexcept(@noex@)>; // \seebelow

  // func.search, searchers
  template<class ForwardIterator1, class BinaryPredicate = equal_to<>>
    class default_searcher;                                                         // freestanding

  template<class RandomAccessIterator,
           class Hash = hash<typename iterator_traits<RandomAccessIterator>::value_type>,
           class BinaryPredicate = equal_to<>>
    class boyer_moore_searcher;

  template<class RandomAccessIterator,
           class Hash = hash<typename iterator_traits<RandomAccessIterator>::value_type>,
           class BinaryPredicate = equal_to<>>
    class boyer_moore_horspool_searcher;

  // unord.hash, class template hash
  template<class T>
    struct hash;                                                                    // freestanding

  namespace ranges {
    // range.cmp, concept-constrained comparisons
    struct equal_to;                                                                // freestanding
    struct not_equal_to;                                                            // freestanding
    struct greater;                                                                 // freestanding
    struct less;                                                                    // freestanding
    struct greater_equal;                                                           // freestanding
    struct less_equal;                                                              // freestanding
  }
}
