.. _supref-ide-03:

Examining The Jetbrains New File Template
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
First the template checks to see if the file name contains an underscore, if so it assumes file_name is snake_case,
otherwise it assumes the file name is PascalCase.  If the name is snake_case it is converted to PascalCase.

.. code-block::

   #set( $PascalCaseName = "" )
   #if( $NAME.contains("_") )
       #set($part = "")
   #set($parts = $NAME.split("_"))
   #foreach($part in $parts)
       #if($part.length() > 0)
           #set($firstChar = $part.substring(0, 1).toUpperCase())
           #set($restChars = $part.substring(1).toLowerCase())
           #set($PascalCaseName = "${PascalCaseName}${firstChar}${restChars}")
       #end
   #end
   #else
        #set($PascalCaseName = "${NAME}")
   #end

Then the template processes the parent class variable, by first converting any capital D that is preceded by a digit
to a lower case d, and then converting the parent class name to snake_case to determine the include
header from :term:`godot-cpp`.

``#set($include_file = $ParentClass.replaceAll('([0-9])D', '$1d').replaceAll("([a-z])([A-Z])", "$1_$2").toLowerCase())``

Up to this point the template has only processed variables, the rest of the template code is
actually generative.  The first thing generated is the file header,this is parsed from the current
C File Header template

``#parse("C File Header.h")``

Any variables declared in the file header will also be available when using the file template.  To change the
C File header see :ref:`supref-ide-04` for CLion, or :ref:`supref-ide-06` for Rider.

Next it generates the header guards based on the configured naming convention in the ide's settings.

.. code-block::

   #[[#ifndef]]# ${INCLUDE_GUARD}
   #[[#define]]# ${INCLUDE_GUARD}

Then it's the actual code template which contains the boilerplate with variables representing the
various values in relation to class name, parent class etc...

.. code-block::

   #[[#include]]# <godot_cpp/classes/${include_file}.hpp>

   using namespace godot;

   class ${PascalCaseName} : public ${ParentClass}{
      GDCLASS(${PascalCaseName},${ParentClass});

   protected:
      static void _bind_methods();

   public:

      ${PascalCaseName}();
   };

Lastly it generates the closing header guard

``#[[#endif]]# //${INCLUDE_GUARD}``

For information about configuring the header guard see :ref:`supref-ide-05` for Clion and :ref:`supref-ide-07` for Rider.