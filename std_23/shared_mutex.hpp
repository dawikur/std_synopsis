namespace std {
  // thread.sharedmutex.class, class shared_mutex
  class shared_mutex;
  // thread.sharedtimedmutex.class, class shared_timed_mutex
  class shared_timed_mutex;
  // thread.lock.shared, class template shared_lock
  template<class Mutex> class shared_lock;
  template<class Mutex>
    void swap(shared_lock<Mutex>& x, shared_lock<Mutex>& y) noexcept;
}
