:topic: Terms

Glossary
________

CMake
=====
Definition of terms used in regards to the CMake build system.

.. glossary::
   :sorted:

   cmake
   CMake
       CMake is a cross-platform, open-source make system. CMake is used to
       control the software compilation process using simple
       platform-independent and compiler-independent configuration files.
       See `CMake docs <CMake_>`__ for more information.

   generator
   Generator
       A CMake Generator is responsible for writing the input files for the native build system.
       See `CMake Generator Docs <CMake generator_>`__ for more information.

   variable
       Variables are the basic unit of storage in the CMake Language. Their values are always of string type, though some commands may interpret the strings as values of other types. The set() and unset() commands explicitly set or unset a variable.
       See `CMake variable`_ and `CMake variables`_ for more information.

   CMAKE_EXPORT_COMPILE_COMMANDS
       Enable/Disable output of compile commands during generation.
       If enabled, generates a compile_commands.json file containing the exact compiler calls for all translation units of the project in machine-readable form.
       See `CMAKE_EXPORT_COMPILE_COMMANDS`_ for more information.

.. include:: ./share/links.rst