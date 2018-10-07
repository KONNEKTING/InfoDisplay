#define MANUFACTURER_ID 7070
#define DEVICE_ID 175
#define REVISION 1

#define COMOBJ_line1time 0
#define COMOBJ_line1date 1
#define COMOBJ_line1byte 2
#define COMOBJ_line1int 3
#define COMOBJ_line1uint 4
#define COMOBJ_line1float 5
#define COMOBJ_line1bool 6
#define COMOBJ_line1text 7
#define COMOBJ_line2byte 8
#define COMOBJ_line2int 9
#define COMOBJ_line2uint 10
#define COMOBJ_line2float 11
#define COMOBJ_line2bool 12
#define COMOBJ_line2text 13
#define COMOBJ_line3byte 14
#define COMOBJ_line3int 15
#define COMOBJ_line3uint 16
#define COMOBJ_line3float 17
#define COMOBJ_line3bool 18
#define COMOBJ_line3text 19
#define COMOBJ_line4byte 20
#define COMOBJ_line4int 21
#define COMOBJ_line4uint 22
#define COMOBJ_line4float 23
#define COMOBJ_line4bool 24
#define COMOBJ_line4text 25
#define COMOBJ_line5byte 26
#define COMOBJ_line5int 27
#define COMOBJ_line5uint 28
#define COMOBJ_line5float 29
#define COMOBJ_line5bool 30
#define COMOBJ_line5text 31
#define COMOBJ_line6byte 32
#define COMOBJ_line6int 33
#define COMOBJ_line6uint 34
#define COMOBJ_line6float 35
#define COMOBJ_line6bool 36
#define COMOBJ_line6text 37
#define COMOBJ_line7byte 38
#define COMOBJ_line7int 39
#define COMOBJ_line7uint 40
#define COMOBJ_line7float 41
#define COMOBJ_line7bool 42
#define COMOBJ_line7text 43
#define COMOBJ_line8byte 44
#define COMOBJ_line8int 45
#define COMOBJ_line8uint 46
#define COMOBJ_line8float 47
#define COMOBJ_line8bool 48
#define COMOBJ_line8text 49
#define PARAM_initialDelay 0
#define PARAM_line1type 1
#define PARAM_line1text 2
#define PARAM_line1unit 3
#define PARAM_line1val0 4
#define PARAM_line1val1 5
#define PARAM_line2type 6
#define PARAM_line2text 7
#define PARAM_line2unit 8
#define PARAM_line2val0 9
#define PARAM_line2val1 10
#define PARAM_line3type 11
#define PARAM_line3text 12
#define PARAM_line3unit 13
#define PARAM_line3val0 14
#define PARAM_line3val1 15
#define PARAM_line4type 16
#define PARAM_line4text 17
#define PARAM_line4unit 18
#define PARAM_line4val0 19
#define PARAM_line4val1 20
#define PARAM_line5type 21
#define PARAM_line5text 22
#define PARAM_line5unit 23
#define PARAM_line5val0 24
#define PARAM_line5val1 25
#define PARAM_line6type 26
#define PARAM_line6text 27
#define PARAM_line6unit 28
#define PARAM_line6val0 29
#define PARAM_line6val1 30
#define PARAM_line7type 31
#define PARAM_line7text 32
#define PARAM_line7unit 33
#define PARAM_line7val0 34
#define PARAM_line7val1 35
#define PARAM_line8type 36
#define PARAM_line8text 37
#define PARAM_line8unit 38
#define PARAM_line8val0 39
#define PARAM_line8val1 40
        
