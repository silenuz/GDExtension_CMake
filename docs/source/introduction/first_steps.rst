First Steps
-----------
An explanation of the initial steps required to acquire the official
:term:`godot cpp template`
and create a repository from it.  Further instruction follows in regards to cloning the repository, and
building the template's example project.

Clone Repository
================

First log into log in to GitHub, and then go to the `Godot CPP Template`_ and click the green
"Use this template" button at the top of the repository page.

This will let you create a copy of the repository with a clean git history.
Next clone the repository that was just created with the --recursive flag.  For example if the repository that was
created from the template is called mycooldemo:

.. code::

    git clone https://github.com/account/mycooldemo.git --recursive

The :term:`godot cpp template` is organized as follows:

.. list-table::
   :widths: 20 50
   :class: borderless

   * - .. figure:: img/intial_repo_content.png
          :width: 100%

          Initial Repository Content
     - #. bin directory
       #. :term:`extension documentation` for classes in the extension
       #. :term:`godot cpp` bindings for the extension
       #. example :term:`Godot` project
       #. source code for the extension
       #. empty custom build profile
       #. :term:`cmake` configuration file
       #. used by :term:`SCons` to build the library for the extension (not used by cmake)

.. note::
    If the repository was cloned without the ``--recursive`` flag, then the :term:`godot-cpp` directory will be empty.  To remedy
    this open the repository directory in a terminal and execute the following;

    .. code::

        git submodule update --init

Initial Configuration
=====================

After cloning the repository :term:`CMake` has to be configured. Open a terminal in the topmost level of the git project that
was just cloned, for example mycooldemo and execute :term:`cmake` with the :term:`option`'s
listed below:

.. code:: shell

   cmake -S . -B cmake-build-debug -G Ninja

* ``-S`` specifies the source directory as the current directory
* ``-B`` specifies the :term:`build directory` as ``cmake-build-debug``,
    can be referred to as ``${CMAKE_BINARY_DIR}`` in the ``CMakeLists.txt`` file
* ``-G`` specifies the :term:`cmake` :term:`generator` :term:`Ninja`

The :term:`build directory` is specified so that generated files do not clutter the source tree with build
artifacts.

..
    .. note::
        :term:`CMake` doesn't build the code, it generates the files that a build tool uses, in this case the Ninja generator creates
        Ninja build files.

        To see the list of available generators, in a terminal run

        .. code:: shell

            cmake -E capabilities

        and look for the generators array, it will contain the generators available to cmake.

If the :term:`Cmake` :term:`generator` is :term:`Ninja`
or `Makefiles <https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#makefile-generators>`_
you can use the configure target to also generate a :term:`compile_commands.json` in the :term:`build directory`. To do so the
:term:`CMAKE_EXPORT_COMPILE_COMMANDS` :term:`CMake` :term:`variable` is added to the configure command with a value of ``ON``.

.. code:: shell

   cmake -S . -B cmake-build-debug -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON


Initial Build
=============

Once configured the :term:`extension` can be built by specifying a target of build followed by the name
of the :term:`cmake` :term:`build directory`:

.. code:: shell

   cmake --build cmake-build-debug

If the build command worked, you should have a new library file for the
target system in the :term:`Godot` project directory.  The example :term:`Godot` project directory is organized as follows:

.. list-table::
   :widths: 20 50
   :class: borderless

   * - .. figure:: img/project_content.png
          :width: 100%

          Godot Project directory
     - #. contains compiled library and extension configuration
       #. standard :term:`Godot` project.


The bin directory of the :term:`Godot` project contains the output of the build.

.. list-table::
   :widths: 20 50
   :class: borderless

   * - .. figure:: img/project_bin.png
          :width: 100%

          Project Bin directory
     - #. compiled libraries for target systems indicated by directory name
       #. :term:`.gdextension file`


Verify the Build
^^^^^^^^^^^^^^^^^^^

In the :term:`Godot` project's bin directory, open the directory corresponding to the target build system.
There should be a library created there that will be named ``EXTENSION-NAME.linux.template_debug.x86_64.so``.

Now open ``example.gdextension`` which is the :term:`configuration file` for the :term:`extension`.

Look for the block of paths for the current platform, and check that the :term:`extension`'s library path corresponds to the correct name
for the compiled library.

If the path name in the :term:`configuration file` is different than the actual path, for example if the
:term:`configuration file` lists

.. code::

    "libEXTENSION-NAME.linux.template_debug.x86_64.so"

And the actual library is named

.. code::

    "EXTENSION-NAME.linux.template_debug.x86_64.so"

then the name of the library will have to be adjusted to account for any differences.

Testing the Build
^^^^^^^^^^^^^^^^^
The :term:`extension` can now be tested by launching the :term:`Godot` editor and importing the :term:`Godot` project directory, or alternatively
the command line can be used to launch the :term:`Godot` editor and load the project.  To do so the command is

``/path/to/godot.executable --editor --path /absolute/path/to/godot_project_folder``

Once the project is loaded in the editor, the :term:`extension` can be tested by running the main scene, which should print the following to the console.

::

   Type: 24

.. hint::

    If the :term:`Godot` project throws a file not found error when loaded in the :term:`Godot` editor
    check the :term:`.gdextension file` and ensure the library name is correct.




.. include:: ../share/links.rst