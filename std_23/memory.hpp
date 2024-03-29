#include <compare>              // see compare.syn

namespace std {
  // pointer.traits, pointer traits
  template<class Ptr> struct pointer_traits;                                        // freestanding
  template<class T> struct pointer_traits<T*>;                                      // freestanding

  // pointer.conversion, pointer conversion
  template<class T>
    constexpr T* to_address(T* p) noexcept;                                         // freestanding
  template<class Ptr>
    constexpr auto to_address(const Ptr& p) noexcept;                               // freestanding

  // ptr.align, pointer alignment
  void* align(size_t alignment, size_t size, void*& ptr, size_t& space);            // freestanding
  template<size_t N, class T>
    [[nodiscard]] constexpr T* assume_aligned(T* ptr);                              // freestanding

  // obj.lifetime, explicit lifetime management
  template<class T>
    T* start_lifetime_as(void* p) noexcept;                                         // freestanding
  template<class T>
    const T* start_lifetime_as(const void* p) noexcept;                             // freestanding
  template<class T>
    volatile T* start_lifetime_as(volatile void* p) noexcept;                       // freestanding
  template<class T>
    const volatile T* start_lifetime_as(const volatile void* p) noexcept;           // freestanding
  template<class T>
    T* start_lifetime_as_array(void* p, size_t n) noexcept;                         // freestanding
  template<class T>
    const T* start_lifetime_as_array(const void* p, size_t n) noexcept;             // freestanding
  template<class T>
    volatile T* start_lifetime_as_array(volatile void* p, size_t n) noexcept;       // freestanding
  template<class T>
    const volatile T* start_lifetime_as_array(const volatile void* p,               // freestanding
	                                      size_t n) noexcept;

  // allocator.tag, allocator argument tag
  struct allocator_arg_t {                                                          // freestanding
      explicit allocator_arg_t() = default;                                         // freestanding
  };
  inline constexpr allocator_arg_t allocator_arg{};                                 // freestanding

  // allocator.uses, uses_allocator
  template<class T, class Alloc> struct uses_allocator;                             // freestanding

  // allocator.uses.trait, uses_allocator
  template<class T, class Alloc>
    constexpr bool @uses_allocator_v@ = uses_allocator<T, Alloc>::value;              // freestanding

  // allocator.uses.construction, uses-allocator construction
  template<class T, class Alloc, class... Args>
    constexpr auto uses_allocator_construction_args(const Alloc& alloc,             // freestanding
                                                    Args&&... args) noexcept;
  template<class T, class Alloc, class Tuple1, class Tuple2>
    constexpr auto uses_allocator_construction_args(const Alloc& alloc,             // freestanding
                                                    piecewise_construct_t,
                                                    Tuple1&& x, Tuple2&& y) noexcept;
  template<class T, class Alloc>
    constexpr auto uses_allocator_construction_args(const Alloc& alloc) noexcept;   // freestanding
  template<class T, class Alloc, class U, class V>
    constexpr auto uses_allocator_construction_args(const Alloc& alloc,             // freestanding
                                                    U&& u, V&& v) noexcept;
  template<class T, class Alloc, class U, class V>
    constexpr auto uses_allocator_construction_args(const Alloc& alloc,             // freestanding
                                                    pair<U, V>& pr) noexcept;
  template<class T, class Alloc, class U, class V>
    constexpr auto uses_allocator_construction_args(const Alloc& alloc,             // freestanding
                                                    const pair<U, V>& pr) noexcept;
  template<class T, class Alloc, class U, class V>
    constexpr auto uses_allocator_construction_args(const Alloc& alloc,             // freestanding
                                                    pair<U, V>&& pr) noexcept;
  template<class T, class Alloc, class U, class V>
    constexpr auto uses_allocator_construction_args(const Alloc& alloc,             // freestanding
                                                    const pair<U, V>&& pr) noexcept;
  template<class T, class Alloc, @pair-like@ P>
    constexpr auto uses_allocator_construction_args(const Alloc& alloc,             // freestanding
                                                    P&& p) noexcept;
  template<class T, class Alloc, class U>
    constexpr auto uses_allocator_construction_args(const Alloc& alloc,             // freestanding
                                                    U&& u) noexcept;
  template<class T, class Alloc, class... Args>
    constexpr T make_obj_using_allocator(const Alloc& alloc, Args&&... args);       // freestanding
  template<class T, class Alloc, class... Args>
    constexpr T* uninitialized_construct_using_allocator(T* p,                      // freestanding
                                                         const Alloc& alloc, Args&&... args);

