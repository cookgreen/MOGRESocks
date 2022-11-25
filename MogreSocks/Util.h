#ifndef _UTILS_H
#define _UTILS_H

#include "Ogre.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace MogreSocks
{
	public ref class Util
	{
	public:
		static void ConvertManagedStrToOgreStr(Ogre::String& o_str, String^ str)
		{
			if(str == nullptr)
				throw gcnew System::NullReferenceException("A null string cannot be converted to an Ogre string.");

			IntPtr p_str = Marshal::StringToHGlobalAnsi(str);
			o_str = static_cast<char*>(p_str.ToPointer());
			Marshal::FreeHGlobal(p_str);
		}
	};
}
#endif