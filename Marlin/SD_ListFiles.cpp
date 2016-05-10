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
	filmetros1 = 0 ,filmetros2=0;
	filgramos1 = 0 ,filgramos2=0;
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
	sscanf(comandline, ";Filament used: %d.%dm %d.%dg", &filmetros1, &filmetros2, &filgramos1, &filgramos2);
	
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
int Listfiles::get_filgramos1(){
	int gram = 0;
	gram = filgramos1;
	return gram;
}
int Listfiles::get_filgramos2(){
	int gram = 0;
	gram = filgramos2;
	return gram;
}
int Listfiles::get_hoursremaning(){
	long hours = 0;
	if (get_hours()==0)return 0;
	hours = ((long)get_hours()*60+(long)get_minutes());
	hours = hours-hours*(long)card.getSdPosition()/(long)card.getFileSize();
	hours = hours/60;
	return (int) hours;
}
int Listfiles::get_minutesremanig(){
	long minu = 0;
	if (get_minutes()==-1)return 0;
	minu = ((long)get_hours()*60+(long)get_minutes());
	minu = minu-minu*(long)card.getSdPosition()/(long)card.getFileSize();
	minu = minu%60;
	return (int) minu;
}