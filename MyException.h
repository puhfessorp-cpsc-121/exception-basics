#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <string>

class MyException
{
	public:
		MyException() = delete;
		MyException(std::string message, int number)
		{
			this->message_ = message;
			this->number_ = number;
		}
		
		std::string what() const
		{
			return "Exception while trying to use the number " + std::to_string(this->number_) + " ==> " + this->message_;
		}
	
	private:
		std::string message_;
		int number_;
};

class MyUncaughtException
{
	public:
		MyUncaughtException() = delete;
		MyUncaughtException(std::string message, int number)
		{
			this->message_ = message;
			this->number_ = number;
		}
		
		std::string what() const
		{
			return "Exception while trying to use the number " + std::to_string(this->number_) + " ==> " + this->message_;
		}
	
	private:
		std::string message_;
		int number_;
};

#endif

