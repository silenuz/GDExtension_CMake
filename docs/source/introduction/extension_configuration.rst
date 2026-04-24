Extension Configuration
-----------------------
A description of the steps required to customize the extension, such as a giving the library a name,
adjusting the extension configuration paths based on the new library name, editing the entry symbol,
and renaming the library_init function.

CMake Configuration
============================
The default library name is ``EXTENSION-NAME`` and to change it, the CMakeLists.txt file is edited.
While there is nothing wrong with keeping the project folder as is, it might be better
to rename it to something more suitable.  So if desired rename the project folder.

For the purposes of this example the project folder will be renamed to demo, and the library name will be
cooldemo.

Change Library Name
^^^^^^^^^^^^^^^^^^^
Open CMakeLists.txt and find the following line:

.. code:: cmake

    set(LIBNAME "EXTENSION-NAME") # "The name of the library"

Change ``EXTENSION-NAME`` to be the name of the library like so:

.. code:: cmake

    set(LIBNAME "cooldemo") # "The name of the library"

Change Project Folder
^^^^^^^^^^^^^^^^^^^^^
Beneath that line should be where it sets the folder for the project, if the name of the project folder was changed it
has to be changed here to.  Find the line:

.. code:: cmake

    set(GODOT_PROJECT_DIR "project" CACHE STRING "The directory of a Godot project folder")

Change ``project`` to be the new name of what was the project folder.

.. code:: cmake

    set(GODOT_PROJECT_DIR "demo" CACHE STRING "The directory of a Godot project folder")

Include Prefix In Library Name
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Currently the CMakeLists.txt file does not currently set a prefix for the library name, which could lead to a
possible name mismatch between the generated library and the content of extension configuration file(``project/bin/example.gdextension``).

This comes down to a matter of preference, the cmake configuration can be edited to generate the
necessary prefix so the generated library conforms to the library naming conventions,
on the various target systems.

Or the library prefix can be omitted from the file name in the extension configuration file,
which will be the next file to edit, where the name will have to be adjusted anyway.
Jump to `Edit Configuration File`_ if the preference is to just adjust the name in the configuration file.

To add prefix generation to the cmake configuration open CMakeLists.txt, and scroll down to near the bottom where this
block of code is:

.. code:: cmake

    set_target_properties(${LIBNAME}
    PROPERTIES
    # The generator expression here prevents msvc from adding a Debug or Release subdir.
    RUNTIME_OUTPUT_DIRECTORY "$<1:${PROJECT_SOURCE_DIR}/bin/${GODOTCPP_PLATFORM}>"

    PREFIX ""
    OUTPUT_NAME "${LIBNAME}${GODOTCPP_SUFFIX}"
    )

Just above it insert the following code, which will detect the target system, and if the target system
isn't windows the filename will have a prefix of ``lib``:

.. code:: cmake

    if(WIN32)
        set(LIBPREFIX "")
    else ()
        set(LIBPREFIX "lib")
    endif ()

Next edit the original block and change ``PREFIX ""`` with ``PREFIX "${LIBPREFIX}"``.

Edit Configuration File
=======================



