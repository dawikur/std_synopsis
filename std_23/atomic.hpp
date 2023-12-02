namespace std {
  // atomics.order, order and consistency
  enum class memory_order : @\unspecnc@;                                            // freestanding
  inline constexpr memory_order memory_order_relaxed = memory_order::relaxed;       // freestanding
  inline constexpr memory_order memory_order_consume = memory_order::consume;       // freestanding
  inline constexpr memory_order memory_order_acquire = memory_order::acquire;       // freestanding
  inline constexpr memory_order memory_order_release = memory_order::release;       // freestanding
  inline constexpr memory_order memory_order_acq_rel = memory_order::acq_rel;       // freestanding
  inline constexpr memory_order memory_order_seq_cst = memory_order::seq_cst;       // freestanding

  template<class T>
    T kill_dependency(T y) noexcept;                                                // freestanding
}

// atomics.lockfree, lock-free property
#define ATOMIC_BOOL_LOCK_FREE @\unspecnc@                                           // freestanding
#define ATOMIC_CHAR_LOCK_FREE @\unspecnc@                                           // freestanding
#define ATOMIC_CHAR8_T_LOCK_FREE @\unspecnc@                                        // freestanding
#define ATOMIC_CHAR16_T_LOCK_FREE @\unspecnc@                                       // freestanding
#define ATOMIC_CHAR32_T_LOCK_FREE @\unspecnc@                                       // freestanding
#define ATOMIC_WCHAR_T_LOCK_FREE @\unspecnc@                                        // freestanding
#define ATOMIC_SHORT_LOCK_FREE @\unspecnc@                                          // freestanding
#define ATOMIC_INT_LOCK_FREE @\unspecnc@                                            // freestanding
#define ATOMIC_LONG_LOCK_FREE @\unspecnc@                                           // freestanding
#define ATOMIC_LLONG_LOCK_FREE @\unspecnc@                                          // freestanding
#define ATOMIC_POINTER_LOCK_FREE @\unspecnc@                                        // freestanding

namespace std {
  // atomics.ref.generic, class template atomic_ref
  template<class T> struct atomic_ref;                                              // freestanding
  // atomics.ref.pointer, partial specialization for pointers
  template<class T> struct atomic_ref<T*>;                                          // freestanding

  // atomics.types.generic, class template atomic
  template<class T> struct atomic;                                                  // freestanding
  // atomics.types.pointer, partial specialization for pointers
  template<class T> struct atomic<T*>;                                              // freestanding

