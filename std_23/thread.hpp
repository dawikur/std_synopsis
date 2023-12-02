#include <compare>              // see compare.syn

namespace std {
  // thread.thread.class, class thread
  class thread;

  void swap(thread& x, thread& y) noexcept;

  // thread.jthread.class, class jthread
  class jthread;

  // thread.thread.this, namespace this_thread
  namespace this_thread {
    thread::id get_id() noexcept;

    void yield() noexcept;
    template<class Clock, class Duration>
      void sleep_until(const chrono::time_point<Clock, Duration>& abs_time);
    template<class Rep, class Period>
      void sleep_for(const chrono::duration<Rep, Period>& rel_time);
  }
}
