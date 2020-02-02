namespace std {
  // pointer.traits, pointer traits
  template <class Ptr> struct pointer_traits;
  template <class T> struct pointer_traits<T*>;

  // util.dynamic.safety, pointer safety
  enum class pointer_safety { relaxed, preferred, strict };
  void declare_reachable(void* p);
  template <class T> T* undeclare_reachable(T* p);
  void declare_no_pointers(char* p, size_t n);
  void undeclare_no_pointers(char* p, size_t n);
  pointer_safety get_pointer_safety() noexcept;

  // ptr.align, pointer alignment function
  void* align(size_t alignment, size_t size, void*& ptr, size_t& space);

  // allocator.tag, allocator argument tag
  struct allocator_arg_t { explicit allocator_arg_t() = default; };
  inline constexpr allocator_arg_t allocator_arg{};

  // allocator.uses, uses_allocator
  template <class T, class Alloc> struct uses_allocator;

  // allocator.traits, allocator traits
  template <class Alloc> struct allocator_traits;

  // default.allocator, the default allocator
  template <class T> class allocator;
  template <class T, class U>
    bool operator==(const allocator<T>&, const allocator<U>&) noexcept;
  template <class T, class U>
    bool operator!=(const allocator<T>&, const allocator<U>&) noexcept;

  // specialized.algorithms, specialized algorithms
  template <class T> constexpr T* addressof(T& r) noexcept;
  template <class T> const T* addressof(const T&&) = delete;
  template <class ForwardIterator>
    void uninitialized_default_construct(ForwardIterator first, ForwardIterator last);
  template <class ExecutionPolicy, class ForwardIterator>
    void uninitialized_default_construct(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                                         ForwardIterator first, ForwardIterator last);
  template <class ForwardIterator, class Size>
    ForwardIterator uninitialized_default_construct_n(ForwardIterator first, Size n);
  template <class ExecutionPolicy, class ForwardIterator, class Size>
    ForwardIterator uninitialized_default_construct_n(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                                                      ForwardIterator first, Size n);
  template <class ForwardIterator>
    void uninitialized_value_construct(ForwardIterator first, ForwardIterator last);
  template <class ExecutionPolicy, class ForwardIterator>
    void uninitialized_value_construct(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                                       ForwardIterator first, ForwardIterator last);
  template <class ForwardIterator, class Size>
    ForwardIterator uninitialized_value_construct_n(ForwardIterator first, Size n);
  template <class ExecutionPolicy, class ForwardIterator, class Size>
    ForwardIterator uninitialized_value_construct_n(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                                                    ForwardIterator first, Size n);
  template <class InputIterator, class ForwardIterator>
    ForwardIterator uninitialized_copy(InputIterator first, InputIterator last,
                                       ForwardIterator result);
  template <class ExecutionPolicy, class InputIterator, class ForwardIterator>
    ForwardIterator uninitialized_copy(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                                       InputIterator first, InputIterator last,
                                       ForwardIterator result);
  template <class InputIterator, class Size, class ForwardIterator>
    ForwardIterator uninitialized_copy_n(InputIterator first, Size n,
                                         ForwardIterator result);
  template <class ExecutionPolicy, class InputIterator, class Size, class ForwardIterator>
    ForwardIterator uninitialized_copy_n(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                                         InputIterator first, Size n,
                                         ForwardIterator result);
  template <class InputIterator, class ForwardIterator>
    ForwardIterator uninitialized_move(InputIterator first, InputIterator last,
                                       ForwardIterator result);
  template <class ExecutionPolicy, class InputIterator, class ForwardIterator>
    ForwardIterator uninitialized_move(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                                       InputIterator first, InputIterator last,
                                       ForwardIterator result);
  template <class InputIterator, class Size, class ForwardIterator>
    pair<InputIterator, ForwardIterator>
      uninitialized_move_n(InputIterator first, Size n, ForwardIterator result);
  template <class ExecutionPolicy, class InputIterator, class Size, class ForwardIterator>
    pair<InputIterator, ForwardIterator>
      uninitialized_move_n(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                           InputIterator first, Size n, ForwardIterator result);
  template <class ForwardIterator, class T>
    void uninitialized_fill(ForwardIterator first, ForwardIterator last,
                            const T& x);
  template <class ExecutionPolicy, class ForwardIterator, class T>
    void uninitialized_fill(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                            ForwardIterator first, ForwardIterator last,
                            const T& x);
  template <class ForwardIterator, class Size, class T>
    ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n, const T& x);
  template <class ExecutionPolicy, class ForwardIterator, class Size, class T>
    ForwardIterator uninitialized_fill_n(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                                         ForwardIterator first, Size n, const T& x);
  template <class T>
    void destroy_at(T* location);
  template <class ForwardIterator>
    void destroy(ForwardIterator first, ForwardIterator last);
  template <class ExecutionPolicy, class ForwardIterator>
    void destroy(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                 ForwardIterator first, ForwardIterator last);
  template <class ForwardIterator, class Size>
    ForwardIterator destroy_n(ForwardIterator first, Size n);
  template <class ExecutionPolicy, class ForwardIterator, class Size>
    ForwardIterator destroy_n(ExecutionPolicy&& exec, // see algorithms.parallel.overloads
                              ForwardIterator first, Size n);

  // unique.ptr, class template unique_ptr
  template <class T> struct default_delete;
  template <class T> struct default_delete<T[]>;
  template <class T, class D = default_delete<T>> class unique_ptr;
  template <class T, class D> class unique_ptr<T[], D>;

  template <class T, class... Args> unique_ptr<T> make_unique(Args&&... args);
  template <class T> unique_ptr<T> make_unique(size_t n);
  template <class T, class... Args> @\unspec@ make_unique(Args&&...) = delete;

  template <class T, class D> void swap(unique_ptr<T, D>& x, unique_ptr<T, D>& y) noexcept;

  template <class T1, class D1, class T2, class D2>
    bool operator==(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
  template <class T1, class D1, class T2, class D2>
    bool operator!=(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
  template <class T1, class D1, class T2, class D2>
    bool operator<(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
  template <class T1, class D1, class T2, class D2>
    bool operator<=(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
  template <class T1, class D1, class T2, class D2>
    bool operator>(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
  template <class T1, class D1, class T2, class D2>
    bool operator>=(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);

  template <class T, class D>
    bool operator==(const unique_ptr<T, D>& x, nullptr_t) noexcept;
  template <class T, class D>
    bool operator==(nullptr_t, const unique_ptr<T, D>& y) noexcept;
  template <class T, class D>
    bool operator!=(const unique_ptr<T, D>& x, nullptr_t) noexcept;
  template <class T, class D>
    bool operator!=(nullptr_t, const unique_ptr<T, D>& y) noexcept;
  template <class T, class D>
    bool operator<(const unique_ptr<T, D>& x, nullptr_t);
  template <class T, class D>
    bool operator<(nullptr_t, const unique_ptr<T, D>& y);
  template <class T, class D>
    bool operator<=(const unique_ptr<T, D>& x, nullptr_t);
  template <class T, class D>
    bool operator<=(nullptr_t, const unique_ptr<T, D>& y);
  template <class T, class D>
    bool operator>(const unique_ptr<T, D>& x, nullptr_t);
  template <class T, class D>
    bool operator>(nullptr_t, const unique_ptr<T, D>& y);
  template <class T, class D>
    bool operator>=(const unique_ptr<T, D>& x, nullptr_t);
  template <class T, class D>
    bool operator>=(nullptr_t, const unique_ptr<T, D>& y);

  // util.smartptr.weak.bad, class bad_weak_ptr
  class bad_weak_ptr;

  // util.smartptr.shared, class template shared_ptr
  template<class T> class shared_ptr;

  // util.smartptr.shared.create, shared_ptr creation
  template<class T, class... Args>
    shared_ptr<T> make_shared(Args&&... args);
  template<class T, class A, class... Args>
    shared_ptr<T> allocate_shared(const A& a, Args&&... args);

  // util.smartptr.shared.cmp, shared_ptr comparisons
  template<class T, class U>
    bool operator==(const shared_ptr<T>& a, const shared_ptr<U>& b) noexcept;
  template<class T, class U>
    bool operator!=(const shared_ptr<T>& a, const shared_ptr<U>& b) noexcept;
  template<class T, class U>
    bool operator<(const shared_ptr<T>& a, const shared_ptr<U>& b) noexcept;
  template<class T, class U>
    bool operator>(const shared_ptr<T>& a, const shared_ptr<U>& b) noexcept;
  template<class T, class U>
    bool operator<=(const shared_ptr<T>& a, const shared_ptr<U>& b) noexcept;
  template<class T, class U>
    bool operator>=(const shared_ptr<T>& a, const shared_ptr<U>& b) noexcept;

  template <class T>
    bool operator==(const shared_ptr<T>& x, nullptr_t) noexcept;
  template <class T>
    bool operator==(nullptr_t, const shared_ptr<T>& y) noexcept;
  template <class T>
    bool operator!=(const shared_ptr<T>& x, nullptr_t) noexcept;
  template <class T>
    bool operator!=(nullptr_t, const shared_ptr<T>& y) noexcept;
  template <class T>
    bool operator<(const shared_ptr<T>& x, nullptr_t) noexcept;
  template <class T>
    bool operator<(nullptr_t, const shared_ptr<T>& y) noexcept;
  template <class T>
    bool operator<=(const shared_ptr<T>& x, nullptr_t) noexcept;
  template <class T>
    bool operator<=(nullptr_t, const shared_ptr<T>& y) noexcept;
  template <class T>
    bool operator>(const shared_ptr<T>& x, nullptr_t) noexcept;
  template <class T>
    bool operator>(nullptr_t, const shared_ptr<T>& y) noexcept;
  template <class T>
    bool operator>=(const shared_ptr<T>& x, nullptr_t) noexcept;
  template <class T>
    bool operator>=(nullptr_t, const shared_ptr<T>& y) noexcept;

  // util.smartptr.shared.spec, shared_ptr specialized algorithms
  template<class T>
    void swap(shared_ptr<T>& a, shared_ptr<T>& b) noexcept;

  // util.smartptr.shared.cast, shared_ptr casts
  template<class T, class U>
    shared_ptr<T> static_pointer_cast(const shared_ptr<U>& r) noexcept;
  template<class T, class U>
    shared_ptr<T> dynamic_pointer_cast(const shared_ptr<U>& r) noexcept;
  template<class T, class U>
    shared_ptr<T> const_pointer_cast(const shared_ptr<U>& r) noexcept;

  // util.smartptr.getdeleter, shared_ptr get_deleter
  template<class D, class T>
    D* get_deleter(const shared_ptr<T>& p) noexcept;

  // util.smartptr.shared.io, shared_ptr I/O
  template<class E, class T, class Y>
    basic_ostream<E, T>& operator<< (basic_ostream<E, T>& os, const shared_ptr<Y>& p);

  // util.smartptr.weak, class template weak_ptr
  template<class T> class weak_ptr;

  // util.smartptr.weak.spec, weak_ptr specialized algorithms
  template<class T> void swap(weak_ptr<T>& a, weak_ptr<T>& b) noexcept;

  // util.smartptr.ownerless, class template owner_less
  template<class T = void> struct owner_less;

  // util.smartptr.enab, class template enable_shared_from_this
  template<class T> class enable_shared_from_this;

  // util.smartptr.shared.atomic, shared_ptr atomic access
  template<class T>
    bool atomic_is_lock_free(const shared_ptr<T>* p);

  template<class T>
    shared_ptr<T> atomic_load(const shared_ptr<T>* p);
  template<class T>
    shared_ptr<T> atomic_load_explicit(const shared_ptr<T>* p, memory_order mo);

  template<class T>
    void atomic_store(shared_ptr<T>* p, shared_ptr<T> r);
  template<class T>
    void atomic_store_explicit(shared_ptr<T>* p, shared_ptr<T> r, memory_order mo);

  template<class T>
    shared_ptr<T> atomic_exchange(shared_ptr<T>* p, shared_ptr<T> r);
  template<class T>
    shared_ptr<T> atomic_exchange_explicit(shared_ptr<T>* p, shared_ptr<T> r, memory_order mo);

  template<class T>
    bool atomic_compare_exchange_weak(
      shared_ptr<T>* p, shared_ptr<T>* v, shared_ptr<T> w);
  template<class T>
    bool atomic_compare_exchange_strong(
      shared_ptr<T>* p, shared_ptr<T>* v, shared_ptr<T> w);
  template<class T>
    bool atomic_compare_exchange_weak_explicit(
      shared_ptr<T>* p, shared_ptr<T>* v, shared_ptr<T> w,
      memory_order success, memory_order failure);
  template<class T>
    bool atomic_compare_exchange_strong_explicit(
      shared_ptr<T>* p, shared_ptr<T>* v, shared_ptr<T> w,
      memory_order success, memory_order failure);

  // util.smartptr.hash, hash support
  template <class T> struct hash;
  template <class T, class D> struct hash<unique_ptr<T, D>>;
  template <class T> struct hash<shared_ptr<T>>;

  // allocator.uses.trait, uses_allocator
  template <class T, class Alloc>
    inline constexpr bool uses_allocator_v = uses_allocator<T, Alloc>::value;
}
