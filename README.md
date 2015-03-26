cputime
=======

While the conventional [`time(1)`](http://linux.die.net/man/1/time) is flexible
and highly portable, it can only report CPU time consumed in hundredths of
seconds. In an online judge context, we'd like to be able to measure CPU time
consumed in milliseconds. This simple utility evaluates the user CPU time used
by a process, and prints it out in milliseconds.

Requirements
------------

`cputime` requires a Linux environment for both compilation and execution as it
depends on Linux-specific resource metrics.

Installation
------------

Run `make` from the project directory to compile the project. After
compilation, the `cputime` binary will exist in the root of the project
directory and can be copied to and run from wherever necessary. For system-wide
installations, `/usr/local/bin/cputime` is generally a good place to put it.

Running
-------

To evalate the execution time of a program with `cputime`, give the path to the
program and its arguments as arguments to `cputime`. For example, to run a
program `/bin/foo` with the argument `bar`, run

    cputime /bin/foo bar