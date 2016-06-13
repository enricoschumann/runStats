#include <R.h>
#include <Rinternals.h>
SEXP m_avg(SEXP x, SEXP n) {
  int i, N, nx;    
  N = asInteger(n);
  x = PROTECT(coerceVector(x, REALSXP));
  nx = length(x);

  SEXP mean = PROTECT(allocVector(REALSXP, nx));
  double *px, *pmean;
  px = REAL(x);
  pmean = REAL(mean);
  for (i = 0; i < N; i++)
    pmean[N - 1] += px[i];
  pmean[N - 1] /= N;

  for (i = 0; i < nx; i++)
    pmean[i] = pmean[i - 1] + (px[i] - px[i - N]) / N;

  UNPROTECT(2);
  return mean;
}
