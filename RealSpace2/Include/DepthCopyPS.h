#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//   fxc /Eps_main /Tps_3_0 /FhInclude/DepthCopyPS.h /VnDepthCopyPSData
//    Source/DepthCopy.hlsl /O3
//
//
// Parameters:
//
//   sampler2D depthTexture;
//   float g_Far;
//   float g_Near;
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   g_Near       c0       1
//   g_Far        c1       1
//   depthTexture s0       1
//

    ps_3_0
    def c2, 1, 0, 0, 0
    dcl_texcoord v0.xy
    dcl_2d s0
    mov r0.x, c1.x
    texld r1, v0, s0
    lrp r2.x, r1.x, r0.x, c0.x
    mul r0.x, r1.x, c1.x
    rcp r0.y, r2.x
    mul oDepth, r0.y, r0.x
    mov oC0, c2.x

// approximately 7 instruction slots used (1 texture, 6 arithmetic)
#endif

const BYTE DepthCopyPSData[] =
{
      0,   3, 255, 255, 254, 255, 
     53,   0,  67,  84,  65,  66, 
     28,   0,   0,   0, 158,   0, 
      0,   0,   0,   3, 255, 255, 
      3,   0,   0,   0,  28,   0, 
      0,   0,   0, 129,   0,   0, 
    151,   0,   0,   0,  88,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   2,   0, 104,   0, 
      0,   0,   0,   0,   0,   0, 
    120,   0,   0,   0,   2,   0, 
      1,   0,   1,   0,   6,   0, 
    128,   0,   0,   0,   0,   0, 
      0,   0, 144,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      2,   0, 128,   0,   0,   0, 
      0,   0,   0,   0, 100, 101, 
    112, 116, 104,  84, 101, 120, 
    116, 117, 114, 101,   0, 171, 
    171, 171,   4,   0,  12,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    103,  95,  70,  97, 114,   0, 
    171, 171,   0,   0,   3,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    103,  95,  78, 101,  97, 114, 
      0, 112, 115,  95,  51,  95, 
     48,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  57,  46,  50,  57,  46, 
     57,  53,  50,  46,  51,  49, 
     49,  49,   0, 171,  81,   0, 
      0,   5,   2,   0,  15, 160, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  31,   0, 
      0,   2,   5,   0,   0, 128, 
      0,   0,   3, 144,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      0,   8,  15, 160,   1,   0, 
      0,   2,   0,   0,   1, 128, 
      1,   0,   0, 160,  66,   0, 
      0,   3,   1,   0,  15, 128, 
      0,   0, 228, 144,   0,   8, 
    228, 160,  18,   0,   0,   4, 
      2,   0,   1, 128,   1,   0, 
      0, 128,   0,   0,   0, 128, 
      0,   0,   0, 160,   5,   0, 
      0,   3,   0,   0,   1, 128, 
      1,   0,   0, 128,   1,   0, 
      0, 160,   6,   0,   0,   2, 
      0,   0,   2, 128,   2,   0, 
      0, 128,   5,   0,   0,   3, 
      0,   8,  15, 144,   0,   0, 
     85, 128,   0,   0,   0, 128, 
      1,   0,   0,   2,   0,   8, 
     15, 128,   2,   0,   0, 160, 
    255, 255,   0,   0
};
