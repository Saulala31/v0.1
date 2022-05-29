#pragma once
#include <iostream>
#include <iterator>
template <typename T> class Vector {
   public:
      typedef T* iterator;
      typedef const T* const_iterator;
      typedef size_t size_type;
      typedef T value_type;
      typedef std::reverse_iterator<iterator> reverse_iterator;
      typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
      std::allocator<T> alloc;

      /// Member functions:

      Vector() { create(); }
      explicit Vector(size_t n, const T& t = T()) { create(n, t); }

      ~Vector() { uncreate(); }

      Vector(const Vector& v) { create(v.begin(), v.end());}
      Vector(const std::initializer_list<T> il) { create(il.begin(), il.end());}

      Vector& operator=(const Vector& other){
         if(&other != this){
            uncreate();
            create(other.begin(), other.end());
         }
         return *this;
      }

      Vector& operator=(std::initializer_list<T> il){
         create(il.begin(), il.end());
         return *this;
      }
      void assign(size_t n, const T& t = T())
      {
         uncreate();
         creat(n, t);
      }
      template<class InputIt>
      void assign(InputIt first, InputIt last)
      {
         uncreate();
         create(first, last);
      }
      void assign(std::initializer_list<T> il)
      {
         uncreate();
         create(il.begin(), il.end());
      }
      
      /// Element access:

      T& at(int index)
      {
         if (index < 0 || size() <= index) throw std::out_of_range("index out of range");
         return values[index];
      }
      const T& at (int index) const 
      {
         if (index < 0 || size() <= index) throw std::out_of_range("index out of range");
         return values[index];
      }
      T& operator[](size_t index)
      {
         if (index < 0 || size() <= index) throw std::out_of_range("index out of range");
         return values[index];
      }
      const T& operator[](size_t index) const 
      {
         if (index < 0 || size() <= index) throw std::out_of_range("index out of range");
         return values[index];
      }
      T& front() {return values[0];}
      const T& front() const {return values[0];}

      T& back() { return values[size() - 1]; };
      const T& back() const { return values[size() - 1]; }

      T* data() {return values;}
      const T* data() const {return values;}

      /// Iterators:

      iterator begin() noexcept { return values; }
      const_iterator begin() const noexcept { return values; }
      const_iterator cbegin() const noexcept { return values; }
      iterator end() noexcept { return avail; }
      const_iterator end() const noexcept { return avail; }
      const_iterator cend() const noexcept { return avail; }
      reverse_iterator rbegin() { return reverse_iterator( end() ); }
      const_reverse_iterator crbegin() const { return reverse_iterator( end() ); }
      reverse_iterator rend() { return reverse_iterator( begin() ); }
      const_reverse_iterator crend() const { return reverse_iterator( begin() ); }

      /// Capacity:

      bool empty() const noexcept { return size() == 0; }

      size_t size() const { return avail - values; }

      void reserve( size_t new_limit ){
         if(new_limit > capacity()){
            iterator new_values = alloc.allocate(new_limit);
            iterator new_avail = uninitialized_copy(values, avail, new_values);
            uncreate();
            values = new_values;
            avail = new_avail;
            limit = values + new_limit;
         }
      }
      
      size_t capacity() const noexcept { return limit - values; }

      void shrink_to_fit(){
         iterator new_values = alloc.allocate(avail - values);
         iterator new_avail = uninitialized_copy(values, avail, new_values);
         uncreate();
         values = new_values;
         avail = new_avail;
         limit = avail;
      }

      /// Modifiers:

      void clear() { uncreate(); }

      void insert( int index, const T& value ){
         if (index < 0 || size() < index) throw std::out_of_range("index out of range");

         if(size() != capacity()){
            ++avail;
            for(int i = size()-1; i > index; i--){
               values[i] = values[i-1];
            }
            values[index] = value;
         }
         else{
            size_t l = capacity();
            for (size_t i = 0; i <l; i++){
               limit++;
            }
            insert(index, value);
         }
      }

      template<typename... Args>

      iterator emplace(int index, Args&&... args){
         if (index < 0 || size() < index) throw std::out_of_range("index out of range");

         if(avail == limit)
            grow();
         
         alloc.construct(avail++, std::forward<Args>(args)...);

         for(int i = size() - 1; i >= index+1; --i)
            std::swap(values[i], values[i-1]);

         return &values[index];
      }
      void erase( int index){
            if((index < 0) || (index >= size())){
               throw std::out_of_range("index out of range");
            }
            for (int i= index; i< size() - 1; ++i)
            {
               values[i] = values[i + 1];
            }
            --avail;
      };
      
      void emplace_back(const T& value){

         if(size() != capacity()){
            ++avail;
            values[size()-1] = value;
         }
         else{
            size_t l = capacity();
            for (size_t i = 0; i <l; i++){
               limit++;
            }
            emplace_back(value);
         }
      };
      void push_back(const T& value){
         if (avail == limit)
            grow();
         alloc.construct(avail++, value);
      }
      void push_back(const T&& value){
         if (avail == limit)
            grow();
         alloc.construct(avail++, value);
      }
      void pop_back() 
      {
         if(size() == 0)
            throw std::out_of_range("vector is empty");
         avail--;
      }
      void resize( unsigned int s){
         reserve(s);
         while (s != size())
         {
            avail--;
         }
      }
      void swap(Vector& a, Vector& b){
         using std::swap;
         swap(a.values, b.values);
         swap(a.avail, b.avail);
         swap(a.limit, b.limit);
      }

      Vector& operator==(const Vector& v){  
        if(this != v){
                limit = v.limit;
                avail = v.avail;
                values = new int[avail];
            for(int i=0;i<avail;i++)
                values[i] = v.values[i];
            }
            return *this;
        }
      
      void create() { values = avail = limit = nullptr;}

      void create(size_t n, const T&) {
         values = alloc.allocate(n);
         limit = avail = values + n;
         uninitialized_fill(values, limit, values);
      }
      void create(const_iterator i, const_iterator j){
         values = alloc.allocate(j - i);
         limit = avail = uninitialized_copy(i, j, values);
      }
      template<class ForwardIt>
      void uninitialized_fill(ForwardIt first, ForwardIt last, const T& values)
      {
         using V = typename std::iterator_traits<ForwardIt>::value_type;
         ForwardIt current = first;
         try {
         for (; current != last; ++current) {
            ::new (const_cast<void*>(static_cast<const volatile void*>(
                std::addressof(*current)))) V(values);
        }
         }  catch (...) {
               for (; first != current; ++first) {
               first->~V();
               }
               throw;
            }
      }
      template<class InputIt, class NoThrowForwardIt>
      NoThrowForwardIt uninitialized_copy(InputIt first, InputIt last, NoThrowForwardIt d_first)
      {
         using V = typename std::iterator_traits<NoThrowForwardIt>::value_type;
         NoThrowForwardIt current = d_first;
         try {
            for (; first != last; ++first, (void) ++current) {
                ::new (const_cast<void*>(static_cast<const volatile void*>(
                std::addressof(*current)))) V(*first);
            }
         return current;
         } catch (...) {
            for (; d_first != current; ++d_first) {
               d_first->~V();
            }
            throw;
         }
      }

      void uncreate(){
         if (values) {
            iterator it = avail;
            while (it != values)
               alloc.destroy(--it);
            alloc.deallocate(values, limit - values);
         }
         values = limit = avail = nullptr;
      }
      void grow(){
         size_t new_size = std::max(2 * (limit - values), ptrdiff_t(1));
         iterator new_values = alloc.allocate(new_size);
         iterator new_avail = uninitialized_copy(values, avail, new_values);
         uncreate();
         values = new_values;
         avail = new_avail;
         limit = values + new_size;
      }

   private:
      iterator values; 
      iterator avail; 
      iterator limit;
};