# Problem 0
0000 All persons are either knights or knaves.
0001 Knights only tell the truth.
0002 Knaves only lie. 

0003   Person's A and B say the following sentances:
000300   A: B is a knight
000301   B: I am not a knight

0004 Is A a knight?

To solve this problem, we can start be representing it's truth table:

| A | B | {T, F, C} |
|---|---|-----------|
| T | T |           |
| T | F |           |
| F | T |           |
| T | T |           |

To solve this problem I will begin by translating each statement into a *formal language*.

This will allow us to remove ambiguity and solve the problem independent independently of it's interpretation like a math problem.

## Formulation of the problem                        # Follow up on grammar defs and formulation
0000  All persons are either knights or knaves.      # it may not be appropriate to call these persons
0100  `(:A (:x (v (INCL x Kn0) (INCL x Kn1))))`

0001  Knights only tell the truth
0101 `(:A x (=> (INCLD x Kn0) (= x T)))`

0002  Knaves only lie
0102 `(:A x (=> (INCLD x Kn1) (= x F)))`

000300 A: B is a knight
010300 (= A (INCLD B Kn0))

000301 B: I am not a knight
010301 (= B (~ (= B Kn0))

## Rules
0200 (:A x (=> (= x F) (~x)))
0201 (= 
020