  // atomics.nonmembers, non-member functions
  template<class T>
    bool atomic_is_lock_free(const volatile atomic<T>*) noexcept;                   // freestanding
  template<class T>
    bool atomic_is_lock_free(const atomic<T>*) noexcept;                            // freestanding
  template<class T>
    void atomic_store(volatile atomic<T>*,                                          // freestanding
                      typename atomic<T>::value_type) noexcept;
  template<class T>
    void atomic_store(atomic<T>*, typename atomic<T>::value_type) noexcept;         // freestanding
  template<class T>
    void atomic_store_explicit(volatile atomic<T>*,                                 // freestanding
                               typename atomic<T>::value_type,
                               memory_order) noexcept;
  template<class T>
    void atomic_store_explicit(atomic<T>*, typename atomic<T>::value_type,          // freestanding
                               memory_order) noexcept;
  template<class T>
    T atomic_load(const volatile atomic<T>*) noexcept;                              // freestanding
  template<class T>
    T atomic_load(const atomic<T>*) noexcept;                                       // freestanding
  template<class T>
    T atomic_load_explicit(const volatile atomic<T>*, memory_order) noexcept;       // freestanding
  template<class T>
    T atomic_load_explicit(const atomic<T>*, memory_order) noexcept;                // freestanding
  template<class T>
    T atomic_exchange(volatile atomic<T>*,                                          // freestanding
                      typename atomic<T>::value_type) noexcept;
  template<class T>
    T atomic_exchange(atomic<T>*, typename atomic<T>::value_type) noexcept;         // freestanding
  template<class T>
    T atomic_exchange_explicit(volatile atomic<T>*,                                 // freestanding
                               typename atomic<T>::value_type,
                               memory_order) noexcept;
  template<class T>
    T atomic_exchange_explicit(atomic<T>*, typename atomic<T>::value_type,          // freestanding
                               memory_order) noexcept;
  template<class T>
    bool atomic_compare_exchange_weak(volatile atomic<T>*,                          // freestanding
                                      typename atomic<T>::value_type*,
                                      typename atomic<T>::value_type) noexcept;
  template<class T>
    bool atomic_compare_exchange_weak(atomic<T>*,                                   // freestanding
                                      typename atomic<T>::value_type*,
                                      typename atomic<T>::value_type) noexcept;
  template<class T>
    bool atomic_compare_exchange_strong(volatile atomic<T>*,                        // freestanding
                                        typename atomic<T>::value_type*,
                                        typename atomic<T>::value_type) noexcept;
  template<class T>
    bool atomic_compare_exchange_strong(atomic<T>*,                                 // freestanding
                                        typename atomic<T>::value_type*,
                                        typename atomic<T>::value_type) noexcept;
  template<class T>
    bool atomic_compare_exchange_weak_explicit(volatile atomic<T>*,                 // freestanding
                                               typename atomic<T>::value_type*,
                                               typename atomic<T>::value_type,
                                               memory_order, memory_order) noexcept;
  template<class T>
    bool atomic_compare_exchange_weak_explicit(atomic<T>*,                          // freestanding
                                               typename atomic<T>::value_type*,
                                               typename atomic<T>::value_type,
                                               memory_order, memory_order) noexcept;
  template<class T>
    bool atomic_compare_exchange_strong_explicit(volatile atomic<T>*,               // freestanding
                                                 typename atomic<T>::value_type*,
                                                 typename atomic<T>::value_type,
                                                 memory_order, memory_order) noexcept;
  template<class T>
    bool atomic_compare_exchange_strong_explicit(atomic<T>*,                        // freestanding
                                                 typename atomic<T>::value_type*,
                                                 typename atomic<T>::value_type,
                                                 memory_order, memory_order) noexcept;

  template<class T>
    T atomic_fetch_add(volatile atomic<T>*,                                         // freestanding
                       typename atomic<T>::difference_type) noexcept;
  template<class T>
    T atomic_fetch_add(atomic<T>*, typename atomic<T>::difference_type) noexcept;   // freestanding
  template<class T>
    T atomic_fetch_add_explicit(volatile atomic<T>*,                                // freestanding
                                typename atomic<T>::difference_type,
                                memory_order) noexcept;
  template<class T>
    T atomic_fetch_add_explicit(atomic<T>*, typename atomic<T>::difference_type,    // freestanding
                                memory_order) noexcept;
  template<class T>
    T atomic_fetch_sub(volatile atomic<T>*,                                         // freestanding
                       typename atomic<T>::difference_type) noexcept;
  template<class T>
    T atomic_fetch_sub(atomic<T>*, typename atomic<T>::difference_type) noexcept;   // freestanding
  template<class T>
    T atomic_fetch_sub_explicit(volatile atomic<T>*,                                // freestanding
                                typename atomic<T>::difference_type,
                                memory_order) noexcept;
  template<class T>
    T atomic_fetch_sub_explicit(atomic<T>*, typename atomic<T>::difference_type,    // freestanding
                                memory_order) noexcept;
  template<class T>
    T atomic_fetch_and(volatile atomic<T>*,                                         // freestanding
                       typename atomic<T>::value_type) noexcept;
  template<class T>
    T atomic_fetch_and(atomic<T>*, typename atomic<T>::value_type) noexcept;        // freestanding
  template<class T>
    T atomic_fetch_and_explicit(volatile atomic<T>*,                                // freestanding
                                typename atomic<T>::value_type,
                                memory_order) noexcept;
  template<class T>
    T atomic_fetch_and_explicit(atomic<T>*, typename atomic<T>::value_type,         // freestanding
                                memory_order) noexcept;
  template<class T>
    T atomic_fetch_or(volatile atomic<T>*,                                          // freestanding
                      typename atomic<T>::value_type) noexcept;
  template<class T>
    T atomic_fetch_or(atomic<T>*, typename atomic<T>::value_type) noexcept;         // freestanding
  template<class T>
    T atomic_fetch_or_explicit(volatile atomic<T>*,                                 // freestanding
                               typename atomic<T>::value_type,
                               memory_order) noexcept;
  template<class T>
    T atomic_fetch_or_explicit(atomic<T>*, typename atomic<T>::value_type,          // freestanding
                               memory_order) noexcept;
  template<class T>
    T atomic_fetch_xor(volatile atomic<T>*,                                         // freestanding
                       typename atomic<T>::value_type) noexcept;
  template<class T>
    T atomic_fetch_xor(atomic<T>*, typename atomic<T>::value_type) noexcept;        // freestanding
  template<class T>
    T atomic_fetch_xor_explicit(volatile atomic<T>*,                                // freestanding
                                typename atomic<T>::value_type,
                                memory_order) noexcept;
  template<class T>
    T atomic_fetch_xor_explicit(atomic<T>*, typename atomic<T>::value_type,         // freestanding
                                memory_order) noexcept;

