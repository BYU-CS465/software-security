# TOCTOU

This code demonstrates a TOCTOU (time of check, time of use) vulnerability.

## Requirements

You must have Docker Desktop installed

## Compile

- `make docker` -- to build the docker container
- `make login` -- to login to the docker container
- `make` -- to build the code AFTER logging into the docker container

While logged in to the Docker container, you can also use gdb to inspect the
code.

## Threads Example

The code in `threads-example` shows how threads work.

## Inventory

This code simulates a store with a single product and a stream of customers that
want to buy the product. Each customer:

- checks the inventory (imagine the customer loads a page with information about
  the product, which also shows how many items are in stock),
- pauses for a random amount of time (imagine the customer needs to read the
  page), and then
- purchases the product, which requires decrementing the inventory.

Customers are implemented using threads.

Run:

```
./inventory [number]
```

to run the program with a given number of customers.

The program starts with 10 products in stock, so try running with <= 10
customers, and with more customers. Because of a TOCTOU vulnerability, running
with more than 10 customers will cause the store to have a negative number of
books on hand, even though each customer checks if the inventory is > 0 before
making a purchase.

Run:

```
./inventory-fixed [number]
```

to run a fixed version of the program. This version uses a mutex to ensure that
the TOCTOU vulnerability no longer exists.

The code in `inventory-monitor` shows a monitor-like way of organizing mutexes.
