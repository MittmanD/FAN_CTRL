#include "io.h"

volatile unsigned char *dip_port[] =                {&DIP0_PORT,&DIP1_PORT,&DIP2_PORT,&DIP3_PORT};
volatile unsigned char *dip_tris[] =                {&DIP0_TRIS,&DIP1_TRIS,&DIP2_TRIS,&DIP3_TRIS};
const unsigned char     dip_pin[] =                  {DIP0,DIP1,DIP2,DIP3};


void dip_init (void)
{
    unsigned char I;
    for (I=0; I<4; I++)
    {
        *(dip_port[I]) &= (~(dip_pin[I]));
        *(dip_tris[I]) |=   (dip_pin[I]);
    }
}

unsigned char dip_read (void)
{
    unsigned char I;
    unsigned char RetVal = 0;
    for (I=0;I<4;I++)
    {
        if ((*(dip_port[I])) & (dip_pin[I]))
           RetVal |=   (1 << I);
        else
           RetVal &= (~(1 << I));
    }
    return RetVal;
}