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

#include "OgreSocksBase.h"


namespace OgreSocks
{
	//struct for the connect thread 
	typedef struct ThreadDisconData
	{
		Ogre::String addr;
		unsigned long port;
	} THREADDISCONDATA, *PTHREADDISCONDATA;

	//struct for the disconnect thread 
	typedef struct ThreadConData
	{
		Ogre::String addr;
		unsigned long port;
		int err;
	} THREADCONDATA, *PTHREADCONDATA;

	//!  OgreSocksTCP class. 
	/*!
		The OgreSocksTCP class is the base class for the TCP sockets, currently 
		OgreSocksTCPClient and OgreSocksTCPServer. You cannot create an instance of this class.
		The OgreSocksTCP class extends the OgreSocksBase class and implements the actual creating and 
		binding of the OgreSocket at the Winsock level. It also handles the FD_CLOSE event,	implements 
		the shutdown/close of the sockets, and sets the 'disconnect' callback. 
	*/
	class OGRESOCKS_DECL OgreSocksTCP : public OgreSocksBase
	{
	public:
	//functions	
		void SetConnectListener(ConnectCallbackBase* theCallback);//either FD_CONNECT or FD_ACCEPT, handle separately in client/server class
		void SetDisconnectListener(DisconnectCallbackBase* theCallback);

	protected:
	//functions
		//protected constructor because we dont want our users to create sockets directly, they must use the OgreSocksManager class
		OgreSocksTCP(Ogre::String addr, unsigned long port, unsigned long msg, unsigned long msgFlags);
		virtual ~OgreSocksTCP();
		virtual void _Init(unsigned long timeout);
		virtual void _Reset(unsigned long timeout);
		virtual void _Shutdown(SOCKET sock, bool bInitThisShutdown, bool bInitPreviousShutdown = true);
		virtual void _Close(SOCKET sock);
		virtual void _Send(SOCKET sock=NULL) = 0;
		virtual LONG _WndProc(HWND hwnd, UINT msg, WPARAM wParam, LONG lParam);	
		DWORD _Thread_Fire_DisconnCallback(void* threadData);
		DWORD _Thread_Fire_ConnectCallback(void* m_iConnectErr);

	//callbacks
		ConnectCallbackBase* m_ConnectCallback;
		DisconnectCallbackBase* m_DisconnectCallback;

	//thunks
		OgreSocksThunkThreadFireCallback<OgreSocksTCP, DWORD, void*> m_FireConnThreadThunk;
		OgreSocksThunkThreadFireCallback<OgreSocksTCP, DWORD, void*> m_FireDisconnThreadThunk;

	//vars
		bool m_bShutdownCalled;

	private:
		//only the OgreSocksManager can create the sockets
		friend class OgreSocksManager;

	//=================================================
	private:
		friend class OgreSocksTestManager;
	};
}