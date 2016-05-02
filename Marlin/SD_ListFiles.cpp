// 
// 
// 

#include "SD_ListFiles.h"

#include "genieArduino.h"
#include "Touch_Screen_Definitions.h"
#include "Marlin.h"
#include "Configuration.h"
#include "stepper.h"
#include "temperature.h"
#include "cardreader.h"


Listfiles::Listfiles(){
	 dias=-1, horas=-1, minutos=-1;
 comandline[50];
 comandline2[13];

}


void Listfiles::get_lineduration(void){
	
	card.openFile(card.filename, true);
	//memset(comandline, '\0', sizeof(char)*65 );
	//memset(comandline2, '\0', sizeof(char)*65 );
	 dias=-1, horas=-1, minutos=-1;
	char serial_char='\0';
	//comandline="";
	int posi = 0;
	int linecomepoint=0;
	while(linecomepoint < 3){
		memset(comandline, '\0', sizeof(char)*65 );
		while(comandline[0]!=';'){
			serial_char='\0';
			posi = 0;
			while(serial_char != '\n' && posi < 49){
				
				int16_t n=card.get();
				serial_char = (char)n;
				comandline[posi]=serial_char;
				
				
				posi++;
			}
		}
		linecomepoint++;
	}
	card.closefile();
	extract_data();
	Serial.println(comandline);
	
	
}
void Listfiles::extract_data(void){
	sscanf( comandline, ";Print time: %d days %d hours %d minutes", &dias, &horas, &minutos);
	if(minutos ==-1 && horas ==-1){
		dias = 0;
		sscanf( comandline, ";Print time: %d hours %d minutes", &horas, &minutos);
	}
	
	if(minutos ==-1){
		horas = 0;
		sscanf( comandline, ";Print time: %d minutes", &minutos);
	}
	if(minutos ==0){
		minutos = 1;
	}
}
	
int Listfiles::get_hours(){
	int hours = 0;
	if(dias>0){
		hours = 24*dias + horas;
	}
	else{
		hours = horas;
	}
	return hours;
}
int Listfiles::get_minutes(){
	int mins = 0;
	mins = minutos;
	return mins;
}