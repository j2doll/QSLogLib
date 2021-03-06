// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

// AbstractFormatter.h

#ifndef _SLOGLIB_ABSTRACTFORMATTER_H_
#define _SLOGLIB_ABSTRACTFORMATTER_H_

#include "QSLogLib/Message.h"

#include <string>

namespace QSLogLib {
;

enum NewLineFlag
{
	DoNotAppendNewLine = 0,
	AppendNewLine      = 1
};

///! The AbstractFormatter class is the base class of all formatters. A formatter formats a 
///! Message to a std::string. A logging device uses a formatter to format a message.
class AbstractFormatter
{
public:

	AbstractFormatter(NewLineFlag newLineflag = DoNotAppendNewLine)
		: mNewLineFlag(newLineflag)
	{}
	
	virtual ~AbstractFormatter() {}
	
	///! Format a message to std::string.
	virtual std::string FormatMessage(const Message& msg) const = 0;

protected:

	NewLineFlag mNewLineFlag;
};

};	// End namespace

#endif // _SLOGLIB_ABSTRACTFORMATTER_H_
