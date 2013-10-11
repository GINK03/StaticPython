***************
Installing Pyro
***************

This chapter will show how to obtain and install Pyro.

Requirements
------------
You need Python 2.6 or newer for Pyro4.
Also see :ref:`should-i-choose-pyro4`.

Pyro is written in 100% pure Python. It works on any recent operating system.

It will default to using the `serpent <https://pypi.python.org/pypi/serpent>`_ serializer so you
will need to install Serpent as well, unless you configure Pyro to use one of the other serializers.

.. note::
    When Pyro is configured to use pickle or marshal as its serialization format, it is required to have the same *major* Python versions
    on your clients and your servers. Otherwise the different parties cannot decipher each others serialized data.
    This means you cannot let Python 2.x talk to Python 3.x with Pyro. However
    it should be fine to have Python 2.6.2 talk to Python 2.7.3 for instance.
    Using one of the implementation independent protocols (serpent or json) will avoid this limitation.


Obtaining and installing Pyro
-----------------------------

Pyro can be found on the Python package index: http://pypi.python.org/pypi/Pyro4/  (package name ``Pyro4``)

You can install it using :command:`pip` or :command:`easy_install`, or download the distribution archive (.tar.gz)
from Pypi and run the ``setup.py`` script from that manually.
Pyro installs as the ``Pyro4`` package with a couple of sub modules that you usually don't have to access directly.
The `serpent <https://pypi.python.org/pypi/serpent>`_ serialization library is installed as a dependency.

.. note::
    Windows users: use one of the suggested tools to install Pyro.
    If you decide to get the distribution archive (.tar.gz) and use that,
    one way to extract it is to use the (free) `7-zip <http://www.7-zip.org>`_ archive utility.

If you want you can also obtain the source directly from Github: https://github.com/irmen/Pyro4


Stuff you get in the distribution archive
-----------------------------------------
If you decide to download the distribution (.tar.gz) you have a bunch of extras over installing Pyro directly.
It contains:

  docs/
    the Sphinx/RST sources for this manual
  examples/
    dozens of examples that demonstrate various Pyro features (highly recommended)
  tests/
    all unit tests
  src/
    The library source code (only this part is installed if you install the ``Pyro4`` package)
  and a couple of other files:
    a setup script and other miscellaneous files such as the license (see :doc:`license`).
