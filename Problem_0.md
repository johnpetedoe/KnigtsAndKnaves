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


## Rule Set 0
0200 (:A x (^ (=> (= x F) (~x)) (=> (~x) (= x F)))
0300  For all *x*, "*x* is false" implies the "negation of *x*".

0201 (:A x (^ (=> x (= x T)) (=> (= x T) x))
0301 For all *x*, "*x* implies '*x* is *true*'" and "'*x* is True' implies *x*".  

0202 (:A [A, B] (=> (^ (= A T) (= B T)) (^ A B))
0302 For all pairs, *A B*, "'*A* is true' and '*B* is true' implies "*A* and *B*"". 

0203 (:A (: [a, b, c] (=> (^ (= a b) (= b c)) (= a c))))
0303 For all triplets, *a b c*, "'a is equal to b' and 'b is equal to c' implies 'a is equal to c'"

0204 (:A (: [a, b, c] (=> (=> a b) (=> b c))) (=> a c))
0201 For all triplets, *a b c*, "'a implies b' and 'b implies c' implies 'a implies c'".

# PROOF 0 (= A T)
0400 (=> A (~ (INCL B Kn0)))
0500

0401 (= A (INCL B Kn0))

0402 (=> (^ (=> A (~(INCL B Kn0))) (= A (INCL B Kn0))) (=> (INC B Kn0) (~(INCL B Kn0))) )

0403 (=> (INCL B Kn0) (~ (INCL B Kn0)))  # SEP
                                         # CONTRADICTION

# PROOF 1 (^ (= A T) (= B F))
0600 (= A T)                                 # GIVEN

0601 (= B F)                                 # GIVEN

0602 (= A (INCL B Kn0))                      # 0000

0603 (^ (= A T) (= A (INCL B Kn0)))          # 0202, 0000, 0602

0604 (= (INCL B Kn0) T)                      # 0603, 0202

0605 (=> (= (INCL B Kn0) T) (INCL B Kn0)) )  # 

0606 (INCL B Kn0)                            # SEP

0607 (=> (INCL B Kn0) (= B T))               # 0204

0608 (=> (= B T) (~ (INCL B Kn0)))           # 0202

0609 (=> (INCL B Kn0) (~ (INCL B Kn0)))      # 0203
                                             # CONTRADICTION

CONCLUSION: **A** telling the truth necessitates the *inconsistancy* of the sustem **{A B}**. If A is a knight, the system, **{A B}**, is *inconsistant*.

Fortunatley for **{A B}**, **A** has made no statements about it's own knight-hood.

If you're interested in more problems like this, or have questions about either the language or system used to formulate this problem, feel free to contact the author at: 

*johnpetedoe@proton.me* 

