#ifndef NATIVE_UTIL_H
#define NATIVE_UTIL_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/godot.hpp>

using namespace godot;

class NativeUtil : public Object {
	GDCLASS(NativeUtil, Object);

public:
	static Error memcpy_from_packed(int p_dst, const PackedByteArray p_src, int p_count);
        static Error memcpy_to_packed(PackedByteArray p_dst, const int p_src, int p_count);

protected:
	static void _bind_methods();
};
#endif // NATIVE_UTIL_H

