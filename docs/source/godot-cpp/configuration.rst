godot-cpp Configuration
-----------------------

It is possible to further configure cmake to set specific ``godot-cpp``
variables such as \* `Changing the project
folder <#change-project-folder>`__ \* `Enabling developer
builds <#developer-build>`__ \* `Enabling exception
handling <#exception-handling>`__

Change Project Folder
=====================

To change the project folder, first rename the folder named project to the name you wish for the extension.

Now open ``CMakeLists.txt`` and near the top, just
under where the library name was changed in the initial setup is a line
like so:

.. code:: cmake

   set(GODOT_PROJECT_DIR "project" CACHE STRING "The directory of a Godot project folder")

Change ``project`` to be the name of the newly renamed folder. So if you
changed the project folder name to mycooldemo, then it would look like
this:

.. code:: cmake

   set(GODOT_PROJECT_DIR "mycooldemo" CACHE STRING "The directory of a Godot project folder")

Developer Build
===============

At some point you may wish to include debug symbols in your extension,
whether for troubleshooting or profiling. To do so simply add the
developer build variable near the top of the
``CMakeLists.txt`` with a value of ``ON``:

.. code:: cmake

   set(GODOTCPP_DEV_BUILD ON)

The default ``GODOTCPP_SUFFIX`` for the output library may have ``.dev``
as part of the name, if this is the case it is likely that the name of
the library is no longer correct in the
`gdextension <./project/bin/example.gdextension>`__ file. You can either
correct the name in the
`gdextension <./project/bin/example.gdextension>`__ file to account for
the ``.dev`` in the library name, or you can adjust the
``CMakeLists.txt`` file to strip ``.dev`` from the
suffix.

Here’s how to strip ``.dev`` from the suffix.

Near the end of the ``CMakeLists.txt`` file it sets
the target properties for the output, just above that, add this line:

.. code:: cmake

   string(REPLACE ".dev" "" MYSUFFIX "${GODOTCPP_SUFFIX}")

This will parse the ``GODOTCPP_SUFFIX`` and replace ``.dev`` with an
empty string, with the resulting value being assigned to the
``MYSUFFIX`` variable.

Now in the ``set_target_properties`` block, the last thing set is the
``OUTPUT_NAME`` change

.. code:: shell

   OUTPUT_NAME "${LIBNAME}${GODOTCPP_SUFFIX}"

To:

.. code:: shell

   OUTPUT_NAME "${LIBNAME}${MYSUFFIX}"

Final Result:

.. code:: cmake

   string(REPLACE ".dev" "" MYSUFFIX "${GODOTCPP_SUFFIX}")

   set_target_properties(${LIBNAME}
           PROPERTIES
           # The generator expression here prevents msvc from adding a Debug or Release subdir.
           RUNTIME_OUTPUT_DIRECTORY "$<1:${PROJECT_SOURCE_DIR}/bin/${GODOTCPP_PLATFORM}>"

           PREFIX "${LIBPREFIX}"
           OUTPUT_NAME "${LIBNAME}${MYSUFFIX}"
   )

Exception Handling
==================

By default, exception handling is disabled, as Godot doesn’t use
exceptions anywhere, so with exceptions disabled the resulting binary is
about 20 percent smaller and builds significantly faster.

If however you are including a third party library in the build, and the
library requires exception handling, or if you wish to use exceptions
despite the drawbacks, simply add the following line near the top of
``CMakeLists.txt`` file.

.. code:: cmake

   set( GODOTCPP_DISABLE_EXCEPTIONS OFF)