#include "stdafx.h"

namespace Error
{
	//    0 - 99 - системные ошибки
	// 100 - 109 - ошибки параметров
	// 110 - 119 - ошибки открытия и чтения файлов

	ERROR errors[ERROR_MAX_ENTRY] = 
    {
    ERROR_ENTRY(0, "Недопустимый код ошибки"),
    ERROR_ENTRY(1, "Системный сбой"),
    ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
    ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
    ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40),
    ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
    ERROR_ENTRY(100, "Параметр -in должен быть задан"),
    ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
    ERROR_ENTRY(104, "Превышена длина входного параметра"),
    ERROR_ENTRY(105, "Дублирование идентификатора"),
    ERROR_ENTRY(106, "Идентификатор не определён"), ERROR_ENTRY_NODEF(107), ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
    ERROR_ENTRY(110, "Ошибка при открытии файла с исходным кодом (-in)"),
    ERROR_ENTRY(111, "Недопустимый символ в исходном файле (-in)"),
    ERROR_ENTRY(112, "Ошибка при создании файла с протоколом (-log)"),
    ERROR_ENTRY(113, "Ошибка при создании выходного файла с расширением .out"),
    ERROR_ENTRY(114, "Недопустимый размер таблицы лексем"),
    ERROR_ENTRY(115, "Превышен размер таблицы лексем"),
    ERROR_ENTRY(117, "Недопустимый размер таблицы идентификаторов"),
    ERROR_ENTRY(118, "Превышен размер таблицы идентификаторов"),
    ERROR_ENTRY(119, "Превышена длина лексемы"),
    ERROR_ENTRY_NODEF10(120),
    ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160),
    ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190), ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300),
    ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
    ERROR_ENTRY(600, "Неверная структура программы"),
    ERROR_ENTRY(601, "Ошибочный оператор"),
    ERROR_ENTRY(602, "Ошибка в выражении"),
    ERROR_ENTRY(603, "Ошибка в параметрах функции"),
    ERROR_ENTRY(604, "Ошибка в параметрах вызываемой функции"),
    ERROR_ENTRY(605, "Казан"), ERROR_ENTRY_NODEF(606), ERROR_ENTRY_NODEF(607), ERROR_ENTRY_NODEF(608), ERROR_ENTRY_NODEF(609), ERROR_ENTRY_NODEF10(610),
    ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630), ERROR_ENTRY_NODEF10(640), ERROR_ENTRY_NODEF10(650), ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670),
    ERROR_ENTRY_NODEF10(680), ERROR_ENTRY_NODEF10(690),
    ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800),
    ERROR_ENTRY_NODEF100(900)
    };

	ERROR geterror(int id)
	{
		if (id > ERROR_MAX_ENTRY - 1 || id < 1)
			return errors[0];
		return errors[id - 1];
	}
	ERROR geterrorin(int id, int line = -1, int col = -1, unsigned char* text = (unsigned char*)"")
	{
		if (id > ERROR_MAX_ENTRY - 1 || id < 1)
			return errors[0];
		else
		{
			errors[id].inext.col = col;
			errors[id].inext.line = line;
			errors[id].inext.text = text;
			return errors[id];
		}
	}
};