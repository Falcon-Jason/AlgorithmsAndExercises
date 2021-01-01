#include <stdio.h>
double guessSqrt(double guess, double x){
    return (guess * guess - x < 1e-6) && (guess * guess - x > -1e-6) ?
            guess : guessSqrt((guess + (x / guess)) / 2, x);
}
double squareRoot(double x){
    return guessSqrt(x/2, x);
}
int main(){
    double x;
    scanf("%lg", &x);
    printf("%g\n", squareRoot(x));
    return 0;
}