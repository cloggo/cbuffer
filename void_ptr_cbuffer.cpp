/**
 *   \file void_ptr_cbuffer.cpp
 *   \brief A Documented file.
 *
 *  Detailed description
 *
 */

#include "void_ptr_cbuffer.h"
#include <cstring>

VoidPtrCBuffer::VoidPtrCBuffer(size_t capacity, size_t offset, void* buffer)
  : capacity_(capacity), offset_(offset),
    buffer_(static_cast<char*>(buffer)),
    left_(buffer_), right_(buffer_), end_(buffer_ + capacity_ * offset_) {
}

VoidPtrCBuffer::~VoidPtrCBuffer() {
  //   delete[] this->buffer_;
}

void* VoidPtrCBuffer::decFromLeft() {
  if(left_ == right_) {
    return nullptr;
  }

  void* tmp = left_;

  if(left_ == end_) {
    left_ = buffer_;
  }
  else {
    left_ += offset_;
  }

  return tmp;
}

void* VoidPtrCBuffer::decFromRight() {
  if(left_ == right_) {
    return nullptr;
  }

  if(right_ == buffer_) {
    right_ = end_;
  }
  else {
    right_ -= offset_;
  }

  return right_;
}

void* VoidPtrCBuffer::incFromRight() {
  void* tmp = right_;

  if(right_ == end_) {
    right_ = buffer_;
  }
  else {
    right_ += offset_;
  }

  if(left_ == right_) {
    if(left_ == end_) {
      left_ = buffer_;
    }
    else {
      left_ += offset_;
    }
  }

  return tmp;
}

#if 0

void VoidPtrCBuffer::append(const void* v) {
  memcpy(this->incFromRight(), v, offset_);
}

#endif
