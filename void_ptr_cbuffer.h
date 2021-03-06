/**
 *   \file void_ptr_cbuffer.h
 *   \brief A Documented file.
 *
 *  Detailed description
 *
 */

#ifndef VOID_PTR_CBUFFER_H
#define VOID_PTR_CBUFFER_H

#include <cstring>

class VoidPtrCBuffer {
public:
  VoidPtrCBuffer(std::size_t capacity, std::size_t offset, void* buffer);
  ~VoidPtrCBuffer();

  void* incFromRight();
  void* decFromRight();
  void* decFromLeft();

protected:
  //  void append(const void* v);
  VoidPtrCBuffer(){}
  VoidPtrCBuffer(const VoidPtrCBuffer& rhs) {}
  VoidPtrCBuffer& operator=(const VoidPtrCBuffer& rhs) {}

private:
  std::size_t capacity_;
  std::size_t offset_;
  char* buffer_;
  char* left_;
  char* right_;
  char* end_;
};


#endif /* VOID_PTR_CBUFFER_H */
