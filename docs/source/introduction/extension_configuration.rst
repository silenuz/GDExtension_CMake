Extension Configuration
-----------------------
A description of the steps required to customize the extension:

* Change the :term:`library` name
* Edit the :term:`entry symbol` to reflect the new :term:`library` name
* Adjust extension paths to reflect new the :term:`library` name
* Update the :term:`entry point` function signature with the new :term:`entry symbol`

CMake Configuration
============================
The default :term:`library` name is ``EXTENSION-NAME`` and to change it, the CMakeLists.txt file is edited.
While there is nothing wrong with keeping the :term:`project` directory as is, it might be better
to rename it to something more suitable.  So if desired rename the :term:`project` directory.

For the purposes of this example the :term:`project` directory will be renamed to demo, and the 
:term:`library` name will be renamed to cooldemo.

Change Library Name
^^^^^^^^^^^^^^^^^^^
Open CMakeLists.txt and find the following line:

.. code:: cmake

    set(LIBNAME "EXTENSION-NAME") # "The name of the library"

Change ``EXTENSION-NAME`` to be the name of the library like so:

.. code:: cmake

    set(LIBNAME "cooldemo") # "The name of the library"

Change Project Folder
^^^^^^^^^^^^^^^^^^^^^
Beneath that line should be where it sets the directory for the :term:`project`, if the name of the :term:`project`
directory was changed, it has to be changed here to.  Find the line:

.. code:: cmake

    set(GODOT_PROJECT_DIR "project" CACHE STRING "The directory of a Godot project folder")

Change ``project`` to be the new name of the :term:`project` directory.

.. code:: cmake

    set(GODOT_PROJECT_DIR "demo" CACHE STRING "The directory of a Godot project folder")

Include Prefix In Library Name
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Currently the CMakeLists.txt file does not currently set a prefix for the :term:`library` name, which could lead to a
possible name mismatch between the generated :term:`library` and the content of :term:`extension`'s :term:`.gdextension file`.

This comes down to a matter of preference, the cmake configuration can be edited to generate the
necessary prefix so the :term:`library` conforms to the naming conventions,
on the various :term:`target platform`s.

Or the :term:`library` prefix can be omitted from the file name in the :term:`extension`'s :term:`.gdextension file`,
which will be the next file to edit, where the name will have to be adjusted anyway.
If the preference is to just adjust the :term:`library` name in the :term:`.gdextension file`, skip to `Edit :term:`.gdextension file``_ .

To add prefix generation to the cmake configuration open CMakeLists.txt, and scroll down to near the bottom where this
block of code is:

.. code:: cmake

    set_target_properties(${LIBNAME}
    PROPERTIES
    # The generator expression here prevents msvc from adding a Debug or Release subdir.
    RUNTIME_OUTPUT_DIRECTORY "$<1:${PROJECT_SOURCE_DIR}/bin/${GODOTCPP_PLATFORM}>"

    PREFIX ""
    OUTPUT_NAME "${LIBNAME}${GODOTCPP_SUFFIX}"
    )

Just above it insert the following code, which will detect the :term:`target platform`, and if the :term:`target platform`
is anything but windows, the :term:`library`'s filename will have a prefix of ``lib``:

.. code:: cmake

    if(WIN32)
        set(LIBPREFIX "")
    else ()
        set(LIBPREFIX "lib")
    endif ()

Next edit the original block and change ``PREFIX ""`` with ``PREFIX "${LIBPREFIX}"``.

Edit :term:`Configuration <.gdextension file_>`__
=================================================

The :term:`.gdextension file` in the :term:`project` contains the instructions for how to load the :term:`extension`.
The instructions are separated into specific sections.

Now that cmake compiles the :term:`library` with a different name, in order for :term:`Godot` to be able to load the :term:`extension`, 
the :term:`library`'s :term:`entry symbol` has to be edited.  As well the :term:`library`'s path has to be updated in the
:term:`.gdextension file`.

Open the :term:`extension`'s :term:`.gdextension file` for example (``demo/bin/example.gdextension``).

Change Entry Symbol
^^^^^^^^^^^^^^^^^^^

Find the configurations section (it should be near the top) and looks like this:

.. code-block:: INI
   :emphasize-lines: 3

    [configuration]

    entry_symbol = "example_library_init"
    compatibility_minimum = "4.1"
    reloadable = false

Change the :term:`entry symbol` from ``example_library_init`` to ``libraryname_library_init``, so for the cooldemo
:term:`library` in the example, it is changed to this:

.. code-block:: INI
   :emphasize-lines: 3

    [configuration]

    entry_symbol = "cooldemo_library_init"
    compatibility_minimum = "4.1"
    reloadable = false

Change Extension Path
^^^^^^^^^^^^^^^^^^^^^

Have a look at the library section, this section informs :term:`Godot` of the path to the :term:`extension`'s
:term:`library` for each :term:`target platform`.  These paths are relative to the :term:`.gdextension file`.

To adjust the paths in this section it is easiest to just do a find and replace.

If the CMakeLists.txt file was altered to generate the lib prefix on systems other than windows,
find "``EXTENSION-NAME``" and replace with the actual :term:`library` name like "``cooldemo``".

Otherwise find "``libEXTENSION-NAME``" and replace it with the :term:`library` name, this will fix the non windows names.
Now find "``EXTENSION-NAME``" and replace it with the :term:`library` name to fix the rest.

Change File Name
^^^^^^^^^^^^^^^^

