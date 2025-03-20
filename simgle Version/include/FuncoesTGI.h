#include "vicdefs.h"
#include "digihrt.h"
#include <math.h>

#define HRTcol 512
#define HRTlin 460

//--------- variáveis global ----------
extern unsigned int enderecobase;
extern int modo_video;
extern int hrtlargura, hrtaltura;
//-------------------------------------

int InicializarHRT()
{
int erro;

modo_video = 0;
enderecobase = 0xd400;
erro = HRTstart(enderecobase,modo_video);

return(erro);
}

void LerImagem(imgdes far *imagem)
{

HRTendframe(enderecobase);
//HRTendframe(enderecobase);

HRTreadimage(enderecobase, imagem, 0, 0, HRTcol - 1, HRTlin - 1);

HRTlive(enderecobase);

}

void CalcDrawHisto(imgdes *Figura, HDC Canvas, int top, int left, int height, int width)
{
long near *redtab;  /* Location of red histogram table */
long near *grntab;  /* Location of green histogram table */
long near *blutab;  /* Location of blue histogram table */
RECT rect;  /* Where to display the histogram on screen (in pixels) */

redtab = (long near *)LocalAlloc(LPTR,256 * sizeof(long) * 3);

grntab = &redtab[256];
blutab = &redtab[512];

calchisto(Figura, redtab, grntab,blutab);

rect.top = top;
rect.left = left;
rect.right = width;
rect.bottom = height;

drawhisto(Canvas, &rect, 8,
          redtab,
          grntab,
          blutab);

LocalFree((HLOCAL)redtab);

}

void espelho(imgdes far *imagem)
{
mirrorimage(imagem,imagem);
}

void backup(imgdes far *fonte, imgdes far *destino)
{
int bpp;

freeimage(destino);

if (fonte->buffwidth == 512)
    bpp = 8;
else bpp = 24;

allocimage(destino,hrtlargura,hrtaltura,bpp);

copyimage(fonte, destino);
//copyimage(imgdes far *srcimg, imgdes far *desimg);
}


//negative(imgdes far *srcimg, imgdes far *desimg);
//mirrorimage(imgdes far *srcimg, imgdes far *desimg);
//convert8bitto1bit(int mode, imgdes far *srcimg, imgdes far *desimg);

