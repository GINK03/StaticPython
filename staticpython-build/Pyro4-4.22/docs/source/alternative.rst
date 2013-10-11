*********************************************
Running on alternative Python implementations
*********************************************

Pyro is written in 100% pure Python which -theoretically- enables it to be used with
any compatible Python implementation.
There are a few gotchas however.

.. note::
   If possible please use the most recent version available of the Python implementation.


Jython
------
.. sidebar:: Jython

  `Jython <http://jython.org>`_ is a Python implementation running on the Java virtual machine.

- You'll need to use Jython 2.7 or newer (2.5 is no longer supported by Pyro)
- The multiplexing server type (select/poll-based server) is not reliable on Jython.
  You can only use the threadpool server type.
- You cannot use the ``other`` parameter to the requestloop of a Threadpool server.
  The workaround is to spawn a separate thread for each socket that you need to listen to.
  (The name server does this for the broadcast server, if it detects that it is running on Jython)

IronPython
----------
.. sidebar:: IronPython

  `IronPython <http://ironpython.net>`_ is a Python implementation running on the .NET virtual machine.

- Pyro requires the :kbd:`zlib` module, which is not included in older IronPython versions. IronPython 2.7 includes it by default.
  If you need to install it manually, get it `from the developer <https://bitbucket.org/jdhardy/ironpythonzlib/downloads/>`_.

- IronPython cannot properly serialize exception objects, which could lead to problems when dealing with
  Pyro's enhanced tracebacks. For now, Pyro contains a workaround for this IronPython `bug <http://ironpython.codeplex.com/workitem/30805>`_.

Pypy
----
.. sidebar:: Pypy

  `Pypy <http://pypy.org>`_ is a Python implementation written in Python itself, and it usually
  is quite a lot faster than the default implementation because it has a :abbr:`JIT (Just in time)`-compiler.

I haven't used Pypy much let alone with Pyro, but it seems that at least the recent builds (1.9 and newer)
of Pypy work fine with Pyro.

