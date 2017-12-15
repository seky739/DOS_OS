//
// Created by micha on 15.11.2017.
//

#ifndef OS_PROJ_OPFUNCTION_H
#define OS_PROJ_OPFUNCTION_H

#include "Registers.h"


int moveEax(Registr* , bit8*);
int moveC(Registr*, bit8*);
int moveE(Registr* , bit8*);
int xor_instr(Registr*, bit8*);
int moveEdx(Registr*, bit8*);
int moveEsi(Registr*, bit8*);
int moveEbx(Registr*, bit8*);
int jmp(Registr*, bit8*);
int inc(Registr*, bit8*);
int add(Registr*, bit8*);
int moveA(Registr*, bit8*);
int incebx(Registr*, bit8*);
int incedx(Registr*, bit8*);
int dececx(Registr*, bit8*);
int moveah(Registr*, bit8*);
int addaddr(Registr*, bit8*);
int movedi(Registr*, bit8*);
int movec7(Registr*, bit8*);
int jnp(Registr*, bit8*);
int cmp(Registr*, bit8*);
int jne(Registr*, bit8*);

char doplnek(char value);




#endif //OS_PROJ_OPFUNCTION_H
