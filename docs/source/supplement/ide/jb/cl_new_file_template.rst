.. _supref-ide-01:

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

For an explanation of how the template works see :ref:`supref-ide-03`.