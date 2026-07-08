# Problem 0 v1
0000: All persons are either knights or knaves.

0001: Knights only tell the truth.

0002: Knaves only lie. 

0003: Person's A and B say the following sentances:

000300:   A: B is a knight

000301:   B: I am not a knight

0004: Is A a knight?

To solve this problem, we can start be representing it's truth table:


| A | B | {T, F, C} |
|---|---|-----------|
| T | T |           |
| T | F |           |
| F | T |           |
| T | T |           |


To solve this problem I will begin by translating each statement into a *formal language*.

This will allow us to remove ambiguity and solve the problem independent independently of it's interpretation like a math problem.

### Formulation of the problem                      

0000  All persons are either knights or knaves.

0100  `(:A x (v (INCL x Kn0) (INCL x Kn1)))`

0800 For all **x**, **x** is included in the set of *knights*' or **x** is inlcluded in the set of *knaves*. 


0001  Knights only tell the truth

0101 `(:A x (=> (INCL x Kn0) (= x T)))`

0801 For all **x**, '**x**' is included in the set of knights' implies '**x** is **true**'.


0002  Knaves only lie

0102 `(:A x (=> (INCL x Kn1) (= x F)))`

0802 For all **x**, '**x** is included in the set of knaves' implies '**x** is **false**'.


000300 A: B is a knight

010300 `(= A (INCL B Kn0))`

080300 **A** is equal to the statement, '**B** is included in the set of *knights*'.


000301 B: I am not a knight

010301 `(= B (~ (INCL B Kn0))`

080300 **B** is equal to the statement, 'It is not the case, that B is included in the set of *knights*'.


## Rule Set 0
0200: `(:A x (^ (=> (= x F) (~x)) (=> (~x) (= x F)))`

0300:  For all **x**, "**x** is false" implies the "negation of **x**".

0201: `(:A x (^ (=> x (= x T)) (=> (= x T) x))`

0301: For all **x**, "**x** implies '**x** is **true**'" and "'**x** is True' implies **x**".  

0202: `(:A [A, B] (=> (^ (= A T) (= B T)) (^ A B))`

0302: For all pairs, **A B**, "'**A** is true' and '**B** is true' implies "**A** and **B**"". 

0203: `(:A (: [a, b, c] (=> (^ (= a b) (= b c)) (= a c))))`

0303: For all triplets, **a b c**, "'**a** is equal to **b**' and '**b** is equal to **c**' implies '**a** is equal to **c**'"

0204: `(:A (: [a, b, c] (=> (=> a b) (=> b c))) (=> a c))`

0304: For all triplets, **a, b, c**, "'**a** implies **b**' and '**b** implies **c**' implies '**a** implies **c**'".

0205: `(:A (: [a, b] (=> a b)) (=> (= a T) (= b T) ) )`

0305: For all pairs, **a, b**, such that: "**a** implies **b**", "'**a** is **true**', implies '**b** is **true**'".

0206: `(:A (: [a, b, c] (^ (= a b) (=> b c))) (=> a c))`

0306: For all triplets, **a, b, c**, such that: "'the statement **a** is equal to the statement **b**' and '**b** implies **c**'" implies "**a** implies **c**". 


#### PROOF 0 (= A T)

0401:  `(= A (INCL B Kn0))`

0501:  **A** is equal to the statement, '**B** is a *knight*'.


0402:  `(= B (~ (INCL B Kn0)))`

0502:  **B** is equal to the statement, 'It is not the case that **B** is included in the set of *knights*' 


0403:  `(=> (= A T) (= (INCL B Kn0) T) )`

0503:  "**A** is **true**" implies "'**B** is included in the set of knights' is **true**"


0404: `(=> (INCL B Kn0) (= B T))`

0504: '**B** is included in the set of *knights*' implies '**B** is **true**'


0405:  `(=> (= B T) (= (~ (INCL B Kn0)) T))`

0505:  "**B** is true" implies: "It is not the case that, '**B** is included in the set of *knights*' is *true*"


