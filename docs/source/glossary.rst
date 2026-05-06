:topic: Terms

.. role:: underline
    :class: underline

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

   CMake cache
   cache
      The CMake cache may be thought of as a configuration file.
      The first time CMake is run on a project, it produces a CMakeCache.txt file in the top directory of the
      build tree. CMake uses this file to store a set of global cache variables, whose values persist across
      multiple runs within a project build tree.

   generator
   Generator
       A CMake Generator is responsible for writing the input files for the native build system.

       See `CMake Generator Docs <CMake generator_>`__ for more information.

   variable
       Variables are the basic unit of storage in the CMake Language. Their values are always of string type, though some commands may interpret the strings as values of other types.
       The set() and unset() commands explicitly set or unset a variable.

       See `CMake variable`_ , `CMake variables`_ , and `CMake build variables`_ for more information.

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
       platform is the target platform.

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

       The libraries section contains the :term:`library` paths for loading the compiled :term:`extension`.  These paths are relative
       to this file.

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

       This is the directory containing the project.godot file.

       The bin sub directory contains the :term:`.gdextension file` as well as a sub directory for each :term:`target platform`.
       By default the compiled library for the :term:`extension` will be found in the folder named for the :term:`target platform`.

       The walkthrough renames this directory :term:`demo`.

   target
        A target is usually the name of a file that is generated by a program; examples of targets are executable or object files. A target can also be the name of an action to carry out, such as ‘clean’

   library
        The GDExtension resource type represents a :term:`shared library` which can expand the functionality of the engine

   entry symbol
       Sets the starting address (entry point) for an executable or shared library,
       by exposing the functionality of the :term:`entry point`.

       The entry symbol for the :term:`extension` is defined in the configuration section
       of the :term:`.gdextension file`.

       See `Entry Symbol`_ for more information

   entry point
        A function that specifies a user-defined starting address for an .exe file or DLL.
        By default, the starting address is a function name from the C run-time library.

        See `Entry Point`_ for more information

   entry point function
      When you create a GDExtension, you must define an entry point function, to serve as the :term:`entry point` for the :term:`library`.
      In the :term:`template's<template>` :term:`register_types.cpp` file this function is initially named ``example_library_init``.
      :term:`Godot` calls this function when loading the :term:`library`.

      Inside this function you use :term:`GDExtensionBinding::InitObject` to register two critical callbacks:

      * An initializer, by using :term:`register_initializer` to register the :term:`initialization function`
      * A terminator, by using :term:`register_terminator` to register the

       .. important::
          The name of the entry point function must be the same as the name of the :term:`entry symbol`

   register_types.cpp
      Location: ``src`` directory

      A core file in :term:`GDExtension` :term:`template`, implementations here are used to initialize and register C++ classes with the
      :term:`Godot` engine.  It contains the :term:`entry point` for the :term:`extension`, and has three key functions:

      * :term:`Entry Point Function <entry point function>`
      * An :term:`Initialization Function`
      * A :term:`Deinitialization Function`

   Initialization Function
   initialization function
          Name in :term:`template`: ``initialize_gdextension_types``.

          Found in :term:`register_types.cpp` this function is registered as a callback function in the :term:`entry point function`
          using :term:`register_initializer`.

          Godot calls this initialization function across four levels:

          * CORE: Post-engine core.
          * SERVERS: Post-servers (physics/rendering).
          * SCENE: Registration for nodes and objects.
          * EDITOR: Editor-specific plugins.

          Classes are registered here with the :term:`Godot` :term:`ClassDB` using "``GDREGISTER_CLASS(ClassName)``",
          specifically using the SCENE level to make them available in the editor.

   Deinitialization Function
   deinitialization function
      Name in :term:`template`: ``uninitialize_gdextension_types``.

      Found in :term:`register_types.cpp` this function is registered as a callback function in the :term:`entry point function`
      using :term:`register_terminator`.  This function cleans up any memory or resources allocated during initialization.

      * Purpose:  It acts as the counterpart to the :term:`initialization function`, ensuring resources allocated are properly freed to avoid memory leaks or crashes.
      * Signature: It usually takes ModuleInitializationLevel p_level as an argument to determine if it should clean up core, editor, or scene types

   ClassDB
      In the :term:`Godot` Engine, ClassDB is a static class that acts as a central repository for all available engine classes.
      It provides access to metadata stored for every class registered within the engine, allowing you to inspect
      properties, methods, and signals at runtime.

      **Key Functions:**

      * Instantiating Objects:
         You can create a new instance of a built-in class by its name using ClassDB.instantiate("ClassName")

      * Querying Class Info:
         You can check if a class exists, find its parent class, or list all classes that inherit from a specific type (e.g., all types of Node).

      * Metadata Inspection:
         It allows you to retrieve a list of properties, methods, and signals for any given class name.

      * Type Checking:
         You can verify if a class inherits from another (e.g., is_parent_class)

      .. important::
         When developing a C++ module or :term:`GDExtension`, ClassDB must be used to manually register custom classes
         and bind their methods in order to expose them to the  :term:`Godot` engine.

      See `ClassDB`_ for more information.

   register_initializer
      In a :term:`GDExtension`, register_initializer is a method used within the :term:`library's<library>`
      :term:`entry point function` to define a callback function that :term:`Godot` calls when initializing the
      :term:`extension`.

      .. literalinclude:: share/entry_point_function.c
         :language: c
         :caption: register_initializer
         :emphasize-lines: 7

   register_terminator
      In a :term:`GDExtension`, register_terminator is a method used within the :term:`library's<library>`
      :term:`entry point function` to define a callback function that :term:`Godot` calls when unloading the
      :term:`extension`.

      .. literalinclude:: share/entry_point_function.c
         :language: c
         :caption: register_terminator
         :emphasize-lines: 8

   GDExtensionBinding::InitObject
      A key component in the :term:`godot cpp` bindings, it is used to initialize the :term:`library`. It acts as a
      registration handler within the :term:`entry point function`, setting up initialization and termination
      routines.

      It is used within the :term:`entry point function` of the :term:`library` to register
      the :term:`initialization function` for callbacks using :term:`register_initializer` and the
      :term:`deinitialization function` for callbacks using :term:`register_terminator`.

   GDCLASS
      GDCLASS is a fundamental macro used in C++ header files to register a custom class so the engine can
      interact with it. It serves as a bridge, enabling signal, property, and method binding for use in
      GDScript and the :term:`Godot` Editor.

      * Core Requirements:
         Single Inheritance: The class must inherit from a :term:`Godot` built in class
         (like Node, Sprite2D, or Resource).  :term:`Godot` does not support multiple inheritance for
         :term:`GDExtension` classes.
      * Macro Placement:
         The macro must be placed at the very beginning of the class body, usually under the public access modifier.
      * Required Function:
         You must declare a ``protected static void _bind_methods()`` function in your class header.
         This is where you register the class's methods, properties, and signals with the :term:`Godot` :term:`ClassDB`.

      .. admonition:: GDCLASS header file example
         :class: dropdown

         .. literalinclude:: share/gdclass_example.h
            :language: cpp
            :caption: GDCLASS example
            :emphasize-lines: 8,12

Other
=====
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


Walkthrough
===========
Definition of terms specific to the walkthrough

.. glossary::
   :sorted:

   mycooldemo
      In the walkthrough mycooldemo refers to both the directory name where the :term:`template` is cloned/downloaded to,
      as well as the :term:`CMake` project name for the :term:`extension` as a whole.

   demo
      This is the name the walkthrough gives the :term:`project` directory.

   cooldemo
      This is the name the walkthrough gives the :term:`library` for the compiled :term:`extension`



.. include:: ./share/links.rst