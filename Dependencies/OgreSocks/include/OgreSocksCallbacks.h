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

#include "stdafx.h"

namespace OgreSocks
{
	//define macros so the caller does not have to provide the 'this' pointer, or use the <> brackets
	#define MakeConnectCallback(theClass, theFunc) _CreateConnectCallback<theClass>(this, &theClass::theFunc)
	#define MakeReceiveCallback(theClass, theFunc) _CreateReceiveCallback<theClass>(this, &theClass::theFunc)
	#define MakeDisconnectCallback(theClass, theFunc) _CreateDisconnectCallback<theClass>(this, &theClass::theFunc)


	//forward declarations
	template <class Class>class ConnectCallback;
	template <class Class>class ReceiveCallback;
	template <class Class>class DisconnectCallback;

	//The CreateXXXXXXCallback functions were created because the SetXXXXXXListener functions need to take a 'callback' object, 
	//which will contain the necessary callback info, ie CLASS::FUNCTION. The CreateXXXXXXCallback functions are therefore template functions
	//that take the class and a pointer to the function in the class that will be the callback function. The CreateXXXXXXCallback functions 
	//create an instance of the actual XXXXXXCallback object, and set the class and function pointer, before returning the callback object
	template<class Class>
	ConnectCallback<Class>* _CreateConnectCallback(Class* theClass, void (Class::*theFunction)(Ogre::String, unsigned long, int))
	{
		ConnectCallback<Class>* pCallback = new ConnectCallback<Class>;
		pCallback->SetClass(theClass);
		pCallback->SetMethod(theFunction);

		return pCallback;
	}

	template<class Class>
	ReceiveCallback<Class>* _CreateReceiveCallback(Class* theClass, void (Class::*theFunction)(std::list<char>, Ogre::String, unsigned long port))
	{
		ReceiveCallback<Class>* pCallback = new ReceiveCallback<Class>;
		pCallback->SetClass(theClass);
		pCallback->SetMethod(theFunction);

		return pCallback;
	}

	template<class Class>
	DisconnectCallback<Class>* _CreateDisconnectCallback(Class* theClass, void (Class::*theFunction)(Ogre::String, unsigned long port))
	{
		DisconnectCallback<Class>* pCallback = new DisconnectCallback<Class>;
		pCallback->SetClass(theClass);
		pCallback->SetMethod(theFunction);

		return pCallback;
	}

	//These are the base classes for the actual XXXXXXCallback classes. We use these to provide the functions that we want - in this case, 
	//just Fire_XXXXXXCallback. Having a non-template base class allows us to cast the XXXXXXXCallback template class into a more 'friendly'
	//base class that we can pass as an argumment to SetXXXXXXeListener, and allows us to declare the XXXXXXCallback as a XXXXXXXCallbackBase 
	//data member 
	class ConnectCallbackBase
	{
	public:
		virtual void Fire_ConnectCallback(Ogre::String, unsigned long, int) = 0;
	protected:
		ConnectCallbackBase() {}
	};

	class ReceiveCallbackBase
	{
	public:
		virtual void Fire_ReceiveCallback(std::list<char> data, Ogre::String addr, unsigned long port) = 0;
	protected:
		ReceiveCallbackBase() {}
	};

	class DisconnectCallbackBase
	{
	public:
		virtual void Fire_DisconnectCallback(Ogre::String addr, unsigned long port) = 0;
	protected:
		DisconnectCallbackBase() {}
	};


	//And finally, the actual callback classes. These inherit from the above base classes and define the Fire_XXXXXCallback functions.
	//The caller will not use these classes directly. They will use the macros that 'wrap' the CreateXXXXXXCallback functions to create
	//an instance of these classes and set the callback's info, ie class name and member function within that class.
	template<class Class>
	class ConnectCallback : public ConnectCallbackBase
	{
	public:
		ConnectCallback() 
		{
			m_TheClass = 0; m_TheFunction = 0;
		}

		typedef void (Class::*Function)(Ogre::String, unsigned long, int);

		void SetClass(Class* pClass)                    
		{ 
			m_TheClass = pClass; 
		}

		void SetMethod(Function pMethod)   
		{
			m_TheFunction = pMethod;
		}

	protected:

		void Fire_ConnectCallback(Ogre::String addr, unsigned long port, int i)
		{
			if(m_TheClass && m_TheFunction) 
			{ 
				(m_TheClass->*m_TheFunction)(addr, port, i);
			}
		}

	private:
		Class*        m_TheClass;
		Function    m_TheFunction;
	};

	template<class Class>
	class ReceiveCallback : public ReceiveCallbackBase
	{
	public:
		ReceiveCallback() 
		{
			m_TheClass = 0; m_TheFunction = 0;
		}

		typedef void (Class::*Function)(std::list<char> data, Ogre::String addr, unsigned long port);

		void SetClass(Class* pClass)                    
		{ 
			m_TheClass = pClass; 
		}

		void SetMethod(Function pMethod)   
		{
			m_TheFunction = pMethod;
		}

	protected:

		void Fire_ReceiveCallback(std::list<char> data, Ogre::String addr, unsigned long port)
		{
			if(m_TheClass && m_TheFunction) 
			{ 
				(m_TheClass->*m_TheFunction)(data, addr, port);
			}
		}

	private:
		Class*        m_TheClass;
		Function    m_TheFunction;
	};

	template<class Class>
	class DisconnectCallback : public DisconnectCallbackBase
	{
	public:
		DisconnectCallback() 
		{
			m_TheClass = 0; m_TheFunction = 0;
		}

		typedef void (Class::*Function)(Ogre::String addr, unsigned long port);

		void SetClass(Class* pClass)                    
		{ 
			m_TheClass = pClass; 
		}

		void SetMethod(Function pMethod)   
		{
			m_TheFunction = pMethod;
		}

	protected:

		void Fire_DisconnectCallback(Ogre::String addr, unsigned long port)
		{
			if(m_TheClass && m_TheFunction) 
			{ 
				(m_TheClass->*m_TheFunction)(addr, port);
			}
		}

	private:
		Class*        m_TheClass;
		Function    m_TheFunction;
	};
}