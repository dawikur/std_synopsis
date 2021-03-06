namespace std {
  // atomics.order, order and consistency
  enum memory_order;
  template <class T>
    T kill_dependency(T y) noexcept;

  // atomics.lockfree, lock-free property
  #define ATOMIC_BOOL_LOCK_FREE @\unspec@
  #define ATOMIC_CHAR_LOCK_FREE @\unspec@
  #define ATOMIC_CHAR16_T_LOCK_FREE @\unspec@
  #define ATOMIC_CHAR32_T_LOCK_FREE @\unspec@
  #define ATOMIC_WCHAR_T_LOCK_FREE @\unspec@
  #define ATOMIC_SHORT_LOCK_FREE @\unspec@
  #define ATOMIC_INT_LOCK_FREE @\unspec@
  #define ATOMIC_LONG_LOCK_FREE @\unspec@
  #define ATOMIC_LLONG_LOCK_FREE @\unspec@
  #define ATOMIC_POINTER_LOCK_FREE @\unspec@

  // atomics.types.generic, generic types
  template<class T> struct atomic;
  template<> struct atomic<@integral@>;
  template<class T> struct atomic<T*>;

  // atomics.types.operations.general, general operations on atomic types
  //  In the following declarations, atomic-type is either
  //  atomic<T> or a named base class for T from
  //  Table~tab:atomics.integral or inferred from Table~tab:atomics.typedefs or from bool.
  // If it is atomic<T>, then the declaration is a template
  // declaration prefixed with \tcode{template <class T>}.
  bool atomic_is_lock_free(const volatile @atomic-type@*) noexcept;
  bool atomic_is_lock_free(const @atomic-type@*) noexcept;
  void atomic_init(volatile @atomic-type@*, T) noexcept;
  void atomic_init(@atomic-type@*, T) noexcept;
  void atomic_store(volatile @atomic-type@*, T) noexcept;
  void atomic_store(@atomic-type@*, T) noexcept;
  void atomic_store_explicit(volatile @atomic-type@*, T, memory_order) noexcept;
  void atomic_store_explicit(@atomic-type@*, T, memory_order) noexcept;
  T atomic_load(const volatile @atomic-type@*) noexcept;
  T atomic_load(const @atomic-type@*) noexcept;
  T atomic_load_explicit(const volatile @atomic-type@*, memory_order) noexcept;
  T atomic_load_explicit(const @atomic-type@*, memory_order) noexcept;
  T atomic_exchange(volatile @atomic-type@*, T) noexcept;
  T atomic_exchange(@atomic-type@*, T) noexcept;
  T atomic_exchange_explicit(volatile @atomic-type@*, T, memory_order) noexcept;
  T atomic_exchange_explicit(@atomic-type@*, T, memory_order) noexcept;
  bool atomic_compare_exchange_weak(volatile @atomic-type@*, T*, T) noexcept;
  bool atomic_compare_exchange_weak(@atomic-type@*, T*, T) noexcept;
  bool atomic_compare_exchange_strong(volatile @atomic-type@*, T*, T) noexcept;
  bool atomic_compare_exchange_strong(@atomic-type@*, T*, T) noexcept;
  bool atomic_compare_exchange_weak_explicit(volatile @atomic-type@*, T*, T, 
    memory_order, memory_order) noexcept;
  bool atomic_compare_exchange_weak_explicit(@atomic-type@*, T*, T.
    memory_order, memory_order) noexcept;
  bool atomic_compare)exchange_strong_explicit(volatile @atomic-type@*, T*, T,
    memory_order, memory_order) noexcept;
  bool atomic_compare_exchange_strong_explicit(@atomic-type@*, T*, T,
    memory_order, memory_order) noexcept;

  // atomics.types.operations.templ, templated operations on atomic types
  template <class T>
    T atomic_fetch_add(volatile @atomic<T>@*, T) noexcept;
  template <class T>
    T atomic_fetch_add(@atomic<T>@*, T) noexcept;
  template <class T>
    T atomic_fetch_add_explicit(volatile atomic<T>*, T, memory_order) noexcept;
  template <class T>
    T atomic_fetch_add_explicit(atomic<T>*, T, memory_order) noexcept;
  template <class T>
    T atomic_fetch_sub(volatile atomic<T>*, T) noexcept;
  template <class T>
    T atomic_fetch_sub(atomic<T>*, T) noexcept;
  template <class T>
    T atomic_fetch_sub_explicit(volatile atomic<T>*, T, memory_order) noexcept;
  template <class T>
    T atomic_fetch_sub_explicit(atomic<T>*, T, memory_order) noexcept;
  template <class T>
    T atomic_fetch_and(volatile atomic<T>*, T) noexcept;
  template <class T>
    T atomic_fetch_and(atomic<T>*, T) noexcept;
  template <class T>
    T atomic_fetch_and_explicit(volatile atomic<T>*, T, memory_order) noexcept;
  template <class T>
    T atomic_fetch_and_explicit(atomic<T>*, T, memory_order) noexcept;
  template <class T>
    T atomic_fetch_or(volatile atomic<T>*, T) noexcept;
  template <class T>
    T atomic_fetch_or(atomic<T>*, T) noexcept;
  template <class T>
    T atomic_fetch_or_explicit(volatile atomic<T>*, T, memory_order) noexcept;
  template <class T>
    T atomic_fetch_or_explicit(atomic<T>*, T, memory_order) noexcept;
  template <class T>
    T atomic_fetch_xor(volatile atomic<T>*, T) noexcept;
  template <class T>
    T atomic_fetch_xor(atomic<T>*, T) noexcept;
  template <class T>
    T atomic_fetch_xor_explicit(volatile atomic<T>*, T, memory_order) noexcept;
  template <class T>
    T atomic_fetch_xor_explicit(atomic<T>*, T, memory_order) noexcept;

  // atomics.types.operations.arith, arithmetic operations on atomic types
  // In the following declarations, atomic-integral is either
  // atomic<T> or a named base class for T from
  // Table~tab:atomics.integral or inferred from Table~tab:atomics.typedefs.
  // If it is atomic<T>, then the declaration is a template
  // specialization declaration prefixed with \tcode{template <>}.

  @integral@ atomic_fetch_add(volatile @atomic-integral@*, @integral@) noexcept;
  @integral@ atomic_fetch_add(@atomic-integral@*, @integral@) noexcept;
  @integral@ atomic_fetch_add_explicit(volatile @atomic-integral@*, @integral@, memory_order) noexcept;
  @integral@ atomic_fetch_add_explicit(@atomic-integral@*, @integral@, memory_order) noexcept;
  @integral@ atomic_fetch_sub(volatile @atomic-integral@*, @integral@) noexcept;
  @integral@ atomic_fetch_sub(@atomic-integral@*, @integral@) noexcept;
  @integral@ atomic_fetch_sub_explicit(volatile @atomic-integral@*, @integral@, memory_order) noexcept;
  @integral@ atomic_fetch_sub_explicit(@atomic-integral@*, @integral@, memory_order) noexcept;
  @integral@ atomic_fetch_and(volatile @atomic-integral@*, @integral@) noexcept;
  @integral@ atomic_fetch_and(@atomic-integral@*, @integral@) noexcept;
  @integral@ atomic_fetch_and_explicit(volatile @atomic-integral@*, @integral@, memory_order) noexcept;
  @integral@ atomic_fetch_and_explicit(@atomic-integral@*, @integral@, memory_order) noexcept;
  @integral@ atomic_fetch_or(volatile @atomic-integral@*, @integral@) noexcept;
  @integral@ atomic_fetch_or(@atomic-integral@*, @integral@) noexcept;
  @integral@ atomic_fetch_or_explicit(volatile @atomic-integral@*, @integral@, memory_order) noexcept;
  @integral@ atomic_fetch_or_explicit(@atomic-integral@*, @integral@, memory_order) noexcept;
  @integral@ atomic_fetch_xor(volatile @atomic-integral@*, @integral@) noexcept;
  @integral@ atomic_fetch_xor(@atomic-integral@*, @integral@) noexcept;
  @integral@ atomic_fetch_xor_explicit(volatile @atomic-integral@*, @integral@, memory_order) noexcept;
  @integral@ atomic_fetch_xor_explicit(@atomic-integral@*, @integral@, memory_order) noexcept;

  // atomics.types.operations.pointer, partial specializations for pointers

  template <class T>
    T* atomic_fetch_add(volatile atomic<T*>*, ptrdiff_t) noexcept;
  template <class T>
    T* atomic_fetch_add(atomic<T*>*, ptrdiff_t) noexcept;
  template <class T>
    T* atomic_fetch_add_explicit(volatile atomic<T*>*, ptrdiff_t, memory_order) noexcept;
  template <class T>
    T* atomic_fetch_add_explicit(atomic<T*>*, ptrdiff_t, memory_order) noexcept;
  template <class T>
    T* atomic_fetch_sub(volatile atomic<T*>*, ptrdiff_t) noexcept;
  template <class T>
    T* atomic_fetch_sub(atomic<T*>*, ptrdiff_t) noexcept;
  template <class T>
    T* atomic_fetch_sub_explicit(volatile atomic<T*>*, ptrdiff_t, memory_order) noexcept;
  template <class T>
    T* atomic_fetch_sub_explicit(atomic<T*>*, ptrdiff_t, memory_order) noexcept;

  // atomics.types.operations.req, initialization
  #define ATOMIC_VAR_INIT(value) @\seebelow@

  // atomics.flag, flag type and operations
  struct atomic_flag;
  bool atomic_flag_test_and_set(volatile atomic_flag*) noexcept;
  bool atomic_flag_test_and_set(atomic_flag*) noexcept;
  bool atomic_flag_test_and_set_explicit(volatile atomic_flag*, memory_order) noexcept;
  bool atomic_flag_test_and_set_explicit(atomic_flag*, memory_order) noexcept;
  void atomic_flag_clear(volatile atomic_flag*) noexcept;
  void atomic_flag_clear(atomic_flag*) noexcept;
  void atomic_flag_clear_explicit(volatile atomic_flag*, memory_order) noexcept;
  void atomic_flag_clear_explicit(atomic_flag*, memory_order) noexcept;
  #define ATOMIC_FLAG_INIT @\seebelow@

  // atomics.fences, fences
  extern "C" void atomic_thread_fence(memory_order) noexcept;
  extern "C" void atomic_signal_fence(memory_order) noexcept;
}
