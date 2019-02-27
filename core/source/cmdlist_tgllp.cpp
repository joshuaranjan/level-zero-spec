#include "runtime/gen12lp/hw_cmds.h"
#include "runtime/gen12lp/hw_info.h"
#include "cmdlist_hw.inl"
#include "igfxfmid.h"

namespace L0 {

template <>
struct CommandListProductFamily<IGFX_TIGERLAKE_LP> : public CommandListCoreFamily<IGFX_GEN12LP_CORE> {
    using CommandListCoreFamily::CommandListCoreFamily;
};

static CommandListPopulateFactory<IGFX_TIGERLAKE_LP, CommandListProductFamily<IGFX_TIGERLAKE_LP>> populateTGLLP;

} // namespace L0
