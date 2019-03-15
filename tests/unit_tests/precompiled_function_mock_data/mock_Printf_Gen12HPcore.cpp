// This is a generated file
// Check L0::ult::ModuleCreate_onlineCompilationModuleTest_Test::TestBody for details

#include "tests/unit_tests/mock_module_precompiled.h"

namespace L0 {
namespace ult {

static const uint32_t Printf_SimdSize_Gen12HPcore = 32;

static const uint32_t Printf_ISA_Gen12HPcore[] = 
{
    0x80030061, 0x7f054220, 0x00000000, 0x00000000, 0x80000065, 0x7f458220, 0x02000004, 0xffffffe0, 
    0x80000065, 0x7f058110, 0x01000044, 0x00ff00ff, 0x80001a40, 0x7f458220, 0x01007f44, 0x00600060, 
    0x8000195b, 0x7f448220, 0x01017f44, 0x00c07f04, 0x00001901, 0x00010000, 0x00000000, 0x00000000, 
    0x80034031, 0x01240000, 0xa9fa7f0c, 0x02100000, 0x80003040, 0x7f458220, 0x01007f44, 0x00800080, 
    0xe8001901, 0x00010001, 0x80034131, 0x05140000, 0xa7fa7f0c, 0x02100000, 0x80033161, 0x7f054220, 
    0x00000000, 0x00000000, 0x80000065, 0x7f458220, 0x02000004, 0xffffffe0, 0xe8001901, 0x00010001, 
    0x80034231, 0x07240000, 0xa9fa7f0c, 0x02100000, 0x80032061, 0x03050220, 0x00100004, 0x00000000, 
    0x80000966, 0x80018220, 0x01008000, 0x04c004c0, 0x80040961, 0x0c054560, 0x00000000, 0x00000000, 
    0x80040061, 0x0e054560, 0x00000000, 0x00000000, 0x00040061, 0x0c054560, 0x00000000, 0x00140014, 
    0x00240061, 0x0e054560, 0x00000000, 0x00140014, 0x80231a40, 0x0c260660, 0x06200c04, 0x00200c24, 
    0x80231a40, 0x0e260660, 0x06200e04, 0x00200e24, 0x80221a40, 0x0c470660, 0x06300c44, 0x00300c24, 
    0x80221a40, 0x0e470660, 0x06300e44, 0x00300e24, 0x80221a40, 0x0c670660, 0x06300c64, 0x00300c24, 
    0x80221a40, 0x0e670660, 0x06300e64, 0x00300e24, 0x80221a40, 0x0c850660, 0x06000c64, 0x00340c85, 
    0x80220040, 0x0d850660, 0x06000d64, 0x00340d85, 0x80221b40, 0x0e850660, 0x06000e64, 0x00340e85, 
    0x80220040, 0x0f850660, 0x06000f64, 0x00340f85, 0x80231b40, 0x0d050660, 0x06000ce4, 0x00460d05, 
    0x80231a40, 0x0f050660, 0x06000ee4, 0x00460f05, 0x80002261, 0x04050330, 0x000008c4, 0x00000000, 
    0x80241940, 0x0e050660, 0x06000de4, 0x00460e05, 0x80001961, 0x08050660, 0x00000fe4, 0x00000000, 
    0x80009131, 0x100c0000, 0xcffe0414, 0x0128080c, 0x80042140, 0x0c050660, 0x02460c05, 0x00001004, 
    0x80040040, 0x0e050660, 0x02460e05, 0x00001004, 0x00041a40, 0x05058660, 0x05460c05, 0xffecffec, 
    0x00040040, 0x11058660, 0x05460c05, 0x00000000, 0x00241b40, 0x0a058660, 0x05460e05, 0xffecffec, 
    0x00240040, 0x13058660, 0x05460e05, 0x00000000, 0x00031c61, 0x48060220, 0x00460505, 0x00000000, 
    0x00130061, 0x4a060220, 0x00460605, 0x00000000, 0x00841d70, 0x00018260, 0x52461105, 0x00400001, 
    0x00231d61, 0x4c060220, 0x00460a05, 0x00000000, 0x00330061, 0x4e060220, 0x00460b05, 0x00000000, 
    0x00a41e70, 0x00018260, 0x52461305, 0x00400001, 0x00031e40, 0x50050770, 0x020008c4, 0x00204804, 
    0x00131d40, 0x52050770, 0x020008c4, 0x00204a04, 0x00231b40, 0x54050770, 0x020008c4, 0x00204c04, 
    0x00331a40, 0x56050770, 0x020008c4, 0x00204e04, 0x0185002e, 0x0000c000, 0x00000090, 0x00000090, 
    0x00040040, 0x15058660, 0x05460505, 0x00040004, 0x00240040, 0x17058660, 0x05460a05, 0x00040004, 
    0x00041a70, 0x00018260, 0x52461505, 0x00400001, 0x00241a70, 0x00018260, 0x52461705, 0x00400001, 
    0x1105002e, 0x0000c000, 0x000002c8, 0x00000040, 0x00040061, 0x19054560, 0x00000000, 0xffffffff, 
    0x00240061, 0x1b054560, 0x00000000, 0xffffffff, 0x0005002e, 0x0000c000, 0x00000228, 0x00000010, 
    0x0005002f, 0x00004000, 0x00000000, 0x00000218, 0x80000061, 0x36054130, 0x00000000, 0x00030003, 
    0x80200061, 0x37054130, 0x00000000, 0x00030003, 0x22200041, 0x03110916, 0x00035661, 0x1e050330, 
    0x00345005, 0x00000000, 0x00135661, 0x20050330, 0x00345205, 0x00000000, 0x00040061, 0x26054560, 
    0x00000000, 0x00000000, 0x00235661, 0x22050330, 0x00345405, 0x00000000, 0x00335661, 0x24050330, 
    0x00345605, 0x00000000, 0x00240061, 0x28054560, 0x00000000, 0x00000000, 0x00040061, 0x2e050660, 
    0x00003644, 0x00000000, 0x00045661, 0x2c050660, 0x00003624, 0x00000000, 0x00030040, 0x38058770, 
    0x05345005, 0x00040004, 0x00130040, 0x3a058770, 0x05345205, 0x00040004, 0x00240061, 0x34050660, 
    0x00003744, 0x00000000, 0x602a0061, 0x00013600, 0x00245761, 0x32050660, 0x00003724, 0x00000000, 
    0x00040061, 0x2e054560, 0x00000000, 0x00030003, 0x00040061, 0x2c050160, 0x00580105, 0x00000000, 
    0x00230040, 0x3c058770, 0x05345405, 0x00040004, 0x00330040, 0x3e058770, 0x05345605, 0x00040004, 
    0x66300061, 0x00013700, 0xa21d0049, 0x03110912, 0x00240061, 0x34054560, 0x00000000, 0x00030003, 
    0x00240061, 0x32050160, 0x00580205, 0x00000000, 0xe8005701, 0x00010001, 0x00044331, 0x00000000, 
    0xc3fe1e24, 0x01a42614, 0x0024d431, 0x00000000, 0xc3fe2224, 0x01a42814, 0x0004a531, 0x00000000, 
    0xc1fe3824, 0x01962a34, 0x00249631, 0x00000000, 0xc1fe3c24, 0x01963034, 0x00041b52, 0x19040968, 
    0x06060105, 0x07041d04, 0x00240052, 0x1b040968, 0x06060205, 0x07041d04, 0x00030040, 0x50058770, 
    0x05345005, 0x00100010, 0x00130040, 0x52058770, 0x05345205, 0x00100010, 0x00230040, 0x54058770, 
    0x05345405, 0x00100010, 0x00330040, 0x56058770, 0x05345605, 0x00100010, 0x0005002f, 0x00004000, 
    0x00000000, 0x00000070, 0x00035461, 0x40050330, 0x00345005, 0x00000000, 0x00135461, 0x42050330, 
    0x00345205, 0x00000000, 0x00235461, 0x44050330, 0x00345405, 0x00000000, 0x00335461, 0x46050330, 
    0x00345605, 0x00000000, 0x0004b731, 0x00000000, 0xc3fe4024, 0x01a41914, 0x00249831, 0x00000000, 
    0xc3fe4424, 0x01a41b14, 0x0005002f, 0x00004000, 0x00000000, 0x00000010, 0x80030061, 0x7f050aa0, 
    0x00460305, 0x00000000, 0x80034931, 0x580c0000, 0xa000030c, 0x02780000, 0x80032961, 0x00010220, 
    0x00465805, 0x00000000, 0xe8001101, 0x00010001, 0x80030031, 0x00000004, 0x70207f0c, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const uint32_t Printf_CrossThreadDataBase_Gen12HPcore[] = 
{
    0x00000000, 0x00000000, 0x00000000, 0x00000020, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 
    0x84e10000, 0x000001b8, 0x841c2000, 0x000001b8, 0x84660000, 0x000001b8, 0x00000000, 0x00000000, 
    0x00000020, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const uint32_t Printf_PerThreadDataBase_Gen12HPcore[] = 
{
    0x00010000, 0x00030002, 0x00050004, 0x00070006, 0x00090008, 0x000b000a, 0x000d000c, 0x000f000e, 
    0x00110010, 0x00130012, 0x00150014, 0x00170016, 0x00190018, 0x001b001a, 0x001d001c, 0x001f001e, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const bool Printf_HasBarriers_Gen12HPcore = 0;

static const uint32_t Printf_SlmSize_Gen12HPcore = 0x0;

static const bool Printf_HasPrintfOutput_Gen12HPcore = 1;

static const std::pair<int, int> Printf_BufferArgIndicesAndOffsets_Gen12HPcore[] = { {0x0, 0x20}, {0x1, 0x28},  };

static const uint32_t Printf_GroupSizeInPerThreadData_Gen12HPcore[] = { 0x20, 0x1, 0x1 };

static const PrecompiledFunctionMockData Printf_Gen12HPcore {
Printf_SimdSize_Gen12HPcore,
Printf_ISA_Gen12HPcore, sizeof(Printf_ISA_Gen12HPcore),
Printf_CrossThreadDataBase_Gen12HPcore, sizeof(Printf_CrossThreadDataBase_Gen12HPcore),
Printf_PerThreadDataBase_Gen12HPcore, sizeof(Printf_PerThreadDataBase_Gen12HPcore),
Printf_GroupSizeInPerThreadData_Gen12HPcore,
Printf_BufferArgIndicesAndOffsets_Gen12HPcore, sizeof(Printf_BufferArgIndicesAndOffsets_Gen12HPcore) / sizeof(Printf_BufferArgIndicesAndOffsets_Gen12HPcore[0]),
Printf_HasBarriers_Gen12HPcore,
Printf_SlmSize_Gen12HPcore,
Printf_HasPrintfOutput_Gen12HPcore
};

RegisterPrecompiledFunctionMocksData Register_Printf_Gen12HPcore{ & Printf_Gen12HPcore, "Printf", "Gen12HPcore" }; 

} // namespace L0
} // namespace ult
