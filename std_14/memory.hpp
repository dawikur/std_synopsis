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
  void* align(std::size_t alignment, std::size_t size,
    void*& ptr, std::size_t& space);

  // allocator.tag, allocator argument tag
  struct allocator_arg_t { };
  constexpr allocator_arg_t allocator_arg{};

  // allocator.uses, uses_allocator
  template <class T, class Alloc> struct uses_allocator;

  // allocator.traits, allocator traits
  template <class Alloc> struct allocator_traits;

  // default.allocator, the default allocator:
  template <class T> class allocator;
  template <> class allocator<void>;
  template <class T, class U>
    bool operator==(const allocator<T>&, const allocator<U>&) noexcept;
  template <class T, class U>
    bool operator!=(const allocator<T>&, const allocator<U>&) noexcept;

  // storage.iterator, raw storage iterator:
  template <class OutputIterator, class T> class raw_storage_iterator;

  // temporary.buffer, temporary buffers:
  template <class T>
    pair<T*,ptrdiff_t> get_temporary_buffer(ptrdiff_t n) noexcept;
  template <class T>
    void return_temporary_buffer(T* p);

  // specialized.algorithms, specialized algorithms:
  template <class T> T* addressof(T& r) noexcept;
  template <class InputIterator, class ForwardIterator>
    ForwardIterator uninitialized_copy(InputIterator first, InputIterator last,
                                       ForwardIterator result);
  template <class InputIterator, class Size, class ForwardIterator>
    ForwardIterator uninitialized_copy_n(InputIterator first, Size n,
                                         ForwardIterator result);
  template <class ForwardIterator, class T>
    void uninitialized_fill(ForwardIterator first, ForwardIterator last,
                            const T& x);
  template <class ForwardIterator, class Size, class T>
    ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n, const T& x);

  // unique.ptr class template unique_ptr:
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

  // util.smartptr.weakptr, class bad_weak_ptr:
  class bad_weak_ptr;

  // util.smartptr.shared, class template shared_ptr:
  template<class T> class shared_ptr;

  // util.smartptr.shared.create, shared_ptr creation
  template<class T, class... Args> shared_ptr<T> make_shared(Args&&... args);
  template<class T, class A, class... Args>
    shared_ptr<T> allocate_shared(const A& a, Args&&... args);

  // util.smartptr.shared.cmp, shared_ptr comparisons:
  template<class T, class U>
    bool operator==(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;
  template<class T, class U>
    bool operator!=(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;
  template<class T, class U>
    bool operator<(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;
  template<class T, class U>
    bool operator>(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;
  template<class T, class U>
    bool operator<=(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;
  template<class T, class U>
    bool operator>=(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;

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

  // util.smartptr.shared.spec, shared_ptr specialized algorithms:
  template<class T> void swap(shared_ptr<T>& a, shared_ptr<T>& b) noexcept;

  // util.smartptr.shared.cast, shared_ptr casts:
  template<class T, class U>
    shared_ptr<T> static_pointer_cast(shared_ptr<U> const& r) noexcept;
  template<class T, class U>
    shared_ptr<T> dynamic_pointer_cast(shared_ptr<U> const& r) noexcept;
  template<class T, class U>
    shared_ptr<T> const_pointer_cast(shared_ptr<U> const& r) noexcept;

  // util.smartptr.getdeleter, shared_ptr get_deleter:
  template<class D, class T> D* get_deleter(shared_ptr<T> const& p) noexcept;

  // util.smartptr.shared.io, shared_ptr I/O:
  template<class E, class T, class Y>
    basic_ostream<E, T>& operator<< (basic_ostream<E, T>& os, shared_ptr<Y> const& p);

  // util.smartptr.weak, class template weak_ptr:
  template<class T> class weak_ptr;

  // util.smartptr.weak.spec, weak_ptr specialized algorithms:
  template<class T> void swap(weak_ptr<T>& a, weak_ptr<T>& b) noexcept;

  // util.smartptr.ownerless, class template owner_less:
  template<class T> class owner_less;

  // util.smartptr.enab, class template enable_shared_from_this:
  template<class T> class enable_shared_from_this;

  // util.smartptr.shared.atomic, shared_ptr atomic access:
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
    shared_ptr<T> atomic_exchange_explicit(shared_ptr<T>* p, shared_ptr<T> r,
                                           memory_order mo);

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

  // util.smartptr.hash hash support
  template <class T> struct hash;
  template <class T, class D> struct hash<unique_ptr<T, D> >;
  template <class T> struct hash<shared_ptr<T> >;

  // depr.auto.ptr, auto_ptr (deprecated)
  template <class X> class auto_ptr;
}
