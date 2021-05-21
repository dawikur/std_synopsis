namespace std {
  // stoptoken, class stop_token
  class stop_token;

  // stopsource, class stop_source
  class stop_source;

  // no-shared-stop-state indicator
  struct nostopstate_t {
    explicit nostopstate_t() = default;
  };
  inline constexpr nostopstate_t nostopstate{};

  // stopcallback, class stop_callback
  template<class Callback>
  class stop_callback;
}
