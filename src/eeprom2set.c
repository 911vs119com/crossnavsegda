#include <stdio.h>

enum modelist {
  STARTLEVEL = 5,
  CELLDELAY = 7,
  CELLLEVEL = 8,
  ZERODELAY = 11,
  ZEROTEST = 12,
  PURGE = 13,
  TOTALMERCURYDELAY = 21,
  TOTALMERCURY = 22,
  ELEMENTALMERCURYDELAY = 26,
  ELEMENTALMERCURY = 27,
  PRECALIBRATIONDELAY = 31,
  CALIBRATION = 32,
  POSTCALIBRATIONDELAY = 33
};

struct lengthtablestruct {
  int startlevel;
  int celldelay;
  int celllevel;
  int zerodelay;
  int zerotest;
  int purge;
  int totalmercurydelay;
  int totalmercury;
  int elementalmercurydelay;
  int elementalmercury;
  int precalibrationdelay;
  int calibration;
  int postcalibrationdelay;
};

struct jumptablestruct {
  enum modelist startlevel;
  enum modelist celldelay;
  enum modelist celllevel;
  enum modelist zerodelay;
  enum modelist zerotest;
  enum modelist purge;
  enum modelist totalmercurydelay;
  enum modelist totalmercury;
  enum modelist elementalmercurydelay;
  enum modelist elementalmercury;
  enum modelist precalibrationdelay;
  enum modelist calibration;
  enum modelist postcalibrationdelay;
};

int main(void)
{
	struct eeprom
	{
		unsigned char ip[4];
		unsigned char mac[6];
		struct lengthtablestruct length_table;
	  struct jumptablestruct jump_table;
	};
	struct eeprom e;
	fgets((char *)&e,sizeof(e),stdin);
	printf("ip = %hhu.%hhu.%hhu.%hhu\n",e.ip[0],e.ip[1],e.ip[2],e.ip[3]);
	printf("mac = %hhx:%hhx:%hhx:%hhx:%hhx:%hhx\n",e.mac[0],e.mac[1],e.mac[2],e.mac[3],e.mac[4],e.mac[5]);
	printf("startlevel = %hu\nprecalibrationdelay = %hu\ncalibration = %hu\npostcalibrationdelay = %hu\ncelldelay = %hu\ncelllevel = %hu\nzerodelay = %hu\nzerotest = %hu\ntotalmercurydelay = %hu\ntotalmercury = %hu\nelementalmercurydelay = %hu\nelementalmercury = %hu\npurge = %hu\n",e.length_table.startlevel,e.length_table.precalibrationdelay,e.length_table.calibration,e.length_table.postcalibrationdelay,e.length_table.celldelay,e.length_table.celllevel,e.length_table.zerodelay,e.length_table.zerotest,e.length_table.totalmercurydelay,e.length_table.totalmercury,e.length_table.elementalmercurydelay,e.length_table.elementalmercury,e.length_table.purge);
	return 0;
}