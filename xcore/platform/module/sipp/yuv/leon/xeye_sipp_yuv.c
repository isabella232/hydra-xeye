///
/// @file
/// @copyright All code copyright Movidius Ltd 2014, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief     This file contains the source code of the SIPP pipeline
///            generated by the SIPP Graph Designer.
///
///
///  ************************ DO NOT EDIT, THIS IS A GENERATED FILE!!!! ************************
///

#ifdef __cplusplus
extern "C" {
#endif
#include "xeye_sipp_yuv.h"

#include <include/sippHwDefs.h>
#include <arch/ma2x5x/include/sippHwDefs_ma2x5x.h>
#include "sensor_common.h"
#include "xeye_info.h"

#ifdef _cplusplus
}
#endif

static SensorType_t Xeye_Sensor;

void SippSetSensorType(const int sensor_type)
{
    Xeye_Sensor = sensor_type;
}

void sipp_platform_init(void) {
    sippPlatformInit();
}

void readCam214SIPPDebayerHdmiInput(Cam214SIPPDebayerHdmi *pPl)
{
   //Ensure parameter is used to avoid compiler warning
   (void)(pPl);
}

void writeCam214SIPPDebayerHdmiOutput(Cam214SIPPDebayerHdmi *pPl)
{
   //Ensure parameter is used to avoid compiler warning
   (void)(pPl);
}