Technically the name portion of the :term:`.gdextension file` doesn't matter, as :term:`Godot` loads it based on the file extension,
however it is recommended that the :term:`.gdextension file` be renamed to reflect the name of the :term:`library`.

.. todo: this sucks find better wording

Currently the :term:`.gdextension file` is named "``example.gdextension``"
replace the word example with the :term:`library` name like this "``cooldemo.gdextension``".


Source Code Configuration
=========================

The last step is to edit the source code in ``src/register_types.cpp``, which is a core file in any :term:`GDExtension`,
and is used to initialize and register C++ classes with the :term:`Godot` engine.  It contains the :term:`entry point` for
the :term:`extension`, and has three key functions:

* Initialization Function:
    name: initialize_gdextension_types. It is called by Godot at different initialization levels (e.g., Core, Servers, Scene, Editor). You use ClassDB::register_class<YourClassName>() here to expose your classes to Godot.
* Deinitialization Function:
    name: uninitialize_gdextension_types. This cleans up any memory or resources allocated during initialization.
* Entry Point (extern "C"):
    The main entry function (e.g., example_library_init) that Godot calls when loading the dynamic library. It sets up the binding between your C++ code and the GDExtension interface.

Rename Init Function
^^^^^^^^^^^^^^^^^^^^

Open ``src/register_types.cpp`` and scroll to near the bottom where the main entry function is, it looks like this:

.. code:: cpp

    	// Initialization
	GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
	{
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
		init_obj.register_initializer(initialize_gdextension_types);
		init_obj.register_terminator(uninitialize_gdextension_types);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}

Now replace the word example in the function definition to be the name chosen as the entry symbol in the gdextension
:term:`.gdextension file`.  For the cooldemo example the original:

``example_library_init``

would become:

``cooldemo_library_init``

At this point the extension is properly configured, and can be built and tested,
however while the file is open, let's examine the other two methods, to see how the extension's
"``ExampleClass``" is registered, and examine the method that unloads the extension.

Registering Classes
^^^^^^^^^^^^^^^^^^^
Near the top of the of the file is the ``initialize_gdextension_types`` function,
which receives pointers from Godot to initiate binding with the engine.

The library_init function sets up registration callbacks (like register_initializer) and defines the initialization level.
Godot calls this initialization function across four levels:

   * CORE: Post-engine core.
   * SERVERS: Post-servers (physics/rendering).
   * SCENE: Registration for nodes and objects.
   * EDITOR: Editor-specific plugins.

Within the initializer function, register classes with the Godot ClassDB using "``GDREGISTER_CLASS(ClassName)``"
specifically during the SCENE level to make them available in the editor.

The method in the example extension:

.. code-block:: cpp
   :emphasize-lines: 6

   void initialize_gdextension_types(ModuleInitializationLevel p_level)
   {
       if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
           return;
       }
       GDREGISTER_CLASS(ExampleClass);
   }

The extension currently registers a single class called ``ExampleClass``, at the scene initialization level.
The example class implements a function called "``print_type``" :

.. code:: cpp

   void ExampleClass::print_type(const Variant &p_variant) const {
       print_line(vformat("Type: %d", p_variant.get_type()));
   }

To see how the ``ExampleClass`` is used in Godot to print "``Type: 24``", open ``demo/example.gd`` which is
the script attached to the main scene.

The script is pretty simple:

.. code:: GDScript

   extends Node

   func _ready() -> void:
       var example := ExampleClass.new()
       example.print_type(example)

When the scene reaches the ``_ready()`` state, the example class object is instantiated in the standard way,
it then calls the ``print_type`` function passing itself as the argument.

Un-Initialization
^^^^^^^^^^^^^^^^^

The method that is responsible for unloading the extension is called ``uninitialize_gdextension_types`` and should be right below the the ``intialize_gdextension_types`` function,.

* Purpose:  It acts as the counterpart to initialize_gdextension_types, ensuring resources allocated in C++ are properly freed to avoid memory leaks or crashes during hot reloading.
* Signature: It usually takes ModuleInitializationLevel p_level as an argument to determine if it should clean up core, editor, or scene types

Typical Usage:

.. code:: cpp

   void uninitialize_gdextension_types(ModuleInitializationLevel p_level) {
       if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
           return;
       }
       // cleanup registration here
   }

This function is empty as the extension currently requires no cleanup.

.. warning::

    * Hot Reloading Warning: If you are using hot reloading (reloadable = true in .gdextension), failing to implement this function properly can lead to crashes in Main::cleanup()
    * Singleton Cleanup: If you registered singletons, they must be unregistered here. Be cautious with GDExtensionManager, ResourceUID, or IP singletons, as they can cause crashes if not handled correctly during shutdown
    * Static Variable Issues: Do not use static variables with Godot types (like RID or Node) in your classes, as they may be destroyed after the GDExtension system has already shut down.


Build and Test
==============

Now it's time to build and test the library with the new configuration.

Build
^^^^^

Compile the new version of the extension, with the configuration changes

.. code:: shell

   cmake --build cmake-build

Test
^^^^
The project can now be tested by launching the Godot editor and importing the project folder, or alternatively
the command line can be used to launch the Godot editor and load the project.  To do so the command is

``/path/to/godot.executable --editor --path /absolute/path/to/project``

After the project is loaded in the editor, the extension can be tested by running the main scene

Source Code
===========

:ref:`coderef101`

:ref:`coderef102`

:ref:`coderef103`

:ref:`coderef104`

:ref:`coderef105`

