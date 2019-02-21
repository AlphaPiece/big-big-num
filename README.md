# BigBigNum
A calculator that is able to compute big numbers (arbitrary-precision numbers).

Assume an int type in a computer can only contain a number between 0 and 999.
Then we can contruct a big number by using linked list: Each node of the list contains 3 digits of the big number.

## Addition & Subtraction

```
    123 000 000
 +        1 111
--- --- --- ---
    123 001 111
    
    
        711 000
 +      511 111
--- --- --- ---
      1 222 111


    123 000 000
 -        1 111
--- --- --- ---
    123 001 111


          2 019
 -    1 000 020
--- --- --- ---
      - 998 001
```

It's easy to handle addtion and subtraction. If we are going to do addition and subtraction on twe numbers with different
signs, we can handle like below:

```
1 - (-1) = 1 + 1
1 + (-1) = 1 - 1
```

## Multiplication

Mutiplication is based on addition. Notice that

```
1234 * 123 = 1234 * (1 * 10^2 + 2 * 10^1 + 3 * 10^0)
           = 123400 * 1 + 12340 * 2 + 1234 * 3
           = 123400 + 24680 + 3702
           = 151782
```

So we can factor out the second multiplier as a representation of the form

```
c_m * 10^m + c_m-1 * 10^m-1 + ... + c_1 * 10^1 + c_0 * 10^0
```

where c_m, ..., c_0 are natural numbers.
