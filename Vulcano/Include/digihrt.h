/* DIGIHRT.H - Useful and necessary definitions for the HRT512-8 digitizer
   Copyright (c) 1989-1993, ALL RIGHTS RESERVED
      Catenary Systems
      470 Belleview
      St Louis, MO 63119
      (314) 962-7833
*/
#ifndef _DIGIHRT_H_
#define _DIGIHRT_H_

#if defined WIN32 || defined _WIN32
# define huge 
# define _export
#endif

/* Port definitions for the HRT512-8 digitizer board */
#define CNTL_REG   0x2000   // Control Reg (at base segment + 0x2000)
#define Y_REG      0x2002   // Y Reg (at base seg + 0x2002)
#define CRTC_REG   0x3000   // CRTC Reg (at base seg + 0x3000)
#define BTPAL_REG  0x3400   // BT478 Reg (at base seg + 0x3400)

/* Video standard equates */
#define VIC_NTSC 0
#define VIC_PAL  1

/* Control Reg bit definitions */
#define  OE     1   // Overlay enable */
#define  GE     2   // Genlock enable, 0 when grabbing or displaying
                    //   video, 1 when accessing video memory
#define  SG     4   // Static grab (set to 0, then 1 to grab next frame)
#define  CG     8   // Continuous grab (set to 0 to display cont video)
#define  WE    16   // Window enable (set to 1)
#define  IRE   32   // Int Req Enable (set to 0)
#define  SS    64   // Sync select (set to 0 for ext sync for grabbing or
                    //  displaying video, 1 for accessing video memory.
#define  UGD  128   // Unconditional Grab Disable (set to 1 unless poor
                    //  video, then use it to grab signal.

/* Some common modes */
#define  SELFSYNC   (1|GE|CG|WE|SS)
#define  FREEZE     (1|CG|WE|UGD)
#define  LIVE       (1|WE|UGD)
#define  POORFREEZE (1|CG|WE)

/* Some useful macros */
/* Set Y register address */
#define SET_YADDR(ba) ((unsigned far *)ba + Y_REG)
/* Set address of where to read/write digitizer data */
#define SET_BADDR(ba,x) (ba + x)

// Private messages we handle
typedef enum {
   WM_INITCHILD = WM_USER+0x101,
   WM_GETDIGIDATAFCTN,
   WM_PUTDIGIDATAFCTN,
   WM_INITCRTCFCTN, 
   WM_SETCRTCREGFCTN, 
   WM_FREEZEFCTN,   // Keep this order!!!
   WM_LIVEFCTN, 
   WM_POORFREEZEFCTN, 
   WM_SELFSYNCFCTN, 
   WM_ENDFRAMEFCTN, 
   WM_DETECTFCTN, 
   WM_CRTCSTATUSFCTN, 
   WM_SETLUTFCTN, 
   WM_GETREGVALFCTN, 
   WM_SETREGVALFCTN, 
   } HRT_MSG;

/* Read a line of image data struct */
#pragma pack(2)
typedef struct { 
   WORD baseSeg;
   short scrnx;
   short scrny;
   short cols; // Pixels to get
   UCHAR far *buffer; // Where to store image data
   } READLINEDATA;
#pragma pack()

#pragma pack(2)
typedef struct { 
   WORD baseSeg;
   UCHAR far *table;
   } TABLEDATA;
#pragma pack()

/* Reg values struct */
#pragma pack(2)
typedef struct { 
   WORD baseSeg;
   WORD reg;
   WORD value;
   } REGDATA;
#pragma pack()

#if defined WIN32 || defined _WIN32
# define FP_SEG(fp) (HIWORD(fp))
# define FP_OFF(fp) (LOWORD(fp))
#endif

// Universal Thunk definition we need
typedef DWORD (WINAPI *UT32PROC)(LPVOID,DWORD,LPVOID *);
typedef void (*GETDIGIDATA16QT)(READLINEDATA FAR *);
typedef void (*PUTDIGIDATA16QT)(READLINEDATA FAR *);
typedef void (*INITCRTC16QT)(TABLEDATA FAR *);
typedef void (*SETLUT16QT)(TABLEDATA FAR *);
typedef void (*SETCRTCREG16QT)(REGDATA FAR *);
typedef void (*FREEZE16QT)(unsigned);
typedef void (*LIVE16QT)(unsigned);
typedef void (*POORFREEZE16QT)(unsigned);
typedef void (*SELFSYNC16QT)(unsigned);
typedef void (*CRTCSTATUS16QT)(unsigned);
typedef int  (*ENDFRAME16QT)(unsigned);
typedef int  (*DETECT16QT)(unsigned);
typedef int  (*GETREGVAL16QT)(unsigned);
typedef void (*SETREGVAL16QT)(REGDATA FAR *);

typedef HINSTANCE (WINAPI *LOADLIBRARY16)(LPCSTR);
typedef void (WINAPI *FREELIBRARY16)(HINSTANCE);
typedef FARPROC (WINAPI *GETPROCADDRESS16)(HMODULE, LPCSTR);
typedef void (_cdecl *QT_THUNK)(void);

