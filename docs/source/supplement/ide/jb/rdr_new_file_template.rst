.. _supref-ide-02:

Rider New File Template
=======================
The following details how to add a file template for creating a new :term:`GDExtension` class.
It generates the header and implementation files with the necessary boilerplate for use as
part of a :term:`GDExtension`.

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

For an explanation of how the template works see :ref:`supref-ide-03`.