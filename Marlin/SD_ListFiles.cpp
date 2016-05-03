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
	filmetros1 = 0 ,filmetros1=0;
 comandline[50];
 comandline2[18];

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
		memset(comandline, '\0', sizeof(comandline) );
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
	extract_data();
	memset(comandline, '\0', sizeof(comandline) );
	posi = 0;
	serial_char='\0';
	
	while(serial_char != '\n' && posi < 49){
		
		int16_t n=card.get();
		serial_char = (char)n;
		comandline[posi]=serial_char;
		
		
		posi++;
	}
	extract_data1();
	card.closefile();
	memset(comandline, '\0', sizeof(comandline) );
		
	//Serial.println(comandline);
	
	
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
void Listfiles::extract_data1(void){
	//Serial.println(comandline);
	sscanf(comandline, ";Filament used: %d.%d ", &filmetros1, &filmetros2);
	
	//Serial.println(filmetros1);
	
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
int Listfiles::get_filmetros1(){
	int metr = 0;
	metr = filmetros1;
	return metr;
}
int Listfiles::get_filmetros2(){
	int metr = 0;
	metr = filmetros2;
	return metr;
}