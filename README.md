# RPn algorithm and easy calculator

Edsger Dijkstra algorithm for Reverse Polish notation (Postfix notation).

Implemented basic operations such as
 - a plus         (+)
 - minus          (-)
 - multiplication (\*)
 - division       (/)
 - exponentiation (^)

# Compilation and launch

Just use the g++ compiler
```sh
$ g++ code.cpp -o app.out
$ ./app.out
```
# About RPn

Reverse Polish notation (RPN), also known as Polish postfix notation or simply postfix notation, is a mathematical notation in which operators follow their operands, in contrast to Polish notation (PN), in which operators precede their operands.

 - Example:

```sh
infix:  ((15 ÷ (7 − (1 + 1))) × 3) − (2 + (1 + 1))
postfix: 15 7 1 1 + − ÷ 3 × 2 1 1 + + −
```

More info on [Wiki](https://en.wikipedia.org/wiki/Reverse_Polish_notation).
