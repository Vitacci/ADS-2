// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1.0;
  if (n == 0) {
    return 1;
  }
  for (int i = 1; i <= n; i++) {
      res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  int fres = 1;
  for (int i = 1; i <= n; ++i) {
      fres *= i;
  }
  return fres;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double eres = 1;
  for (int i = 1; i <= count; ++i) {
      eres += calcItem(x, i);
  }
  return eres;
}

double sinn(double x, uint16_t count) {
  double sinres = 0.0;
  double term = x;
  int sign = 1;
  for (uint64_t i = 1; i <= count; ++i) {
  	sinres += sign * term;
  	sign *= -1;
  	term = term * x * x / (2 * i) / (2 * i + 1);
  }
  return sinres;
}

double cosn(double x, uint16_t count) {
  double cosres = 1.0;
  double term = 1.0;
  for (uint64_t i = 1; i <= count; ++i) {
  	term *= -x * x / ((2 * i) * (2 * i - 1));
  	cosres += term;
  }
  return cosres;
}
