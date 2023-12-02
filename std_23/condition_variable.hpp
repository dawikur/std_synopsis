namespace std {
  // thread.condition.condvar, class condition_variable
  class condition_variable;
  // thread.condition.condvarany, class condition_variable_any
  class condition_variable_any;

  // thread.condition.nonmember, non-member functions
  void notify_all_at_thread_exit(condition_variable& cond, unique_lock<mutex> lk);

  enum class cv_status { no_timeout, timeout };
}