  template<class T>
    void atomic_wait(const volatile atomic<T>*,                                     // freestanding
	             typename atomic<T>::value_type) noexcept;
  template<class T>
    void atomic_wait(const atomic<T>*, typename atomic<T>::value_type) noexcept;    // freestanding
  template<class T>
    void atomic_wait_explicit(const volatile atomic<T>*,                            // freestanding
                              typename atomic<T>::value_type,
                              memory_order) noexcept;
  template<class T>
    void atomic_wait_explicit(const atomic<T>*, typename atomic<T>::value_type,     // freestanding
                              memory_order) noexcept;
  template<class T>
    void atomic_notify_one(volatile atomic<T>*) noexcept;                           // freestanding
  template<class T>
    void atomic_notify_one(atomic<T>*) noexcept;                                    // freestanding
  template<class T>
    void atomic_notify_all(volatile atomic<T>*) noexcept;                           // freestanding
  template<class T>
    void atomic_notify_all(atomic<T>*) noexcept;                                    // freestanding

  // atomics.alias, type aliases
  using atomic_bool           = atomic<bool>;                                       // freestanding
  using atomic_char           = atomic<char>;                                       // freestanding
  using atomic_schar          = atomic<signed char>;                                // freestanding
  using atomic_uchar          = atomic<unsigned char>;                              // freestanding
  using atomic_short          = atomic<short>;                                      // freestanding
  using atomic_ushort         = atomic<unsigned short>;                             // freestanding
  using atomic_int            = atomic<int>;                                        // freestanding
  using atomic_uint           = atomic<unsigned int>;                               // freestanding
  using atomic_long           = atomic<long>;                                       // freestanding
  using atomic_ulong          = atomic<unsigned long>;                              // freestanding
  using atomic_llong          = atomic<long long>;                                  // freestanding
  using atomic_ullong         = atomic<unsigned long long>;                         // freestanding
  using atomic_char8_t        = atomic<char8_t>;                                    // freestanding
  using atomic_char16_t       = atomic<char16_t>;                                   // freestanding
  using atomic_char32_t       = atomic<char32_t>;                                   // freestanding
  using atomic_wchar_t        = atomic<wchar_t>;                                    // freestanding

  using atomic_int8_t         = atomic<int8_t>;                                     // freestanding
  using atomic_uint8_t        = atomic<uint8_t>;                                    // freestanding
  using atomic_int16_t        = atomic<int16_t>;                                    // freestanding
  using atomic_uint16_t       = atomic<uint16_t>;                                   // freestanding
  using atomic_int32_t        = atomic<int32_t>;                                    // freestanding
  using atomic_uint32_t       = atomic<uint32_t>;                                   // freestanding
  using atomic_int64_t        = atomic<int64_t>;                                    // freestanding
  using atomic_uint64_t       = atomic<uint64_t>;                                   // freestanding

