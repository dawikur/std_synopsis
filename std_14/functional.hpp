namespace std {
  // depr.base, base (deprecated):
  template <class Arg, class Result> struct unary_function;
  template <class Arg1, class Arg2, class Result> struct binary_function;

  // refwrap, reference_wrapper:
  template <class T> class reference_wrapper;

  template <class T> reference_wrapper<T> ref(T&) noexcept;
  template <class T> reference_wrapper<const T> cref(const T&) noexcept;
  template <class T> void ref(const T&&) = delete;
  template <class T> void cref(const T&&) = delete;

  template <class T> reference_wrapper<T> ref(reference_wrapper<T>) noexcept;
  template <class T> reference_wrapper<const T> cref(reference_wrapper<T>) noexcept;

  // arithmetic.operations, arithmetic operations:
  template <class T = void> struct plus;
  template <class T = void> struct minus;
  template <class T = void> struct multiplies;
  template <class T = void> struct divides;
  template <class T = void> struct modulus;
  template <class T = void> struct negate;
  template <> struct plus<void>;
  template <> struct minus<void>;
  template <> struct multiplies<void>;
  template <> struct divides<void>;
  template <> struct modulus<void>;
  template <> struct negate<void>;

  // comparisons, comparisons:
  template <class T = void> struct equal_to;
  template <class T = void> struct not_equal_to;
  template <class T = void> struct greater;
  template <class T = void> struct less;
  template <class T = void> struct greater_equal;
  template <class T = void> struct less_equal;
  template <> struct equal_to<void>;
  template <> struct not_equal_to<void>;
  template <> struct greater<void>;
  template <> struct less<void>;
  template <> struct greater_equal<void>;
  template <> struct less_equal<void>;

  // logical.operations, logical operations:
  template <class T = void> struct logical_and;
  template <class T = void> struct logical_or;
  template <class T = void> struct logical_not;
  template <> struct logical_and<void>;
  template <> struct logical_or<void>;
  template <> struct logical_not<void>;

  // bitwise.operations, bitwise operations:
  template <class T = void> struct bit_and;
  template <class T = void> struct bit_or;
  template <class T = void> struct bit_xor;
  template <class T = void> struct bit_not;
  template <> struct bit_and<void>;
  template <> struct bit_or<void>;
  template <> struct bit_xor<void>;
  template <> struct bit_not<void>;

  // negators, negators:
  template <class Predicate> class unary_negate;
  template <class Predicate>
    constexpr unary_negate<Predicate> not1(const Predicate&);
  template <class Predicate> class binary_negate;
  template <class Predicate>
    constexpr binary_negate<Predicate> not2(const Predicate&);

  // func.bind, bind:
  template<class T> struct is_bind_expression;
  template<class T> struct is_placeholder;

  template<class F, class... BoundArgs>
    @\unspec@ bind(F&&, BoundArgs&&...);
  template<class R, class F, class... BoundArgs>
    @\unspec@ bind(F&&, BoundArgs&&...);

  namespace placeholders {
    // M is the implementation-defined number of placeholders
    extern @\unspec@ _1;
    extern @\unspec@ _2;
                .
                .
                .
    extern @\unspec@ _M;
  }

  // depr.lib.binders, binders (deprecated):
  template <class Fn> class binder1st;
  template <class Fn, class T>
    binder1st<Fn> bind1st(const Fn&, const T&);
  template <class Fn> class binder2nd;
  template <class Fn, class T>
    binder2nd<Fn> bind2nd(const Fn&, const T&);

  // depr.function.pointer.adaptors, adaptors (deprecated):
  template <class Arg, class Result> class pointer_to_unary_function;
  template <class Arg, class Result>
    pointer_to_unary_function<Arg,Result> ptr_fun(Result (*)(Arg));
  template <class Arg1, class Arg2, class Result>
    class pointer_to_binary_function;
  template <class Arg1, class Arg2, class Result>
    pointer_to_binary_function<Arg1,Arg2,Result>
      ptr_fun(Result (*)(Arg1,Arg2));

  // depr.member.pointer.adaptors, adaptors (deprecated):
  template<class S, class T> class mem_fun_t;
  template<class S, class T, class A> class mem_fun1_t;
  template<class S, class T>
      mem_fun_t<S,T> mem_fun(S (T::*f)());
  template<class S, class T, class A>
      mem_fun1_t<S,T,A> mem_fun(S (T::*f)(A));
  template<class S, class T> class mem_fun_ref_t;
  template<class S, class T, class A> class mem_fun1_ref_t;
  template<class S, class T>
      mem_fun_ref_t<S,T> mem_fun_ref(S (T::*f)());
  template<class S, class T, class A>
      mem_fun1_ref_t<S,T,A> mem_fun_ref(S (T::*f)(A));

  template <class S, class T> class const_mem_fun_t;
  template <class S, class T, class A> class const_mem_fun1_t;
  template <class S, class T>
    const_mem_fun_t<S,T> mem_fun(S (T::*f)() const);
  template <class S, class T, class A>
    const_mem_fun1_t<S,T,A> mem_fun(S (T::*f)(A) const);
  template <class S, class T> class const_mem_fun_ref_t;
  template <class S, class T, class A> class const_mem_fun1_ref_t;
  template <class S, class T>
    const_mem_fun_ref_t<S,T> mem_fun_ref(S (T::*f)() const);
  template <class S, class T, class A>
    const_mem_fun1_ref_t<S,T,A> mem_fun_ref(S (T::*f)(A) const);

  // func.memfn, member function adaptors:
  template<class R, class T> @\unspec@ mem_fn(R T::*);

  // func.wrap polymorphic function wrappers:
  class bad_function_call;

  template<class> class function; // undefined
  template<class R, class... ArgTypes> class function<R(ArgTypes...)>;

  template<class R, class... ArgTypes>
    void swap(function<R(ArgTypes...)>&, function<R(ArgTypes...)>&);

  template<class R, class... ArgTypes>
    bool operator==(const function<R(ArgTypes...)>&, nullptr_t);
  template<class R, class... ArgTypes>
    bool operator==(nullptr_t, const function<R(ArgTypes...)>&);
  template<class R, class... ArgTypes>
    bool operator!=(const function<R(ArgTypes...)>&, nullptr_t);
  template<class R, class... ArgTypes>
    bool operator!=(nullptr_t, const function<R(ArgTypes...)>&);

  // unord.hash, hash function primary template:
  template <class T> struct hash;

  // Hash function specializations
  template <> struct hash<bool>;
  template <> struct hash<char>;
  template <> struct hash<signed char>;
  template <> struct hash<unsigned char>;
  template <> struct hash<char16_t>;
  template <> struct hash<char32_t>;
  template <> struct hash<wchar_t>;
  template <> struct hash<short>;
  template <> struct hash<unsigned short>;
  template <> struct hash<int>;
  template <> struct hash<unsigned int>;
  template <> struct hash<long>;
  template <> struct hash<long long>;
  template <> struct hash<unsigned long>;
  template <> struct hash<unsigned long long>;

  template <> struct hash<float>;
  template <> struct hash<double>;
  template <> struct hash<long double>;

  template<class T> struct hash<T*>;
}
