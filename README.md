# Bistro-nomalloc

A fresh take on Epitech's "Bistromathique" project, a mythical calculator working on numbers of unlimited length.

The original had a few specific constraints, like reading from STDIN, supporting any characters for base/operands,... None of that here.

Here, I tried another constraint: no malloc.

# No malloc?

Actually, no allocations of any kind. No cheating with buffers on the stack, or other "tricks".

The only trick is doing everything within ARGV[1].

# Features
Current features:

- [x] Parentheses and priority
- [x] Multiplication
- [ ] Division / Modulo
- [ ] Substraction
- [x] Addition
- [ ] Controlled debug statements

# Usage

```shell
$ make
$ ./bistromathique "(1+2+3)*4"
24
```