  // allocator.traits, allocator traits
  template<class Alloc> struct allocator_traits;                                    // freestanding

  template<class Pointer, class SizeType = size_t>
  struct allocation_result {                                                        // freestanding
    Pointer ptr;
    SizeType count;
  };

  // default.allocator, the default allocator
  template<class T> class allocator;
  template<class T, class U>
    constexpr bool operator==(const allocator<T>&, const allocator<U>&) noexcept;

  // specialized.addressof, addressof
  template<class T>
    constexpr T* addressof(T& r) noexcept;                                          // freestanding
  template<class T>
    const T* addressof(const T&&) = delete;                                         // freestanding

  // specialized.algorithms, specialized algorithms
  // special.mem.concepts, special memory concepts
  template<class I>
    concept @nothrow-input-iterator@ = @\seebelow@;    // \expos
  template<class I>
    concept @nothrow-forward-iterator@ = @\seebelow@;  // \expos
  template<class S, class I>
    concept @nothrow-sentinel-for@ = @\seebelow@;      // \expos
  template<class R>
    concept @nothrow-input-range@ = @\seebelow@;       // \expos
  template<class R>
    concept @nothrow-forward-range@ = @\seebelow@;     // \expos

  template<class NoThrowForwardIterator>
    void uninitialized_default_construct(NoThrowForwardIterator first,              // freestanding
                                         NoThrowForwardIterator last);
  template<class ExecutionPolicy, class NoThrowForwardIterator>
    void uninitialized_default_construct(ExecutionPolicy&& exec,                    // see algorithms.parallel.overloads
                                         NoThrowForwardIterator first,
                                         NoThrowForwardIterator last);
  template<class NoThrowForwardIterator, class Size>
    NoThrowForwardIterator
      uninitialized_default_construct_n(NoThrowForwardIterator first, Size n);      // freestanding
  template<class ExecutionPolicy, class NoThrowForwardIterator, class Size>
    NoThrowForwardIterator
      uninitialized_default_construct_n(ExecutionPolicy&& exec,                     // see algorithms.parallel.overloads
                                        NoThrowForwardIterator first, Size n);

  namespace ranges {
    template<@nothrow-forward-iterator@ I, @nothrow-sentinel-for@<I> S>
      requires @default_initializable@<iter_value_t<I>>
        I uninitialized_default_construct(I first, S last);                         // freestanding
    template<@nothrow-forward-range@ R>
      requires @default_initializable@<range_value_t<R>>
        borrowed_iterator_t<R> uninitialized_default_construct(R&& r);              // freestanding

    template<@nothrow-forward-iterator@ I>
      requires @default_initializable@<iter_value_t<I>>
        I uninitialized_default_construct_n(I first, iter_difference_t<I> n);       // freestanding
  }

  template<class NoThrowForwardIterator>
    void uninitialized_value_construct(NoThrowForwardIterator first,                // freestanding
                                       NoThrowForwardIterator last);
  template<class ExecutionPolicy, class NoThrowForwardIterator>
    void uninitialized_value_construct(ExecutionPolicy&& exec,                      // see algorithms.parallel.overloads
                                       NoThrowForwardIterator first,
                                       NoThrowForwardIterator last);
  template<class NoThrowForwardIterator, class Size>
    NoThrowForwardIterator
      uninitialized_value_construct_n(NoThrowForwardIterator first, Size n);        // freestanding
  template<class ExecutionPolicy, class NoThrowForwardIterator, class Size>
    NoThrowForwardIterator
      uninitialized_value_construct_n(ExecutionPolicy&& exec,                       // see algorithms.parallel.overloads
                                      NoThrowForwardIterator first, Size n);

  namespace ranges {
    template<@nothrow-forward-iterator@ I, @nothrow-sentinel-for@<I> S>
      requires @default_initializable@<iter_value_t<I>>
        I uninitialized_value_construct(I first, S last);                           // freestanding
    template<@nothrow-forward-range@ R>
      requires @default_initializable@<range_value_t<R>>
        borrowed_iterator_t<R> uninitialized_value_construct(R&& r);                // freestanding

    template<@nothrow-forward-iterator@ I>
      requires @default_initializable@<iter_value_t<I>>
        I uninitialized_value_construct_n(I first, iter_difference_t<I> n);         // freestanding
  }

