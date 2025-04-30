#include "native_util.h"

Error memcpy_from_packed(uint8_t *p_dst, const Vector<uint8_t> p_src, const int p_count) {
	if (p_count > p_src.size())
		return ERR_PARAMETER_RANGE_ERROR;
	else {
		memcpy(p_dst, p_src.ptr(), p_count);
        	return OK;
	}
}

Error memcpy_to_packed(Vector<uint8_t> p_dst, const uint8_t *p_src, const int p_count) {
        if (p_count > p_dst.size())
                return ERR_PARAMETER_RANGE_ERROR;
        else {
                memcpy(p_dst.ptrw(), p_src, p_count);
                return OK;
        }
}

void NativeUtil::_bind_methods() {
	ClassDB::bind_static_method("NativeUtil", D_METHOD("memcpy_from_packed", "dst", "src", "count"), &NativeUtil::memcpy_from_packed);
	ClassDB::bind_static_method("NativeUtil", D_METHOD("memcpy_to_packed", "dst", "src", "count"), &NativeUtil::memcpy_to_packed);
}
