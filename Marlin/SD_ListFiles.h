// SD_ListFiles.h

#ifndef _SD_LISTFILES_h
#define _SD_LISTFILES_h


	#include "arduino.h"
	
	#include "genieArduino.h"
	#include "Touch_Screen_Definitions.h"
	#include "Marlin.h"
	#include "Configuration.h"
	#include "stepper.h"
	#include "temperature.h"
	#include "cardreader.h"
	
	
	
	
class Listfiles
{
	public:
	Listfiles();
	void get_lineduration(void);
	int get_hours(void);
	int get_minutes(void);
	public:
	int dias, horas, minutos;
	char comandline[50];
	char comandline2[13];
	private:
	void extract_data(void);
	
};
	
extern Listfiles listsd;	
	
	
	



#endif

