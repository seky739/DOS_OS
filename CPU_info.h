//
// Created by micha on 15.11.2017.
//

#ifndef OS_PROJ_CPU_INFO_H
#define OS_PROJ_CPU_INFO_H

#define REG_COUNT 16							// počet dostupných registrů
#define HEADER_SIZE 0x100 					// velikost hlavicky v pameni ptogramu
#define SEGMENT_SIZE 65536				// velikost rezervované paměti
#define INTERRUPTS_COUNT 256		// velikost tabulky přerušení;

#define DISPLAY_POINTER	0xB800		// pointer do paměti pro uložení výstupu na display
#define STRING 0x24								// terminální znak výpisu řetězce (pro int 21h)



void printReg(Registr *regs);
register16 *getRMregister(bit8 position, bit8 val, Registr *regs);
register16 *getRMsegment(bit8 position, bit8 val, Registr *regs);
bit8 getRMmode(bit8 val);

// obsluha přerušení

int int_10(Registr *regs, bit8 *memory);
int int_20(Registr *regs, bit8 *memory);
int int_21(Registr *regs, bit8 *memory);

void writeBuffer(bit8 *memory);

#endif //OS_PROJ_CPU_INFO_H
