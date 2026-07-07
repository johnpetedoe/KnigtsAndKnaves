# Problem 0 v1
0000 All persons are either knights or knaves.

0001 Knights only tell the truth.

0002 Knaves only lie. 

0003 Person's A and B say the following sentances:

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
0300  For all x, "x is false" implies the "negation of x".

0201 (=> [A, B] (^ A B))
0202 (=> (^ (= a b) (= b c)) (= a c))
0203 ()
## PROOF 0 (= A T)

# PROOF 0 (= A T)
0400 (=> A (~ (INCL B Kn0)))
0401 (= A (INCL B Kn0))
0402 (=> (^ (=> A (~(INCL B Kn0))) (= A (INCL B Kn0))) (=> (INC B Kn0) (~(INCL B Kn0))) )
0403 (=> (INCL B Kn0) (~ (INCL B Kn0))) # SEP
                                        # CONTRADICTION
                                        # THE SYSTEM {A B} is INCONSISTANT
# PROOF 1 (^ (= A T) (= B F))
0600 (= A T)                            # GIVEN
0601 (= B F)                            # GIVEN
0602 (= A (INCL B Kn0))                 # 0000
0603 (^ (= A T) (= A (INCL B Kn0)))     # 0201, 0000, 0602
0604 (= (INCL B Kn0) T)                 # 0603, 0202
0605 (=> (= (INCL B Kn0) T) (INCL B Kn0)) )
