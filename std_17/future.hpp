namespace std {
  enum class future_errc {
    broken_promise = @\impdef@,
    future_already_retrieved = @\impdef@,
    promise_already_satisfied = @\impdef@,
    no_state = @\impdef@
  };

  enum class launch : @@ {
    async = @@,
    deferred = @@,
    @\impdef@
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

  template <class> class packaged_task;   // not defined
  template <class R, class... ArgTypes>
    class packaged_task<R(ArgTypes...)>;

  template <class R, class... ArgTypes>
    void swap(packaged_task<R(ArgTypes...)>&, packaged_task<R(ArgTypes...)>&) noexcept;

  template <class R, class Alloc>
    struct uses_allocator<packaged_task<R>, Alloc>;

  template <class F, class... Args>
    future<invoke_result_t<decay_t<F>, decay_t<Args>...>>
    async(F&& f, Args&&... args);
  template <class F, class... Args>
    future<invoke_result_t<decay_t<F>, decay_t<Args>...>>
    async(launch policy, F&& f, Args&&... args);
}