  template<class InputIterator, class NoThrowForwardIterator>
    NoThrowForwardIterator uninitialized_copy(InputIterator first,                  // freestanding
                                              InputIterator last,
                                              NoThrowForwardIterator result);
  template<class ExecutionPolicy, class ForwardIterator, class NoThrowForwardIterator>
    NoThrowForwardIterator uninitialized_copy(ExecutionPolicy&& exec,               // see algorithms.parallel.overloads
                                              ForwardIterator first, ForwardIterator last,
                                              NoThrowForwardIterator result);
  template<class InputIterator, class Size, class NoThrowForwardIterator>
    NoThrowForwardIterator uninitialized_copy_n(InputIterator first, Size n,        // freestanding
                                                NoThrowForwardIterator result);
  template<class ExecutionPolicy, class ForwardIterator, class Size,
           class NoThrowForwardIterator>
    NoThrowForwardIterator uninitialized_copy_n(ExecutionPolicy&& exec,             // see algorithms.parallel.overloads
                                                ForwardIterator first, Size n,
                                                NoThrowForwardIterator result);

  namespace ranges {
    template<class I, class O>
      using uninitialized_copy_result = in_out_result<I, O>;                        // freestanding
    template<@input_iterator@ I, @sentinel_for@<I> S1,
             @nothrow-forward-iterator@ O, @nothrow-sentinel-for@<O> S2>
      requires @constructible_from@<iter_value_t<O>, iter_reference_t<I>>
        uninitialized_copy_result<I, O>
          uninitialized_copy(I ifirst, S1 ilast, O ofirst, S2 olast);               // freestanding
    template<@input_range@ IR, @nothrow-forward-range@ OR>
      requires @constructible_from@<range_value_t<OR>, range_reference_t<IR>>
        uninitialized_copy_result<borrowed_iterator_t<IR>, borrowed_iterator_t<OR>>
          uninitialized_copy(IR&& in_range, OR&& out_range);                        // freestanding

    template<class I, class O>
      using uninitialized_copy_n_result = in_out_result<I, O>;                      // freestanding
    template<@input_iterator@ I, @nothrow-forward-iterator@ O, @nothrow-sentinel-for@<O> S>
      requires @constructible_from@<iter_value_t<O>, iter_reference_t<I>>
        uninitialized_copy_n_result<I, O>
          uninitialized_copy_n(I ifirst, iter_difference_t<I> n,                    // freestanding
                               O ofirst, S olast);
  }

  template<class InputIterator, class NoThrowForwardIterator>
    NoThrowForwardIterator uninitialized_move(InputIterator first,                  // freestanding
                                              InputIterator last,
                                              NoThrowForwardIterator result);
  template<class ExecutionPolicy, class ForwardIterator, class NoThrowForwardIterator>
    NoThrowForwardIterator uninitialized_move(ExecutionPolicy&& exec,               // see algorithms.parallel.overloads
                                              ForwardIterator first, ForwardIterator last,
                                              NoThrowForwardIterator result);
  template<class InputIterator, class Size, class NoThrowForwardIterator>
    pair<InputIterator, NoThrowForwardIterator>
      uninitialized_move_n(InputIterator first, Size n,                             // freestanding
                           NoThrowForwardIterator result);
  template<class ExecutionPolicy, class ForwardIterator, class Size,
           class NoThrowForwardIterator>
    pair<ForwardIterator, NoThrowForwardIterator>
      uninitialized_move_n(ExecutionPolicy&& exec,                                  // see algorithms.parallel.overloads
                           ForwardIterator first, Size n, NoThrowForwardIterator result);

  namespace ranges {
    template<class I, class O>
      using uninitialized_move_result = in_out_result<I, O>;                        // freestanding
    template<@input_iterator@ I, @sentinel_for@<I> S1,
             @nothrow-forward-iterator@ O, @nothrow-sentinel-for@<O> S2>
      requires @constructible_from@<iter_value_t<O>, iter_rvalue_reference_t<I>>
        uninitialized_move_result<I, O>
          uninitialized_move(I ifirst, S1 ilast, O ofirst, S2 olast);               // freestanding
    template<@input_range@ IR, @nothrow-forward-range@ OR>
      requires @constructible_from@<range_value_t<OR>, range_rvalue_reference_t<IR>>
        uninitialized_move_result<borrowed_iterator_t<IR>, borrowed_iterator_t<OR>>
          uninitialized_move(IR&& in_range, OR&& out_range);                        // freestanding

