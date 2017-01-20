# SwigAutomation

This script is built on [SWIG](https://github.com/swig/swig) which is an
acronym for **S**implified **W**rapper and **I**nterface **G**enerator. In
the creators' own words:

    SWIG is a compiler that integrates C and C++ with languages including
    Perl, Python, Tcl, Ruby, PHP, Java, C#, D, Go, Lua, Octave, R, Scheme
    (Guile, MzScheme/Racket, CHICKEN), Scilab, Ocaml, Modula-3, Common Lisp
    (CLISP, Allegro CL, CFFI, UFFI) and Pike.

This is a standalone script that runs on Python and makes the fantastic ease
of SWIG even easier by autogenerating the necessary files and running all of
the commands needed to build your module... you only need to type one line!

## Getting Started

To use this script, copy it to your bin. I put mine in /usr/local/bin. Be sure
to check the shabang in line 1 and line 66 and change them if necessary. Also,
be sure to change the author in the setup file on line 79. Lastly, you'll
obviously need to have [SWIG](https://github.com/swig/swig) installed.

### Usage

When run, this script will

* Make sure that SWIG is installed
* Check that '#include file.h' is in the source file and / or add it for you
* Creates *file.i*, *file.h* and *setup.py*
* Run swig and build the file (set to build in place)

In essence, you can run everyting with just one line! Here's how it works - 
Consider the provided file *locatevalue.c* It contains a function called
*LocateValue* and is used as

```
double LocateValue(double magic_number, int top, double precision)
```

Then simply cd to the directory with *locatevalue.c* and do

```
$ wrap -f locatevalue -u "double LocateValue(double magic_number, int top, double precision)"
```

If the file were a .cpp (i.e. *locatevalue.cpp*), then simply set the '-c++' flag to *True*

```
$ wrap -f locatevalue -u "double LocateValue(double magic_number, int top, double precision)" -c++ True
```

Check the directory and you should see a number of new files, including *locatvalue.py*. Now
you can import it like any other Python module. In Ipython, I'll load the pure python function 
and the newly wrapped function and compare run times. It looks something like this

```
In [1]: from locatevalue import LocateValue

In [2]: from pylocatevalue import PyLocateValue

In [3]: %timeit LocateValue(1234.5678, 100000, 0.001)
1 loop, best of 3: 370 ms per loop

In [4]: %timeit PyLocateValue(1234.5678, 100000, 0.001)
1 loop, best of 3: 21.9 s per loop

In [5]: 21.9 / .370
Out[5]: 59.189189189189186
```

### Conclusion

Our wrapped function is around 60x faster than the pure python function. SWIG
is amazing all by itself, this just adds some ease to the process through
autogenerating the necessary documents and ensuring that your files all have
the correct name, your function is defined in the right way and saving time
by only requiring a single line.

