
#ifndef SKENTAGON_UTILITY_HEADER_INCLUDED
#define SKENTAGON_UTILITY_HEADER_INCLUDED

#include <initializer_list>
#include <memory>
#include <cstddef>

namespace skentagon {
  //sizeOfArray
  template<class T, std::size_t SIZE>
  inline std::size_t sizeOfArray( const T (&a)[SIZE] ){return SIZE;}

  //vector
  template<class T>
  class vector {
    public:
      class iterator {
        public:
          constexpr iterator next( iterator x, typename std::iterator_traits<iterator>::difference_type n = 1 ){
            std::advance(x,n);
            return x;
          }
          constexpr iterator prev( iterator x, typename std::iterator_traits<iterator>::difference_type n = 1 ){
            std::advance(x,-n);
            return x;
          }
        private:
      };
      vector();
      vector( std::size_t t ) : size(t), p(make_shared<T>(size)) {}
      vector( initializer_list<T> il ) : size(il.size()), p(make_shared<T>(il.size())) {
        for( auto i = il.begin(); i < il.end() ; ++i ){
          p[i-il.begin()] = *i;
        }
      }
      vector( const vector& rhs ) = default;
      // This class is light so that move constructor is not required
      //noexcept vector( vector&& rhs )
      vector( vector& parent, std::size_t index, std::size_t size ) = default;
      T& operator[]( std::size_t n ){ return const_cast<T>( (static_cast<const vector<T>*>(this)->operator[](n)) ); }
      const T& operator[]( std::size_t n ) const { return p[index+t]; }
      T& at( std::size_t n ){ return const_cast<T>( operator[](static_cast<const vector<T>*>(this)->at(n)) ); }
      const T& at( std::size_t n ) const { if (size()<=n)throw std::range_error("an range error occurred"); return operator[](n); }
      iterator begin() noexcept { return const_cast<iterator>( static_cast<const vector<T>*>(this)->cbegin() ); }
      const iterator begin() const noexcept { return cbegin(); }
      const iterator cbegin() const noexcept { return p[0]; }
      iterator end() noexcept { return const_cast<iterator>( static_cast<const vector<T>*>(this)->cend() ); }
      const iterator end() const noexcept { return cend(); }
      const iterator cend() const noexcept {}
      iterator rbegin() noexcept { return const_cast<iterator>( static_cast<const vector<T>*>(this)->crbegin() ); }
      const iterator rbegin() const noexcept { return crbegin(); }
      const iterator crbegin() const noexcept {}
      iterator rend() noexcept { return const_cast<iterator>( static_cast<const vector<T>*>(this)->crend() ); }
      const iterator rend() const noexcept { return crend(); }
      const iterator crend() const noexcept {}
      std::size_t size() const noexcept { return size-index; }
      // 以下未実装
      //void resize( std::size_t sz ){}
      //void resize( std::size_t sz, const T& c ){}
      #if __cplusplus < 201703L
        bool empty() const noexcept { return begin()==end(); }
      #else
        [[nodiscard]] bool empty() const noexcept { return begin()==end(); }
      #endif
    private:
      std::shared_ptr<T> p;
      const std::size_t index = 0;
      std::size_t size;
  };

  //array
  template<class T>
  class array {
    public:
      template<class... Args>
      array( std::size_t* length, T* p, std::size_t rank, std::size_t range )
        : length(length), p(p), rank(rank), range(range) {}
      array( const Args... args ){
        rank = sizeof...(args);
        length = new std::size_t[rank];
        length.reserve(rank);
        {
          void readArgs( const std::size_t t, const Args... args ){
            length[length.size()-sizeof...(args)-1] = t;
            readArgs(args...);
          }
          void readArgs(){}
          readArgs(args...);
        }
        #ifdef __cpp_fold_expressions
          range = args * ... * 1;
        #else
        {
          void f( const std::size_t t ){}
          void f( const std::size_t t, const Args... args ){
            range *= t;
            f(args...);
          }
          f(args...);
        }
        #endif
        p = new T[range];
      }
      ~array(){ delete length; delete p; }
      std::size_t rank() const { return rank; };
      template<std::size_t D>
      std::size_t getLength<D>() const { return length[D]; }
      const array<T>& operator[](std::size_t t) const& {}
      array<T>& operator[](std::size_t t) & {}
      array<T> operator[](std::size_t t) const && {}
    private:
      std::size_t* length;
      T* p;
      std::size_t rank;
      std::size_t range;
  };
}

#endif