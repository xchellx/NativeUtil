#include "native_util.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/class_db.hpp>

Error memcpy_from_packed(int p_dst, const PackedByteArray p_src, int p_count) {
	if (p_count > p_src.size())
		return ERR_PARAMETER_RANGE_ERROR;
	else {
		uint8_t *p_dst_ptr = reinterpret_cast<uint8_t *>(&p_dst);
		memcpy(p_dst_ptr, p_src.ptr(), p_count);
        	return OK;
	}
}

Error memcpy_to_packed(PackedByteArray p_dst, const int p_src, int p_count) {
        if (p_count > p_dst.size())
                return ERR_PARAMETER_RANGE_ERROR;
        else {
		const uint8_t *p_src_ptr = reinterpret_cast<const uint8_t *>(&p_src);
                memcpy(p_dst.ptrw(), p_src_ptr, p_count);
                return OK;
        }
}

void NativeUtil::_bind_methods() {
	ClassDB::bind_static_method("NativeUtil", D_METHOD("memcpy_from_packed", "dst", "src", "count"), &NativeUtil::memcpy_from_packed);
	ClassDB::bind_static_method("NativeUtil", D_METHOD("memcpy_to_packed", "dst", "src", "count"), &NativeUtil::memcpy_to_packed);
}
