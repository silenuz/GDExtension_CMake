Configuring Rider
-----------------
`Rider <https://www.jetbrains.com/rider/>`_ is primarily an IDE for C# and .Net development, however it does include support for cmake files and building
GDExtensions as of version 2026.1.

Even if :term:`CMake` has been configured, Rider may not default to the correct :term:`generator` for the :term:`template`.

If the template has already been configured be sure to set the :term:`generator` to the same value as was used for the when
configuring from the command line interface.  Ensure the :term:`build directory` is correct as well.

Open the :term:`template` folder in Rider, you will be presented with the Open project Wizard, set the :term:`generator`
and :term:`build directory`.

.. figure:: /ide/img/rdr_open_project.gif
    :width: 100%

    Open Project Wizard

If Rider created a ``cmake-build-debug`` directory, and your :term:`build directory` is ``cmake-build`` you can go ahead and delete
the ``cmake-build-debug`` directory.

Depending on the operating system the correct debugger may or not be set, in order to be able to set breakpoints
and get code hints the correct debugger must be set.  Open the File menu and choose ``Settings``, under settings expand
``Build, Execution, Deployment`` and select ``Toolchains``, make sure the ``Debugger`` is set to ``Bundled LLDB``.

.. figure:: /ide/img/rdr_set_debugger.gif
    :width: 100%

    Setting The Debugger

The :term:`template's<template>` contents will load in the project window, and the README will be displayed in the main editor
window.  Expand the :term:`template` entry in the project window,
right click the folder that contains the Godot :term:`project` and copy the absolute path to the
:term:`project` folder.

.. figure:: /ide/img/rdr_copy_path.gif
    :width: 50%

    Copy Path to Godot Project

Next click the configuration dropdown.

.. figure:: /ide/img/rd_project_view.png
    :width: 100%

    Initial Project View

From the dropdown choose ``Edit Configurations``.

.. figure:: /ide/img/edit_configuration_cl.png
    :width: 25%

    Configuration Dropdown

Choose the :term:`library` by name in the left panel of the configuration window.  There are three fields that have to
filled in.

* Executable - this should be the path to the :term:`Godot` executable
* Program arguments - ``--editor --path /absolute/path/to/Godot/project`` (project path copied above)
* Working directory - $ProjectFileDir$

.. figure:: /ide/img/rdr_build_config.gif
    :width: 100%

    Build Configuration

To be able to set breakpoints, the :term:`template` must be launched at least once in the editor first.  Once
the necessary fields are filled in, click apply and launch the :term:`project` in the :term:`Godot` editor.

Rider should now be configured.

Rider New File Template
=======================

