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


#endif //OS_PROJ_CPU_INFO_H
