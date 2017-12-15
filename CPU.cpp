//
// Created by micha on 13.12.2017.
//
#include "Opfunction.h"
#include "CPU_info.h"
#include <stdio.h>



void printReg(Registr *regs)
{
    printf ("ax: %x ", regs->ax);
    printf ("bx: %x ", regs->bx);
    printf ("cx: %x ", regs->cx);
    printf ("dx: %x ", regs->dx);
    printf ("si: %x ", regs->si);
    printf ("di: %x ", regs->di);
    printf ("cs: %x ", regs->cs);
    printf ("ds: %x ", regs->ds);
    printf ("es: %x ", regs->es);
    printf ("ss: %x ", regs->ss);
    printf ("sp: %x ", regs->sp);
    printf ("bp: %x ", regs->bp);
    printf ("ip: %x ", regs->ip);
    printf ("fl: %x ", regs->flag);
    printf ("pref: %x ", regs->instrukcniPrefix);
    printf ("espr: %x ", regs->ESprefer);
    printf("\n");
}


// dekodování RM parametru
// vrací register (pro obecné registry)
// position = 1|2  zda chceme znát první nebo druhý registr





register16 *getRMregister(bit8 position, bit8 val, Registr *regs)
{

    //printf ("getRMregister pozice: %d val pred: 0x%x\n", position, val);
    if (position == 2)	// dekoduji druhy register
    {
        val <<= 2;			// smazani modu - prvni dva byty
        val >>= 5;			// osmazani nepotřebneho parametru
    }
    else
        val &= 7;			// nulovani prvnich 5 bitu tzn mod a druhy parametr


    //printf ("getRMregister val po: %d\n", val);
    switch (val)
    {
        case 0: return &regs->ax; break;
        case 1: return &regs->cx; break;
        case 2: return &regs->dx; break;
        case 3: return &regs->bx; break;
        case 4: return &regs->sp; break;
        case 5: return &regs->di; break;
        case 6: return &regs->si; break;
        case 7: return &regs->bx; break;

        default:
            printf("neznamy registr.\n");
            return NULL;
            break;
    }
}

register16 *getRMsegment(bit8 position, bit8 val, Registr *regs)
{

    if (position == 2)	// dekoduji druhý register
    {
        val <<= 2;			// smazani modu - prvni dva byty
        val >>= 5;			// smazani nepotřebneho parametru
    }
    else
        val &= 7;			// nulovani prvnich 5 bitu tzn mod a druhy parametr

    switch (val)
    {
        case 0: return &regs->es; break;
        case 1: return &regs->cs; break;
        case 3: return &regs->ds; break;
        default:
            printf("neznamy registr.\n");
            return NULL;
            break;
    }

}

// dekodování RM parametru
// vrací mód reprezentovaný prvními dvěma byty
bit8 getRMmode(bit8 val)
{
    return val >> 6;
}

int int_10(Registr *regs, bit8 *memory)
{
    int i;

        printf("INT 10\n");

    // smazání displeje
    for (i=0; i< 80*25*2; i++)
        memory[DISPLAY_POINTER + i] = 0;

    regs->ip++;
    return(0);
}

int int_20(Registr *regs, bit8 *memory)
{
        printf("INT 20. \n");

    writeBuffer(memory);
}

/*
AH = 09h - WRITE STRING TO STANDARD OUTPUT

Entry: DS:DX -> '$'-terminated string
Return: AL = 24h

*/

// zapisuje retezec do vystupniho obrazovkoveho bufferu

int int_21(Registr *regs, bit8 *memory)
{
    int i, addr;
    bit8 c;


        printf("INT 21. \n");

    for (i=0; i< 80*25*2; i++)	//nebudu riskovat zacyklení
    {
        addr = regs->dx +i;	// ds ignoruji, je to tiny
        c =  memory[addr];
        if (c == STRING)
            break;
        //printf("%c (%x) ",c, c);
        memory[DISPLAY_POINTER + 2 * i] = c;	// zapisuji do bufferu na sudé pozice, liché jsou formátování
    }

    regs->ah = 1; // STRING;
    regs->ip++;
    return(0);
}

// zapisuje obrazovkovy buffer na obrazovku

void writeBuffer(bit8 *memory)
{
    int i;
    bit8 c;

    //for (i=0; i< 80*25*2; i++)
    for (i=0; i< 300; i++)
    {
        c = memory[DISPLAY_POINTER + 2 * i] ;	// nacitam znaky na sudych pozicich
        if (c > 0x20 && c < 0xff)
            printf("%c",c);
        else
            printf("%c", 0x20);

        c = memory[DISPLAY_POINTER + 2 * i +1];


    }
    printf("\n");


}