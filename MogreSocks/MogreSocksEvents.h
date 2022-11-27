#ifndef _MOGRESOCKSEVENTS_H
#define _MOGRESOCKSEVENTS_H

#include "OgreSocksCallbacks.h"
#include "Util.h"

using namespace OgreSocks;
using namespace System;
using namespace System::Runtime::InteropServices;

namespace MogreSocks
{
	delegate void ConnectEventHandler(String^, unsigned long, int);
	delegate void DisconnectEventHandler(String^, unsigned long);
	delegate void ReceiveEventHandler(array<Byte>^, String^, unsigned long);
}

#endif