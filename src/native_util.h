#ifndef NATIVE_UTIL_H
#define NATIVE_UTIL_H

#ifdef WIN32
#include <windows.h>
#endif

#include <gdextension_interface.h>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/type_info.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/method_bind.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/templates/vector.hpp>

using namespace godot;

class NativeUtil : public Object {
	GDCLASS(NativeUtil, Object);

public:
	static Error memcpy_from_packed(uint8_t *p_dst, const Vector<uint8_t> p_src, const int p_count);
        static Error memcpy_to_packed(Vector<uint8_t> p_dst, const uint8_t *p_src, const int p_count);

protected:
	static void _bind_methods();
};
#endif // NATIVE_UTIL_H