KnxComObject KnxDevice::_comObjectsList[] = {
    /* Index 0 - line1time */ KnxComObject(KNX_DPT_10_001, 0x2b),
    /* Index 1 - line1date */ KnxComObject(KNX_DPT_11_001, 0x2b),
    /* Index 2 - line1byte */ KnxComObject(KNX_DPT_5_004, 0x2b),
    /* Index 3 - line1int */ KnxComObject(KNX_DPT_8_001, 0x2b),
    /* Index 4 - line1uint */ KnxComObject(KNX_DPT_7_001, 0x2b),
    /* Index 5 - line1float */ KnxComObject(KNX_DPT_9_001, 0x2b),
    /* Index 6 - line1bool */ KnxComObject(KNX_DPT_1_001, 0x2b),
    /* Index 7 - line1text */ KnxComObject(KNX_DPT_16_001, 0x2b),
    /* Index 8 - line2byte */ KnxComObject(KNX_DPT_5_004, 0x2b),
    /* Index 9 - line2int */ KnxComObject(KNX_DPT_8_001, 0x2b),
    /* Index 10 - line2uint */ KnxComObject(KNX_DPT_7_001, 0x2b),
    /* Index 11 - line2float */ KnxComObject(KNX_DPT_9_001, 0x2b),
    /* Index 12 - line2bool */ KnxComObject(KNX_DPT_1_001, 0x2b),
    /* Index 13 - line2text */ KnxComObject(KNX_DPT_16_001, 0x2b),
    /* Index 14 - line3byte */ KnxComObject(KNX_DPT_5_004, 0x2b),
    /* Index 15 - line3int */ KnxComObject(KNX_DPT_8_001, 0x2b),
    /* Index 16 - line3uint */ KnxComObject(KNX_DPT_7_001, 0x2b),
    /* Index 17 - line3float */ KnxComObject(KNX_DPT_9_001, 0x2b),
    /* Index 18 - line3bool */ KnxComObject(KNX_DPT_1_001, 0x2b),
    /* Index 19 - line3text */ KnxComObject(KNX_DPT_16_001, 0x2b),
    /* Index 20 - line4byte */ KnxComObject(KNX_DPT_5_004, 0x2b),
    /* Index 21 - line4int */ KnxComObject(KNX_DPT_8_001, 0x2b),
    /* Index 22 - line4uint */ KnxComObject(KNX_DPT_7_001, 0x2b),
    /* Index 23 - line4float */ KnxComObject(KNX_DPT_9_001, 0x2b),
    /* Index 24 - line4bool */ KnxComObject(KNX_DPT_1_001, 0x2b),
    /* Index 25 - line4text */ KnxComObject(KNX_DPT_16_001, 0x2b),
    /* Index 26 - line5byte */ KnxComObject(KNX_DPT_5_004, 0x2b),
    /* Index 27 - line5int */ KnxComObject(KNX_DPT_8_001, 0x2b),
    /* Index 28 - line5uint */ KnxComObject(KNX_DPT_7_001, 0x2b),
    /* Index 29 - line5float */ KnxComObject(KNX_DPT_9_001, 0x2b),
    /* Index 30 - line5bool */ KnxComObject(KNX_DPT_1_001, 0x2b),
    /* Index 31 - line5text */ KnxComObject(KNX_DPT_16_001, 0x2b),
    /* Index 32 - line6byte */ KnxComObject(KNX_DPT_5_004, 0x2b),
    /* Index 33 - line6int */ KnxComObject(KNX_DPT_8_001, 0x2b),
    /* Index 34 - line6uint */ KnxComObject(KNX_DPT_7_001, 0x2b),
    /* Index 35 - line6float */ KnxComObject(KNX_DPT_9_001, 0x2b),
    /* Index 36 - line6bool */ KnxComObject(KNX_DPT_1_001, 0x2b),
    /* Index 37 - line6text */ KnxComObject(KNX_DPT_16_001, 0x2b),
    /* Index 38 - line7byte */ KnxComObject(KNX_DPT_5_004, 0x2b),
    /* Index 39 - line7int */ KnxComObject(KNX_DPT_8_001, 0x2b),
    /* Index 40 - line7uint */ KnxComObject(KNX_DPT_7_001, 0x2b),
    /* Index 41 - line7float */ KnxComObject(KNX_DPT_9_001, 0x2b),
    /* Index 42 - line7bool */ KnxComObject(KNX_DPT_1_001, 0x2b),
    /* Index 43 - line7text */ KnxComObject(KNX_DPT_16_001, 0x2b),
    /* Index 44 - line8byte */ KnxComObject(KNX_DPT_5_004, 0x2b),
    /* Index 45 - line8int */ KnxComObject(KNX_DPT_8_001, 0x2b),
    /* Index 46 - line8uint */ KnxComObject(KNX_DPT_7_001, 0x2b),
    /* Index 47 - line8float */ KnxComObject(KNX_DPT_9_001, 0x2b),
    /* Index 48 - line8bool */ KnxComObject(KNX_DPT_1_001, 0x2b),
    /* Index 49 - line8text */ KnxComObject(KNX_DPT_16_001, 0x2b)
};
const byte KnxDevice::_numberOfComObjects = sizeof (_comObjectsList) / sizeof (KnxComObject); // do not change this code
       
