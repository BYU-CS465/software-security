# x32 buffer overflow attack with shellcode

This code illustrates a buffer overflow attack with shellcode.

The program in `stack-overflow.cc` uses `strcpy()` without checking the length of a
user-supplied string. This allows an attacker to overwrite the return address
that is on the stack.

For this example, the goal is to execute shellcode. The provided shellcode will cat /etc/passwd
and is taken from: https://www.exploit-db.com/shellcodes/13609

The Makefile compiles the code with stack protection turned off. To
compile the code:

- `make` -- compile the code

##

## Running Python exploit script

To help with the exploit, the code also includes `exploit.py`. This code
creates payload that can be used for the exploit.

To get started, create a virtual environment:

```
python3 -m venv .venv
source .venv/bin/activate
```

You can then run:

```
python exploit.py > payload.txt
./stack < payload.txt
```

to run the attack and execute the shellcode.




