// This is a generated file
// Check L0::ult::ModuleCreate_onlineCompilationModuleTest_Test::TestBody for details

#include "tests/unit_tests/mock_module_precompiled.h"

namespace L0 {
namespace ult {

static const uint32_t Printf_SimdSize_Gen9core = 32;

static const uint32_t Printf_ISA_Gen9core[] = 
{
    0x00600001, 0x2060020c, 0x00200000, 0x00000000, 0x00008006, 0x30000004, 0x16001000, 0x04c004c0, 
    0x00800001, 0x21801e2c, 0x00000000, 0x00000000, 0x00800001, 0x21c01e2c, 0x00000000, 0x00000000, 
    0x00800001, 0x21801e28, 0x00000000, 0x00140014, 0x00802001, 0x21c01e28, 0x00000000, 0x00140014, 
    0x00000001, 0x2080430c, 0x00000118, 0x00000000, 0x00602040, 0x41840a2c, 0x0a400180, 0x00400184, 
    0x00602040, 0x41c40a2c, 0x0a4001c0, 0x004001c4, 0x00402040, 0x61880a2c, 0x0a600188, 0x00600184, 
    0x00402040, 0x61c80a2c, 0x0a6001c8, 0x006001c4, 0x00402040, 0x618c0a2c, 0x0a60018c, 0x00600184, 
    0x00402040, 0x61cc0a2c, 0x0a6001cc, 0x006001c4, 0x00402040, 0x21900a2c, 0x0a00018c, 0x00690190, 
    0x00402040, 0x21b00a2c, 0x0a0001ac, 0x006901b0, 0x00402040, 0x21d00a2c, 0x0a0001cc, 0x006901d0, 
    0x00402040, 0x21f00a2c, 0x0a0001ec, 0x006901f0, 0x00602040, 0x21a00a2c, 0x0a00019c, 0x008d01a0, 
    0x00602040, 0x21e00a2c, 0x0a0001dc, 0x008d01e0, 0x00802040, 0x21c00a2c, 0x0a0001bc, 0x008d01c0, 
    0x00000001, 0x21000a2c, 0x000001fc, 0x00000000, 0x0c000033, 0x0200801c, 0x00000081, 0x0414a7ff, 
    0x00800040, 0x21800a2c, 0x028d0180, 0x00000200, 0x00800040, 0x21c00a2c, 0x028d01c0, 0x00000200, 
    0x00800040, 0x22200a28, 0x1e8d0180, 0x00000000, 0x00802040, 0x22600a28, 0x1e8d01c0, 0x00000000, 
    0x00800040, 0x20a00a28, 0x1e8d0180, 0xffecffec, 0x00802040, 0x21400a28, 0x1e8d01c0, 0xffecffec, 
    0x05800010, 0x20000220, 0x068d0220, 0x00400001, 0x05802010, 0x20000220, 0x068d0260, 0x00400001, 
    0x00600040, 0x29604b28, 0x02000118, 0x008d00a0, 0x00601040, 0x29a04b28, 0x02000118, 0x008d00c0, 
    0x00602040, 0x29e04b28, 0x02000118, 0x008d0140, 0x00603040, 0x2a204b28, 0x02000118, 0x008d0160, 
    0x00b1002e, 0x20000e00, 0x000000a0, 0x000000a0, 0x00800040, 0x22a00a28, 0x1e8d00a0, 0x00040004, 
    0x00802040, 0x22e00a28, 0x1e8d0140, 0x00040004, 0x05800010, 0x20000222, 0x068d02a0, 0x00400001, 
    0x05802010, 0x20000222, 0x068d02e0, 0x00400001, 0x00a1002e, 0x20000e02, 0x000002e0, 0x00000050, 
    0x00000001, 0x26001604, 0x00000000, 0x00000000, 0x00800001, 0x23201e28, 0x00000000, 0xffffffff, 
    0x00802001, 0x23601e28, 0x00000000, 0xffffffff, 0x00a1002e, 0x20000e00, 0x00000230, 0x00000010, 
    0x00a0002f, 0x20000000, 0x0e000000, 0x00000220, 0x00000001, 0x2720170c, 0x00000000, 0x00030003, 
    0x00002001, 0x2740170c, 0x00000000, 0x00030003, 0x00000041, 0x20880a2c, 0x0a000120, 0x00000064, 
    0x00600001, 0x24204308, 0x00690960, 0x00000000, 0x00601001, 0x24604308, 0x006909a0, 0x00000000, 
    0x00800001, 0x25201e28, 0x00000000, 0x00000000, 0x00602001, 0x24a04308, 0x006909e0, 0x00000000, 
    0x00603001, 0x24e04308, 0x00690a20, 0x00000000, 0x00802001, 0x25601e28, 0x00000000, 0x00000000, 
    0x201ad601, 0x00393100, 0x2016d601, 0x00392f00, 0x00600040, 0x27604b28, 0x1e690960, 0x00040004, 
    0x00601040, 0x27a04b28, 0x1e6909a0, 0x00040004, 0x00802001, 0x26e00a28, 0x00000748, 0x00000000, 
    0x2002d601, 0x00392d00, 0x00802001, 0x26a00a28, 0x00000744, 0x00000000, 0x00800001, 0x26201e28, 
    0x00000000, 0x00030003, 0x00800001, 0x25e01228, 0x00b10020, 0x00000000, 0x00602040, 0x27e04b28, 
    0x1e6909e0, 0x00040004, 0x00603040, 0x28204b28, 0x1e690a20, 0x00040004, 0x00802001, 0x26600a28, 
    0x00000740, 0x00000000, 0x00800040, 0x23a01228, 0x0ab10020, 0x00000088, 0x00802040, 0x23e01228, 
    0x0ab10040, 0x00000088, 0x00802001, 0x26e01e28, 0x00000000, 0x00030003, 0x00802001, 0x26a01228, 
    0x00b10040, 0x00000000, 0x0c800033, 0x00029070, 0x00000422, 0x080691ff, 0x20019640, 0x071d1907, 
    0x0c802033, 0x0002b070, 0x000004a2, 0x080691ff, 0x00802040, 0x23600a28, 0x0a8d03e0, 0x000000e0, 
    0x0c800033, 0x0002d070, 0x00000766, 0x080658ff, 0x00600040, 0x29604b28, 0x1e690960, 0x00100010, 
    0x0c802033, 0x00033070, 0x000007e6, 0x080658ff, 0x00601040, 0x29a04b28, 0x1e6909a0, 0x00100010, 
    0x00602040, 0x29e04b28, 0x1e6909e0, 0x00100010, 0x00603040, 0x2a204b28, 0x1e690a20, 0x00100010, 
    0x00a0002f, 0x20000000, 0x0e000000, 0x00000070, 0x00600001, 0x28604308, 0x00690960, 0x00000000, 
    0x00601001, 0x28a04308, 0x006909a0, 0x00000000, 0x00602001, 0x28e04308, 0x006909e0, 0x00000000, 
    0x00603001, 0x29204308, 0x00690a20, 0x00000000, 0x0c800033, 0x00019070, 0x00000862, 0x080691ff, 
    0x0c802033, 0x0001b070, 0x000008e2, 0x080691ff, 0x00a0002f, 0x20000000, 0x0e000000, 0x00000000, 
    0x20004d01, 0x00037f07, 0x07600031, 0x20000204, 0x06000fe0, 0x82000010, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const uint32_t Printf_CrossThreadDataBase_Gen9core[] = 
{
    0x00000000, 0x00000000, 0x00000000, 0x00000020, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 
    0xd5a68000, 0x0000016c, 0xd5a6e000, 0x0000016c, 0xd5f90000, 0x0000016c, 0x00000000, 0x00000000, 
    0x00000020, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const uint32_t Printf_PerThreadDataBase_Gen9core[] = 
{
    0x00010000, 0x00030002, 0x00050004, 0x00070006, 0x00090008, 0x000b000a, 0x000d000c, 0x000f000e, 
    0x00110010, 0x00130012, 0x00150014, 0x00170016, 0x00190018, 0x001b001a, 0x001d001c, 0x001f001e, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const bool Printf_HasBarriers_Gen9core = 0;

static const uint32_t Printf_SlmSize_Gen9core = 0x0;

static const bool Printf_HasPrintfOutput_Gen9core = 1;

static const std::pair<int, int> Printf_BufferArgIndicesAndOffsets_Gen9core[] = { {0x0, 0x20}, {0x1, 0x28},  };

static const uint32_t Printf_GroupSizeInPerThreadData_Gen9core[] = { 0x20, 0x1, 0x1 };

static const PrecompiledFunctionMockData Printf_Gen9core {
Printf_SimdSize_Gen9core,
Printf_ISA_Gen9core, sizeof(Printf_ISA_Gen9core),
Printf_CrossThreadDataBase_Gen9core, sizeof(Printf_CrossThreadDataBase_Gen9core),
Printf_PerThreadDataBase_Gen9core, sizeof(Printf_PerThreadDataBase_Gen9core),
Printf_GroupSizeInPerThreadData_Gen9core,
Printf_BufferArgIndicesAndOffsets_Gen9core, sizeof(Printf_BufferArgIndicesAndOffsets_Gen9core) / sizeof(Printf_BufferArgIndicesAndOffsets_Gen9core[0]),
Printf_HasBarriers_Gen9core,
Printf_SlmSize_Gen9core,
Printf_HasPrintfOutput_Gen9core
};

RegisterPrecompiledFunctionMocksData Register_Printf_Gen9core{ & Printf_Gen9core, "Printf", "Gen9core" }; 

} // namespace L0
} // namespace ult