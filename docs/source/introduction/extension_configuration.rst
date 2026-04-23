Extension Configuration
-----------------------
A description of the steps required to customize the extension, such as a giving the library a name,
adjusting the extension configuration paths based on the new library name, editing the entry symbol,
and renaming the library_init function.

Library Name
============
The default library name is ``EXTENSION-NAME`` and to change it, the CMakeLists.txt file is edited.
While there is nothing wrong with keeping the project folder as is, it might be better
to rename it to something more suitable.  So if desired rename the project folder.

For the purposes of this example the project folder will be renamed to demo, and the library name will be
cooldemo.  Open CMakeLists.txt and find the following line:

.. code:: cmake

    set(LIBNAME "EXTENSION-NAME") # "The name of the library"

Change ``EXTENSION-NAME`` to be the name of the library like so:

.. code:: cmake

    set(LIBNAME "cooldemo") # "The name of the library"

Beneath that line should be where it sets the folder for the project, if the name of the project folder was changed it
has to be changed here to.  Find the line:

.. code:: cmake

    set(GODOT_PROJECT_DIR "project" CACHE STRING "The directory of a Godot project folder")

Change ``project`` to be the new name of what was the project folder.

.. code:: cmake

    set(GODOT_PROJECT_DIR "demo" CACHE STRING "The directory of a Godot project folder")



