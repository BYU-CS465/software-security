# Buffer overflow attacks

This code illustrates a buffer overflow attack. The program in
`stack-overflow.cc` uses `strcpy()` without checking the length of a
user-supplied string. This allows an attacker to overwrite the return address
that is on the stack.

For this example, the goal is to write a new return address on the stack, one
that points to the `win()` function, which would otherwise not be called.

The Makefile compiles the code with stack protection turned off. To
compile the code:

- `make` -- compile the code

## Running Python exploit script

To help with the exploit, the code also includes `exploit.py`. This code
prints out a variable number of `A's` and then an address.

To get started, create a virtual environment and install `pwn`:

```
python3 -m venv .venv
source .venv/bin/activate
pip install pwn
```

You can then run:

```
python exploit.py > output.bin
./stack < output.bin
```

to try to get the right address on the stack. To help you find the right
address, use `gdb` and the `disassemble`
command, e.g. `disassemble win`.



