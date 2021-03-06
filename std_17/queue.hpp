#include <initializer_list>

namespace std {
  template <class T, class Container = deque<T>> class queue;
  template <class T, class Container = vector<T>,
            class Compare = less<typename Container::value_type>>
    class priority_queue;

  template <class T, class Container>
    bool operator==(const queue<T, Container>& x, const queue<T, Container>& y);
  template <class T, class Container>
    bool operator< (const queue<T, Container>& x, const queue<T, Container>& y);
  template <class T, class Container>
    bool operator!=(const queue<T, Container>& x, const queue<T, Container>& y);
  template <class T, class Container>
    bool operator> (const queue<T, Container>& x, const queue<T, Container>& y);
  template <class T, class Container>
    bool operator>=(const queue<T, Container>& x, const queue<T, Container>& y);
  template <class T, class Container>
    bool operator<=(const queue<T, Container>& x, const queue<T, Container>& y);

  template <class T, class Container>
    void swap(queue<T, Container>& x, queue<T, Container>& y) noexcept(noexcept(x.swap(y)));
  template <class T, class Container, class Compare>
    void swap(priority_queue<T, Container, Compare>& x,
              priority_queue<T, Container, Compare>& y) noexcept(noexcept(x.swap(y)));
}