  using atomic_int_least8_t   = atomic<int_least8_t>;                               // freestanding
  using atomic_uint_least8_t  = atomic<uint_least8_t>;                              // freestanding
  using atomic_int_least16_t  = atomic<int_least16_t>;                              // freestanding
  using atomic_uint_least16_t = atomic<uint_least16_t>;                             // freestanding
  using atomic_int_least32_t  = atomic<int_least32_t>;                              // freestanding
  using atomic_uint_least32_t = atomic<uint_least32_t>;                             // freestanding
  using atomic_int_least64_t  = atomic<int_least64_t>;                              // freestanding
  using atomic_uint_least64_t = atomic<uint_least64_t>;                             // freestanding

  using atomic_int_fast8_t    = atomic<int_fast8_t>;                                // freestanding
  using atomic_uint_fast8_t   = atomic<uint_fast8_t>;                               // freestanding
  using atomic_int_fast16_t   = atomic<int_fast16_t>;                               // freestanding
  using atomic_uint_fast16_t  = atomic<uint_fast16_t>;                              // freestanding
  using atomic_int_fast32_t   = atomic<int_fast32_t>;                               // freestanding
  using atomic_uint_fast32_t  = atomic<uint_fast32_t>;                              // freestanding
  using atomic_int_fast64_t   = atomic<int_fast64_t>;                               // freestanding
  using atomic_uint_fast64_t  = atomic<uint_fast64_t>;                              // freestanding

  using atomic_intptr_t       = atomic<intptr_t>;                                   // freestanding
  using atomic_uintptr_t      = atomic<uintptr_t>;                                  // freestanding
  using atomic_size_t         = atomic<size_t>;                                     // freestanding
  using atomic_ptrdiff_t      = atomic<ptrdiff_t>;                                  // freestanding
  using atomic_intmax_t       = atomic<intmax_t>;                                   // freestanding
  using atomic_uintmax_t      = atomic<uintmax_t>;                                  // freestanding

  using atomic_signed_lock_free   = @\seebelow@;
  using atomic_unsigned_lock_free = @\seebelow@;

  // atomics.flag, flag type and operations
  struct atomic_flag;                                                               // freestanding

  bool atomic_flag_test(const volatile atomic_flag*) noexcept;                      // freestanding
  bool atomic_flag_test(const atomic_flag*) noexcept;                               // freestanding
  bool atomic_flag_test_explicit(const volatile atomic_flag*,                       // freestanding
                                 memory_order) noexcept;
  bool atomic_flag_test_explicit(const atomic_flag*, memory_order) noexcept;        // freestanding
  bool atomic_flag_test_and_set(volatile atomic_flag*) noexcept;                    // freestanding
  bool atomic_flag_test_and_set(atomic_flag*) noexcept;                             // freestanding
  bool atomic_flag_test_and_set_explicit(volatile atomic_flag*,                     // freestanding
                                         memory_order) noexcept;
  bool atomic_flag_test_and_set_explicit(atomic_flag*, memory_order) noexcept;      // freestanding
  void atomic_flag_clear(volatile atomic_flag*) noexcept;                           // freestanding
  void atomic_flag_clear(atomic_flag*) noexcept;                                    // freestanding
  void atomic_flag_clear_explicit(volatile atomic_flag*, memory_order) noexcept;    // freestanding
  void atomic_flag_clear_explicit(atomic_flag*, memory_order) noexcept;             // freestanding

  void atomic_flag_wait(const volatile atomic_flag*, bool) noexcept;                // freestanding
  void atomic_flag_wait(const atomic_flag*, bool) noexcept;                         // freestanding
  void atomic_flag_wait_explicit(const volatile atomic_flag*,                       // freestanding
                                 bool, memory_order) noexcept;
  void atomic_flag_wait_explicit(const atomic_flag*,                                // freestanding
                                 bool, memory_order) noexcept;
  void atomic_flag_notify_one(volatile atomic_flag*) noexcept;                      // freestanding
  void atomic_flag_notify_one(atomic_flag*) noexcept;                               // freestanding
  void atomic_flag_notify_all(volatile atomic_flag*) noexcept;                      // freestanding
  void atomic_flag_notify_all(atomic_flag*) noexcept;                               // freestanding
  #define ATOMIC_FLAG_INIT @\seebelownc@                                                // freestanding

  // atomics.fences, fences
  extern "C" void atomic_thread_fence(memory_order) noexcept;                       // freestanding
  extern "C" void atomic_signal_fence(memory_order) noexcept;                       // freestanding
}
