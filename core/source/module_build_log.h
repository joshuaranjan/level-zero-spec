#pragma once
#include "xe_common.h"
#include "xe_module.h"

struct _xe_module_build_log_handle_t {
};

namespace L0 {

struct Module;

struct ModuleBuildLog : public _xe_module_build_log_handle_t {
    static ModuleBuildLog *create(Module *module);

    virtual xe_result_t destroy() = 0;
    virtual xe_result_t getString(uint32_t *pSize,
                                  char **pBuildLog) = 0;

    ModuleBuildLog() = default;
    ModuleBuildLog(const ModuleBuildLog &) = delete;
    ModuleBuildLog(ModuleBuildLog &&) = delete;
    ModuleBuildLog &operator=(const ModuleBuildLog &) = delete;
    ModuleBuildLog &operator=(ModuleBuildLog &&) = delete;

    static ModuleBuildLog *fromHandle(xe_module_build_log_handle_t handle) {
        return static_cast<ModuleBuildLog *>(handle);
    }

    inline xe_module_build_log_handle_t toHandle() {
        return this;
    }
};

} // namespace L0