// my game theory notes
// https://www.codechef.com/viewsolution/1025398589

/*
above post have the basics that i know about grundy numbers 
*/


// ith Fibbonaci number

Fibonacci(y) {
    if (y <= 0) return 0;
    if (y <= 2) return 1;
    if (y in fibonacci_cache) {
        return fibonacci_cache[y];
    }
    int f, b, a;
    b = y / 2; // integer division
    a = y - b;
    f = (Fibonacci(a) * Fibonacci(b + 1) + Fibonacci(a - 1) * Fibonacci(b)) % MOD;
    fibonacci_cache[y] = f;
    return f;
}