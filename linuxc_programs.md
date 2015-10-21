GNU/linux Statements
====================

## Overview

# External Function

Ensure yourself you are able to write and compile a program with an external library written by you. Force yourserlf to use a Makefile.

Fork
----

Write a program that writes 20 names in a file.
Use a function _spawn_ to fork a process that writes 10 names in a file.

```bash
  the_owl@eniac$ ./first_names <filename>
```

Spawn it again when the SIGCHLD is first received.

Show the content of  the file using _fopen_ and _fprintf_ when the second
process is done.

