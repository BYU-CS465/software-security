# Heap overflow attacks

This code illustrates a heap overflow attack. The programs in `heap-overflow.cc`
and `heap-overflow2.cc` use `strcpy()` without checking the length of a
user-supplied string. This allows an attacker to write past the allocated memory
on the heap and potentially corrupt other storage on the heap.

## Changing permissions

The first program, `heap-overflow.cc` stores an integer "role" for the user,
which is set to 1 (the default) for an ordinary user and 0 for an admin. By
overflowing a buffer, you can change the role of a user to admin.

## Changing a funciton pointer

The second program, `heap-overflow2.cc` stores a function pointer on the heap.
By overflowing a buffer, you can change this function pointer so that it points
to the `win()` function. A real exploit could try to point to some more
dangerous code.

## Exploits

To help with the exploits, the code includes `exploit.py`, and the Docker
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
