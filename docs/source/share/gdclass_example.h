// MyNode.hpp
#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class MyNode : public Node2D {
    // 1. Define the class and its parent
    GDCLASS(MyNode, Node2D);

protected:
    // 2. Required for registering methods and properties
    static void _bind_methods();

public:
    MyNode();
    ~MyNode();

    void my_function();
};
