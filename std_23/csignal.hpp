namespace std {
  using sig_atomic_t = @\seebelow@;

  // support.signal, signal handlers
  extern "C" using @signal-handler@ = void(int);  // \expos
  @signal-handler@* signal(int sig, @signal-handler@* func);

  int raise(int sig);
}

#define SIG_DFL @\seebelow@
#define SIG_ERR @\seebelow@
#define SIG_IGN @\seebelow@
#define SIGABRT @\seebelow@
#define SIGFPE @\seebelow@
#define SIGILL @\seebelow@
#define SIGINT @\seebelow@
#define SIGSEGV @\seebelow@
#define SIGTERM @\seebelow@
