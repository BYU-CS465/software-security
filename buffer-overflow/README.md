# Buffer overflow attacks

This code illustrates a buffer overflow attack. The program in
`stack-overflow.cc` uses `strcpy()` without checking the length of a
user-supplied string. This allows an attacker to overwrite the return address
that is on the stack.

For this example, the goal is to write a new return address on the stack, one
that points to the `win()` function, which would otherwise not be called.

The code includes a `Dockerfile` so that you can compile the code with stack
protection turned off (this disables stack canaries) and run 32-bit code on a
64-bit machine. To use the Docker container:

- `make docker` -- makes the Docker container
- `make login` -- execute a shell in the Docker container
- `make` -- compile the code

To help with the exploit, the code also includes `exploit.py`, and the Docker
container includes the Python modules necessary to run the code. This code
prints out a variable number of `A's` and then an address.

You can run:

```
python3 exploit.py > output.bin
./stack < output.bin
```

to try to get the right address on the stack. To help you find the right
address, use `gdb` from inside the Docker container and the `disassemble`
command, e.g. `disassemble win`.