    template<class I, class O>
      using uninitialized_move_n_result = in_out_result<I, O>;                      // freestanding
    template<@input_iterator@ I,
             @nothrow-forward-iterator@ O, @nothrow-sentinel-for@<O> S>
      requires @constructible_from@<iter_value_t<O>, iter_rvalue_reference_t<I>>
        uninitialized_move_n_result<I, O>
          uninitialized_move_n(I ifirst, iter_difference_t<I> n,                    // freestanding
                               O ofirst, S olast);
  }

  template<class NoThrowForwardIterator, class T>
    void uninitialized_fill(NoThrowForwardIterator first,                           // freestanding
                            NoThrowForwardIterator last, const T& x);
  template<class ExecutionPolicy, class NoThrowForwardIterator, class T>
    void uninitialized_fill(ExecutionPolicy&& exec,                                 // see algorithms.parallel.overloads
                            NoThrowForwardIterator first, NoThrowForwardIterator last,
                            const T& x);
  template<class NoThrowForwardIterator, class Size, class T>
    NoThrowForwardIterator
      uninitialized_fill_n(NoThrowForwardIterator first, Size n, const T& x);       // freestanding
  template<class ExecutionPolicy, class NoThrowForwardIterator, class Size, class T>
    NoThrowForwardIterator
      uninitialized_fill_n(ExecutionPolicy&& exec,                                  // see algorithms.parallel.overloads
                           NoThrowForwardIterator first, Size n, const T& x);

  namespace ranges {
    template<@nothrow-forward-iterator@ I, @nothrow-sentinel-for@<I> S, class T>
      requires @constructible_from@<iter_value_t<I>, const T&>
        I uninitialized_fill(I first, S last, const T& x);                          // freestanding
    template<@nothrow-forward-range@ R, class T>
      requires @constructible_from@<range_value_t<R>, const T&>
        borrowed_iterator_t<R> uninitialized_fill(R&& r, const T& x);               // freestanding

    template<@nothrow-forward-iterator@ I, class T>
      requires @constructible_from@<iter_value_t<I>, const T&>
        I uninitialized_fill_n(I first, iter_difference_t<I> n, const T& x);        // freestanding
  }

  // specialized.construct, construct_at
  template<class T, class... Args>
    constexpr T* construct_at(T* location, Args&&... args);                         // freestanding

  namespace ranges {
    template<class T, class... Args>
      constexpr T* construct_at(T* location, Args&&... args);                       // freestanding
  }

  // specialized.destroy, destroy
  template<class T>
    constexpr void destroy_at(T* location);                                         // freestanding
  template<class NoThrowForwardIterator>
    constexpr void destroy(NoThrowForwardIterator first,                            // freestanding
                           NoThrowForwardIterator last);
  template<class ExecutionPolicy, class NoThrowForwardIterator>
    void destroy(ExecutionPolicy&& exec,                                            // see algorithms.parallel.overloads
                 NoThrowForwardIterator first, NoThrowForwardIterator last);
  template<class NoThrowForwardIterator, class Size>
    constexpr NoThrowForwardIterator destroy_n(NoThrowForwardIterator first,        // freestanding
                                               Size n);
  template<class ExecutionPolicy, class NoThrowForwardIterator, class Size>
    NoThrowForwardIterator destroy_n(ExecutionPolicy&& exec,                        // see algorithms.parallel.overloads
                                     NoThrowForwardIterator first, Size n);

  namespace ranges {
    template<@destructible@ T>
      constexpr void destroy_at(T* location) noexcept;                              // freestanding

    template<@nothrow-input-iterator@ I, @nothrow-sentinel-for@<I> S>
      requires @destructible@<iter_value_t<I>>
        constexpr I destroy(I first, S last) noexcept;                              // freestanding
    template<@nothrow-input-range@ R>
      requires @destructible@<range_value_t<R>>
        constexpr borrowed_iterator_t<R> destroy(R&& r) noexcept;                   // freestanding

    template<@nothrow-input-iterator@ I>
      requires @destructible@<iter_value_t<I>>
        constexpr I destroy_n(I first, iter_difference_t<I> n) noexcept;            // freestanding
  }

  // unique.ptr, class template unique_ptr
  template<class T> struct default_delete;                                          // freestanding
  template<class T> struct default_delete<T[]>;                                     // freestanding
  template<class T, class D = default_delete<T>> class unique_ptr;                  // freestanding
  template<class T, class D> class unique_ptr<T[], D>;                              // freestanding

