# Static and Circular Queue
  A small and simple Circular queue for embedded systems - with error safe code and no dynamic allocation.

  A circular queue is just a neat use of the '%' (Modulo) operator to negate the use of memory reordering and moving.
I decided to make this for beginners and professionals alike - The queue is small, easy to understand, safe, and static.
It has helpful return values for it's functions that you can use to debug your program, and an easy interface as well.

  This class is simple, easy to understand, and pretty much memory efficient, since you are only passing elements by value
when you are pulling them out of the queue, and once an element is inserted, it is not moved around any more. :)

  Here ya are, if you want to use a queue, and cant bother to write it yourself, or dont want the overhead of the C++
<queue> header.
