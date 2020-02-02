namespace std {
  class mutex;
  class recursive_mutex;
  class timed_mutex;
  class recursive_timed_mutex;

  struct defer_lock_t { };
  struct try_to_lock_t { };
  struct adopt_lock_t { };

  constexpr defer_lock_t  defer_lock { };
  constexpr try_to_lock_t try_to_lock { };
  constexpr adopt_lock_t  adopt_lock { };

  template <class Mutex> class lock_guard;
  template <class Mutex> class unique_lock;

  template <class Mutex>
    void swap(unique_lock<Mutex>& x, unique_lock<Mutex>& y) noexcept;

  template <class L1, class L2, class... L3> int try_lock(L1&, L2&, L3&...);
  template <class L1, class L2, class... L3> void lock(L1&, L2&, L3&...);

  struct once_flag {
    constexpr once_flag() noexcept;

    once_flag(const once_flag&) = delete;
    once_flag& operator=(const once_flag&) = delete;
  };

  template<class Callable, class ...Args>
    void call_once(once_flag& flag, Callable func, Args&&... args);
}
