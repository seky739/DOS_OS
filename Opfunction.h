//
// Created by micha on 15.11.2017.
//

#ifndef OS_PROJ_OPFUNCTION_H
#define OS_PROJ_OPFUNCTION_H

#include "Registers.h"

int moveEax(Registr *r, bit8 *pamet);
int moveC(Registr *r, bit8 *pamet);
int moveE(Registr *r, bit8 *pamet);
int xor_instr(Registr *r, bit8 *pamet);
int moveEdx(Registr *r, bit8 *pamet);
int moveEsi(Registr *r, bit8 *pamet);
int moveEbx(Registr *r, bit8 *pamet);
int jmp(Registr *r, bit8 *pamet);
int inc(Registr *r, bit8 *pamet);
int add(Registr *r, bit8 *pamet);
int moveA(Registr *r, bit8 *pamet);
int incebx(Registr *r, bit8 *pamet);
int incedx(Registr *r, bit8 *pamet);
int dececx(Registr *r, bit8 *pamet);
int moveah(Registr *r, bit8 *pamet);
int addaddr(Registr *r, bit8 *pamet);
int movedi(Registr *r, bit8 *pamet);
int movec7(Registr *r, bit8 *pamet);

#endif //OS_PROJ_OPFUNCTION_H
