/**
 *   \file void_ptr_cbuffer.h
 *   \brief A Documented file.
 *
 *  Detailed description
 *
 */

#ifndef VOID_PTR_CBUFFER_H
#define VOID_PTR_CBUFFER_H

#include <inttypes.h>

class VoidPtrCBuffer {
public:
  VoidPtrCBuffer(uint32_t capacity, uint32_t offset, void* buffer);
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
  uint32_t capacity_;
  uint32_t offset_;
  char* buffer_;
  char* left_;
  char* right_;
  char* end_;
};


#endif /* VOID_PTR_CBUFFER_H */
