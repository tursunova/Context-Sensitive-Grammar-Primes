# Context Sensitive Grammar For Prime Numbers
## Code hint: just run 'main.cpp'
### Non-terminals: (S), (Q), (a), (b), (a+), (b+), (-#), (a-), (b-), (a*), (b*), (b0), (0c), (a.), (b.), (.c)
### Terminals: (#), (t)
### Rules:
1.  (S) -> (a)(Q)
2.  (Q) -> (b)(Q)
3.  (Q) -> (b+)
4.  (b+)(#) -> (b*)(#)
5.  (b)(b*) -> (b*)(c)
6.  (a)(b*) -> (a*)(a-)
7.  (a)(a*) ->(a*)(a-)
8.  (#)(a*) -> (#)(a+)
9.  (a-)(a) -> (a)(a-)
10. (a-)(#) -> (a)(-#)
11. (b-)(b) -> (b)(b-)
12. (a-)(b) -> (a)(b-)
13. (b-)(#) -> (b)(-#)
14. (b-)(c) -> (b)(b)
15. (a-)(c) -> (a)(b)
16. (-#) ->  (#)
17. (a+)(a) -> (a)(a+)
18. (a+)(b) -> (a)(b+)
19. (b+)(b) -> (b)(b+)
20. (b+)(c) -> (b)(b0)
21. (a+)(c) -> (a)(b0)
22. (b0)(c) -> (b)(0c)
23. (0c) -> (.c)
24. (b)(.c) -> (b.)(c)
25. (b)(b.) -> (b.)(b)
26. (a)(b.) -> (a.)(b)
27. (a.) -> (a*)
28. (a+)(#) -> (t)(#)
29. (a)(t) -> (t)(t)
