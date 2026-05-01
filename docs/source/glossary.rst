:topic: Terms

Glossary
________

CMake
=====
Definition of terms used in regards to the CMake build system.

.. glossary::
   :sorted:

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
       Variables are the basic unit of storage in the CMake Language. Their values are always of string type, though some commands may interpret the strings as values of other types.
       The set() and unset() commands explicitly set or unset a variable.

       See `CMake variable`_ ,`CMake variables`_ , and `CMake build variables`_ for more information.

   build variable
        Software projects often require variables to be set on the command line when invoking :term:`CMake`.  Other project-specific variables may be available to control builds,
        such as enabling or disabling components of the project.
        Other project-specific variables may be available to control builds, such as enabling or disabling components of the project.

        See `CMake build variables`_ for more information.

   build configuration
        Configurations determine specifications for a certain type of build, such as Release or Debug.
        The way this is specified depends on the type of :term:`generator` being used.

        See `CMake build configuration`_ for more information

   CMAKE_EXPORT_COMPILE_COMMANDS
       Enable/Disable output of :term:`compile commands` during generation.
       If enabled, generates a :term:`compile_commands.json` file containing the exact compiler calls for all translation units of the project in machine-readable form.

       See `CMAKE_EXPORT_COMPILE_COMMANDS`_ for more information.

   option
       A command used in scripts to define user-configurable settings, as well as the command-line flags used to pass these settings during the build process.

       See `CMake options`_ for more information.

   CMAKE_BINARY_DIR
   binary directory
   build directory
       In CMake, the build directory, also known as the binary directory, is where all generated files are stored.

       See `CMAKE_BINARY_DIR`_ for more information.

   target platform
       The target platform is the computer system the compiled :term:`extension` is being built for.

       Each potential target platform for the :term:`extension` has a folder in the :term:`project`'s bin directory.

   host platform
       The host platform is the computer system that is compiling the binary output.  During native compilation the host
       platform is the same as the target platform.

   cmake target
       Each executable and library described in the :term:`CMake` files is a build target, and the buildsystem may
       describe custom targets, either for internal use, or for user consumption,  for example to create documentation.

       :term:`CMake` provides some built in targets for all build systems providing :term:`CMake` files

       * :term:`all <target all>`

       * :term:`help <target help>`

       * :term:`clean <target clean>`

       * :term:`test <target test>`

       * :term:`install <target install>`

       * :term:`package <target package>`

       * :term:`package_source <target package_source>`

   target all
       The default :term:`target` used by Makefile :term:`Generators <Generator>` and :term:`Ninja` :term:`Generators <Generator>`. Builds all
       :term:`targets <cmake target>` in the buildsystem, except those which are excluded by their EXCLUDE_FROM_ALL target property or
       EXCLUDE_FROM_ALL directory property. The name ALL_BUILD is used for this purpose for the Xcode and Visual Studio Generators.

   target help
       Lists the :term:`targets <cmake target>` available for build. This :term:`target <cmake target>` is available when using the
       Makefile :term:`Generators <Generator>` or :term:`Ninja` :term:`Generators <Generator>`, and the exact output is tool-specific.

   target clean
       Delete built object files and other output files. The Makefile :term:`Generators <Generator>` create a clean :term:`target <cmake target>` per directory,
       so that an individual directory can be cleaned. The :term:`Ninja` tool provides its own granular -t clean system.

   target test
       Runs tests. This :term:`target <cmake target>` is only automatically available if the :term:`CMake` files provide CTest-based tests.

       See also `Running Tests <CMake tests_>`__.

   target install
       Installs the software. This :term:`target <cmake target>` is only automatically available if the software defines install
       rules with the install() command.

       See also `CMake install`_

   target package
       Creates a binary package. This :term:`target <cmake target>` is only automatically available if the :term:`CMake` files provide CPack-based packages.

   target package_source
       Creates a source package. This :term:`target <cmake target>` is only automatically available if the :term:`CMake` files provide CPack-based packages.


GDExtension
===========
Definition of terms specific to GDExtension development

.. glossary::
   :sorted:

   template
   godot-cpp-template
       Quickstart template for GDExtension development with Godot and C++

       `Github Repository <Godot CPP Template_>`__

   extension
   GDExtension
       GDExtension is a Godot-specific technology that lets the engine interact with native shared libraries at runtime. You can use it to run native code without compiling it with the engine.
       See `GDExtension system`_ for more information.

   gdextension file
   .gdextension file
       The .gdextension file in your project contains the instructions for how to load the :term:`GDExtension`. The instructions are separated into specific sections.

       See `.gdextension`_ for more information

   Godot
       free and open source community-driven 2D and 3D game engine

       See `Godot`_ for more information

   godot cpp
   godot-cpp
       C++ bindings for the Godot script API

       `Github Repository <Godot CPP Bindings_>`__

   extension documentation
   adding documentation
       The :term:`GDExtension` documentation system works in a similar manner to the built-in engine documentation: It uses XML files (one per class) to document the exposed constructors, properties, methods, constants, signals, and more.

       See `GDExtension Documentation`_ for more information


   build profile
   build_profile.json
       A build profile refers to a configuration that controls which parts of the engine API are available or optimized during the compilation of your extension's C++ bindings or the extension itself.


   project
       The example :term:`Godot` project, which in the initial download of the :term:`template` is simply called project.
       The bin sub directory contains the :term:`.gdextension file` as well as a sub directory for each :term:`target platform`.
       By default the compiled library for the :term:`extension` will be found in the folder named for the :term:`target platform`.

       The walkthrough renames this directory demo.

   target
        A target is usually the name of a file that is generated by a program; examples of targets are executable or object files. A target can also be the name of an action to carry out, such as ‘clean’

   library
        The GDExtension resource type represents a :term:`shared library` which can expand the functionality of the engine

   entry symbol
       Sets the starting address (entry point) for an executable or shared library

       The entry symbol for the :term:`extension` is defined in the configuration section
       of the :term:`.gdextension file`.

   entry point
        A function that specifies a user-defined starting address for an .exe file or DLL.
        By default, the starting address is a function name from the C run-time library.

        .. important::
           The name of the entry point function must be the same as the :term:`entry symbol`

Other
===========
Definition of miscellaneous terms

.. glossary::
   :sorted:

   SCons
       SCons is an Open Source software construction tool. Think of SCons as a cross-platform substitute for the classic Make utility.

       See `SCons`_ for more information

   Ninja
       Ninja is a small build system with a focus on speed. It differs from other build systems in two major respects: it is designed to have its input files generated by a higher-level build system, and it is designed to run builds as fast as possible.

       See `Ninja`_ for more information

   compile commands
   compile_commands.json
        A JSON-formatted compilation database that specifies exactly how each source file in a C or C++ project should be compiled.
        It acts as a standardized "map" that allows external tools—like Language Servers (LSP), linters, and static analyzers—to understand
        your project's structure without needing to execute the entire build system

   clangd
        A :term:`language server` for C++ that works with many editors.

   language server
        A language server is a specialized program that processes programming language-related tasks, like text generation, grammar correction, rephrasing, summarization, data extraction, and more.

        Most modern language servers implement the :term:`Language Server Protocol`

   LSP
   Language Server Protocol
       The Language Server Protocol (LSP) defines the protocol used between an editor or IDE and a language server that provides language features like auto complete, go to definition, find all references etc.

   shared library
       A shared library is a library of executable code that is loaded in memory such that multiple executables (programs and other libraries) can use it at runtime.



.. include:: ./share/links.rst