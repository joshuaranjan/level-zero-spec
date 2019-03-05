#pragma once
#include "runtime/command_stream/linear_stream.h"
#include "runtime/helpers/aligned_memory.h"
#include "runtime/helpers/ptr_math.h"
#include "runtime/helpers/basic_math.h"
#include "runtime/memory_manager/graphics_allocation.h"
#include "runtime/memory_manager/memory_constants.h"

namespace OCLRT {
class GraphicsAllocation;
}

namespace L0 {
constexpr size_t defaultHeapSize = 64 * KB;

class IndirectHeap : public OCLRT::LinearStream {
    using BaseClass = LinearStream;
    using GraphicsAllocation = OCLRT::GraphicsAllocation;

  public:
    enum Type {
        DYNAMIC_STATE = 0,
        GENERAL_STATE,
        INDIRECT_OBJECT,
        SURFACE_STATE,
        NUM_TYPES
    };

    IndirectHeap(void *buffer, size_t bufferSize);
    IndirectHeap(GraphicsAllocation *buffer);
    IndirectHeap(GraphicsAllocation *buffer, bool canBeUtilizedAs4GbHeap);

    // Disallow copy'ing
    IndirectHeap(const IndirectHeap &) = delete;
    IndirectHeap &operator=(const IndirectHeap &) = delete;

    void align(size_t alignment);
    uint64_t getHeapGpuStartOffset() const;
    uint64_t getHeapGpuBase() const;
    uint32_t getHeapSizeInPages() const;

  protected:
    bool canBeUtilizedAs4GbHeap = false;
};

inline void IndirectHeap::align(size_t alignment) {
    auto address = alignUp(ptrOffset(buffer, sizeUsed), alignment);
    sizeUsed = ptrDiff(address, buffer);
}

inline uint32_t IndirectHeap::getHeapSizeInPages() const {
    if (this->canBeUtilizedAs4GbHeap)
        return MemoryConstants::sizeOf4GBinPageEntities;

    return (static_cast<uint32_t>(getMaxAvailableSpace()) + MemoryConstants::pageMask) / MemoryConstants::pageSize;
}

inline uint64_t IndirectHeap::getHeapGpuStartOffset() const {
    if (this->canBeUtilizedAs4GbHeap)
        return this->graphicsAllocation->getGpuAddressToPatch();

    return 0llu;
}

inline uint64_t IndirectHeap::getHeapGpuBase() const {
    if (this->canBeUtilizedAs4GbHeap)
        return this->graphicsAllocation->gpuBaseAddress;

    return this->graphicsAllocation->getGpuAddress();
}
} // namespace L0
