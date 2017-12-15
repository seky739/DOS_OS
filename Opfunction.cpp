//
// Created by micha on 15.11.2017.
//
#include <stdio.h>
#include <cstdlib>
#include "Opfunction.h"
#include "Opcodes.h"
#include "CPU_info.h"
#include "Registers.h"

int moveEax(Registr *r, bit8 *pamet)  {

    if (r->instrukcniPrefix == 0)
    {
        r->al = pamet[r->ip +1];
        r->ah =  pamet[r->ip +2];
        r->ip+=3;
        printf ("MOVEAX.\n");
    }
    else
    {
        printf ("MOVEAX s prefixem %x nebylo implementováno.\n", r->instrukcniPrefix);
        return(-1);
    }
    return(0);
}

int moveC(Registr *r, bit8 *pamet) {
    bit8 RMcode;
    register16 *reg1, *reg2;
    printf ("MOVE8C.\n");
    RMcode = pamet[r->ip+1];

  switch (getRMmode(RMcode))
    {
        case 3:		// mod 11, kde se pouzivaji pouze registry
            reg2 = getRMsegment(2, RMcode, r);
           reg1 = getRMregister(1, RMcode, r);
            *reg1 = *reg2;


                printf("Instrukce MOVE Segmetový REG do obecný REG \n");
            break;
        default:
           // printf("nedefinovaný RM mod %d", getRMmode(RMcode));
            return(-1);
    }
    r->ip+=2;
    return(0);

}

int moveE(Registr *r, bit8 *pamet)
{
    printf ("MOVE8E.\n");
    bit8 RMcode;
    register16 *reg1, *reg2;

    RMcode = pamet[r->ip+1];

    switch (getRMmode(RMcode))
    {
        case 3:		// mod 11, kde se pouzivaji pouze registry
            reg2 = getRMregister(1, RMcode, r);
            reg1 = getRMsegment(2, RMcode, r);
            *reg1 = *reg2;


                printf("Instrukce MOVE obecný REG do Segmetový REG \n");
            break;
        default:
            printf("nedefinovaný RM mod %d", getRMmode(RMcode));
            return(-1);
    }
    r->ip+=2;
    return(0);

}

int xor_instr(Registr *r, bit8 *pamet) {
    printf ("XOR.\n");
    bit8 param,value;
    register16 *reg1, *reg2;


    if (r->instrukcniPrefix == OPSIZE)
    {
        param =pamet[r->ip +1];
        r->ip+=2;
        reg2 = getRMregister(1, param, r);
        reg1 = getRMregister(2, param, r);
        *reg1= *reg2 ^ *reg1;

    }
    else
    {
       /* param =pamet[r->ip +1];
        value =pamet[r->ip +2];
        reg2 = getRMregister(1, param, r);
        reg1 = getRMregister(2, param, r);
        *reg1= *reg1 ^ value;
        *reg2= *reg2 ^ value;*/
        printf ("XOR bez prefixu nebyl implementován.\n");
        return(-1);
    }
    r->instrukcniPrefix=0;
    return(0);

}

int moveEdx(Registr *r, bit8 *pamet) {
    printf ("MOVEDX.\n");
    if (r->instrukcniPrefix == 0)
    {
        r->dl = pamet[r->ip+1]; 					// nízký byte
        r->dh =  pamet[r->ip+2] ; 				// vysoký byte
        r->ip+=3;

    }
    else
    {
        printf ("MOVEDX s prefixem nebylo implementováno.\n");
        return(-1);
    }
    return(0);


}

int moveEsi(Registr *r, bit8 *pamet) {
    printf ("MOVESI.\n");
    if (r->instrukcniPrefix == 0)
    {
        r->si = pamet[r->ip+1]; 					// nízký byte
        r->si +=  pamet[r->ip+2] * 256; 	// vysoký byte
        r->ip+=3;
    }
    else
    {
        printf ("MOVE SI s prefixem nebylo implementováno.\n");
        return(-1);
    }
    return(0);

}

int moveEbx(Registr *r, bit8 *pamet) {
    printf ("MOVEBX.\n");
    if (r->instrukcniPrefix == 0)
    {
        r->bl = pamet[r->ip+1];
        r->bh =  pamet[r->ip+2] ;
        r->ip+=3;
    }
    else
    {
        printf ("MOVE BX s prefixem nebylo implementováno.\n");
        return(-1);
    }
    return(0);
}

int jmp(Registr *r, bit8 *pamet) {
    printf ("JMP.\n");
    int jmp=-1;
    jmp = pamet[r->ip+1];
    printf("Znak je : %x : %x : \n",(bit8) jmp,(bit8) pamet[r->ip+3]);
  /*  for (int i = 100; i < (SEGMENT_SIZE * sizeof(bit8)); ++i) {
        printf("%x ",pamet[r->ip+i]);
    }*/
    jmp = doplnek(jmp);
   // jmp = ~jmp; // doplnek pro skok
   // jmp++;
   // jmp=0 - jmp;
   // printReg(r);

    r->ip += jmp;			// relativne skocim o minus jeden
    r->ip += 2;
    //printf("%d",r->ip);
    //printReg(r);
    return(0);
}

int inc(Registr *r, bit8 *pamet) {
    printf ("INC.\n");
    bit8 RMcode=0;
    register16 *reg;


    RMcode = pamet[r->ip+1];

    reg = getRMregister(1, RMcode, r);
    *reg = *reg+1;
    r->ip+=2;

    return(0);
}

