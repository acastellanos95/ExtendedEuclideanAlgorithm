#include <iostream>
#include <tuple>
#include "gmpxx.h"

/// Solve the equation ua+vb=gcd(a,b)
/// \param a
/// \param b
/// \return tuple(u,v,gcd(a,b)) of the equation ua+vb=gcd(a,b)
std::tuple<mpz_class, mpz_class, mpz_class> extendedGCD(const mpz_class &a, const mpz_class &b)
{
  mpz_class Zero("0", 10);

  mpz_class rMinusOne = a;
  mpz_class r = b;

  mpz_class sMinusOne("1", 10);
  mpz_class s("0", 10);

  mpz_class tMinusOne("0", 10);
  mpz_class t("1", 10);

  while (cmp(r, Zero) != 0)
  {
    mpz_class quotient;
    quotient = rMinusOne / r;

    mpz_class rTmp;
    rTmp = r;
    r = rMinusOne - quotient * rTmp;
    rMinusOne = rTmp;

    mpz_class sTmp;
    sTmp = s;
    s = sMinusOne - quotient * sTmp;
    sMinusOne = sTmp;

    mpz_class tTmp;
    tTmp = t;
    t = tMinusOne - quotient * tTmp;
    tMinusOne = tTmp;
  }

  return std::make_tuple(sMinusOne, tMinusOne, rMinusOne);
}

int main()
{
  mpz_class a, b;
  std::cout << "Introduzca el valor a: ";
  std::cin >> a;
  std::cout << "Introduzca el valor b: ";
  std::cin >> b;
  std::cout << a << ", " << b << "\n";
  auto result = extendedGCD(a, b);

  std::cout << "El maximo comun divisor gcd(a,b)=" << std::get<2>(result) << '\n';
  std::cout << "La solucion a la ecuacion u*" << a << "+v*" << b << "=" << std::get<2>(result) << " es :\n";
  std::cout << "u=" << std::get<0>(result) << ", v=" << std::get<1>(result) << '\n';
  std::cout << "Verificacion (Debe ser igual al gcd): " << (std::get<0>(result)*a) + (std::get<1>(result)*b) << "\n";
  return 0;
}
