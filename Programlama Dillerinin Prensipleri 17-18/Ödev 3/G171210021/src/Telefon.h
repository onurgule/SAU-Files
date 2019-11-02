#ifndef TEL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IMEI.h"
#define TEL_H
struct TEL{
	Imei imei;
	char telno[11];
	void (*RastgeleTelUret)(struct TEL*);
};
typedef struct TEL* Tel;
Tel TelefonOlustur();
void RastgeleTelUret(Tel);
#endif
