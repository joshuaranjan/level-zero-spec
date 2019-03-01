#pragma once
#include "device.h"
#include "xe_image.h"

struct _xe_image_handle_t {
};

namespace L0 {

struct Image : public _xe_image_handle_t {
    virtual xe_result_t destroy() = 0;

    static Image *create(const xe_image_desc_t *desc);

    static Image *fromHandle(xe_image_handle_t handle) {
        return static_cast<Image *>(handle);
    }

    inline xe_image_handle_t toHandle() {
        return this;
    }
};

} // namespace L0
