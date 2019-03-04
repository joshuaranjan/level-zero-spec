#include "runtime/gen9/hw_cmds.h"
#include "runtime/gen9/hw_info.h"
#include "cmdqueue_hw.inl"
#include "igfxfmid.h"

namespace L0 {

static CommandQueuePopulateFactory<IGFX_KABYLAKE, CommandQueueHw<IGFX_GEN9_CORE>> populateKBL;

} // namespace L0