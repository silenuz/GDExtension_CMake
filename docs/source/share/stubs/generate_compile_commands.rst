To create the :term:`compile commands` file, the :term:`variable` named :term:`CMAKE_EXPORT_COMPILE_COMMANDS`
is assigned a value of ``ON`` and passed as an :term:`option` to the cmake executable.

.. code:: shell

   cmake -S . -B cmake-build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON