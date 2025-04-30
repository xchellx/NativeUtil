#ifndef NATIVE_UTIL_H
#define NATIVE_UTIL_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class NativeUtil : public Object {
	GDCLASS(NativeUtil, Object);

public:
	Error memcpy_from_packed(uint8_t *p_dest, const Vector<uint8_t> p_src, const int p_count);
        Error memcpy_to_packed(Vector<uint8_t> *p_dest, const uint8_t *p_src, const int p_count);

protected:
	static void _bind_methods() {}
};
#endif // NATIVE_UTIL_H

