/**
 *   \file cbuffer.h
 *   \brief A Documented file.
 *
 *  Detailed description
 *
 */
#ifndef CBUFFER_H
#define CBUFFER_H

#include <cstring>
#include "void_ptr_cbuffer.h"


// WARNING:
// * DON'T assume return data was initialized because
//   returned pointer pointed to data that may have been used previously
// * data pointed to could be override because the buffer is circular

template <class T>
class CBuffer  {
public:
  CBuffer(size_t capacity);
  ~CBuffer();

  T* incFromRight() {return static_cast<T*>(cbuffer_.incFromRight());}
  T* decFromRight() {return static_cast<T*>(cbuffer_.decFromRight());}
  T* decFromLeft() {return static_cast<T*>(cbuffer_.decFromLeft());}

  T* operator++(int) {return static_cast<T*>(cbuffer_.incFromRight());}
  T* operator--(int) {return static_cast<T*>(cbuffer_.decFromRight());}
  T* operator--() {return static_cast<T*>(cbuffer_.decFromLeft());}

protected:
  // WARNING: it does not do deep copy (not follows member pointers)
  //  void append(const T& v) {cbuffer_.append(&v);}
  CBuffer(){}
  CBuffer(const CBuffer& rhs) {}
  CBuffer& operator=(const CBuffer& rhs) {}

private:
  T* vbuffer_;
  VoidPtrCBuffer cbuffer_;
};

template <class T>
CBuffer<T>::CBuffer(size_t capacity)
  : vbuffer_(new T[capacity + 1]),
    cbuffer_(capacity, sizeof(T), vbuffer_) {
}

template<class T>
CBuffer<T>::~CBuffer() {
  delete[] this->vbuffer_;
}

#endif /* CBUFFER_H */
