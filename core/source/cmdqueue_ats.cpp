#include "runtime/gen12hp/hw_cmds.h"
#include "runtime/gen12hp/hw_info.h"
#include "cmdqueue_hw.inl"
#include "igfxfmid.h"

namespace L0 {

static CommandQueuePopulateFactory<IGFX_TIGERLAKE_HP, CommandQueueHw<IGFX_GEN12_CORE>> populateTGLHP;

} // namespace L0
