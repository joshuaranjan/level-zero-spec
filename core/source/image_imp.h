#pragma once
#ifndef IMAGE_INTERNAL
#error "Don't #include this file directly."
#endif //CMD_LIST_INTERNAL

#include "image.h"

namespace L0 {

struct ImageImp : public Image {

    xe_result_t destroy() override;

    virtual bool initialize();

    ImageImp(const xe_image_desc_t *desc) {
        if (desc)
            imageDesc = *desc;
    }

protected:
    xe_image_desc_t imageDesc;
};

} //namespace L0