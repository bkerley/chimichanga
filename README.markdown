Welcome to Chimichanga
======================

Chimichanga is a crummy stack based language.  Right now it's
broken to require x86\_64 while I play with bytecode.

How do I compile this?
----------------------

You need these packages:

* make - tested with GNU Make 3.81
* gcc - tested with i686-apple-darwin9-gcc-4.0.1 (GCC) 4.0.1 (Apple Inc. build 5470) (Aspen 5470.3)
* GNU readline - tested with 5.2
* ruby - tested with ruby 1.8.6 (2007-09-23 patchlevel 110) [i686-darwin9.0.0]
* diff - tested with GNU diffutils 2.8.1

Once you have those, you should be able to run `make` and get the
`chimi` binary.  If not, you might have to point your environment
variables or the `Makefile` at the proper include and library
directories.

You mean you don't have an autoconf set up?
-------------------------------------------

Right.  I respect your time too much to make you wait through a
minute of autoconf testing for working `fprintf()` and `strtol()`
implementations.  Running `make test` will tell you if something's
broken.  If it doesn't, please email me the test case.

What are pre2c.rb and init.pre?
-------------------------------

I wanted a nice way to add procs that required a bit more intuition
than I know how to get out of the C preprocessor, and that also made
the finished C easy to inspect.

`pre2c` basically tallies up the dispatch calls, translates the names
into valid C function names, and sticks them all in a function at the
end that's called at startup to load up the procs into the symbol
dictionary.

It also does macro replacement, mostly to make binary operations nice
and short.

That's the crappiest testing framework I've ever seen?
------------------------------------------------------

I'm glad you like it.  Try and keep one test to each line; it makes
finding the failed one easier.

Who do I complain to?
---------------------

Nominally, you can complain to <bkerley@brycekerley.net>

Practically, it's your own fault for using chimichnga instead of one
of these completely fine alternatives (listed in reverse alphabetical
order):

* Postscript (or Ghostscript)
* Forth
* Factor

