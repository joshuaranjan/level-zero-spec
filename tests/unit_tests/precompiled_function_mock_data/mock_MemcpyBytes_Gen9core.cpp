// This is a generated file
// Check L0::ult::ModuleCreate_onlineCompilationModuleTest_Test::TestBody for details

#include "tests/unit_tests/mock_module_precompiled.h"

namespace L0 {
namespace ult {

static const uint32_t MemcpyBytes_SimdSize_Gen9core = 32;

static const uint32_t MemcpyBytes_ISA_Gen9core[] = 
{
    0x00600001, 0x2060020c, 0x00200000, 0x00000000, 0x00008006, 0x30000004, 0x16001000, 0x04c004c0, 
    0x00000041, 0x20800a2c, 0x0a000110, 0x00000064, 0x20004d01, 0x00037f07, 0x00800040, 0x20a01228, 
    0x0ab10020, 0x00000080, 0x00802040, 0x21201228, 0x0ab10040, 0x00000080, 0x20019640, 0x07050507, 
    0x00802040, 0x21200a28, 0x0a8d0120, 0x000000e0, 0x00600040, 0x21604b28, 0x02000108, 0x008d00a0, 
    0x00601040, 0x21a04b28, 0x02000108, 0x008d00c0, 0x00602040, 0x21e04b28, 0x02000108, 0x008d0120, 
    0x00603040, 0x22204b28, 0x02000108, 0x008d0140, 0x00600040, 0x22e04b28, 0x02000100, 0x008d00a0, 
    0x00601040, 0x23204b28, 0x02000100, 0x008d00c0, 0x00602040, 0x23604b28, 0x02000100, 0x008d0120, 
    0x00603040, 0x23a04b28, 0x02000100, 0x008d0140, 0x0c800031, 0x22604268, 0x06000160, 0x082410ff, 
    0x0c802031, 0x22a04268, 0x060001e0, 0x082410ff, 0x00800001, 0x23e02208, 0x00600260, 0x00000000, 
    0x00802001, 0x24202208, 0x006002a0, 0x00000000, 0x0c800033, 0x0001f070, 0x000002e2, 0x080690ff, 
    0x0c802033, 0x00021070, 0x00000362, 0x080690ff, 0x07600031, 0x20000204, 0x06000fe0, 0x82000010, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const uint32_t MemcpyBytes_CrossThreadDataBase_Gen9core[] = 
{
    0x00000000, 0x00000000, 0x00000000, 0x00000020, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 
    0x6edc3000, 0x000002b1, 0x6ee0f000, 0x000002b1, 0x00000020, 0x00000001, 0x00000001, 0x00000000
};


static const uint32_t MemcpyBytes_PerThreadDataBase_Gen9core[] = 
{
    0x00010000, 0x00030002, 0x00050004, 0x00070006, 0x00090008, 0x000b000a, 0x000d000c, 0x000f000e, 
    0x00110010, 0x00130012, 0x00150014, 0x00170016, 0x00190018, 0x001b001a, 0x001d001c, 0x001f001e, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const bool MemcpyBytes_HasBarriers_Gen9core = 0;

static const uint32_t MemcpyBytes_SlmSize_Gen9core = 0x0;

static const std::pair<int, int> MemcpyBytes_BufferArgIndicesAndOffsets_Gen9core[] = { {0x0, 0x20}, {0x1, 0x28},  };

static const uint32_t MemcpyBytes_GroupSizeInPerThreadData_Gen9core[] = { 0x20, 0x1, 0x1 };

static const PrecompiledFunctionMockData MemcpyBytes_Gen9core {
MemcpyBytes_SimdSize_Gen9core,
MemcpyBytes_ISA_Gen9core, sizeof(MemcpyBytes_ISA_Gen9core),
MemcpyBytes_CrossThreadDataBase_Gen9core, sizeof(MemcpyBytes_CrossThreadDataBase_Gen9core),
MemcpyBytes_PerThreadDataBase_Gen9core, sizeof(MemcpyBytes_PerThreadDataBase_Gen9core),
MemcpyBytes_GroupSizeInPerThreadData_Gen9core,
MemcpyBytes_BufferArgIndicesAndOffsets_Gen9core, sizeof(MemcpyBytes_BufferArgIndicesAndOffsets_Gen9core) / sizeof(MemcpyBytes_BufferArgIndicesAndOffsets_Gen9core[0]),
MemcpyBytes_HasBarriers_Gen9core,
MemcpyBytes_SlmSize_Gen9core
};

RegisterPrecompiledFunctionMocksData Register_MemcpyBytes_Gen9core{ & MemcpyBytes_Gen9core, "MemcpyBytes", "Gen9core" }; 

} // namespace L0
} // namespace ult
