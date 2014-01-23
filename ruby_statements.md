STATEMENTS
==========

Daemons
-------

###01 First Daemon

Write a program that logs "I'm a daemon doing daemon things" into a tempfile every five seconds.

Use ruby 1.9.2 or above and

```ruby
Process.daemon
```

###02 Fork

Daemonize a program using _Kernel#fork_.


###03 Windows Service

Create a windows service accepting command line arguments register and delete.
With no arguments and when not registered it prints usage.
When initiated it shall watch for the existence of "_C:\WeAreOne.txt_" and if doesn't
exist or is removed it will recreate it with a default content.
