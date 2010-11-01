#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
using std::string;

namespace VCell {
	class Exception
	{
	public:
		Exception();
		Exception(string message);
		Exception(string title, string message);
		virtual string getExactMessage();
		string getMessage(void);
		~Exception(void);
		static void rethrowException(Exception& ex, string replacementMessage="");
		void replaceMessage(string& replacementMessage);
		static string add_escapes(string str);
	//	static string add_escape(char ch);

	protected:
		string message;	
		string title;	
	};
}

#endif
