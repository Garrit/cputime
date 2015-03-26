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

    make
    sudo make install

...will compile the project and install the `cputime` binary to
`/usr/local/bin/cputime`.

Conversely, the `uninstall` Make target will attempt to remove the binary.

Running
-------

To evalate the execution time of a program with `cputime`, give the path to the
program and its arguments as arguments to `cputime`. For example, to run a
program `/bin/foo` with the argument `bar`, run

    cputime /bin/foo bar

The execution time of `/bin/foo` in milliseconds will be the last line of
output to `stdout`.