int add(Registr *r, bit8 *pamet) {
    printf ("ADD.\n");
    bit8 RMcode=0;
    register16 *reg1, *reg2;

    RMcode = pamet[r->ip+1];

    reg1 = getRMregister(1, RMcode, r);
    reg2 = getRMregister(2, RMcode, r);
    *reg2 = *reg2 + *reg1;

    r->ip+=2;
    return(0);


}

int moveA(Registr *r, bit8 *pamet) {
    printf ("MOVE8A.\n");
    bit8 RMcode;
    register16 *reg1, *reg2, addr;

    RMcode = pamet[r->ip+1];

    switch (getRMmode(RMcode))
    {
        case 0:		// mod 00, regiter + adresa
            reg1 = getRMregister(2,RMcode, r);

            if (r->instrukcniPrefix == 0)
            {
                addr =  pamet[r->ip+2]  + pamet[r->ip+3] * 256;
                *reg1 = pamet[addr];

                    printf ("Instrukce MOVE z paměti %x do registru R/M \n", addr);
                r->ip+=4;
            }
            if (r->instrukcniPrefix == ADSIZE)
            {
                reg2 = getRMregister(1,RMcode, r);
                //printf("reg2: %x sp: %x \n", reg2, &regs->sp);
                if (reg2 == &r->sp)  //  jedna se o SIB mode (není to uplne ciste, mel bych napsat novou funkci pro RM8 namísto RM16
                {
                    if (pamet[r->ip+2] == 6)		// ostatni rezimy neimplementovany
                        addr = r->ax + r->si;
                    r->ip+=3;

                        printf ("Instrukce MOVE (SIB mode) z paměti %x, z adresy z registru do registru R/M \n", addr);

                }
                else
                {
                    addr = *reg2;
                    r->ip+=2;

                        printf ("Instrukce MOVE z paměti %x, z adresy z registru do registru R/M \n", addr);
                }
                if (r->ESprefer == 0)			// osetreni prefixu ES
                    addr += r->ds;
                else
                    addr += r->es;

                *reg1 = pamet[addr];
            }

            break;
        default:
            printf("nedefinovaný RM mod %d\n", getRMmode(RMcode));
            return(-1);
    }

    return(0);



}

int incebx(Registr *r, bit8 *pamet) {
    r->ip++;
    r->bx = r->bx + 1;
    printf ("INCEBX.\n");
    return(0);

}

int incedx(Registr *r, bit8 *pamet) {
    r->ip++;
    r->dx = r->dx + 1;
    printf ("INCEDX.\n");
    return(0);


}

int dececx(Registr *r, bit8 *pamet) {
    r->ip++;
    r->cx = r->cx - 1;
    printf ("DECECX.\n");
    return(0);


}

int moveah(Registr *r, bit8 *pamet) {
    r->ah = pamet[r->ip+1];

        printf ("MOVE do AH prictu %x\n",pamet[r->ip+1]);
    r->ip+=2;
    return(0);

}

int addaddr(Registr *r, bit8 *pamet) {

    printf ("ADDADDR.\n");

    bit8 RMcode=0;
    register16 *reg1, *reg2, addr;

    RMcode = pamet[r->ip+1];
    //printReg(r);
    reg1 = getRMregister(2, RMcode, r);
    reg2 = getRMregister(1, RMcode, r);
    addr = *reg2;
   // printReg(r);
    pamet[addr] = pamet[addr] + *reg1;
    r->ip+=2;
    return(0);

}

int movedi(Registr *r, bit8 *pamet) {
    r->di = pamet[r->ip+1]; 								// nízký byte
    r->di +=  pamet[r->ip+2]  * 256; 				// vysoký byte
    r->ip+=3;
        printf ("MOVE do DI\n");
    return(0);


}

int movec7(Registr *r, bit8 *pamet) {
    bit8 RMcode;
    register16 *reg, addr, val;
    printf ("MOVEC7.\n");
    RMcode = pamet[r->ip+1];

    switch (getRMmode(RMcode))
    {
        case 2:		// mod 10, kde se pouzije adresa z registru + hodnota
            reg = getRMregister(1, RMcode, r);
            addr =  r->ds + *reg + pamet[r->ip+2] + pamet[r->ip+3] * 256;
            val = pamet[r->ip+4] + pamet[r->ip+5] * 256;
            pamet[addr] = val;


                printf("Instrukce MOVE C7 na adresu DI+reg (%x) R/M hodnotu %x \n", addr, val);
            break;
        default:
            printf("nedefinovaný RM mod %d", getRMmode(RMcode));
            return(-1);
    }
    r->ip+=6;
    return(0);



}

int jnp(Registr *r, bit8 *pamet){
    printf ("JNP.\n");
    return 0;
}
int cmp(Registr *r, bit8 *pamet){
    bit8 RMcode=0;
    register16 *reg1, *reg2, addr;
    printf ("CMP.\n");
    RMcode = pamet[r->ip+1];

    reg1 = getRMregister(1, RMcode, r);
   if (*reg1 == pamet[r->ip+2])
        r->porovnavani = 1;
    else
        r->porovnavani = 0;

    r->ip+=3;
    return(0);



}
int jne(Registr *r, bit8 *pamet){
    int jmp = 0;
    printf ("JNE.\n");
    if (r->porovnavani == 1)
    {
        r->ip+=2;
        printf ("Instrukce JNE shoda, posun dal\n");
    }
    else
    {
        jmp = doplnek(pamet[r->ip+1]);

        r->ip = r->ip + jmp;
        r->ip+=2;

            printf ("Instrukce JNE skok o %d na %x\n", jmp, r->ip);
    }
    return(0);
}

char doplnek(char value)
{
    value = ~value;
    value++;
    return 0 - value;
}