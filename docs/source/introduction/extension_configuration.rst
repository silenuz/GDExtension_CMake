Extension Configuration
-----------------------
A description of the steps required to customize the extension, such as a giving the library a name,
adjusting the extension configuration paths based on the new library name, editing the entry symbol,
and renaming the library_init function.

CMake Configuration
============================
The default library name is ``EXTENSION-NAME`` and to change it, the CMakeLists.txt file is edited.
While there is nothing wrong with keeping the project folder as is, it might be better
to rename it to something more suitable.  So if desired rename the project folder.

For the purposes of this example the project folder will be renamed to demo, and the library name will be
cooldemo.

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
Beneath that line should be where it sets the folder for the project, if the name of the project folder was changed it
has to be changed here to.  Find the line:

.. code:: cmake

    set(GODOT_PROJECT_DIR "project" CACHE STRING "The directory of a Godot project folder")

Change ``project`` to be the new name of what was the project folder.

.. code:: cmake

    set(GODOT_PROJECT_DIR "demo" CACHE STRING "The directory of a Godot project folder")

Include Prefix In Library Name
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Currently the CMakeLists.txt file does not currently set a prefix for the library name, which could lead to a
possible name mismatch between the generated library and the content of extension configuration file(``project/bin/example.gdextension``).

This comes down to a matter of preference, the cmake configuration can be edited to generate the
necessary prefix so the library conforms to the naming conventions,
on the various target systems.

Or the library prefix can be omitted from the file name in the extension configuration file,
which will be the next file to edit, where the name will have to be adjusted anyway.
If the preference is to just adjust the name in the configuration file, skip to `Edit Configuration File`_ .

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

Just above it insert the following code, which will detect the target system, and if the target system
isn't windows the filename will have a prefix of ``lib``:

.. code:: cmake

    if(WIN32)
        set(LIBPREFIX "")
    else ()
        set(LIBPREFIX "lib")
    endif ()

Next edit the original block and change ``PREFIX ""`` with ``PREFIX "${LIBPREFIX}"``.

Edit Configuration File
=======================
The `.gdextension <https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_file.html#>`_ file in your project contains the instructions for how to load the GDExtension.
The instructions are separated into specific sections.

Now that cmake compiles the library with a different name, in order for Godot to be able to load the extension, the library's entry
symbol has to be edited along with changing the extension name in the various defined paths in the configuration file.

Open the extension configuration file(``project/bin/example.gdextension``).

Change Entry Symbol
^^^^^^^^^^^^^^^^^^^

Find the configurations section (it should be near the top) and looks like this:

.. code:: INI

    [configuration]

    entry_symbol = "example_library_init"
    compatibility_minimum = "4.1"
    reloadable = false

Change the entry symbol from ``example_library_init`` to ``libraryname_library_init``, so for the cooldemo
library in the example it is changed to this:

.. code:: INI

    [configuration]

    entry_symbol = "cooldemo_library_init"
    compatibility_minimum = "4.1"
    reloadable = false

Change Extension Path
^^^^^^^^^^^^^^^^^^^^^

Next have a look at the library section, this section informs Godot of the path to the extension for various target
systems.  To adjust the paths in this section it is easiest to just do a find and replace.

If the CMakeLists.txt file was altered to generate the lib prefix on systems other than windows,
find "``EXTENSION-NAME``" and replace with the actual library name like "``cooldemo``".

Otherwise find "``libEXTENSION-NAME``" and replace it with the library name.

Change File Name
^^^^^^^^^^^^^^^^

Technically the name portion of the configuration file doesn't matter, as Godot loads it based on the file extension,
however it is recommended that the configuration file be renamed to reflect the name of the library.

.. todo: this sucks find better wording

Currently the configuration file is named "``example.gdextension``"
replace the word example with the library name like this "``cooldemo.gdextension``".


Source Code Configuration
=========================

The last step is to edit the source code in ``src/register_types.cpp``, this file is responsible for initializing
the extension and registering objects in the extension with the Godot engine.  Lastly it is also responsible
for any steps required when uninitializing the extension.

Rename Init Function
^^^^^^^^^^^^^^^^^^^^

Open ``src/register_types.cpp`` and scroll to near the bottom where the initialization function is, it looks like this:

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
configuration file.  For the cooldemo example the original:

``GDExtensionBool GDE_EXPORT example_library_init``

would become:

``GDExtensionBool GDE_EXPORT cooldemo_library_init``

At this point the extension is properly configured, and can be built and tested,
however while the file is open, let's examine the other two methods, to see how the extension's
"``ExampleClass``" is registered, and examine the method that unloads the extension.

Registering Classes
^^^^^^^^^^^^^^^^^^^
Near the top of the of the file is the ``initialize_gdextension_types`` function,
which receives pointers from Godot to initiate binding to the engine.

The library_init function sets up registration callbacks (like register_initializer) and defines the initialization level.
Godot calls this initialization function across four levels:

   * CORE: Post-engine core.
   * SERVERS: Post-servers (physics/rendering).
   * SCENE: Registration for nodes and objects.
   * EDITOR: Editor-specific plugins.

Within the initializer function, register classes with the Godot ClassDB using "``GDREGISTER_CLASS(ClassName)``"
specifically during the SCENE level to make them available in the editor.

The method in the example extension:

.. code:: cpp

   void initialize_gdextension_types(ModuleInitializationLevel p_level)
   {
       if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
           return;
       }
       GDREGISTER_CLASS(ExampleClass);
   }

The extension currently registers a single class called ``ExampleClass``, at the scene initialization level.
The example class defines a method called "``print_type``"
which takes a variant as an argument, and prints the variant's type.

.. code:: cpp

   void ExampleClass::print_type(const Variant &p_variant) const {
       print_line(vformat("Type: %d", p_variant.get_type()));
   }

To see how the ``ExampleClass`` is used in Godot to print "``Type: 24``", open ``project/example.gd`` which is
the script attached to the main scene.

The script is pretty simple:

.. code:: GDScript

   extends Node

   func _ready() -> void:
       var example := ExampleClass.new()
       example.print_type(example)

When the scene reaches the ``_ready()`` state, the example class object is instantiated in the standard way,
it then calls the ``print_type`` function passing itself as the argument, which means the ``ExampleClass``
has a variant type of 24.

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



