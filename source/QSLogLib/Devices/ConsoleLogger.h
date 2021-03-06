// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

// ConsoleLoffer.h

#ifndef _SLOGLIB_CONSOLELOGGER_H_
#define _SLOGLIB_CONSOLELOGGER_H_

#include "QSLogLib/Devices/AbstractLoggingDevice.h"

#include <iostream>

namespace QSLogLib {
;

// The ConsoleLogger class writes the logging messages to a console (STDOUT).
class ConsoleLogger : public AbstractLoggingDevice
{
public:
	
	ConsoleLogger(AbstractFormatter* formatter) 
		: AbstractLoggingDevice(formatter) {}
	ConsoleLogger(AbstractFormatter* formatter, const std::string& name) 
		: AbstractLoggingDevice(formatter, name) {}
	ConsoleLogger(AbstractFormatter* formatter, const std::string& name, bool isEnabled, bool isBuffered, size_t numBufferedMessages)
		: AbstractLoggingDevice(formatter, name, isEnabled, isBuffered, numBufferedMessages) {}
	
protected:
	
	inline void _WriteMessage(const std::string& message)
	{
		std::cout << message;
	}
};

};	// End namespace

#endif