byte KonnektingDevice::_paramSizeList[] = {
    /* Index 0 - initialDelay */ PARAM_UINT16,
    /* Index 1 - line1type */ PARAM_UINT8,
    /* Index 2 - line1text */ PARAM_STRING11,
    /* Index 3 - line1unit */ PARAM_STRING11,
    /* Index 4 - line1val0 */ PARAM_STRING11,
    /* Index 5 - line1val1 */ PARAM_STRING11,
    /* Index 6 - line2type */ PARAM_UINT8,
    /* Index 7 - line2text */ PARAM_STRING11,
    /* Index 8 - line2unit */ PARAM_STRING11,
    /* Index 9 - line2val0 */ PARAM_STRING11,
    /* Index 10 - line2val1 */ PARAM_STRING11,
    /* Index 11 - line3type */ PARAM_UINT8,
    /* Index 12 - line3text */ PARAM_STRING11,
    /* Index 13 - line3unit */ PARAM_STRING11,
    /* Index 14 - line3val0 */ PARAM_STRING11,
    /* Index 15 - line3val1 */ PARAM_STRING11,
    /* Index 16 - line4type */ PARAM_UINT8,
    /* Index 17 - line4text */ PARAM_STRING11,
    /* Index 18 - line4unit */ PARAM_STRING11,
    /* Index 19 - line4val0 */ PARAM_STRING11,
    /* Index 20 - line4val1 */ PARAM_STRING11,
    /* Index 21 - line5type */ PARAM_UINT8,
    /* Index 22 - line5text */ PARAM_STRING11,
    /* Index 23 - line5unit */ PARAM_STRING11,
    /* Index 24 - line5val0 */ PARAM_STRING11,
    /* Index 25 - line5val1 */ PARAM_STRING11,
    /* Index 26 - line6type */ PARAM_UINT8,
    /* Index 27 - line6text */ PARAM_STRING11,
    /* Index 28 - line6unit */ PARAM_STRING11,
    /* Index 29 - line6val0 */ PARAM_STRING11,
    /* Index 30 - line6val1 */ PARAM_STRING11,
    /* Index 31 - line7type */ PARAM_UINT8,
    /* Index 32 - line7text */ PARAM_STRING11,
    /* Index 33 - line7unit */ PARAM_STRING11,
    /* Index 34 - line7val0 */ PARAM_STRING11,
    /* Index 35 - line7val1 */ PARAM_STRING11,
    /* Index 36 - line8type */ PARAM_UINT8,
    /* Index 37 - line8text */ PARAM_STRING11,
    /* Index 38 - line8unit */ PARAM_STRING11,
    /* Index 39 - line8val0 */ PARAM_STRING11,
    /* Index 40 - line8val1 */ PARAM_STRING11
};
const int KonnektingDevice::_numberOfParams = sizeof (_paramSizeList); // do not change this code
