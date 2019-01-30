#pragma once
#ifndef CMD_LIST_INTERNAL
#error "Don't #include this file directly."
#endif //CMD_LIST_INTERNAL

#include "cmd_list.h"

namespace OCLRT {
class LinearStream;
}

namespace xe {
struct GraphicsAllocation;

struct CommandListImp : public CommandList {
    CommandListImp(Device *device)
        : device(device),
          allocation(nullptr),
          commandStream(nullptr) {
    }

    xe_result_t destroy() override;

    virtual bool initialize();

  protected:
    virtual ~CommandListImp();

    Device *device;
    GraphicsAllocation *allocation;
    OCLRT::LinearStream *commandStream;
};

} // namespace xe