// Prototypes of functions in VICHRT16.DLL
void _export WINAPI Initcrtc16QT(TABLEDATA far *lpData);
void _export WINAPI Setlut16QT(TABLEDATA far *lpData);
void _export WINAPI GetDigiData16QT(READLINEDATA FAR *lpData);
void _export WINAPI PutDigiData16QT(READLINEDATA FAR *lpData);
void _export WINAPI Setcrtcreg16QT(REGDATA far *lpData);
void _export WINAPI Freeze16QT(DWORD baseSeg);
void _export WINAPI Poorfreeze16QT(DWORD baseSeg);
void _export WINAPI Live16QT(DWORD baseSeg);
void _export WINAPI Selfsync16QT(DWORD baseSeg);
int  _export WINAPI Crtcstatus16QT(DWORD baseSeg);
int  _export WINAPI Endframe16QT(DWORD baseSeg);
int  _export WINAPI Detect16QT(DWORD baseSeg);
int  _export WINAPI Getregval16QT(DWORD baseSeg);
void _export WINAPI Setregval16QT(REGDATA far *lpData);

#ifdef __cplusplus
  extern "C" {
#endif

#if defined WIN32 || defined _WIN32

int  _export WINAPI HRTcrtcstatus(unsigned baseSeg);
int  _export WINAPI HRTgetregval(unsigned baseSeg, unsigned reg);
void _export WINAPI HRTsetregval(unsigned baseSeg, unsigned reg, int value);
int  _export WINAPI HRTdetect(unsigned baseSeg);
int  _export WINAPI HRTendframe(unsigned baseSeg);
int  _export WINAPI HRTframeaverage(unsigned baseSeg, int frames,
   imgdes far *desimg, int scrnx, int scrny, int scrnendx, int scrnendy,
   int (WINAPI *dspfct)());
void _export WINAPI HRTfreeze(unsigned baseSeg);
void _export WINAPI HRTgetsize(int far *cols, int far *rows);
void _export WINAPI HRTinitcrtc(unsigned baseSeg, UCHAR far *crtc_table);
void _export WINAPI HRTlive(unsigned baseSeg);
void _export WINAPI HRTpoorfreeze(unsigned baseSeg);
int  _export WINAPI HRTreadimage(unsigned baseSeg, imgdes far *desimg,
   int scrnx, int scrny, int scrnendx, int scrnendy);
void _export WINAPI HRTselfsync(unsigned baseSeg);
void _export WINAPI HRTsetcrtcreg(unsigned baseSeg, int reg, int value);
void _export WINAPI HRTsetlut(unsigned baseSeg, UCHAR far *lut_table);
int  _export WINAPI HRTstart(unsigned baseSeg, int vidstd);
int  _export WINAPI HRTwriteimage(unsigned baseSeg, imgdes far *srcimg, int scrnx,
   int scrny, int scrnendx, int scrnendy);
WORD _export WINAPI HRTVictorversion(void);
#else

// 16-bit Windows
UCHAR far * _export WINAPI HRTgetbaseaddr(unsigned baseSeg);
int  _export WINAPI HRTcrtcstatus(UCHAR far *baseAddr);
int  _export WINAPI HRTdetect(UCHAR far *baseAddr);
int  _export WINAPI HRTendframe(UCHAR far *baseAddr);
int  _export WINAPI HRTframeaverage(UCHAR far *baseAddr, int frames,
   imgdes far *desimg, int scrnx, int scrny, int scrnendx, int scrnendy,
   int (WINAPI *dspfct)());
void _export WINAPI HRTfreeze(UCHAR far *baseAddr);
int  _export WINAPI HRTgetpixel(UCHAR far *baseAddr, int xscr, int yscr);
void _export WINAPI HRTgetsize(int far *cols, int far *rows);
void _export WINAPI HRTinitcrtc(UCHAR far *baseAddr, UCHAR far *crtc_table);
void _export WINAPI HRTlive(UCHAR far *baseAddr);
void _export WINAPI HRTpoorfreeze(UCHAR far *baseAddr);
int  _export WINAPI HRTreadimage(UCHAR far *baseAddr, imgdes far *desimg,
   int scrnx, int scrny, int scrnendx, int scrnendy);
void _export WINAPI HRTreadpen(UCHAR far *baseAddr, int far *xaddr, int far *yaddr);
int  _export WINAPI HRTreadpixel(UCHAR far *baseAddr, int xscr, int yscr);
void _export WINAPI HRTselfsync(UCHAR far *baseAddr);
void _export WINAPI HRTsetcrtcreg(UCHAR far *baseAddr, int reg, int value);
void _export WINAPI HRTsetlut(UCHAR far *baseAddr, UCHAR far *lut_table);
int  _export WINAPI HRTsetpixel(UCHAR far *baseAddr, int xscr, int yscr, int value);
void _export WINAPI HRTsetwinpos(UCHAR far *baseAddr, int hsync, int vsync);
void _export WINAPI HRTsetwinsize(UCHAR far *baseAddr, int width, int height);
int  _export WINAPI HRTstart(UCHAR far *baseAddr, int vidstd);
int  _export WINAPI HRTwriteimage(UCHAR far *baseAddr, imgdes far *srcimg, int scrnx,
   int scrny, int scrnendx, int scrnendy);
int  _export WINAPI HRTwritepixel(UCHAR far *baseAddr, int xscr, int yscr, int value);
void _export WINAPI usepalvideo(int vidtype);
#endif

#ifdef __cplusplus
  }
#endif
#endif  // _DIGIHRT_H_
