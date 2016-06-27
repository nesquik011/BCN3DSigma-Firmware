/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino/Genuino Mega w/ ATmega2560 (Mega 2560), Platform=avr, Package=arduino
*/

#define __AVR_ATmega2560__
#define ARDUINO 168
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
#define F_CPU 16000000L
#define ARDUINO 168
#define ARDUINO_AVR_MEGA2560
#define ARDUINO_ARCH_AVR
extern "C" void __cxa_pure_virtual() {;}

void serial_echopair_P(const char *s_P, float v);
void serial_echopair_P(const char *s_P, double v);
void serial_echopair_P(const char *s_P, unsigned long v);
void enquecommand(const char *cmd);
void enquecommand_P(const char *cmd);
void setup_killpin();
void setup_photpin();
void setup_powerhold();
void suicide();
void servo_init();
//
//
int getBuflen ();
inline void ListFilesUpfunc();
inline void ListFilesDownx3func();
inline void ListFileListINITSD();
inline void ListFileListENTERBACKFORLDERSD();
void update_screen_printing();
void update_screen_noprinting();
void update_screen_sdcard();
void touchscreen_update();
void get_command();
float code_value();
long code_value_long();
bool code_seen(char code);
float x_home_pos(int extruder);
static int x_home_dir(int extruder);
static void axis_is_at_home(int axis);
static void set_bed_level_equation_lsq(double *plane_equation_coefficients);
static void set_bed_level_equation_3pts(float z_at_pt_1, float z_at_pt_2, float z_at_pt_3);
int sentit (float dz);
float voltes (float dz);
int aprox (float voltes);
static void run_z_probe();
static void do_blocking_move_to(float x, float y, float z);
static void do_blocking_move_relative(float offset_x, float offset_y, float offset_z);
static void setup_for_endstop_move();
static void clean_up_after_endstop_move();
static void engage_z_probe();
static void retract_z_probe();
static float probe_pt(float x, float y, float z_before);
static void homeaxis(int axis);
void homeFromMain();
void refresh_cmd_timeout(void);
inline void gcode_G0_G1();
inline void gcode_G2();
inline void gcode_G3();
inline void gcode_G4();
inline void gcode_G10();
inline void gcode_G11();
inline void gcode_G28();
inline void gcode_G40();
inline void gcode_G41();
inline void gcode_G43();
inline void gcode_G33();
inline void gcode_G34();
inline void gcode_G69();
inline void gcode_G70();
inline void gcode_G29();
inline void gcode_G30();
inline void gcode_G31();
inline void gcode_G32();
inline void gcode_G90();
inline void gcode_G91();
inline void gcode_G92();
inline void gcode_M0_M1();
inline void gcode_M17();
inline void gcode_M20();
inline void gcode_M21();
inline void gcode_M22();
inline void gcode_M23();
inline void gcode_M24();
inline void gcode_M25();
inline void gcode_M26();
inline void gcode_M27();
inline void gcode_M28();
inline void gcode_M29();
inline void gcode_M30();
inline void gcode_M32();
inline void gcode_M928();
inline void gcode_M31();
inline void gcode_M42();
inline void gcode_M48();
inline void gcode_M104();
inline void gcode_M112();
inline void gcode_M140();
inline void gcode_M105();
inline void gcode_M190();
inline void gcode_M106();
inline void gcode_M107();
inline void gcode_M126();
inline void gcode_M127();
inline void gcode_M128();
inline void gcode_M129();
inline void gcode_M109();
inline void gcode_M80();
inline void gcode_M81();
inline void gcode_M82();
inline void gcode_M83();
inline void gcode_M84();
inline void gcode_M85();
inline void gcode_M92();
inline void gcode_M115();
inline void gcode_M117();
inline void gcode_M114();
inline void gcode_M120();
inline void gcode_M119();
inline void gcode_M121();
inline void gcode_M150();
inline void gcode_M200();
inline void gcode_M201();
inline void gcode_M202();
inline void gcode_M203();
inline void gcode_M204();
inline void gcode_M205();
inline void gcode_M206();
inline void gcode_M665();
inline void gcode_M207();
inline void gcode_M208();
inline void gcode_M209();
inline void gcode_M218();
inline void gcode_M220();
inline void gcode_M221();
inline void gcode_M226();
inline void gcode_M280();
inline void gcode_M300();
inline void gcode_M301();
inline void gcode_M304();
inline void gcode_M240();
inline void gcode_M250();
inline void gcode_M302();
inline void gcode_M303();
inline void gcode_M307();
inline void gcode_M360();
inline void gcode_M361();
inline void gcode_M362();
inline void gcode_M363();
inline void gcode_M364();
inline void gcode_M365();
inline void gcode_M400();
inline void gcode_M401();
inline void gcode_M402();
inline void gcode_M404();
inline void gcode_M405();
inline void gcode_M406();
inline void gcode_M407();
inline void gcode_M500();
inline void gcode_M501();
inline void gcode_M502();
inline void gcode_M503();
inline void gcode_M504();
inline void gcode_M505();
inline void gcode_M510();
inline void gcode_M520();
inline void gcode_M530();
inline void gcode_M540();
inline void gcode_M600();
inline void gcode_M605();
inline void gcode_M907();
inline void gcode_M908();
inline void gcode_M350();
inline void gcode_M351();
inline void gcode_M999();
inline void gcode_M851();
inline void gcode_T0_T1();
void gcode_T0_T1_auto(int code);
void process_commands();
void changeToolSigma(int tool);
void changeTool(int ntool);
void FlushSerialRequestResend();
void ClearToSend();
void get_coordinates();
void clamp_to_software_endstops(float target[3]);
void recalc_delta_settings(float radius, float diagonal_rod);
void calculate_delta(float cartesian[3]);
void prepare_move();
void prepare_arc_move(char isclockwise);
void controllerFan();
void calculate_SCARA_forward_Transform(float f_scara[3]);
void calculate_delta(float cartesian[3]);
void handle_status_leds(void);
void manage_inactivity();
void kill();
void Stop();
bool IsStopped();
void setPwmFrequency(uint8_t pin, int val);
void left_test_print_code();
void right_test_print_code();
void home_axis_from_code(bool x_c, bool y_c, bool z_c);

