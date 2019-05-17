# Simon-Tatham-s-Twiddle-3x3
C file

## I made this file for my AI class,basically any input you give to the programm it's going to solve it
### Algorithm is: 
-First and Second row numbers get to their positions:
- 1-2-3
- 4-5-6
- x-x-x

-The remaining last row with the 'x-x-x' is : 7-8-9 with any variations (8-9-7,9-7-8,....)

-Made an algorithm,which always turn this last row to a position, where it can be done with alg1,
without turning the first 2 rows in bad position.

-Probably not the fastest way to solve the puzzle, but it works

-algorithm:
1. alg:
7 9 8 --> 9 8 7 --> 8 7 9 --> alg2 --> 9 7 8

-variations: (right : 7 8 9)
7 9 8 done
8 7 9 done
8 9 7 ->  9 7 8 with algorithm
9 7 8 done 
9 8 7 done 
