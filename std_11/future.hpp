namespace std {
  enum class future_errc {
    broken_promise,
    future_already_retrieved,
    promise_already_satisfied,
    no_state
  };

  enum class launch : @@ {
    async = @@,
    deferred = @@,
    @@
  };

  enum class future_status {
    ready,
    timeout,
    deferred
  };

  template <> struct is_error_code_enum<future_errc> : public true_type { };
  error_code make_error_code(future_errc e) noexcept;
  error_condition make_error_condition(future_errc e) noexcept;

  const error_category& future_category() noexcept;

  class future_error;

  template <class R> class promise;
  template <class R> class promise<R&>;
  template <> class promise<void>;

  template <class R>
    void swap(promise<R>& x, promise<R>& y) noexcept;

  template <class R, class Alloc>
    struct uses_allocator<promise<R>, Alloc>;

  template <class R> class future;
  template <class R> class future<R&>;
  template <> class future<void>;

  template <class R> class shared_future;
  template <class R> class shared_future<R&>;
  template <> class shared_future<void>;

  template <class> class packaged_task;   // undefined
  template <class R, class... ArgTypes>
    class packaged_task<R(ArgTypes...)>;

  template <class R>
    void swap(packaged_task<R(ArgTypes...)>&, packaged_task<R(ArgTypes...)>&) noexcept;

  template <class R, class Alloc>
    struct uses_allocator<packaged_task<R>, Alloc>;

  template <class F, class... Args>
    future<typename result_of<F(Args...)>::type>
    async(F&& f, Args&&... args);
  template <class F, class... Args>
    future<typename result_of<F(Args...)>::type>
    async(launch policy, F&& f, Args&&... args);
}
