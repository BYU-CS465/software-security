# Integer Vulnerabilities

This code demonstrates integer vulnerabilities.

## Requirements

You must have Docker Desktop installed

## Compile

- `make docker` -- to build the docker container
- `make login` -- to login to the docker container
- `make` -- to build the code AFTER logging into the docker container

While logged in to the Docker container, you can also use gdb to inspect the
code.

## Rectangular

This code prints out very basic ascii art -- a rectangle filled with one
character. The program asks the user for:

- the width of the rectangle
- the height of the rectangle
- a character

Run:

```
./rectangle
```

Try entering a rectangle with:

- width: 235
- height: 279

Because the width and height are stored as unsigned 16-bit integers, this will
result in a rectangle being allocated that has room for 235 \* 279 = 65565 =
2^16 + 29 = 29 characters. This is an integer overflow bug. Thus if we loop
through all 235 columns and 279 rows, the program will crash when accessing
unallocated memory.

## Waiting List

This code simulates customers buying a book. Initially, the store has 1000
copies of the book available. Each customer checks the number of available
copies and then decrements this by 1. If the resulting inventory is >= 0, then
the customer is able to buy a book. If the inventory is negative, this
represents that customer's spot on the waiting list for the book.

Run:

```
./waiting-list 2000
```

You should see 1000 customers join the waiting list.

Run:

```
./waiting-list 34000
```

You should see the waiting list grow to 2^15 = 32,768 and then wrap around. This
is an integer underflow bug.
