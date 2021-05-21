namespace std {
  using jmp_buf = @\seebelow@;
  [[noreturn]] void longjmp(jmp_buf env, int val);
}

#define setjmp(env) @\seebelow@