0406:  `(=> (= (~ (INCL B Kn0)) T) (~ (INCL B Kn0)))`                        

0506:  "It is not the case that, '**B** is included in the set of *knights*' is **true**" implies "It is not the case that, '**B** is included in the set of *knights*'"


0407:  `(=> A (~ (INCL B Kn0)))`                                                               # 0204

0507:  **A** implies, It is not the case, that **B** is included in the set of *knights*.


0408:  `(=> (= A (INCL B Kn0)) (= (= A (INCL B Kn0) T)) )`                                     # 0201, 0401

0508: "**A** is equal to the statement, '**B** is included in the set of *knights*'" implies "'**A** is equal to the statement, "**B** is included in the set of *knights*"' is **true**".


0409:  `(=> (=> A (~ (INCL B Kn0))) (= (=> A (~ (INCL B Kn0))) T) )`                           # 0201, 0407

0509: "**A** implies 'it is not the case that **B** is not included in the set of *knights*'" implies "'**A** implies "it is not the case that **B** is included in the set of *knights*"' is **true**".


0410:  `(= (=> A (~ (INCL B Kn0))) T)`                                                         # 0205, 0409  

0510: "'**A** implies "it is not the case that **B** is not included in the set of *knights*"' is **true**"



0411: `(= (= A (INCL B Kn0)) T)`                                                               # 0205, 0408

0511: "'**A** is equal to the statement, "**B** is included in the set of *knights*"' is **true**"


0412: `(=> (^ (= A (INCL B Kn0)) (=> A (~ (INCL B Kn0)))) (=> (INCL B Kn0) (~ (INCL B Kn0))))  # 0206` 

0512: "'**A** is equal to the statement, "**B** is included in the set of *knights*"' and '**A** implies "it is not the case that **B** is included in the set of *knights*"'" implies, "'**B** is included in the set of *knights*' implies 'It is not the case that **B** is included in the set of *knights*'"


0413: `(=> (INCL B Kn0) (~ (INCL B Kn0)))`                                                     # CONTRADITION

0513: "'**B** is included in the set of *knights*' implies 'It is not the case that **B** is included in the set of *knights*'"


#### PROOF 1 (^ (= A T) (= B F))
0600: `(= A T)`                                 # GIVEN

0700:  A is true


0601: `(= B F)`                                 # GIVEN

0701: B is false


0602: `(= A (INCL B Kn0))`                      # 0000

0702:  **A** is equal to the statement, '**B** is included in the set of knights'.


0603: `(^ (= A T) (= A (INCL B Kn0)))`          # 0202, 0000, 0602

0703:  **A** is true and **A** is equal to the statement, '**B** is included in the set of knights'.


0604: `(= (INCL B Kn0) T)`                      # 0603, 0202

0704: **B** is included in the set of *knights*" is *true* 


0605: `(=> (= (INCL B Kn0) T) (INCL B Kn0)) )`  # 0201

0705: "'**B** is included in the set of *knights*' is *true*" implies "**B** is included in the set of *knights*"


0606: `(INCL B Kn0)`                            # SEP

0706: "**B** is included in the set of *knights*"


0607: `(=> (INCL B Kn0) (= B T))`               # 0204

0707: "**B** is included in the set of *knights*" implies "**B** is *true*"


0608: `(=> (= B T) (~ (INCL B Kn0)))`           # 0202

0708: "**B** is *true*" implies "It is not the case, '**B** is included in the set of *knights*'" 


0609: `(=> (INCL B Kn0) (~ (INCL B Kn0)))`      # 0203
0709: "**B** is included in the set of *knights*" implies "It is not the case, '**B** is included in the set of *knights*'"                                                                 # CONTRADICTION


CONCLUSION: **A** telling the truth necessitates the *inconsistancy* of the sustem **{A B}**. If **A** is a knight, the system, **{A B}**, is *inconsistant*.

Fortunatley for **{A B}**, **A** has made no statements about it's own knight-hood.


If you're interested in more problems like this, or have questions about either the language or system used to formulate this problem, feel free to contact the author at: 

*johnpetedoe@proton.me* 