#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega\pins_arduino.h" 
#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\arduino.h"
#include <..\Marlin\Marlin.pde>
#include <..\Marlin\BlinkM.cpp>
#include <..\Marlin\BlinkM.h>
#include <..\Marlin\Configuration.h>
#include <..\Marlin\ConfigurationStore.cpp>
#include <..\Marlin\ConfigurationStore.h>
#include <..\Marlin\Configuration_adv.h>
#include <..\Marlin\DOGMbitmaps.h>
#include <..\Marlin\Hysteresis.cpp>
#include <..\Marlin\Hysteresis.h>
#include <..\Marlin\LCD_Handler.h>
#include <..\Marlin\LiquidCrystalRus.cpp>
#include <..\Marlin\LiquidCrystalRus.h>
#include <..\Marlin\Marlin.h>
#include <..\Marlin\Marlin.ino>
#include <..\Marlin\Marlin_main.cpp>
#include <..\Marlin\SD_ListFiles.cpp>
#include <..\Marlin\SD_ListFiles.h>
#include <..\Marlin\Sd2Card.cpp>
#include <..\Marlin\Sd2Card.h>
#include <..\Marlin\Sd2PinMap.h>
#include <..\Marlin\SdBaseFile.cpp>
#include <..\Marlin\SdBaseFile.h>
#include <..\Marlin\SdFatConfig.h>
#include <..\Marlin\SdFatStructs.h>
#include <..\Marlin\SdFatUtil.cpp>
#include <..\Marlin\SdFatUtil.h>
#include <..\Marlin\SdFile.cpp>
#include <..\Marlin\SdFile.h>
#include <..\Marlin\SdInfo.h>
#include <..\Marlin\SdVolume.cpp>
#include <..\Marlin\SdVolume.h>
#include <..\Marlin\Servo.cpp>
#include <..\Marlin\Servo.h>
#include <..\Marlin\Touch_Screen_Definitions.h>
#include <..\Marlin\cardreader.cpp>
#include <..\Marlin\cardreader.h>
#include <..\Marlin\digipot_mcp4451.cpp>
#include <..\Marlin\dogm_font_data_marlin.h>
#include <..\Marlin\dogm_lcd_implementation.h>
#include <..\Marlin\fastio.h>
#include <..\Marlin\genieArduino.cpp>
#include <..\Marlin\genieArduino.h>
#include <..\Marlin\language.cpp>
#include <..\Marlin\language.h>
#include <..\Marlin\motion_control.cpp>
#include <..\Marlin\motion_control.h>
#include <..\Marlin\pins.h>
#include <..\Marlin\planner.cpp>
#include <..\Marlin\planner.h>
#include <..\Marlin\qr_solve.cpp>
#include <..\Marlin\qr_solve.h>
#include <..\Marlin\speed_lookuptable.h>
#include <..\Marlin\stepper.cpp>
#include <..\Marlin\stepper.h>
#include <..\Marlin\temperature.cpp>
#include <..\Marlin\temperature.h>
#include <..\Marlin\thermistortables.h>
#include <..\Marlin\ultralcd.cpp>
#include <..\Marlin\ultralcd.h>
#include <..\Marlin\ultralcd_implementation_hitachi_HD44780.h>
#include <..\Marlin\ultralcd_st7920_u8glib_rrd.h>
#include <..\Marlin\vector_3.cpp>
#include <..\Marlin\vector_3.h>
#include <..\Marlin\watchdog.cpp>
#include <..\Marlin\watchdog.h>