void buildCam214SIPPDebayerHdmi(Cam214SIPPDebayerHdmi *pPl)
{
    // create new pipeline
    pPl->pl               = sippCreatePipeline(0, 2, SIPP_MBIN(mbinImgSipp));

    // create filters
    if (Xeye_Sensor == Sensor_IMX378) {
        pPl->dmaIn0          =  sippCreateFilter(pPl->pl, 0x00,SIPP_ISP_PIPE_BUFFER_WIDTH_IMX378, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX378, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(UInt16), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
        pPl->sigmaDnsMa2x5x0 =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX378, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX378, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(UInt16), SIPP_AUTO,          (FnSvuRun)SIPP_SIGMA_ID,      0);
        pPl->lscMa2x5x0      =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX378, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX378, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(UInt16), SIPP_AUTO,          (FnSvuRun)SIPP_LSC_ID,        0);
        pPl->rawMa2x5x0      =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX378, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX378, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_RAW_ID,        0);
        pPl->debayerMa2x5x0  =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX378, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX378, N_PL(3),  SZ(UInt16), SIPP_AUTO,          (FnSvuRun)SIPP_DBYR_ID,       0);
        sippFilterAddOBuf(pPl->debayerMa2x5x0, SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES, sizeof(fp16));
        pPl->dogLtmMa2x5x0   =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX378, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX378, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(fp16), SIPP_AUTO,          (FnSvuRun)SIPP_DOGL_ID,       0);
        pPl->ydnsMa2x5x0     =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX378, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX378, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(fp16), SIPP_AUTO,          (FnSvuRun)SIPP_LUMA_ID,       0);
        pPl->sharpenMa2x5x0  =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX378, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX378, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(fp16), SIPP_AUTO,          (FnSvuRun)SIPP_SHARPEN_ID,    0);
        pPl->chromaGenMa2x5x0 =  sippCreateFilter(pPl->pl, SIPP_RESIZE, ISPC_CHROMA_PIPE_WIDTH_IMX378, ISPC_CHROMA_PIPE_HEIGHT_IMX378, N_PL(3),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_CGEN_ID,       0);
        pPl->medianMa2x5x0   =  sippCreateFilter(pPl->pl, 0x0,        ISPC_CHROMA_PIPE_WIDTH_IMX378, ISPC_CHROMA_PIPE_HEIGHT_IMX378, N_PL(3),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_MED_ID,        0);
        pPl->chromadnsMa2x5x0 =  sippCreateFilter(pPl->pl, 0x0,        ISPC_CHROMA_PIPE_WIDTH_IMX378, ISPC_CHROMA_PIPE_HEIGHT_IMX378, N_PL(3),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_CHROMA_ID,     0);
        pPl->colorcombMa2x5x0 =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX378, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX378, N_PL(3),  SZ(UInt16), SIPP_AUTO,          (FnSvuRun)SIPP_CC_ID,         0);
        pPl->lutMa2x5x0      =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX378, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX378, N_PL(3),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_LUT_ID,        0);
        pPl->polyphasefirMa2x5xY =  sippCreateFilter(pPl->pl, SIPP_RESIZE, POLY_Y_IMAGE_WIDTH_IMX378, POLY_Y_IMAGE_HEIGHT_IMX378, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_UPFIRDN_ID,    0);
        pPl->polyphasefirMa2x5xU =  sippCreateFilter(pPl->pl, SIPP_RESIZE, POLY_UV_IMAGE_WIDTH_IMX378, POLY_UV_IMAGE_HEIGHT_IMX378, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_UPFIRDN_ID,    0);
        pPl->polyphasefirMa2x5xV =  sippCreateFilter(pPl->pl, SIPP_RESIZE, POLY_UV_IMAGE_WIDTH_IMX378, POLY_UV_IMAGE_HEIGHT_IMX378, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_UPFIRDN_ID,    0);
        pPl->dmaOutY         =  sippCreateFilter(pPl->pl, 0x00,       POLY_Y_IMAGE_WIDTH_IMX378, POLY_Y_IMAGE_HEIGHT_IMX378, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
        pPl->dmaOutU         =  sippCreateFilter(pPl->pl, 0x00,       POLY_UV_IMAGE_WIDTH_IMX378, POLY_UV_IMAGE_HEIGHT_IMX378, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
        pPl->dmaOutV         =  sippCreateFilter(pPl->pl, 0x00,       POLY_UV_IMAGE_WIDTH_IMX378, POLY_UV_IMAGE_HEIGHT_IMX378, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
    } else {
        pPl->dmaIn0          =  sippCreateFilter(pPl->pl, 0x00,       SIPP_ISP_PIPE_BUFFER_WIDTH_IMX214, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX214, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(UInt16), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
        pPl->sigmaDnsMa2x5x0 =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX214, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX214, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(UInt16), SIPP_AUTO,          (FnSvuRun)SIPP_SIGMA_ID,      0);
        pPl->lscMa2x5x0      =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX214, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX214, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(UInt16), SIPP_AUTO,          (FnSvuRun)SIPP_LSC_ID,        0);
        pPl->rawMa2x5x0      =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX214, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX214, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_RAW_ID,        0);
        pPl->debayerMa2x5x0  =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX214, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX214, N_PL(3),  SZ(UInt16), SIPP_AUTO,          (FnSvuRun)SIPP_DBYR_ID,       0);
        sippFilterAddOBuf(pPl->debayerMa2x5x0, SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES, sizeof(fp16));
        pPl->dogLtmMa2x5x0   =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX214, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX214, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(fp16), SIPP_AUTO,          (FnSvuRun)SIPP_DOGL_ID,       0);
        pPl->ydnsMa2x5x0     =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX214, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX214, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(fp16), SIPP_AUTO,          (FnSvuRun)SIPP_LUMA_ID,       0);
        pPl->sharpenMa2x5x0  =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX214, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX214, N_PL(SIPP_ISP_PIPE_BUFFER_INPUT_NUM_PLANES), SZ(fp16), SIPP_AUTO,          (FnSvuRun)SIPP_SHARPEN_ID,    0);
        pPl->chromaGenMa2x5x0 =  sippCreateFilter(pPl->pl, SIPP_RESIZE, ISPC_CHROMA_PIPE_WIDTH_IMX214, ISPC_CHROMA_PIPE_HEIGHT_IMX214, N_PL(3),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_CGEN_ID,       0);
        pPl->medianMa2x5x0   =  sippCreateFilter(pPl->pl, 0x0,        ISPC_CHROMA_PIPE_WIDTH_IMX214, ISPC_CHROMA_PIPE_HEIGHT_IMX214, N_PL(3),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_MED_ID,        0);
        pPl->chromadnsMa2x5x0 =  sippCreateFilter(pPl->pl, 0x0,        ISPC_CHROMA_PIPE_WIDTH_IMX214, ISPC_CHROMA_PIPE_HEIGHT_IMX214, N_PL(3),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_CHROMA_ID,     0);
        pPl->colorcombMa2x5x0 =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX214, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX214, N_PL(3),  SZ(UInt16), SIPP_AUTO,          (FnSvuRun)SIPP_CC_ID,         0);
        pPl->lutMa2x5x0      =  sippCreateFilter(pPl->pl, 0x0,        SIPP_ISP_PIPE_BUFFER_WIDTH_IMX214, SIPP_ISP_PIPE_BUFFER_HEIGHT_IMX214, N_PL(3),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_LUT_ID,        0);
        pPl->polyphasefirMa2x5xY =  sippCreateFilter(pPl->pl, SIPP_RESIZE, POLY_Y_IMAGE_WIDTH_IMX214, POLY_Y_IMAGE_HEIGHT_IMX214, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_UPFIRDN_ID,    0);
        pPl->polyphasefirMa2x5xU =  sippCreateFilter(pPl->pl, SIPP_RESIZE, POLY_UV_IMAGE_WIDTH_IMX214, POLY_UV_IMAGE_HEIGHT_IMX214, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_UPFIRDN_ID,    0);
        pPl->polyphasefirMa2x5xV =  sippCreateFilter(pPl->pl, SIPP_RESIZE, POLY_UV_IMAGE_WIDTH_IMX214, POLY_UV_IMAGE_HEIGHT_IMX214, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_UPFIRDN_ID,    0);
        pPl->dmaOutY         =  sippCreateFilter(pPl->pl, 0x00,       POLY_Y_IMAGE_WIDTH_IMX214, POLY_Y_IMAGE_HEIGHT_IMX214, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
        pPl->dmaOutU         =  sippCreateFilter(pPl->pl, 0x00,       POLY_UV_IMAGE_WIDTH_IMX214, POLY_UV_IMAGE_HEIGHT_IMX214, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
        pPl->dmaOutV         =  sippCreateFilter(pPl->pl, 0x00,       POLY_UV_IMAGE_WIDTH_IMX214, POLY_UV_IMAGE_HEIGHT_IMX214, N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
    }

   // link filters
   sippLinkFilter(pPl->sigmaDnsMa2x5x0, pPl->dmaIn0,        5,5                 );
   sippLinkFilter(pPl->lscMa2x5x0,    pPl->sigmaDnsMa2x5x0, 1,1                 );
   sippLinkFilter(pPl->rawMa2x5x0,    pPl->lscMa2x5x0,    5,5                 );
   sippLinkFilter(pPl->debayerMa2x5x0, pPl->rawMa2x5x0,    11,11               );
   sippLinkFilter(pPl->dogLtmMa2x5x0, pPl->debayerMa2x5x0, 15,15               );
   sippLinkFilterSetOBuf(pPl->dogLtmMa2x5x0, pPl->debayerMa2x5x0, 1);
   sippLinkFilter(pPl->ydnsMa2x5x0,   pPl->dogLtmMa2x5x0, 11,11               );
   sippLinkFilter(pPl->sharpenMa2x5x0, pPl->ydnsMa2x5x0,   7,7                 );
   sippLinkFilter(pPl->chromaGenMa2x5x0, pPl->debayerMa2x5x0, 6,6                 );
   sippLinkFilter(pPl->medianMa2x5x0, pPl->chromaGenMa2x5x0, 7,7                 );
   sippLinkFilter(pPl->medianMa2x5x0, pPl->debayerMa2x5x0, 1,0                 );
   sippLinkFilterSetOBuf(pPl->medianMa2x5x0, pPl->debayerMa2x5x0, 1);
   sippLinkFilter(pPl->chromadnsMa2x5x0, pPl->medianMa2x5x0, 3,3                 );
   sippLinkFilter(pPl->colorcombMa2x5x0, pPl->sharpenMa2x5x0, 1,1                 );
   sippLinkFilter(pPl->colorcombMa2x5x0, pPl->chromadnsMa2x5x0, 5,5                 );
   sippLinkFilter(pPl->lutMa2x5x0,    pPl->colorcombMa2x5x0, 1,1                 );
   sippLinkFilter(pPl->polyphasefirMa2x5xY, pPl->lutMa2x5x0,    7,7                 );
   sippLinkFilter(pPl->polyphasefirMa2x5xU, pPl->lutMa2x5x0,    7,7                 );
   sippLinkFilter(pPl->polyphasefirMa2x5xV, pPl->lutMa2x5x0,    7,7                 );
   sippLinkFilter(pPl->dmaOutY,       pPl->polyphasefirMa2x5xY, 1,1                 );
   sippLinkFilter(pPl->dmaOutU,       pPl->polyphasefirMa2x5xU, 1,1                 );
   sippLinkFilter(pPl->dmaOutV,       pPl->polyphasefirMa2x5xV, 1,1                 );

}

void configCam214SIPPDebayerHdmi(Cam214SIPPDebayerHdmi *pPl)
{
    DmaParam            *dmaIn0Cfg          = (DmaParam         *)pPl->dmaIn0->params;
    SigmaParam          *sigmaDnsMa2x5x0Cfg = (SigmaParam       *)pPl->sigmaDnsMa2x5x0->params;
    LscParam            *lscMa2x5x0Cfg      = (LscParam         *)pPl->lscMa2x5x0->params;
    RawParam            *rawMa2x5x0Cfg      = (RawParam         *)pPl->rawMa2x5x0->params;
    DbyrParam           *debayerMa2x5x0Cfg  = (DbyrParam        *)pPl->debayerMa2x5x0->params;
    DogLtmParam         *dogLtmMa2x5x0Cfg   = (DogLtmParam      *)pPl->dogLtmMa2x5x0->params;
    YDnsParam           *ydnsMa2x5x0Cfg     = (YDnsParam        *)pPl->ydnsMa2x5x0->params;
    UsmParam            *sharpenMa2x5x0Cfg  = (UsmParam         *)pPl->sharpenMa2x5x0->params;
    GenChrParam         *chromaGenMa2x5x0Cfg= (GenChrParam      *)pPl->chromaGenMa2x5x0->params;
    MedParam            *medianMa2x5x0Cfg   = (MedParam         *)pPl->medianMa2x5x0->params;
    ChrDnsParam         *chromadnsMa2x5x0Cfg= (ChrDnsParam      *)pPl->chromadnsMa2x5x0->params;
    ColCombParam        *colorcombMa2x5x0Cfg= (ColCombParam     *)pPl->colorcombMa2x5x0->params;
    LutParam            *lutMa2x5x0Cfg      = (LutParam         *)pPl->lutMa2x5x0->params;
    PolyFirParam        *polyphasefirMa2x5xYCfg= (PolyFirParam     *)pPl->polyphasefirMa2x5xY->params;
    PolyFirParam        *polyphasefirMa2x5xUCfg= (PolyFirParam     *)pPl->polyphasefirMa2x5xU->params;
    PolyFirParam        *polyphasefirMa2x5xVCfg= (PolyFirParam     *)pPl->polyphasefirMa2x5xV->params;
    DmaParam            *dmaOutYCfg         = (DmaParam         *)pPl->dmaOutY->params;
    DmaParam            *dmaOutUCfg         = (DmaParam         *)pPl->dmaOutU->params;
    DmaParam            *dmaOutVCfg         = (DmaParam         *)pPl->dmaOutV->params;

   uint8_t BAYER_PATTERN_locate = 0;

    if ((Xeye_Sensor == Sensor_AR0330) || (Xeye_Sensor == Sensor_AR0144)) {
        BAYER_PATTERN_locate = GRBG;
    } else {
        BAYER_PATTERN_locate = RGGB;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // here go through all the filter instances and assign the value for all parameter
    // fields as defined in the filter property window
    sigmaDnsMa2x5x0Cfg->thresh[0]=(ISPC_SIGMA_THRESH1_P0 <<  0 | ISPC_SIGMA_THRESH2_P0 <<  8 | ISPC_SIGMA_THRESH1_P1 << 16 | ISPC_SIGMA_THRESH2_P1 << 24);
    sigmaDnsMa2x5x0Cfg->thresh[1]=(ISPC_SIGMA_THRESH1_P2 <<  0 | ISPC_SIGMA_THRESH2_P2 <<  8 | ISPC_SIGMA_THRESH1_P3 << 16 | ISPC_SIGMA_THRESH2_P3 << 24);
    sigmaDnsMa2x5x0Cfg->cfg= SIGMA_DNS_CFG(ISPC_SIGMA_NOISE_FLOOR, (ispc_bayer_bits - 1), SIGMA_DNS_PASSTHRU_BIT,FORMAT);
    sigmaDnsMa2x5x0Cfg->bayerPattern=BAYER_PATTERN_locate;
    sigmaDnsMa2x5x0Cfg->blcGR=sensor_black_level;
    sigmaDnsMa2x5x0Cfg->blcR=sensor_black_level;
    sigmaDnsMa2x5x0Cfg->blcB=sensor_black_level;
    sigmaDnsMa2x5x0Cfg->blcGB=sensor_black_level;
    lscMa2x5x0Cfg->gmBase=   ispcLscMesh;
    lscMa2x5x0Cfg->gmWidth=  ISPC_LSC_GAIN_MAP_W;
    lscMa2x5x0Cfg->gmHeight= ISPC_LSC_GAIN_MAP_H;
    lscMa2x5x0Cfg->dataFormat=SIPP_LSC_CFG_FORMAT(BAYER);
    lscMa2x5x0Cfg->dataWidth=ispc_bayer_bits;
    rawMa2x5x0Cfg->grgbPlat= RAW_GRGB_PLATO(ISPC_GRGB_IMBAL_PLAT_DARK,ISPC_GRGB_IMBAL_PLAT_BRIGHT);
    rawMa2x5x0Cfg->grgbDecay=RAW_GRGB_DECAY(ISPC_GRGB_IMBAL_DECAY_BRIGHT, ISPC_GRGB_IMBAL_DECAY_DARK);
    rawMa2x5x0Cfg->badPixCfg=RAW_BAD_PIX_CFG(ISPC_BAD_PIX_NOISE_LEVEL, ISPC_BAD_PIX_ALPHA_G_HOT, ISPC_BAD_PIX_ALPHA_G_COLD, ISPC_BAD_PIX_ALPHA_RB_HOT, ISPC_BAD_PIX_ALPHA_RB_COLD);
    rawMa2x5x0Cfg->cfg=      RAW_CFG(BAYER,BAYER_PATTERN_locate,GRGB_IMBAL_EN,0,AE_PATCH_STATS_EN,AE_RGB_HIST_STATS_EN,(ispc_bayer_bits - 1),ISPC_GRGB_IMBAL_THRESHOLD,0,AF_PATCH_STATS_EN,BAYER_2x2_MODE,AE_Y_HIST_STATS_EN,HOT_COLD_PIX_SUPPRESS_EN);
    rawMa2x5x0Cfg->gainSat[0]=((ISPC_RAW_CLAMP_0<<16) | ISPC_RAW_GAIN_GR );
    rawMa2x5x0Cfg->gainSat[1]= ((ISPC_RAW_CLAMP_1<<16) | ISPC_RAW_GAIN_R );
    rawMa2x5x0Cfg->gainSat[2]= ((ISPC_RAW_CLAMP_2<<16) | ISPC_RAW_GAIN_B );
    rawMa2x5x0Cfg->gainSat[3]= ((ISPC_RAW_CLAMP_3<<16) | ISPC_RAW_GAIN_GB );
    rawMa2x5x0Cfg->statsBase=0;
    rawMa2x5x0Cfg->statsPlanes=0;
    rawMa2x5x0Cfg->statsPatchCfg=0;
    rawMa2x5x0Cfg->statsPatchStart=0;
    rawMa2x5x0Cfg->statsPatchSkip=0;
    rawMa2x5x0Cfg->statsThresh=0;
    rawMa2x5x0Cfg->afF1coefs[0]=0;
    rawMa2x5x0Cfg->afF1coefs[1]=0;
    rawMa2x5x0Cfg->afF1coefs[2]=0;
    rawMa2x5x0Cfg->afF1coefs[3]=0;
    rawMa2x5x0Cfg->afF1coefs[4]=0;
    rawMa2x5x0Cfg->afF1coefs[5]=0;
    rawMa2x5x0Cfg->afF1coefs[6]=0;
    rawMa2x5x0Cfg->afF1coefs[7]=0;
    rawMa2x5x0Cfg->afF1coefs[8]=0;
    rawMa2x5x0Cfg->afF1coefs[9]=0;
    rawMa2x5x0Cfg->afF1coefs[10]=0;
    rawMa2x5x0Cfg->afF2coefs[0]=0;
    rawMa2x5x0Cfg->afF2coefs[1]=0;
    rawMa2x5x0Cfg->afF2coefs[2]=0;
    rawMa2x5x0Cfg->afF2coefs[3]=0;
    rawMa2x5x0Cfg->afF2coefs[4]=0;
    rawMa2x5x0Cfg->afF2coefs[5]=0;
    rawMa2x5x0Cfg->afF2coefs[6]=0;
    rawMa2x5x0Cfg->afF2coefs[7]=0;
    rawMa2x5x0Cfg->afF2coefs[8]=0;
    rawMa2x5x0Cfg->afF2coefs[9]=0;
    rawMa2x5x0Cfg->afF2coefs[10]=0;
    rawMa2x5x0Cfg->afMinThresh=0;
    rawMa2x5x0Cfg->afSubtract=0;
    rawMa2x5x0Cfg->afPatchCfg=0;
    rawMa2x5x0Cfg->afPatchStart=0;
    rawMa2x5x0Cfg->afStatsBase=0;
    rawMa2x5x0Cfg->histLumaBase=0;
    rawMa2x5x0Cfg->histRgbBase=0;
    debayerMa2x5x0Cfg->cfg=  DEBAYER_CFG(BAYER_PATTERN_locate,0,0,ispc_bayer_bits,ISPC_DEBAYER_BITS,IMAGE_ORDER_OUT, OUTPUT_PLANE_NO,0);
    debayerMa2x5x0Cfg->thresh=DEBAYER_THRESH(0,0,1,1,1,0) ;
    debayerMa2x5x0Cfg->dewormCfg=DEBAYER_DEWORM(ISPC_DEMOSAIC_MIX_OFFSET,ISPC_DEMOSAIC_MIX_SLOPE);
    debayerMa2x5x0Cfg->lumaWeight=DEBAYER_LUMA_COEFS_CFG(ISPC_DEMOSAIC_LUMA_WEIGHT_RED , ISPC_DEMOSAIC_LUMA_WEIGHT_GREEN, ISPC_DEMOSAIC_LUMA_WEIGHT_BLUE);
    dogLtmMa2x5x0Cfg->cfg=   DOGL_CFG_SET(DOG_LTM_MODE,ISPC_DOG_THR,DOG_OUTPUT_CLAMP,DS_MODE,ISPC_LTM_FILTER_TH1,0,DOG_HEIGHT);;
    dogLtmMa2x5x0Cfg->dogCoeffs11=dogCoeffs11;
    dogLtmMa2x5x0Cfg->dogCoeffs15=dogCoeffs15;
    dogLtmMa2x5x0Cfg->dogStrength=ISPC_DOG_STRENGTH;
    dogLtmMa2x5x0Cfg->ltmCurves=(u16 *)ltm_curves;
    ydnsMa2x5x0Cfg->cfg=     LUMA_DNS_CFG(0x1, ISPC_LUMA_DNS_REF_SHIFT, ISPC_LUMA_DNS_ALPHA, ISPC_LUMA_DNS_BITPOS);
    ydnsMa2x5x0Cfg->gaussLut[0]=gaussLut[0];
    ydnsMa2x5x0Cfg->gaussLut[1]=gaussLut[1];
    ydnsMa2x5x0Cfg->gaussLut[2]=gaussLut[2];
    ydnsMa2x5x0Cfg->gaussLut[3]=gaussLut[3];
    ydnsMa2x5x0Cfg->f2=      ISPC_LUMA_DNS_F2;
    ydnsMa2x5x0Cfg->gammaLut[0]=gammaLut[0];
    ydnsMa2x5x0Cfg->gammaLut[1]=gammaLut[1];
    ydnsMa2x5x0Cfg->gammaLut[2]=gammaLut[2];
    ydnsMa2x5x0Cfg->gammaLut[3]=gammaLut[3];
    ydnsMa2x5x0Cfg->gammaLut[4]=gammaLut[4];
    ydnsMa2x5x0Cfg->distCfg= (u32)ispcYDnsDistLut;
    ydnsMa2x5x0Cfg->distOffsets=X_OFFSET | (Y_OFFSET << 16);

    if (Xeye_Sensor == Sensor_IMX378) {
        ydnsMa2x5x0Cfg->fullFrmDim=(FULL_IMAGE_HEIGHT_IMX378 << 16 ) | FULL_IMAGE_HEIGHT_IMX378;
    } else {
        ydnsMa2x5x0Cfg->fullFrmDim=(FULL_IMAGE_HEIGHT_IMX214 << 16 ) | FULL_IMAGE_HEIGHT_IMX214;
    }
    sharpenMa2x5x0Cfg->cfg=  SHARPEN_CFG( THR, SHARPEN_KERNEL_SIZE,OUTPUT_CLAMP ,SHARPEN_MODE,OUTPUT_DELTAS);
    sharpenMa2x5x0Cfg->strength=SHARPEN_STRENGTH_CFG(SHARPEN_STRENGTH_LIGHTEN, SHARPEN_STRENGTH_DARKEN );
    sharpenMa2x5x0Cfg->clip= SHARPEN_CLIPPING_ALPHA;
    sharpenMa2x5x0Cfg->limit= SHARPEN_LIMITS_CFG(0x0,0x4000);
    sharpenMa2x5x0Cfg->rgnStop01=SHARPEN_RANGESTOP01_CFG(SHARPEN_RANGE_STOP0, SHARPEN_RANGE_STOP1);
    sharpenMa2x5x0Cfg->rgnStop23= SHARPEN_RANGESTOP01_CFG(SHARPEN_RANGE_STOP2, SHARPEN_RANGE_STOP3);
    sharpenMa2x5x0Cfg->coef01=SHARPEN_COEFS01_CFG(0x0,0x0);
    sharpenMa2x5x0Cfg->coef23=SHARPEN_COEFS23_CFG(0x0,0x0);
    chromaGenMa2x5x0Cfg->cfg=CGEN_CFG_SET(ISPC_CGEN_PFR_STRENGTH,ISPC_CGEN_DESAT_OFFSET,ISPC_CGEN_DESAT_SLOPE,ISPC_DEBAYER_BITS,BYPASS_PF_DAD,DS_MODE);
    chromaGenMa2x5x0Cfg->yCoefs=CGEN_LUMA_COEFF_SET(ISPC_CGEN_LUMA_COEFF_R,ISPC_CGEN_LUMA_COEFF_G,ISPC_CGEN_LUMA_COEFF_B) ;
    chromaGenMa2x5x0Cfg->chrCoefs=CGEN_CHROMA_COEFF_SET(ISPC_CGEN_EPSILON,ISPC_CGEN_KR,ISPC_CGEN_KG,ISPC_CGEN_KB);
    medianMa2x5x0Cfg->cfg=   MED_CFG(MEDIAN_KERNEL_SIZE,MEDIAN_OUT_SEL,MEDIAN_THRESHOLD,MEDIAN_LUMA_ABLEND_EN,MEDIAN_LUMA_SAMPLE_EN,0);
    medianMa2x5x0Cfg->lumaAlpha=MED_LUMA_ALPHA(ISPC_CHROMA_MEDIAN_MIX_SLOPE,ISPC_CHROMA_MEDIAN_MIX_OFFSET);
    chromadnsMa2x5x0Cfg->cfg=CHROMA_DNS_CFG(ISPC_CHROMA_DNS_H_ENAB,ISPC_CHROMA_DNS_LIMIT,FORCE_WT_H,FORCE_WT_V,(PLANES_PER_CYCLE-1),ISPC_GREY_DESAT_OFFSET,ISPC_GREY_DESAT_SLOPE);
    chromadnsMa2x5x0Cfg->thr[0]=CHROMA_DNS_THRESH0;
    chromadnsMa2x5x0Cfg->thr[1]=CHROMA_DNS_THRESH1;
    chromadnsMa2x5x0Cfg->greyPt=CHORMA_GREY_PT_SET(ISPC_GREY_POINT_B,ISPC_GREY_POINT_G,ISPC_GREY_POINT_R,GREY_PT_EN);
    chromadnsMa2x5x0Cfg->chrCoefs=CHROMA_DNS_COEFFS_SET(ispcLowpassKernel[4],ispcLowpassKernel[1],ispcLowpassKernel[0]);
    colorcombMa2x5x0Cfg->cfg=CC_CFG(FORCE_LUMA_ONE,0,LUT_3D_BYPASS,LUT_3D_LOAD,U12F_OUTPUT,CC_OUTPUT_PLANE);
    colorcombMa2x5x0Cfg->krgb[0]=ISPC_CC_KR | (ISPC_CC_KG << 16);
    colorcombMa2x5x0Cfg->krgb[1]=(ISPC_CC_KB | ((ISPC_CGEN_EPSILON<<4) << 16));
    colorcombMa2x5x0Cfg->ccm[0]=(ccm_lut_coeffs[0] | (ccm_lut_coeffs[3] << 16));
    colorcombMa2x5x0Cfg->ccm[1]=(ccm_lut_coeffs[6] | (ccm_lut_coeffs[1] << 16));
    colorcombMa2x5x0Cfg->ccm[2]=(ccm_lut_coeffs[4] | (ccm_lut_coeffs[7] << 16));
    colorcombMa2x5x0Cfg->ccm[3]=(ccm_lut_coeffs[2] | (ccm_lut_coeffs[5] << 16));
    colorcombMa2x5x0Cfg->ccm[4]=(ccm_lut_coeffs[8] | (ccm_lut_offsets[0] << 16));
    colorcombMa2x5x0Cfg->ccOffs=(ccm_lut_offsets[1] | (ccm_lut_offsets[2] << 16));
    colorcombMa2x5x0Cfg->threeDLut=0x0;
    colorcombMa2x5x0Cfg->lutFormat=0x0;
    lutMa2x5x0Cfg->cfg=      INTERP_MODE | CHANNEL_MODE<< 1 | (CHANNELS_NO - 1) << 12 | LUT_LOAD << 14 | CSC_ENABLE<< 16;
    lutMa2x5x0Cfg->sizeA=    LUT_REGION0_SIZE_I | (LUT_REGION1_SIZE_I <<  4) | (LUT_REGION2_SIZE_I <<  8) | (LUT_REGION3_SIZE_I << 12) | (LUT_REGION4_SIZE_I << 16) | (LUT_REGION5_SIZE_I << 20) | (LUT_REGION6_SIZE_I << 24) | (LUT_REGION7_SIZE_I << 28);
    lutMa2x5x0Cfg->sizeB=    LUT_REGION8_SIZE_I | (LUT_REGION9_SIZE_I  <<  4) | (LUT_REGION10_SIZE_I <<  8) | (LUT_REGION11_SIZE_I << 12) | (LUT_REGION12_SIZE_I << 16) | (LUT_REGION13_SIZE_I << 20) | (LUT_REGION14_SIZE_I << 24) | (LUT_REGION15_SIZE_I << 28);
    lutMa2x5x0Cfg->lut=      (void *)gammaLutFp16;
    lutMa2x5x0Cfg->lutFormat=LUT_LD_FORMAT;
    lutMa2x5x0Cfg->mat[0]=   LUT_MAT_11;
    lutMa2x5x0Cfg->mat[1]=   LUT_MAT_12;
    lutMa2x5x0Cfg->mat[2]=   LUT_MAT_13;
    lutMa2x5x0Cfg->mat[3]=   LUT_MAT_21;
    lutMa2x5x0Cfg->mat[4]=   LUT_MAT_22;
    lutMa2x5x0Cfg->mat[5]=   LUT_MAT_23;
    lutMa2x5x0Cfg->mat[6]=   LUT_MAT_31;
    lutMa2x5x0Cfg->mat[7]=   LUT_MAT_32;
    lutMa2x5x0Cfg->mat[8]=   LUT_MAT_33;
    lutMa2x5x0Cfg->offset[0]=LUT_OFF_1;
    lutMa2x5x0Cfg->offset[1]=LUT_OFF_2;
    lutMa2x5x0Cfg->offset[2]=LUT_OFF_3;
    polyphasefirMa2x5xYCfg->clamp=0;
    polyphasefirMa2x5xYCfg->horzCoefs=(UInt8*)hCoefs;
    polyphasefirMa2x5xYCfg->vertCoefs=(UInt8*)vCoefs;
    polyphasefirMa2x5xYCfg->planeMode=POLY_PLANE_Y;
    polyphasefirMa2x5xUCfg->clamp=0;
    polyphasefirMa2x5xUCfg->horzCoefs=(UInt8*)hCoefs;
    polyphasefirMa2x5xUCfg->vertCoefs=(UInt8*)vCoefs;
    polyphasefirMa2x5xUCfg->planeMode=POLY_PLANE_U;
    polyphasefirMa2x5xVCfg->clamp=0;

    if (Xeye_Sensor == Sensor_IMX378) {
        polyphasefirMa2x5xYCfg->horzD=POLYFIR_Y_H_DEN_IMX378;
        polyphasefirMa2x5xYCfg->horzN=POLYFIR_Y_H_NUM_IMX378;
        polyphasefirMa2x5xYCfg->vertD=POLYFIR_Y_V_DEN_IMX378;
        polyphasefirMa2x5xYCfg->vertN=POLYFIR_Y_V_NUM_IMX378;
        polyphasefirMa2x5xUCfg->horzD=POLYFIR_U_H_DEN_IMX378;
        polyphasefirMa2x5xUCfg->horzN=POLYFIR_U_H_NUM_IMX378;
        polyphasefirMa2x5xUCfg->vertD=POLYFIR_U_V_DEN_IMX378;
        polyphasefirMa2x5xUCfg->vertN=POLYFIR_U_V_NUM_IMX378;
        polyphasefirMa2x5xVCfg->horzD=POLYFIR_V_H_DEN_IMX378;
        polyphasefirMa2x5xVCfg->horzN=POLYFIR_V_H_NUM_IMX378;
        polyphasefirMa2x5xVCfg->vertD=POLYFIR_V_V_DEN_IMX378;
        polyphasefirMa2x5xVCfg->vertN=POLYFIR_V_V_NUM_IMX378;
    } else {
        polyphasefirMa2x5xYCfg->horzD=POLYFIR_Y_H_DEN_IMX214;
        polyphasefirMa2x5xYCfg->horzN=POLYFIR_Y_H_NUM_IMX214;
        polyphasefirMa2x5xYCfg->vertD=POLYFIR_Y_V_DEN_IMX214;
        polyphasefirMa2x5xYCfg->vertN=POLYFIR_Y_V_NUM_IMX214;
        polyphasefirMa2x5xUCfg->horzD=POLYFIR_U_H_DEN_IMX214;
        polyphasefirMa2x5xUCfg->horzN=POLYFIR_U_H_NUM_IMX214;
        polyphasefirMa2x5xUCfg->vertD=POLYFIR_U_V_DEN_IMX214;
        polyphasefirMa2x5xUCfg->vertN=POLYFIR_U_V_NUM_IMX214;
        polyphasefirMa2x5xVCfg->horzD=POLYFIR_V_H_DEN_IMX214;
        polyphasefirMa2x5xVCfg->horzN=POLYFIR_V_H_NUM_IMX214;
        polyphasefirMa2x5xVCfg->vertD=POLYFIR_V_V_DEN_IMX214;
        polyphasefirMa2x5xVCfg->vertN=POLYFIR_V_V_NUM_IMX214;
    }
   polyphasefirMa2x5xVCfg->horzCoefs=(UInt8*)hCoefs;
   polyphasefirMa2x5xVCfg->vertCoefs=(UInt8*)vCoefs;
   polyphasefirMa2x5xVCfg->planeMode=POLY_PLANE_V;
   dmaIn0Cfg->ddrAddr   = (UInt32)NULL;
   dmaOutYCfg->ddrAddr  = (UInt32)NULL;
   dmaOutUCfg->ddrAddr  = (UInt32)NULL;
   dmaOutVCfg->ddrAddr  = (UInt32)NULL;


}