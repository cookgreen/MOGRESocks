/*
	Copyright 2008 Paul Turnbull

	This file is part of OgreSocks.

    OgreSocks is free software; you can redistribute it and/or modify it under
	the terms of the GNU Lesser General Public License as published by the Free Software
	Foundation; either version 2 of the License, or (at your option) any later
	version.

	This program is distributed in the hope that it will be useful, but WITHOUT
	ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
	FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License along with
	this program; if not, write to the Free Software Foundation, Inc., 59 Temple
	Place - Suite 330, Boston, MA 02111-1307, USA, or go to
	http://www.gnu.org/copyleft/lesser.txt.
*/

#pragma once

#include "OgreSocksCallbacks.h"
#include "OgreSocksThunkWinProc.h"
#include "OgreSocksThunkMessageLoop.h"
#include "OgreSocksThunkThreadFireCallback.h"
#include "OgreSocksConnData.h"
#include "OgreSocksErrors.h"
#include "OgreSocksLogger.h"

#define BUF_LEN 1024
#define SO_MAX_MSG_SIZE   0x2003

namespace OgreSocks
{
	//struct for the recv thread 
	typedef struct ThreadRecvData
	{
		std::list<char> data;
		Ogre::String addr;
		unsigned long port;
	} THREADRECVDATA, *PTHREADRECVDATA;

	//!  OgreSocksBase class. 
	/*!
		The OgreSocksBase class is the base class for all Ogre sockets. You cannot create an instance of this
		class. The OgreSocksBase class handles the FD_READ event and defines the pure virtual _Receive method
		that must be implemented by inheriting classes.
	*/
	class OGRESOCKS_DECL OgreSocksBase
	{
	public:
	//functions
		virtual void Send(std::list<char> data, Ogre::String addr, unsigned long port) = 0;
		OgreSocksConnData GetConnectionData() { return m_SockData; }

		void SetReceiveListener(ReceiveCallbackBase* theCallback);

	protected:
	//functions
		//protected constructor because we dont want our users to create sockets directly, they must use the OgreSocksManager class
		OgreSocksBase(Ogre::String addr, unsigned long port, unsigned long msg, unsigned long msgFlags);
		virtual ~OgreSocksBase();
		virtual void _Init(unsigned long timeout);
		virtual void _Reset(unsigned long timeout);
		virtual void _Close(SOCKET theSock);
		virtual void _Receive(SOCKET theSock, std::list<char> &data, Ogre::String &addr, unsigned long &port) = 0;
		void _ValidateAddress(Ogre::String addr) const;
		DWORD _StartMessageLoop(void*);
		void _StopMessageLoop(unsigned long timeout);
		virtual LONG _WndProc(HWND hwnd, UINT msg, WPARAM wParam, LONG lParam);	
		DWORD _Thread_Fire_RecvCallback(void* threadData);

	//callbacks
		ReceiveCallbackBase* m_ReceiveCallback;

	//variables
		bool				m_bQuitPosted;
		HWND				m_Hwnd;
		HANDLE				m_VALIDHWNDEVENT;
		HANDLE				m_INVALIDHWNDEVENT;
		unsigned long		m_lAsyncMsg;
		unsigned long		m_lAsyncMsgFlags;
		HANDLE				m_WINDOWCLOSEDEVENT;
		unsigned long		m_lWinProcThreadID;
		OgreSocksConnData	m_SockData;
		bool				m_bInitialized;
		OgreSocksLogger*	m_Logger;
		//i don't like the idea of having a 'type' member for any class, however the socket() winsock api requires this.
		//the alternative is to have the UDP and TCP classes have an identical _Init method, with the only difference 
		//being the 'type' paramater to socket().
		long m_lType;

	//thunks
		OgreSocksThunkMessageLoop<OgreSocksBase, DWORD, void*> m_MsgLoopThunk;
		OgreSocksThunkWinProc<OgreSocksBase, LONG, HWND, UINT, WPARAM, LONG> m_WinProcThunk;
		OgreSocksThunkThreadFireCallback<OgreSocksBase, DWORD, void*> m_FireRecvThreadThunk;

	private:
		//only the OgreSocksManager can create the sockets
		friend class OgreSocksManager;
	};
}