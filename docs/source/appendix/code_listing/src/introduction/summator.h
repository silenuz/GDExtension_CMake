/*
 * This source code was "borrowed" from the Godot documentation.
 * © Copyright 2014-2026, Juan Linietsky, Ariel Manzur and the Godot community (CC-BY 3.0)
 * and the original can be found at https://docs.godotengine.org/en/4.4/contributing/development/core_and_modules/custom_modules_in_cpp.html#creating-a-new-module
 *
*/
#pragma once
#include <godot_cpp/classes/object.hpp>

using namespace godot;

/**
 * @class Summator
 * @brief A classic code example for a GDExtension
 *
 * The class must inherit from a Godot built in class (like Object, Node, Sprite2D, or Resource).
 * Godot does not support multiple inheritance for GDExtension classes.
 *
 */
class Summator : public Object
{
	// GDCLASS macro placed at beginning of class body
	GDCLASS(Summator,Object);

	// current total
	int sum;

protected:
	/**
	 * You must declare a protected static void _bind_methods() function in your class header.
	 */
	static void _bind_methods();

public:
	/**
	 * @brief adds the passed value to the current total
	 *
	 * This function simply adds the integer value of the argument to the current total
	 *
	 * @param p_value integer value to be added to the current total
	 * */
	void add(int p_value);

	/**
	 * @brief resets the total to zero
	 *
	 * resets the current total to zero
	 */
	void reset();

	/**
	 * @brief returns the current total
	 *
	 * This function returns the current total, which is the sum of all the integers
	 * the summator added together.
	 *
	 * @return the sum of all the integers that were added together
	 */
	int get_total() const;

	/**
	 * @ brief constructor
	 *
	 *  Create a new instance of the Summator class
	 */
	Summator();
};
