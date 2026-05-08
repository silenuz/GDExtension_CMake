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

CLion New file Template
=======================
The following details how to add a file template for creating a new :term:`GDExtension` class.
It generates the header and implementation files with the necessary boilerplate for use as
part of a :term:`GDExtension`.

Click the main File menu item, and select Settings, expand the editor settings and
select ``File and Code templates``.  Click the plus button to create a new template,
give it a name, and an extension of either .h or .hpp.

.. figure:: /ide/img/cl_add_header.gif
    :width: 100%

    Creating the Template

Now copy the following velocity template:

.. literalinclude:: /appendix/code_listing/src/supplement/header_template.vm
   :caption: Template Header content

And paste it in the template's code window:

.. figure:: /ide/img/clion_template_code_window.png
    :width: 100%

    Code Window

Click apply, now click the add child template button, for the file name use the ``${NAME}`` variable value.

.. figure:: /ide/img/cl_add_child_template.gif
    :width: 100%

    Creating the Child Template

Copy and paste the following implementation template into the child template's code window.

.. literalinclude:: /appendix/code_listing/src/supplement/code_template.vm
   :caption: Template Code content

After clicking apply, it should look like this:

.. figure:: /ide/img/cl_child_template.png
    :width: 100%

    Child Template

Now the new file context menu in the project tree to create a new class for the extension:

.. figure:: /ide/img/cl_new_file.gif
    :width: 100%

    Using the template


