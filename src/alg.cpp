// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1.0;
  for (int i = 1; i <= n; i++) {
      res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double eres = 1.0;
  for (int i = 1; i <= count; ++i) {
      eres += calcItem(x, i);
  }
  return eres;
}

double sinn(double x, uint16_t count) {
  double sinres = x;
  for (uint64_t i = 2; i <= count; ++i) {
    sinres += pown((-1.0), i - 1) * calcItem(x, (2 * i) - 1);
  }
  return sinres;
}

double cosn(double x, uint16_t count) {
  double cosres = 1.0;
  for (uint64_t i = 2; i <= count; ++i) {
    cosres += pown((-1.0), i - 1) * calcItem(x, (2 * i) - 2);
  }
  return cosres;
}
