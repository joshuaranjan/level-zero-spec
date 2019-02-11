#pragma once
#define CMD_LIST_INTERNAL
#include "cmdlist_imp.h"
#undef CMD_LIST_INTERNAL

namespace xe {

template <uint32_t gfxCoreFamily>
struct CommandListHw : public CommandListImp {
    CommandListHw(Device *device) : CommandListImp(device) {
    }

    xe_result_t close() override;
    xe_result_t encodeSignalEvent(xe_event_handle_t hEvent) override;
    xe_result_t encodeWaitOnEvent(xe_event_handle_t hEvent) override;
};

} // namespace xe
