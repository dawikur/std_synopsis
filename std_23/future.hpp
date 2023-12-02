namespace std {
  enum class future_errc {
    broken_promise = @\impdefx{value of future_errc::broken_promise}@,
    future_already_retrieved = @\impdefx{value of future_errc::future_already_retrieved}@,
    promise_already_satisfied = @\impdefx{value of future_errc::promise_already_satisfied}@,
    no_state = @\impdefx{value of future_errc::no_state}@
  };

  enum class launch : @@ {
    async = @@,
    deferred = @@,
    @\impdefx{last enumerator of launch}@
  };

  enum class future_status {
    ready,
    timeout,
    deferred
  };

  // futures.errors, error handling
  template<> struct is_error_code_enum<future_errc> : public true_type { };
  error_code make_error_code(future_errc e) noexcept;
  error_condition make_error_condition(future_errc e) noexcept;

  const error_category& future_category() noexcept;

  // futures.future.error, class future_error
  class future_error;

  // futures.promise, class template promise
  template<class R> class promise;
  template<class R> class promise<R&>;
  template<> class promise<void>;

  template<class R>
    void swap(promise<R>& x, promise<R>& y) noexcept;

  template<class R, class Alloc>
    struct uses_allocator<promise<R>, Alloc>;

  // futures.unique.future, class template future
  template<class R> class future;
  template<class R> class future<R&>;
  template<> class future<void>;

  // futures.shared.future, class template shared_future
  template<class R> class shared_future;
  template<class R> class shared_future<R&>;
  template<> class shared_future<void>;

  // futures.task, class template packaged_task
  template<class> class packaged_task;  // \notdef
  template<class R, class... ArgTypes>
    class packaged_task<R(ArgTypes...)>;

  template<class R, class... ArgTypes>
    void swap(packaged_task<R(ArgTypes...)>&, packaged_task<R(ArgTypes...)>&) noexcept;

  // futures.async, function template async
  template<class F, class... Args>
    [[nodiscard]] future<invoke_result_t<decay_t<F>, decay_t<Args>...>>
      async(F&& f, Args&&... args);
  template<class F, class... Args>
    [[nodiscard]] future<invoke_result_t<decay_t<F>, decay_t<Args>...>>
      async(launch policy, F&& f, Args&&... args);
}
