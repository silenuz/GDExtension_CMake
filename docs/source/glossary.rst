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

   option
       A command used in scripts to define user-configurable settings, as well as the command-line flags used to pass these settings during the build process.
       See `CMake options`_ for more information.

GDExtension
===========
Definition of terms specific to GDExtension development

.. glossary::
   :sorted:

   godot cpp template
   godot-cpp-template
       Quickstart template for GDExtension development with Godot and C++
       `Github Repository <Godot CPP Template_>`__


   GDExtension
       GDExtension is a Godot-specific technology that lets the engine interact with native shared libraries at runtime. You can use it to run native code without compiling it with the engine.
       See `GDExtension system`_ for more information.

   gdextension file
   .gdextension file
       The .gdextension file in your project contains the instructions for how to load the GDExtension. The instructions are separated into specific sections.
       See `.gdextension`_ for more information

   Godot
       free and open source community-driven 2D and 3D game engine
       See `Godot`_ for more information

   Godot CPP Bindings
   godot-cpp
       C++ bindings for the Godot script API
       `Github Repository <Godot CPP Bindings_>`__

   extension documentation
   adding documentation
       The GDExtension documentation system works in a similar manner to the built-in engine documentation: It uses XML files (one per class) to document the exposed constructors, properties, methods, constants, signals, and more.
       See `GDExtension Documentation`_ for more information





.. include:: ./share/links.rst