  template<class T, class... Args>
    constexpr unique_ptr<T> make_unique(Args&&... args);                        // T is not array
  template<class T>
    constexpr unique_ptr<T> make_unique(size_t n);                              // T is U[]
  template<class T, class... Args>
    @\unspecnc@ make_unique(Args&&...) = delete;                                // T is U[N]

  template<class T>
    constexpr unique_ptr<T> make_unique_for_overwrite();                        // T is not array
  template<class T>
    constexpr unique_ptr<T> make_unique_for_overwrite(size_t n);                // T is U[]
  template<class T, class... Args>
    @\unspecnc@ make_unique_for_overwrite(Args&&...) = delete;                  // T is U[N]

  template<class T, class D>
    constexpr void swap(unique_ptr<T, D>& x, unique_ptr<T, D>& y) noexcept;         // freestanding

  template<class T1, class D1, class T2, class D2>
    constexpr bool operator==(const unique_ptr<T1, D1>& x,                          // freestanding
                              const unique_ptr<T2, D2>& y);
  template<class T1, class D1, class T2, class D2>
    bool operator<(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);       // freestanding
  template<class T1, class D1, class T2, class D2>
    bool operator>(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);       // freestanding
  template<class T1, class D1, class T2, class D2>
    bool operator<=(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);      // freestanding
  template<class T1, class D1, class T2, class D2>
    bool operator>=(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);      // freestanding
  template<class T1, class D1, class T2, class D2>
    requires @three_way_comparable_with@<typename unique_ptr<T1, D1>::pointer,
                                       typename unique_ptr<T2, D2>::pointer>
    compare_three_way_result_t<typename unique_ptr<T1, D1>::pointer,
                               typename unique_ptr<T2, D2>::pointer>
      operator<=>(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);        // freestanding

  template<class T, class D>
    constexpr bool operator==(const unique_ptr<T, D>& x, nullptr_t) noexcept;       // freestanding
  template<class T, class D>
    constexpr bool operator<(const unique_ptr<T, D>& x, nullptr_t);                 // freestanding
  template<class T, class D>
    constexpr bool operator<(nullptr_t, const unique_ptr<T, D>& y);                 // freestanding
  template<class T, class D>
    constexpr bool operator>(const unique_ptr<T, D>& x, nullptr_t);                 // freestanding
  template<class T, class D>
    constexpr bool operator>(nullptr_t, const unique_ptr<T, D>& y);                 // freestanding
  template<class T, class D>
    constexpr bool operator<=(const unique_ptr<T, D>& x, nullptr_t);                // freestanding
  template<class T, class D>
    constexpr bool operator<=(nullptr_t, const unique_ptr<T, D>& y);                // freestanding
  template<class T, class D>
    constexpr bool operator>=(const unique_ptr<T, D>& x, nullptr_t);                // freestanding
  template<class T, class D>
    constexpr bool operator>=(nullptr_t, const unique_ptr<T, D>& y);                // freestanding
  template<class T, class D>
    requires @three_way_comparable@<typename unique_ptr<T, D>::pointer>
    constexpr compare_three_way_result_t<typename unique_ptr<T, D>::pointer>
      operator<=>(const unique_ptr<T, D>& x, nullptr_t);                            // freestanding

  template<class E, class T, class Y, class D>
    basic_ostream<E, T>& operator<<(basic_ostream<E, T>& os, const unique_ptr<Y, D>& p);

  // util.smartptr.weak.bad, class bad_weak_ptr
  class bad_weak_ptr;

  // util.smartptr.shared, class template shared_ptr
  template<class T> class shared_ptr;

  // util.smartptr.shared.create, shared_ptr creation
  template<class T, class... Args>
    shared_ptr<T> make_shared(Args&&... args);                                  // T is not array
  template<class T, class A, class... Args>
    shared_ptr<T> allocate_shared(const A& a, Args&&... args);                  // T is not array

  template<class T>
    shared_ptr<T> make_shared(size_t N);                                        // T is U[]
  template<class T, class A>
    shared_ptr<T> allocate_shared(const A& a, size_t N);                        // T is U[]

  template<class T>
    shared_ptr<T> make_shared();                                                // T is U[N]
  template<class T, class A>
    shared_ptr<T> allocate_shared(const A& a);                                  // T is U[N]

  template<class T>
    shared_ptr<T> make_shared(size_t N, const remove_extent_t<T>& u);           // T is U[]
  template<class T, class A>
    shared_ptr<T> allocate_shared(const A& a, size_t N,
                                  const remove_extent_t<T>& u);                 // T is U[]

