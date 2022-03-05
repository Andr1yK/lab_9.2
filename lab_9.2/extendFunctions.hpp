#pragma once

#ifndef _EXTEND_FUNCTION_H_
#define _EXTEND_FUNCTION_H_

#include <iostream>
#include <iomanip>
#include <string>

#include "Student.hpp"

void Fill(Student*, const int N);

void Print(
  Student*, const int,
  std::string*,
  int* = nullptr, bool = false
);

#endif // !_EXTENDFUNCTION_H_
