// This is a generated file
// Check L0::ult::ModuleCreate_onlineCompilationModuleTest_Test::TestBody for details

#include "tests/unit_tests/mock_module_precompiled.h"

namespace L0 {
namespace ult {

static const uint32_t SlmBarrier_SimdSize_Gen12HPcore = 32;

static const uint32_t SlmBarrier_ISA_Gen12HPcore[] = 
{
    0x80030061, 0x7f054220, 0x00000000, 0x00000000, 0x80000065, 0x7f458220, 0x02000004, 0xffffffe0, 
    0x80000065, 0x7f058110, 0x01000044, 0x00ff00ff, 0x80001a40, 0x7f458220, 0x01007f44, 0x00600060, 
    0x8000195b, 0x7f448220, 0x01017f44, 0x00c07f04, 0x00001901, 0x00010000, 0x00000000, 0x00000000, 
    0x80034031, 0x01240000, 0xa9fa7f0c, 0x02100000, 0x80003040, 0x7f458220, 0x01007f44, 0x00800080, 
    0xe8001901, 0x00010001, 0x80034131, 0x05140000, 0xa7fa7f0c, 0x02100000, 0x80033161, 0x7f054220, 
    0x00000000, 0x00000000, 0x80000065, 0x7f458220, 0x02000004, 0xffffffe0, 0xe8001901, 0x00010001, 
    0x80034231, 0x07240000, 0xa9fa7f0c, 0x02100000, 0x80032061, 0x03050220, 0x00100004, 0x00000000, 
    0x80000966, 0x80018220, 0x01008000, 0x04c004c0, 0x00030961, 0x38070110, 0x00460105, 0x00000000, 
    0x00130061, 0x3a070110, 0x00460185, 0x00000000, 0x00230061, 0x3c070110, 0x00460205, 0x00000000, 
    0x00330061, 0x3e070110, 0x00460285, 0x00000000, 0x00031c69, 0x48058170, 0x05303804, 0x00020002, 
    0x00131b69, 0x4a058170, 0x05303a04, 0x00020002, 0x00231a69, 0x4c058170, 0x05303c04, 0x00020002, 
    0x00331969, 0x4e058170, 0x05303e04, 0x00020002, 0xe8002201, 0x00010001, 0x00035440, 0x0c050770, 
    0x07000804, 0x00344805, 0x00030040, 0x18050770, 0x07000844, 0x00344805, 0x00135540, 0x0e050770, 
    0x07000804, 0x00344a05, 0x00130040, 0x1a050770, 0x07000844, 0x00344a05, 0x00235640, 0x10050770, 
    0x07000804, 0x00344c05, 0x00230040, 0x1c050770, 0x07000844, 0x00344c05, 0x00335740, 0x12050770, 
    0x07000804, 0x00344e05, 0x00330040, 0x1e050770, 0x07000844, 0x00344e05, 0xe8005601, 0x00010001, 
    0x00044331, 0x14140000, 0xc3fe0c24, 0x01040000, 0xe8005501, 0x00010001, 0x00044431, 0x20140000, 
    0xc3fe1824, 0x01040000, 0xe8005201, 0x00010001, 0x00244531, 0x16140000, 0xc3fe1024, 0x01040000, 
    0xe8005101, 0x00010001, 0x00244631, 0x22140000, 0xc3fe1c24, 0x01040000, 0x80001e41, 0x20010660, 
    0x01000964, 0x00000324, 0x00040069, 0x24058160, 0x05580105, 0x00020002, 0x00240069, 0x26058160, 
    0x05580205, 0x00020002, 0x80000049, 0x04050660, 0x06000964, 0x00000324, 0x80030065, 0x28058220, 
    0x02000344, 0x7f000000, 0xe8002101, 0x00010001, 0x00041a52, 0x05040968, 0x06060105, 0x07040404, 
    0x00240052, 0x0a040968, 0x06060205, 0x07040404, 0xe8002401, 0x00010001, 0x00042340, 0x14050aa0, 
    0x0a461405, 0x00462005, 0x00049731, 0x00000000, 0xcdfc2414, 0x00961414, 0xe8002601, 0x00010001, 
    0x00242540, 0x16050aa0, 0x0a461605, 0x00462205, 0x00249831, 0x00000000, 0xcdfc2614, 0x00961614, 
    0xe8001b01, 0x00010001, 0x80004931, 0x00000000, 0x3008280c, 0x00000000, 0x80000001, 0x00010000, 
    0xe0000000, 0x00000000, 0x80840070, 0x00018660, 0x15000904, 0x00000000, 0x80a40070, 0x00018660, 
    0x15000904, 0x00000000, 0x01850022, 0x0000c000, 0x00000110, 0x00000028, 0xa2040061, 0x00010060, 
    0x00050024, 0x0000c000, 0x000000f8, 0x000000f8, 0x80000061, 0x04450270, 0x00000904, 0x00000000, 
    0x80010061, 0x29854560, 0x00000000, 0x00000000, 0xa2040061, 0x00010060, 0x62291969, 0x0021295a, 
    0x80000040, 0x29858660, 0x050029a4, 0x00010001, 0xe8001901, 0x00010001, 0x80004a31, 0x2a0c0000, 
    0xa1fc290c, 0x00420000, 0x80000061, 0x04850670, 0x00002984, 0x00000000, 0x80035170, 0x00010330, 
    0x53000484, 0x00000444, 0x80130070, 0x00010330, 0x53000484, 0x00000444, 0x80230070, 0x00010330, 
    0x53000484, 0x00000444, 0x80330070, 0x00010330, 0x53000484, 0x00000444, 0xe8002a01, 0x00010001, 
    0x22041140, 0x2a1104c8, 0x11050028, 0x0000c000, 0x00000020, 0x00000020, 0x80000061, 0x29a50660, 
    0x00002984, 0x00000000, 0x00050027, 0x00004000, 0x00000000, 0xffffff50, 0x00050025, 0x00004000, 
    0x00000000, 0x00000010, 0x80030065, 0x2b058220, 0x02000344, 0x7f000000, 0xe8001901, 0x00010001, 
    0x80004b31, 0x00000000, 0x30082b0c, 0x00000000, 0x80000001, 0x00010000, 0xe0000000, 0x00000000, 
    0x00030061, 0x40060220, 0x00460505, 0x00000000, 0x00130061, 0x42060220, 0x00460605, 0x00000000, 
    0x00230061, 0x44060220, 0x00460a05, 0x00000000, 0x00330061, 0x46060220, 0x00460b05, 0x00000000, 
    0x00031c69, 0x50058670, 0x05204004, 0x00020002, 0x00131b69, 0x52058670, 0x05204204, 0x00020002, 
    0x00231a69, 0x54058670, 0x05204404, 0x00020002, 0x00331969, 0x56058670, 0x05204604, 0x00020002, 
    0x60341161, 0x00010420, 0x00035440, 0x2c050770, 0x07000884, 0x00345005, 0x00135440, 0x2e050770, 
    0x07000884, 0x00345205, 0x66360061, 0x00010420, 0x00235440, 0x30050770, 0x07000884, 0x00345405, 
    0x00335440, 0x32050770, 0x07000884, 0x00345605, 0x0004ac31, 0x00000000, 0xc3fe2c24, 0x01a43414, 
    0x00249d31, 0x00000000, 0xc3fe3024, 0x01a43614, 0x80030061, 0x7f050aa0, 0x00460305, 0x00000000, 
    0x80034e31, 0x580c0000, 0xa000030c, 0x02780000, 0x80032e61, 0x00010220, 0x00465805, 0x00000000, 
    0xe8001101, 0x00010001, 0x80030031, 0x00000004, 0x70207f0c, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const uint32_t SlmBarrier_CrossThreadDataBase_Gen12HPcore[] = 
{
    0x00000000, 0x00000000, 0x00000000, 0x00000020, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 
    0x8420e000, 0x000001b8, 0x84216000, 0x000001b8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000020, 0x00000001, 0x00000001, 0x00000020, 0x00000001, 0x00000001, 0x00000000, 0x00000000
};


static const uint32_t SlmBarrier_PerThreadDataBase_Gen12HPcore[] = 
{
    0x00010000, 0x00030002, 0x00050004, 0x00070006, 0x00090008, 0x000b000a, 0x000d000c, 0x000f000e, 
    0x00110010, 0x00130012, 0x00150014, 0x00170016, 0x00190018, 0x001b001a, 0x001d001c, 0x001f001e, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const bool SlmBarrier_HasBarriers_Gen12HPcore = 1;

static const uint32_t SlmBarrier_SlmSize_Gen12HPcore = 0x40;

static const bool SlmBarrier_HasPrintfOutput_Gen12HPcore = 0;

static const std::pair<int, int> SlmBarrier_BufferArgIndicesAndOffsets_Gen12HPcore[] = { {0x0, 0x20}, {0x1, 0x28},  };

static const uint32_t SlmBarrier_GroupSizeInPerThreadData_Gen12HPcore[] = { 0x20, 0x1, 0x1 };

static const PrecompiledFunctionMockData SlmBarrier_Gen12HPcore {
SlmBarrier_SimdSize_Gen12HPcore,
SlmBarrier_ISA_Gen12HPcore, sizeof(SlmBarrier_ISA_Gen12HPcore),
SlmBarrier_CrossThreadDataBase_Gen12HPcore, sizeof(SlmBarrier_CrossThreadDataBase_Gen12HPcore),
SlmBarrier_PerThreadDataBase_Gen12HPcore, sizeof(SlmBarrier_PerThreadDataBase_Gen12HPcore),
SlmBarrier_GroupSizeInPerThreadData_Gen12HPcore,
SlmBarrier_BufferArgIndicesAndOffsets_Gen12HPcore, sizeof(SlmBarrier_BufferArgIndicesAndOffsets_Gen12HPcore) / sizeof(SlmBarrier_BufferArgIndicesAndOffsets_Gen12HPcore[0]),
SlmBarrier_HasBarriers_Gen12HPcore,
SlmBarrier_SlmSize_Gen12HPcore,
SlmBarrier_HasPrintfOutput_Gen12HPcore
};

RegisterPrecompiledFunctionMocksData Register_SlmBarrier_Gen12HPcore{ & SlmBarrier_Gen12HPcore, "SlmBarrier", "Gen12HPcore" }; 

} // namespace L0
} // namespace ult
