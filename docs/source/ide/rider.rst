Configuring Rider
-----------------
`Rider <https://www.jetbrains.com/rider/>`_ is primarily an IDE for C# and .Net development, however it does include support for cmake files and building
GDExtensions as of version 2026.1.

Build Configuration
===================
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
The following details how to add a file template for creating a new :term:`GDExtension` class.
It generates the header and implementation files with the necessary boilerplate for use as
part of a :term:`GDExtension`.

Creating The Template
^^^^^^^^^^^^^^^^^^^^^
Click the main File menu item, and select Settings, expand the editor settings and
select ``File and Code templates``.  Due to the fact that the ``C++`` language category uses
the Resharper template engine, as it considers C++ a .Net language. As a result this template will be created under
the Other Languages category.

Click the plus button to create a new template,
give it a name, and an extension of either h or hpp.

.. warning::
   Do not start the extension with a dot, just ``h`` or ``hpp``.

.. figure:: /ide/img/cl_add_header.gif
    :width: 100%

    Creating the Template

Save the template as a child template cannot be added till it is saved.  Unfortunately the settings window will close and
have to be reopened, so reopen it and navigate to the new file template.  Copy the following template content:

.. literalinclude:: /appendix/code_listing/src/supplement/header_template.vm
   :caption: Template Header content

And paste it in the template's code window, then select the ``Add Child template`` button to create
the implementation file.  Set the filename to be ``${NAME}`` and set the extension to be cpp.

.. warning::
   do not use a dot in the extension, just use ``cpp``

.. figure:: /ide/img/rdr_setup_template.gif
    :width: 100%

    Template Setup

Copy and paste the following implementation template into the child template's code window.

.. literalinclude:: /appendix/code_listing/src/supplement/code_template.vm
   :caption: Template Code content

Click Save and the file template should be ready to use.
Now the new file context menu in the project tree can be used to create a new class for the extension:

.. figure:: /ide/img/rdr_use_template.gif
    :width: 100%

    Using the template

.. include:: /share/stubs/jetbrains_file_template.rst

