Configure clangd
================
Configuring :term:`clangd` for use with the :term:`extension` consists of two steps:

* Creating a :term:`compile_commands.json` file
* Creating a :term:`clangd` configuration file

Create Compile Commands
^^^^^^^^^^^^^^^^^^^^^^^
.. include:: /share/stubs/generate_compile_commands.rst

Create Configuration
^^^^^^^^^^^^^^^^^^^^
Create a file name ``.clangd`` in the top level of the :term:`template` directory.  :term:`CMake` creates the
:term:`compile commands` file in the :term:`build directory`.  For :term:`clangd` to see this file we have to set the
value of the ``CompilationDatabase`` key to point to the :term:`build directory`.

Also if plan to use the ``# pargma once`` directive you will have to remove it from consideration by :term:`clangd`.
Add the following to the ``.clangd`` file.

.. code-block:: ini

   CompileFlags:
      # Stop clangd from complaining about `#pragma once`
      Remove: [-fno-gnu-unique]
      # set to cmake build directory
      CompilationDatabase: cmake-build/


