# BigBigNum

A calculator called bnc which is able to compute large integers (arbitrary-precision integers).

I will explain the basic idea of the implementation of bnc in the following.

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

It's easy to handle addtion and subtraction. If we are going to do addition and subtraction on two numbers with different signs, we can handle like below:

```
(+1) - (-1) = 1 + 1
(+1) + (-1) = 1 - 1
(-1) - (+1) = -(1 + 1)
(-1) + (+1) = -(1 - 1)
```


## Multiplication

Mutiplication is based on addition. Notice that

```
1234 * 123 = 1234 * (1 * 10^2 + 2 * 10^1 + 3 * 10^0)
           = 123400 * 1 + 12340 * 2 + 1234 * 3
           = 123400 + 24680 + 3702
           = 151782
```

bnc has a left-shift function and a right-shift function. Left-shift shifts all digits of a big number to the left (like adding zeroes after a number); right-shift shifts all digits of a big number to the right (like erasing trailing digits).

So we can factor out the second multiplier as a representation of the form

```
c_m * 10^m + c_m-1 * 10^m-1 + ... + c_1 * 10^1 + c_0 * 10^0
```

where c_m, ..., c_0 are natural numbers, and shift the 10's power times the first multiplier for each term,
and add itself for the scalar times. For example, for the term c_2 * 10^2, we left-shift the first multiplier 2 time,
and then add the result for c_1 times. Let the first multiplier = 1234 and c_2 = 5:

```
Left-shift 1234 for 2 times = 123400
Add 123400 for 5 times = 123400 + 123400 + 123400 + 123400 + 123400 = 617000
```
After we apply this small algorithm to each term of the second multiplier, we add all the term results together to
obtain the product of this multiplicaton.


## Division & Modulo

Division and modulo are both based on subtraction. In fact, the algorithm of division is the reverse of the algorithm of multiplication, and the algorithm of modulo is just a part of the algorithm of division.
Say we want to calculate 151782 / 1234, we will do the following:

```
151782 - 123400 = 28382 < 123400

28382 - 12340 = 16042 >= 12340
16042 - 12340 = 3702 < 12340

3702 - 1234 = 2468 >= 1234
2468 - 1234 = 1234 >= 1234
1234 - 1234 = 0 < 1234


151782 = 123400 * 1 + 12340 * 2 + 1234 * 3 + 0
151782 / 1234 = 123
151782 % 1234 = 0

```

Another example, 5079 / 61.

```
5079 < 6100

5079 - 610 = 4469 >= 610
... (subtract 610 for 6 times)
809 - 610 = 199 < 610

199 - 61 = 138 >= 61
138 - 61 = 77 >= 61
77 - 61 = 16 < 61


5079 = 610 * 8 + 61 * 3 + 16
5079 / 61 = 83
5079 % 61 = 16
```

## Exponent & Factorial

The algorithms for exponent and factorial in bnc are not special at all -- they are heavily based on multiplication.

```
23^15 = (23^5)^3 = (23 * 23 * 23 * 23 * 23)^3 = 6436343^3 = 6436343 * 6436343 * 6436343 = 266635235464391245607

20! = 1 * 2 * ... * 19 * 20 = 2432902008176640000
```

You can see that there is a little trick to avoid doing some repetitive calculations in bnc's exponent. But for factorial, bnc has to multiply every number one by one.


## Test

If you want to check if bnc actually works, you may run the following commands on your terminal (on macOS):

**Addition Test**
- make test1

**Subtraction Test**
- make test2

**Mulitiplication Test**
- make test3

**Division Test**
- make test4

**Modulo Test**
- make test5

**Exponent & Factorial Test**
- make test6

**Mixed Operation Test**
- make test7

**Error Test**
- make test8

All these tests are in the directory 'tests' in root directory of the repository. Feel free to modify them and play around.

### Enjoy!
