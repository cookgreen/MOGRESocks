#ifndef _MOGRESOCKSEVENTS_H
#define _MOGRESOCKSEVENTS_H

#include "OgreSocksCallbacks.h"
#include "Util.h"

using namespace OgreSocks;
using namespace System;
using namespace System::Runtime::InteropServices;

namespace MogreSocks
{
	typedef int (__stdcall *DISCONNCALLBACKMETHOD)(String^, unsigned long);
	typedef int (__stdcall *CONNCALLBACKMETHOD)(String^, unsigned long, int);
	typedef int (__stdcall *RECVCALLBACKMETHOD)(array<Byte>^, String^, unsigned long);

	public class DisconnectNativeListener
	{
	private:
		DISCONNCALLBACKMETHOD cbm;

	public:
		DisconnectNativeListener()
		{

		}

		~DisconnectNativeListener()
		{
		}

		void SetMethod(DISCONNCALLBACKMETHOD cbm)
		{
			this->cbm = cbm;
		}

		void DisconnCallbackMethod(Ogre::String saddr, unsigned long port)
		{
			String^ addr = Util::ConvertOgreStrToManagedStr(saddr);

			cbm(addr, port);
		}
	};
	public ref class DisconnectListener
	{
	public:
		delegate void DisconnectEventHandler(String^, unsigned long);
		event DisconnectEventHandler^ OnDisconnect;

		DisconnectListener()
		{
			disconnectEventHandlerDelegate = gcnew DisconnectEventHandler(this, &DisconnectListener::_OnDisconnect);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(safe_cast<Delegate^>(disconnectEventHandlerDelegate));

			_nativeListener = new DisconnectNativeListener();
			DISCONNCALLBACKMETHOD cb = static_cast<DISCONNCALLBACKMETHOD>(ip.ToPointer());
			_nativeListener->SetMethod(cb);

			_callback = _CreateDisconnectCallback<DisconnectNativeListener>(_nativeListener, &DisconnectNativeListener::DisconnCallbackMethod);
		}

		~DisconnectListener()
		{
			delete _callback;
			delete _nativeListener;
		}

		DisconnectCallback<DisconnectNativeListener>* GetNativePtr()
		{
			return _callback;
		}
	private:
		DisconnectEventHandler^ disconnectEventHandlerDelegate;

		DisconnectNativeListener* _nativeListener;
		DisconnectCallback<DisconnectNativeListener>* _callback;

		void _OnDisconnect(String^ a, unsigned long b)
		{
			OnDisconnect(a, b);
		}
	protected:
		!DisconnectListener()
		{
			delete _callback;
			delete _nativeListener;
		}
	};

	
	public class ConnectNativeListener
	{
	private:
		CONNCALLBACKMETHOD cbm;

	public:
		ConnectNativeListener()
		{

		}

		~ConnectNativeListener()
		{
		}

		void SetMethod(CONNCALLBACKMETHOD cbm)
		{
			this->cbm = cbm;
		}

		void ConnCallbackMethod(Ogre::String saddr, unsigned long port, int i)
		{
			String^ addr = Util::ConvertOgreStrToManagedStr(saddr);

			cbm(addr, port, i);
		}
	};

	public ref class ConnnectListener
	{
	public:
		delegate void ConnectEventHandler(String^, unsigned long, int);
		event ConnectEventHandler^ OnConnect;

		ConnnectListener()
		{
			connectEvenHandlerDelegate = gcnew ConnectEventHandler(this, &ConnnectListener::_OnConnect);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(safe_cast<Delegate^>(connectEvenHandlerDelegate));

			_nativeListener = new ConnectNativeListener();
			CONNCALLBACKMETHOD cb = static_cast<CONNCALLBACKMETHOD>(ip.ToPointer());
			_nativeListener->SetMethod(cb);

			_callback = _CreateConnectCallback<ConnectNativeListener>(_nativeListener, &ConnectNativeListener::ConnCallbackMethod);
		}

		~ConnnectListener()
		{
			delete _callback;
			delete _nativeListener;
		}

		ConnectCallback<ConnectNativeListener>* GetNativePtr()
		{
			return _callback;
		}
	private:
		ConnectEventHandler^ connectEvenHandlerDelegate;

		ConnectNativeListener* _nativeListener;
		ConnectCallback<ConnectNativeListener>* _callback;

		void _OnConnect(String^ b, unsigned long c, int i)
		{
			OnConnect(b, c, i);
		}
	protected:
		!ConnnectListener()
		{
			delete _callback;
			delete _nativeListener;
		}
	};
	
	public class ReceiveNativeListener
	{
	private:
		RECVCALLBACKMETHOD cbm;

	public:
		ReceiveNativeListener()
		{

		}

		~ReceiveNativeListener()
		{
		}

		void SetMethod(RECVCALLBACKMETHOD cbm)
		{
			this->cbm = cbm;
		}

		void ReceiveCallbackMethod(std::list<char> data, Ogre::String saddr, unsigned long port)
		{
			array<Byte>^ bdata = Util::ConvertListCharToByteArray(data);
			String^ addr = Util::ConvertOgreStrToManagedStr(saddr);

			cbm(bdata, addr, port);
		}
	};

	public ref class ReceiveListener
	{
	public:
		delegate void ReceiveEventHandler(array<Byte>^, String^, unsigned long);
		event ReceiveEventHandler^ OnReceive;

		ReceiveListener()
		{
			receiveEvenHandlerDelegate = gcnew ReceiveEventHandler(this, &ReceiveListener::_OnReceive);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(safe_cast<Delegate^>(receiveEvenHandlerDelegate));
			
			_nativeListener = new ReceiveNativeListener();
			RECVCALLBACKMETHOD cb = static_cast<RECVCALLBACKMETHOD>(ip.ToPointer());
			_nativeListener->SetMethod(cb);

			_callback = _CreateReceiveCallback<ReceiveNativeListener>(_nativeListener, &ReceiveNativeListener::ReceiveCallbackMethod);
		}

		~ReceiveListener()
		{
			delete _callback;
			delete _nativeListener;
		}

		ReceiveCallback<ReceiveNativeListener>* GetNativePtr()
		{
			return _callback;
		}
	private:
		ReceiveEventHandler^ receiveEvenHandlerDelegate;

		ReceiveNativeListener* _nativeListener;
		ReceiveCallback<ReceiveNativeListener>* _callback;

		void _OnReceive(array<Byte>^ a, String^ b, unsigned long c)
		{
			OnReceive(a, b, c);
		}
	protected:
		!ReceiveListener()
		{
			delete _callback;
			delete _nativeListener;
		}
	};
}

#endif