  template<class T>
    shared_ptr<T> make_shared(const remove_extent_t<T>& u);                     // T is U[N]
  template<class T, class A>
    shared_ptr<T> allocate_shared(const A& a, const remove_extent_t<T>& u);     // T is U[N]

  template<class T>
    shared_ptr<T> make_shared_for_overwrite();                                  // T is not U[]
  template<class T, class A>
    shared_ptr<T> allocate_shared_for_overwrite(const A& a);                    // T is not U[]

  template<class T>
    shared_ptr<T> make_shared_for_overwrite(size_t N);                          // T is U[]
  template<class T, class A>
    shared_ptr<T> allocate_shared_for_overwrite(const A& a, size_t N);          // T is U[]

  // util.smartptr.shared.cmp, shared_ptr comparisons
  template<class T, class U>
    bool operator==(const shared_ptr<T>& a, const shared_ptr<U>& b) noexcept;
  template<class T, class U>
    strong_ordering operator<=>(const shared_ptr<T>& a, const shared_ptr<U>& b) noexcept;

  template<class T>
    bool operator==(const shared_ptr<T>& x, nullptr_t) noexcept;
  template<class T>
    strong_ordering operator<=>(const shared_ptr<T>& x, nullptr_t) noexcept;

  // util.smartptr.shared.spec, shared_ptr specialized algorithms
  template<class T>
    void swap(shared_ptr<T>& a, shared_ptr<T>& b) noexcept;

  // util.smartptr.shared.cast, shared_ptr casts
  template<class T, class U>
    shared_ptr<T> static_pointer_cast(const shared_ptr<U>& r) noexcept;
  template<class T, class U>
    shared_ptr<T> static_pointer_cast(shared_ptr<U>&& r) noexcept;
  template<class T, class U>
    shared_ptr<T> dynamic_pointer_cast(const shared_ptr<U>& r) noexcept;
  template<class T, class U>
    shared_ptr<T> dynamic_pointer_cast(shared_ptr<U>&& r) noexcept;
  template<class T, class U>
    shared_ptr<T> const_pointer_cast(const shared_ptr<U>& r) noexcept;
  template<class T, class U>
    shared_ptr<T> const_pointer_cast(shared_ptr<U>&& r) noexcept;
  template<class T, class U>
    shared_ptr<T> reinterpret_pointer_cast(const shared_ptr<U>& r) noexcept;
  template<class T, class U>
    shared_ptr<T> reinterpret_pointer_cast(shared_ptr<U>&& r) noexcept;

  // util.smartptr.getdeleter, shared_ptr get_deleter
  template<class D, class T>
    D* get_deleter(const shared_ptr<T>& p) noexcept;

  // util.smartptr.shared.io, shared_ptr I/O
  template<class E, class T, class Y>
    basic_ostream<E, T>& operator<<(basic_ostream<E, T>& os, const shared_ptr<Y>& p);

  // util.smartptr.weak, class template weak_ptr
  template<class T> class weak_ptr;

  // util.smartptr.weak.spec, weak_ptr specialized algorithms
  template<class T> void swap(weak_ptr<T>& a, weak_ptr<T>& b) noexcept;

  // util.smartptr.ownerless, class template owner_less
  template<class T = void> struct owner_less;

  // util.smartptr.enab, class template enable_shared_from_this
  template<class T> class enable_shared_from_this;

  // util.smartptr.hash, hash support
  template<class T> struct hash;                                                    // freestanding
  template<class T, class D> struct hash<unique_ptr<T, D>>;                         // freestanding
  template<class T> struct hash<shared_ptr<T>>;

  // util.smartptr.atomic, atomic smart pointers
  template<class T> struct atomic;                                                  // freestanding
  template<class T> struct atomic<shared_ptr<T>>;
  template<class T> struct atomic<weak_ptr<T>>;

  // out.ptr.t, class template out_ptr_t
  template<class Smart, class Pointer, class... Args>
    class out_ptr_t;

  // out.ptr, function template out_ptr
  template<class Pointer = void, class Smart, class... Args>
    auto out_ptr(Smart& s, Args&&... args);

  // inout.ptr.t, class template inout_ptr_t
  template<class Smart, class Pointer, class... Args>
    class inout_ptr_t;

  // inout.ptr, function template inout_ptr
  template<class Pointer = void, class Smart, class... Args>
    auto inout_ptr(Smart& s, Args&&... args);
}
