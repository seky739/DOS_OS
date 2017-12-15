//
// Created by micha on 15.11.2017.
//

#ifndef OS_PROJ_REGISTERS_H
#define OS_PROJ_REGISTERS_H

typedef unsigned long  register32;
typedef unsigned int  register16;
typedef unsigned char bit8;

typedef struct {
    union					// AX
    {
        register16 ax;
        register32 eax;
        struct
        {
            bit8 al;
            bit8 ah;
        };
    };

    union					// BX
    {
        register16 bx;
        register32 ebx;
        struct
        {
            bit8 bl;
            bit8 bh;
        };
    };
    union				// CX
    {
        register16 cx;
        register32 ecx;
        struct
        {
            bit8 cl;
            bit8 ch;
        };
    };

    union					// DX
    {
        register16 dx;
        register32 edx;
        struct
        {
            bit8 dl;
            bit8 dh;
        };
    };

    register16 si;
    register16 di;

    register16 cs;
    register16 ds;
    register16 es;
    register16 ss;

    register16 sp;
    register16 bp;

    register16 ip;

    bit8 flag;

    bit8 instrukcniPrefix;
    bit8 ESprefer;
    bit8 porovnavani;

    //byte prefix;		// pseudoregistr pro uložení prefixu instrukce 0x66 nebo 0x67
    //byte espref;		// pseudoregistr pro uložení prefixu instrukce říkající, že má použít ES míst DS
    //byte equal;		// pseudoregistr pro uložení výsledku porovnání. Následně se bere v úvahu v podmíněném

}Registr;



#endif //OS_PROJ_REGISTERS_H
