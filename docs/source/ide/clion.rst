Configuring CLion
-----------------
`CLion <https://www.jetbrains.com/clion>`_ is an IDE from Jetbrains for c/c++ development

Build Configuration
===================
Open the :term:`template` folder in Clion, you will be presented with the Open project Wizard:

.. figure:: /ide/img/cl_open_project_wizard.png
    :width: 100%

    Open Project Wizard

The :term:`generator` should be correctly recognized if :term:`CMake` has been configured at least once.
However sometimes when clearing the :term:`CMake cache` the default :term:`generator` may change so it's best to
definitively set the :term:`generator` in the project options.  Also check to ensure the :term:`build directory` is correct.

The :term:`template's<template>` contents will load in the project window, and the README will be displayed in the main editor
window.  Expand the :term:`template` entry in the project window,
right click the folder that contains the Godot :term:`project` and copy the absolute path to the
:term:`project` folder.

.. figure:: /ide/img/get_path_cl.gif
    :width: 50%

    Copy Path to Godot Project

Next click the configuration dropdown.

.. figure:: /ide/img/intial_project_view_cl.png
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

.. figure:: /ide/img/cl_build_configuration.gif
    :width: 100%

    Build Configuration

CLion should now be configured.


