First Steps
-----------
An introduction to the official :term:`godot-cpp-template`, covering

* Acquisition of the :term:`template`
* Organizational review of the template structure
* Initial :term:`template` configuration
* Building the :term:`template`
* Organizational review of the example :term:`Godot` :term:`project`
* Testing the build in the :term:`Godot` editor


Acquiring the :term:`Template <template>`
=========================================
There are multiple ways to acquire the :term:`godot-cpp-template`

The easiest way is to simply clone the :term:`template's <template>` `repository <Godot CPP Template_>`__.

If you want to share your :term:`extension` on GitHub, you can create a repository from the :term:`template`

Lastly you can download the :term:`template` and :term:`godot-cpp` as zip files and manually create the directory tree.
This is the hard way, and provides little added value other than it will lack git tracking,
allowing the developer to create a new git repository with no history.

.. tabs::

   .. tab:: Clone

      Open a terminal in the directory where the cloned :term:`template` is to be downloaded,
      and execute the following command:

      .. code:: shell

         git clone https://github.com/godotengine/godot-cpp-template.git --recursive ./mycooldemo

      This will clone the ``godot-cpp-template`` into a directory named :term:`mycooldemo`.

      .. tip::
         If you wish to detach the :term:`template` from the repository, open a terminal in the
         :term:`template's <template>` directory and execute the following command to remove
         the git origin, allowing for remote origin relocation.

         .. code:: shell

            git remote remove origin

   .. tab:: Create repository
      First log into log in to GitHub, and then go to the `Godot CPP Template`_ and click the green
      "Use this template" button at the top of the repository page.

      .. figure:: img/create_repo.png
          :width: 100%

          Use Template

      This will let you create a copy of the repository with a clean git history.
      Next clone the repository that was just created with the --recursive flag.  For example if the repository that was
      created from the template is called :term:`mycooldemo`:

      .. code:: shell

         git clone https://github.com/account/mycooldemo.git --recursive

   .. tab:: Download
      Open `Godot CPP Template`_ repository in a web browser.  Click the green "Code" button and choose
      Download ZIP.

      .. figure:: img/zip_download.png
          :width: 50%

          Template Download

      Unzip the compressed file, after unzipping, rename the ``godot-cpp-template-main`` directory,
      to reflect the name of the extension.  For example :term:`mycooldemo`.

      At this point there will be no :term:`godot-cpp` bindings for the :term:`extension`.
      Open `Godot CPP Bindings`_ in your browser, click the green "Code" button, and choose Download Zip.

      Extract the archive, and rename the extracted directory from ``godot-cpp-master`` to ``godot-cpp``.
      Now move the ``godot-cpp``  directory to the top level of the :term:`template` directory.

The :term:`template` is organized as follows:

.. list-table::
   :widths: 20 50
   :class: borderless

   * - .. figure:: img/intial_repo_content.png
          :width: 100%

          Initial Repository Content
     - #. bin directory for :term:`SCons` builds (not used by :term:`CMaKE`)
       #. :term:`extension documentation` for classes in the extension
       #. :term:`godot cpp` bindings for the extension
       #. example :term:`Godot` :term:`project`
       #. source code for the extension
       #. empty custom :term:`build profile`
       #. :term:`CMake` configuration file
       #. used by :term:`SCons` to build the :term:`library` for the :term:`extension` (not used by :term:`CMake`)

.. note::
    If the repository was cloned without the ``--recursive`` flag, then the :term:`godot-cpp` directory will be empty.  To remedy
    this open the :term:`template` directory in a terminal and execute the following;

    .. code:: shell

        git submodule update --init

Initial Configuration
=====================

After cloning the repository :term:`CMake` has to be configured. Open a terminal in the topmost level of the :term:`template` that
was just cloned, for example :term:`mycooldemo` and execute cmake with the :term:`option`'s
listed below:

.. code:: shell

   cmake -S . -B cmake-build -G Ninja

* ``-S`` specifies the source directory as the current directory
* ``-B`` specifies the :term:`build directory` as ``cmake-build``,
    can be referred to as ``${CMAKE_BINARY_DIR}`` in the ``CMakeLists.txt`` file
* ``-G`` specifies the :term:`CMake` :term:`generator` :term:`Ninja`

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

If the :term:`CMake` :term:`generator` is :term:`Ninja`
or `Makefiles <https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#makefile-generators>`_
you can use the configuration stage to generate a :term:`compile_commands.json` in the :term:`build directory` for use
with :term:`clangd`. To do so the :term:`CMAKE_EXPORT_COMPILE_COMMANDS` :term:`variable` is assigned a value
of ``ON`` and passed as an :term:`option` to the cmake executable.

.. code:: shell

   cmake -S . -B cmake-build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON


Initial Build
=============

For this introductory guide, native compilation will be used.  This means that the
:term:`target platform` and :term:`host platform` are the same.

.. todo: note about cross compiling

Note goes here about cross compiling

Build
^^^^^

Once configured the :term:`extension` can be built by specifying a target of build followed by the name
of the :term:`CMake` :term:`build directory`:

.. code:: shell

   cmake --build cmake-build

If the build command worked, you should have a new :term:`library` file for the
:term:`host platform` in the :term:`Godot` :term:`project` directory.  The example :term:`Godot` :term:`project` directory is organized as follows:

.. list-table::
   :widths: 20 50
   :class: borderless

   * - .. figure:: img/project_content.png
          :width: 100%

          Godot Project directory
     - #. contains compiled :term:`library` and :term:`.gdextension file`
       #. standard :term:`Godot` project.


The bin directory of the :term:`Godot` :term:`project` contains the output of the build.

.. list-table::
   :widths: 20 50
   :class: borderless

   * - .. figure:: img/project_bin.png
          :width: 100%

          Project Bin directory
     - #. compiled :term:`library` for :term:`target platform`, indicated by directory name
       #. :term:`.gdextension file`


Verify
^^^^^^

In the :term:`project`'s bin directory, open the directory corresponding to the :term:`host platform`.
There should be a :term:`library` created there that will be named ``EXTENSION-NAME.host platform.template_debug.x86_64.so``.

Now open ``example.gdextension`` which is the :term:`.gdextension file` for the :term:`extension`.

Look for the block of paths for the current :term:`host platform`, and check that the :term:`extension`'s :term:`library` path corresponds to the correct name
for the compiled :term:`library`.

If the path name in the :term:`.gdextension file` is different than the actual path, for example if the
:term:`.gdextension file` lists

.. code::

    "libEXTENSION-NAME.linux.template_debug.x86_64.so"

And the actual :term:`library` is named

.. code::

    "EXTENSION-NAME.linux.template_debug.x86_64.so"

then the name of the :term:`library` will have to be adjusted in the :term:`.gdextension file` to account for any differences.

Test
^^^^
The :term:`extension` can now be tested by launching the :term:`Godot` editor and importing the :term:`project` directory, or alternatively
the command line can be used to launch the :term:`Godot` editor and load the :term:`project`.  To do so the command is

``/path/to/godot.executable --editor --path /absolute/path/to/project``

Once the :term:`project` is loaded in the editor, the :term:`extension` can be tested by running the main scene, which should print the following to the console.

::

   Type: 24

.. hint::

    If the :term:`project` throws a file not found error when loaded in the :term:`Godot` editor
    check the :term:`.gdextension file` and ensure the :term:`library` name is correct.


.. include:: ../share/links.rst