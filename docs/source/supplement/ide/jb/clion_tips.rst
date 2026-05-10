CLion tips
----------
Some tips and hints for CLion

.. _supref-ide-04:

Edit C File Header
==================

Open the file Menu and select Settings, expand editor and choose File templates, select the includes tab

.. figure:: /supplement/ide/jb/img/cl_cfile_header.png
    :width: 100%

    Changing The C File Header

For a list of predefined variables see `Jetbrains CLion template variables`_ .


.. _supref-ide-05:

Edit Header Guard Symbol
========================
The header guard symbol should be unique, so it usually relates to the filename.
To configure the pattern for header guard symbol, open the Naming tab in Settings | Editor | Code Style | C/C++ and
specify the template in the Header Guard field:

.. figure:: /supplement/ide/jb/img/cl_header_guard.png
    :width: 100%

    Changing The Header Guard

You can use various predefined variables, for example:

    * ${PROJECT_NAME} - the name of the current project.
    * ${PROJECT_REL_PATH} - the relative target path. For instance, if the project is located in the prj directory, and the target file is prj/src/dir/header.h, then ${PROJECT_REL_PATH} will be equal to src/dir.
    * ${FILE_NAME} - the target filename without extension.
    * ${EXT} - the target file extension.

    For other variables that you can use see `Jetbrains CLion template variables`_.

.. note::

   A valid header guard symbol can contain the following characters: upper case 'A-Z' and lower case 'a-z' letters,
   the underscore sign _, digits (but cannot start with a digit), and the dollar sign $. Note that CLion appends
   an INC_ prefix to symbols that start with digits, and replaces invalid symbols using the INC_${UUID} pattern.

.. include:: /share/links.rst