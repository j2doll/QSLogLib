# QSLogLib

> *Read this in other languages: [English](README.md), :kr: [한국어](README.ko.md)*

<p align="center"><img src="https://github.com/j2doll/QSLogLib/raw/master/markdown.data/qsloglib1.jpg"></p>

- QSLogLib is a log library based on SLogLibs.
- It is ported to Qt with improved devices and function.

## Note
- Cmake is not any more supported. 
- Use Qt. instead of complicated cross-platform code.
- UDP client logger has been added. 
- Other devices will be added. (RDBMS, NoSQL, Bletooth, Serial, DDS, MQ, etc)

## Example

### :one: How to setup

- First, include pri file on your Qt project file(*.pro).

```qmake
# Define QSLogLib relative path. You can fix this directory
#   QSLOG_PARENTPATH = ../../
#   QSLOG_HEADERPATH = ../../QSLogLib/
#   QSLOG_SOURCEPATH = ../../QSLogLib/
include(../../QSLogLib/QSLogLib.pri)
```

### :two: Logging Example for standard output and file

```cpp
#include <QtGlobal>
#include <QCoreApplication>

#include "QSLogLib/SLogLib.h"
#include "QSLogLib/Devices/AbstractLoggingDevice.h"
#include "QSLogLib/Devices/ConsoleLogger.h"
#include "QSLogLib/Devices/FileLogger.h"
#include "QSLogLib/Devices/UdpLogger.h"
#include "QSLogLib/Formatters/AbstractFormatter.h"
#include "QSLogLib/Formatters/DetailedFormatter.h"
#include "QSLogLib/Formatters/ErrorFormatter.h"
#include "QSLogLib/Formatters/InfoFormatter.h"
#include "QSLogLib/Formatters/NullFormatter.h"

int main(int argc, char *argv[])
{
    QCoreApplication mainApp(argc, argv);

    using namespace QSLogLib;

    // add logging device for console and file	
    addLoggingDevice( new ConsoleLogger(new NullFormatter) ); // Console + nullFormat
    addLoggingDevice( new FileLogger("foo.log", new DetailedFormatter) ); // File + detailedFormat

    // The following line writes the message to both console and file.
    int a = 10;
    double b = 15.3;
    const char* c = "Success";
    SLOGLIB_LOG_MSG_INFO("a = " << a << " b = " << b);
    SLOGLIB_LOG_MSG_INFO(c);

    return 0;
}
```

### :three: Logging Example for udp transmission

```cpp
int main(int argc, char *argv[])
{
	QCoreApplication mainApp(argc, argv);

	using namespace QSLogLib;

	std::string strDestAddress = "192.168.137.1";
	unsigned short destPort = 5000;
	addLoggingDevice(new UdpLogger(strDestAddress, destPort, new NullFormatter));

	// The following line writes the message to UDP packet 
	int a = 10;
	double b = 15.3;
	const char* c = "Success";
	SLOGLIB_LOG_MSG_INFO("a = " << a << " b = " << b);
	SLOGLIB_LOG_MSG_INFO(c);

	return 0;
}
```

## Test Environment

- Qt 6.0.0 (MingW, Windows 64bit)
- Qt 5.10.1 (MingW, Windows 32bit)
- Qt 5.6.2 (Linux 64bit)

## License and Authors

- QSLogLib is under MIT License. 
	- SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
	- QSLogLib : j2doll https://github.com/JayTwoLab/QSLogLib

## To Do
- Async. logging with multi-threading processing.

## Contact
- Leave me a issue. https://github.com/JayTwoLab/QSLogLib/issues
- Hi! I'm j2doll. My native language is not English and my English is not fluent. Please, use EASY English. :-)
