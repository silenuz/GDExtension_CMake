godot-cpp Variable List
-----------------------

+-------------+---+-----+----------------------------------------------+
| Variable    | T | D   | Description                                  |
|             | y | efa |                                              |
|             | p | ult |                                              |
|             | e |     |                                              |
+=============+===+=====+==============================================+
| GODOTCPP_BU | P |     | Path to a file containing a feature build    |
| ILD_PROFILE | A |     | profile                                      |
|             | T |     |                                              |
|             | H |     |                                              |
+-------------+---+-----+----------------------------------------------+
| GO          | F |     | Path to a custom GDExtension API JSON file   |
| DOTCPP_CUST | I |     | (takes precedence over                       |
| OM_API_FILE | L |     | ``GODOTCPP_GDEXTENSION_DIR``) (              |
|             | E |     | /path/to/custom_api_file )                   |
|             | P |     |                                              |
|             | A |     |                                              |
|             | T |     |                                              |
|             | H |     |                                              |
+-------------+---+-----+----------------------------------------------+
| GODOTCP     | B | OFF | Compile with MSVC’s debug CRT (/MDd)         |
| P_DEBUG_CRT | O |     |                                              |
|             | O |     |                                              |
|             | L |     |                                              |
+-------------+---+-----+----------------------------------------------+
| GODOTCP     | B | OFF | Developer build with dev-only debugging code |
| P_DEV_BUILD | O |     | (DEV_ENABLED)                                |
|             | O |     |                                              |
|             | L |     |                                              |
+-------------+---+-----+----------------------------------------------+
| GODOT       | B | ON  | Force disabling exception handling code      |
| CPP_DISABLE | O |     | (ON,OFF)                                     |
| _EXCEPTIONS | O |     |                                              |
|             | L |     |                                              |
+-------------+---+-----+----------------------------------------------+
| G           | B | OFF | Enable the godot-cpp.test. integration       |
| ODOTCPP_ENA | O |     | testing targets                              |
| BLE_TESTING | O |     |                                              |
|             | L |     |                                              |
+-------------+---+-----+----------------------------------------------+
| GO          | P | gd  | Path to a custom directory containing        |
| DOTCPP_GDEX | A | ext | GDExtension interface header and API JSON    |
| TENSION_DIR | T | ens | file ( /path/to/gdextension_dir )            |
|             | H | ion |                                              |
+-------------+---+-----+----------------------------------------------+
| GO          | B | ON  | Generate a template version of the Node      |
| DOTCPP_GENE | O |     | class’s get_node. (ON,OFF)                   |
| RATE_TEMPLA | O |     |                                              |
| TE_GET_NODE | L |     |                                              |
+-------------+---+-----+----------------------------------------------+
| GODOTCP     | S | sin | Set the floating-point precision level       |
| P_PRECISION | T | gle | (single,double)                              |
|             | R |     |                                              |
|             | I |     |                                              |
|             | N |     |                                              |
|             | G |     |                                              |
+-------------+---+-----+----------------------------------------------+
| GODO        | S | hid | Symbols visibility on GNU platforms. Use     |
| TCPP_SYMBOL | T | den | ‘auto’ to apply the default value.           |
| _VISIBILITY | R |     | (auto,visible,hidden)                        |
|             | I |     |                                              |
|             | N |     |                                              |
|             | G |     |                                              |
+-------------+---+-----+----------------------------------------------+
| G           | B | OFF | Expose headers as SYSTEM.                    |
| ODOTCPP_SYS | O |     |                                              |
| TEM_HEADERS | O |     |                                              |
|             | L |     |                                              |
+-------------+---+-----+----------------------------------------------+
| GODO        | S | te  | Which target to generate. valid values are   |
| TCPP_TARGET | T | mpl | template_debug, template_release, and editor |
|             | R | ate |                                              |
|             | I | _de |                                              |
|             | N | bug |                                              |
|             | G |     |                                              |
+-------------+---+-----+----------------------------------------------+
| GODOT       | B | ON  | Enable threading support                     |
| CPP_THREADS | O |     |                                              |
|             | O |     |                                              |
|             | L |     |                                              |
+-------------+---+-----+----------------------------------------------+
| G           | B |     | Enable the extra accounting required to      |
| ODOTCPP_USE | O |     | support hot reload. (ON,OFF)                 |
| _HOT_RELOAD | O |     |                                              |
|             | L |     |                                              |
+-------------+---+-----+----------------------------------------------+
| G           | B | ON  | Link MinGW/MSVC C++ runtime libraries        |
| ODOTCPP_USE | O |     | statically                                   |
| _STATIC_CPP | O |     |                                              |
|             | L |     |                                              |
+-------------+---+-----+----------------------------------------------+
| GOD         | B | OFF | Treat warnings as errors                     |
| OTCPP_WARNI | O |     |                                              |
| NG_AS_ERROR | O |     |                                              |
|             | L |     |                                              |
+-------------+---+-----+----------------------------------------------+
| GODOT_      | S | p   | The directory of a Godot project folder      |
| PROJECT_DIR | T | roj |                                              |
|             | R | ect |                                              |
|             | I |     |                                              |
|             | N |     |                                              |
|             | G |     |                                              |
+-------------+---+-----+----------------------------------------------+