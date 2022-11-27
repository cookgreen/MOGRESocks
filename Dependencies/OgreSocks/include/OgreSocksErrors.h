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


namespace OgreSocks
{
	namespace SocketErrors
	{
		struct WINSOCKERROR
		{
			Ogre::String strError;
			Ogre::String strDescription;
		};

		static WINSOCKERROR GetWINSOCKERROR(int err)
		{
			WINSOCKERROR sockErr;
			sockErr.strDescription = "(description not set)";
			sockErr.strError = "(error not set)";

			switch(err)
			{
			case 6://WSA_INVALID_HANDLE
				//Specified event object handle is invalid. 
				//An application attempts to use an event object, but the specified handle is not valid. 
				//Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
				sockErr.strError = "WSA_INVALID_HANDLE";
				sockErr.strDescription = "An application attempted to use an event object, but the specified handle is not valid.";
				break;
			case 8://WSA_NOT_ENOUGH_MEMORY
				//Insufficient memory available. 
				//An application used a Windows Sockets function that directly maps to a Windows function. 
				//The Windows function is indicating a lack of required memory resources. 
				//Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
				sockErr.strError = "WSA_NOT_ENOUGH_MEMORY";
				sockErr.strDescription = "An application used a Windows Sockets function that has insufficient memory resources.";
				break; 
			case 87://WSA_INVALID_PARAMETER
				//One or more parameters are invalid. 
				//An application used a Windows Sockets function which directly maps to a Windows function. 
				//The Windows function is indicating a problem with one or more parameters. 
				//Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
				sockErr.strError = "WSA_INVALID_PARAMETER";
				sockErr.strDescription = "An application used a Windows Sockets function that indicates a problem with one or more parameters.";
				break;
			case 995://WSA_OPERATION_ABORTED
				//Overlapped operation aborted. 
				//An overlapped operation was canceled due to the closure of the socket, or the execution of the SIO_FLUSH command in WSAIoctl. 
				//Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
				sockErr.strError = "WSA_OPERATION_ABORTED";
				sockErr.strDescription = "An overlapped operation was canceled due to the closure of the socket, or the execution of the SIO_FLUSH command in WSAIoctl.";
				break;
			case 996://WSA_IO_INCOMPLETE
				//Overlapped I/O event object not in signaled state. 
				//The application has tried to determine the status of an overlapped operation which is not yet completed. 
				//Applications that use WSAGetOverlappedResult (with the fWait flag set to FALSE) in a polling mode to determine when an overlapped operation has completed, get this error code until the operation is complete. 
				//Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
				sockErr.strError = "WSA_IO_INCOMPLETE";
				sockErr.strDescription = "The application has tried to determine the status of an overlapped operation which is not yet completed.";			
				break;
			case 997://WSA_IO_PENDING
				//Overlapped operations will complete later.
				//The application has initiated an overlapped operation that cannot be completed immediately. 
				//A completion indication will be given later when the operation has been completed. 
				//Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
				sockErr.strError = "WSA_IO_PENDING";
				sockErr.strDescription = "The application has initiated an overlapped operation that cannot be completed immediately.";			
				break;
			case 10004://WSAEINTR
				//Interrupted function call.
				//A blocking operation was interrupted by a call to WSACancelBlockingCall.
				sockErr.strError = "WSAEINTR";
				sockErr.strDescription = "A blocking operation was interrupted by a call to WSACancelBlockingCall.";			
				break;
			case 10009://WSAEBADF
				//File handle is not valid. 
				//The file handle supplied is not valid.
				sockErr.strError = "WSAEBADF";
				sockErr.strDescription = "The file handle supplied is not valid.";			
				break; 
			case 10013://WSAEACCES
				//Permission denied.
				//An attempt was made to access a socket in a way forbidden by its access permissions. 
				//An example is using a broadcast address for sendto without broadcast permission being set using setsockopt(SO_BROADCAST). 
				//Another possible reason for the WSAEACCES error is that when the bind function is called (on Windows NT 4 SP4 or later), 
				//	another application, service, or kernel mode driver is bound to the same address with exclusive access. 
				//Such exclusive access is a new feature of Windows NT 4 SP4 and later, and is implemented by using the SO_EXCLUSIVEADDRUSE option.
				sockErr.strError = "WSAEACCES";
				sockErr.strDescription = "Permission denied. An attempt was made to access a socket in a way forbidden by its access permissions.";			
				break;  
			case 10014://WSAEFAULT
				//Bad address.
				//The system detected an invalid pointer address in attempting to use a pointer argument of a call. 
				//This error occurs if an application passes an invalid pointer value, or if the length of the buffer is too small. 
				//For instance, if the length of an argument, which is a sockaddr structure, is smaller than the sizeof(sockaddr).
				sockErr.strError = "WSAEFAULT";
				sockErr.strDescription = "Bad address. The system detected an invalid pointer address in attempting to use a pointer argument of a call.";			
				break;   
			case 10022://WSAEINVAL
				//Invalid argument.
				//An invalid argument was supplied to a function (for example, specifying an invalid level to the setsockopt function). 
				//In some instances, it also refers to the current state of the socket—for instance, calling accept on a socket that is not listening.
				sockErr.strError = "WSAEINVAL";
				sockErr.strDescription = "An invalid argument was supplied to a function.";			
				break; 
			case 10024://WSAEMFILE
				//Too many open files, or too many open sockets. 
				//Each implementation may have a maximum number of socket handles available, either globally, per process, or per thread.
				sockErr.strError = "WSAEMFILE";
				sockErr.strDescription = "Too many open sockets.";			
				break; 
			case 10035://WSAEWOULDBLOCK
				//Resource temporarily unavailable.
				//This error is returned from operations on nonblocking sockets that cannot be completed immediately, 
				//	for example recv when no data is queued to be read from the socket. 
				//It is a nonfatal error, and the operation should be retried later. 
				//It is normal for WSAEWOULDBLOCK to be reported as the result from calling connect on a nonblocking SOCK_STREAM socket, 
				//	since some time must elapse for the connection to be established.
				sockErr.strError = "WSAEWOULDBLOCK";
				sockErr.strDescription = "An operation on a nonblocking socket cannot be completed immediately.";			
				break;  
			case 10036://WSAEINPROGRESS
				//Operation now in progress.
				//A blocking operation is currently executing. 
				//Windows Sockets only allows a single blocking operation —per task or thread— to be outstanding, 
				//	and if any other function call is made (whether or not it references that or any other socket) 
				//	the function fails with the WSAEINPROGRESS error.
				sockErr.strError = "WSAEINPROGRESS";
				sockErr.strDescription = "A blocking operation is currently executing, and another function call has been made.";			
				break;  
			case 10037://WSAEALREADY
				//Operation already in progress.
				//An operation was attempted on a nonblocking socket with an operation already in progress — that is, calling connect a second time on a nonblocking socket that is already connecting, or canceling an asynchronous request (WSAAsyncGetXbyY) that has already been canceled or completed.
				sockErr.strError = "WSAEALREADY";
				sockErr.strDescription = "Operation already in progress. An operation was attempted on a nonblocking socket with an operation already in progress; for example calling connect a second time on a nonblocking socket that is already connecting, or canceling an asynchronous request that has already been canceled or completed.";			
				break; 
			case 10038://WSAENOTSOCK
				//Socket operation on nonsocket.
				//An operation was attempted on something that is not a socket. 
				//Either the socket handle parameter did not reference a valid socket, or for select, a member of an fd_set was not valid.
				sockErr.strError = "WSAENOTSOCK";
				sockErr.strDescription = "An operation was attempted on something that is not a socket. Probably the socket handle parameter did not reference a valid socket.";			
				break;
			case 10039://WSAEDESTADDRREQ
				//Destination address required.
				//A required address was omitted from an operation on a socket. 
				//For example, this error is returned if sendto is called with the remote address of ADDR_ANY.
				sockErr.strError = "WSAEDESTADDRREQ";
				sockErr.strDescription = "A required address was omitted from an operation on a socket; for example, if sendto is called with the remote address of ADDR_ANY.";			
				break; 
			case 10040://WSAEMSGSIZE
				//Message too unsigned long.
				//A message sent on a datagram socket was larger than the internal message buffer or some other network limit, 
				//	or the buffer used to receive a datagram was smaller than the datagram itself.
				sockErr.strError = "WSAEMSGSIZE";
				sockErr.strDescription = "A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram was smaller than the datagram itself.";			
				break; 
			case 10041://WSAEPROTOTYPE
				//Protocol wrong type for socket. 
				//A protocol was specified in the socket function call that does not support the semantics of the socket type requested. 
				//For example, the ARPA Internet UDP protocol cannot be specified with a socket type of SOCK_STREAM.
				sockErr.strError = "WSAEPROTOTYPE";
				sockErr.strDescription = "A protocol was specified in the socket function call that does not support the semantics of the socket type requested. For example, the ARPA Internet UDP protocol cannot be specified with a socket type of SOCK_STREAM.";			
				break; 
			case 10042://WSAENOPROTOOPT
				//Bad protocol option.
				//An unknown, invalid or unsupported option or level was specified in a getsockopt or setsockopt call.
				sockErr.strError = "WSAENOPROTOOPT";
				sockErr.strDescription = "Bad protocol option - an unknown, invalid or unsupported option or level was specified in a getsockopt or setsockopt call.";			
				break;   
			case 10043://WSAEPROTONOSUPPORT
				//Protocol not supported. 
				//The requested protocol has not been configured into the system, or no implementation for it exists. 
				//For example, a socket call requests a SOCK_DGRAM socket, but specifies a stream protocol.
				sockErr.strError = "WSAEPROTONOSUPPORT";
				sockErr.strDescription = "Protocol not supported - the requested protocol has not been configured into the system, or no implementation for it exists. For example, a socket call has requested a SOCK_DGRAM socket, but has specified a stream protocol.";			
				break; 
			case 10044://WSAESOCKTNOSUPPORT
				//Socket type not supported. 
				//The support for the specified socket type does not exist in this address family. 
				//For example, the optional type SOCK_RAW might be selected in a socket call, and the implementation does not support SOCK_RAW sockets at all.
				sockErr.strError = "WSAESOCKTNOSUPPORT";
				sockErr.strDescription = "Socket type not supported - the support for the specified socket type does not exist in this address family. For example, the optional type SOCK_RAW might be selected in a socket call, and the implementation does not support SOCK_RAW sockets at all.";			
				break;
			case 10045://WSAEOPNOTSUPP
				//Operation not supported.
				//The attempted operation is not supported for the type of object referenced. 
				//Usually this occurs when a socket descriptor to a socket that cannot support this operation is trying to accept a connection on a datagram socket.
				sockErr.strError = "WSAEOPNOTSUPP";
				sockErr.strDescription = "Operation not supported - the attempted operation is not supported for the type of object referenced. Usually this occurs when a socket descriptor to a socket that cannot support this operation is trying to accept a connection on a datagram socket.";			
				break; 
			case 10046://WSAEPFNOSUPPORT
				//Protocol family not supported.
				//The protocol family has not been configured into the system or no implementation for it exists. 
				//This message has a slightly different meaning from WSAEAFNOSUPPORT. 
				//However, it is interchangeable in most cases, and all Windows Sockets functions that return one of these messages also specify WSAEAFNOSUPPORT.
				sockErr.strError = "WSAEPFNOSUPPORT";
				sockErr.strDescription = "Protocol family not supported - the protocol family has not been configured into the system or no implementation for it exists.";			
				break;
			case 10047://WSAEAFNOSUPPORT
				//Address family not supported by protocol family. 
				//An address incompatible with the requested protocol was used. 
				//All sockets are created with an associated address family (that is, AF_INET for Internet Protocols) and a generic protocol type (that is, SOCK_STREAM). 
				//This error is returned if an incorrect protocol is explicitly requested in the socket call, 
				//	or if an address of the wrong family is used for a socket, for example, in sendto.
				sockErr.strError = "WSAEAFNOSUPPORT";
				sockErr.strDescription = "Address family (eg AF_INET for Internet Protocols) not supported by protocol family (eg SOCK_STREAM for TCP/IP). For example, a SOCK_STREAM has been used with sendto.";			
				break; 
			case 10048://WSAEADDRINUSE
				//Address already in use. 
				//Typically, only one usage of each socket address (protocol/IP address/port) is permitted. 
				//This error occurs if an application attempts to bind a socket to an IP address/port that has already been used for an existing socket, 
				//	or a socket that was not closed properly, or one that is still in the process of closing. 
				//For server applications that need to bind multiple sockets to the same port number, consider using setsockopt (SO_REUSEADDR). 
				//Client applications usually need not call bind at all— connect chooses an unused port automatically. 
				//When bind is called with a wildcard address (involving ADDR_ANY), a WSAEADDRINUSE error could be delayed until the specific address is committed. 
				//This could happen with a call to another function later, including connect, listen, WSAConnect, or WSAJoinLeaf.
				sockErr.strError = "WSAEADDRINUSE";
				sockErr.strDescription = "Address already in use. The application has attempted to bind a socket to an IP address/port that has already been used for an existing socket, or a socket that was not closed properly, or one that is still in the process of closing.";			
				break;
			case 10049://WSAEADDRNOTAVAIL
				//Cannot assign requested address.
				//The requested address is not valid in its context.
				//This normally results from an attempt to bind to an address that is not valid for the local computer.
				//This can also result from connect, sendto, WSAConnect, WSAJoinLeaf, or WSASendTo when the remote address or port 
				//	is not valid for a remote computer (for example, address or port 0).
				sockErr.strError = "WSAEADDRNOTAVAIL";
				sockErr.strDescription = "Cannot assign requested address. The requested address (either local or remote) is not valid in its context (either address or port).";			
				break;  
			case 10050://WSAENETDOWN
				//Network is down.
				//A socket operation encountered a dead network. 
				//This could indicate a serious failure of the network system (that is, the protocol stack that the Windows Sockets DLL 
				//	runs over), the network interface, or the local network itself.
				sockErr.strError = "WSAENETDOWN";
				sockErr.strDescription = "Network is down. This could indicate a serious failure of the network system (that is, the protocol stack that the Windows Sockets DLL runs over), the network interface, or the local network itself.";			
				break; 
			case 10051://WSAENETUNREACH
				//Network is unreachable.
				//A socket operation was attempted to an unreachable network. 
				//This usually means the local software knows no route to reach the remote host.
				sockErr.strError = "WSAENETUNREACH";
				sockErr.strDescription = "A socket operation attempted to an unreachable network. This usually means the local software knows no route to reach the remote host.";			
				break;   
			case 10052://WSAENETRESET
				//Network dropped connection on reset.
				//The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. 
				//It can also be returned by setsockopt if an attempt is made to set SO_KEEPALIVE on a connection that has already failed.
				sockErr.strError = "WSAENETRESET";
				sockErr.strDescription = "The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. It can also be returned by setsockopt if an attempt is made to set SO_KEEPALIVE on a connection that has already failed.";			
				break; 
			case 10053://WSAECONNABORTED
				//Software caused connection abort. 
				//An established connection was aborted by the software in your host computer, possibly due to a data transmission time-out or protocol error.
				sockErr.strError = "WSAECONNABORTED";
				sockErr.strDescription = "An established connection was aborted by the software in your host computer, possibly due to a data transmission time-out or protocol error.";			
				break; 
			case 10054://WSAECONNRESET
				//Connection reset by peer. 
				//An existing connection was forcibly closed by the remote host. 
				//This normally results if the peer application on the remote host is suddenly stopped, the host is rebooted, 
				//	the host or remote network interface is disabled, or the remote host uses a hard close (see setsockopt for more information on the SO_LINGER option on the remote socket). 
				//This error may also result if a connection was broken due to keep-alive activity detecting a failure while one or more operations are in progress. 
				//Operations that were in progress fail with WSAENETRESET. Subsequent operations fail with WSAECONNRESET.
				sockErr.strError = "WSAECONNRESET";
				sockErr.strDescription = "Connection reset by peer - an existing connection was forcibly closed by the remote host. This normally results if the peer application on the remote host is suddenly stopped, the host is rebooted, the host or remote network interface is disabled, or the remote host uses a hard close. This error may also result if a connection was broken due to keep-alive activity detecting a failure while one or more operations are in progress. Operations that were in progress fail with WSAENETRESET. Subsequent operations fail with WSAECONNRESET.";			
				break; 
			case 10055://WSAENOBUFS
				//No buffer space available.
				//An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.
				sockErr.strError = "WSAENOBUFS";
				sockErr.strDescription = "No buffer space available. An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.";			
				break; 
			case 10056://WSAEISCONN
				//Socket is already connected. 
				//A connect request was made on an already-connected socket. 
				//Some implementations also return this error if sendto is called on a connected SOCK_DGRAM socket (for SOCK_STREAM sockets, 
				//	the to parameter in sendto is ignored) although other implementations treat this as a legal occurrence.
				sockErr.strError = "WSAEISCONN";
				sockErr.strDescription = "A connect request was made on an already-connected socket.";			
				break; 
			case 10057://WSAENOTCONN
				//Socket is not connected. 
				//A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram 
				//	socket using sendto) no address was supplied. 
				//Any other type of operation might also return this error—for example, setsockopt setting SO_KEEPALIVE if the connection has been reset.
				sockErr.strError = "WSAENOTCONN";
				sockErr.strDescription = "A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using sendto) no address was supplied.";			
				break;  
			case 10058://WSAESHUTDOWN
				//Cannot send after socket shutdown.
				//A request to send or receive data was disallowed because the socket had already been shut down in that direction 
				//	with a previous shutdown call. 
				//By calling shutdown a partial close of a socket is requested, which is a signal that sending or receiving, 
				//	or both have been discontinued.
				sockErr.strError = "WSAESHUTDOWN";
				sockErr.strDescription = "A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call. By calling shutdown a partial close of a socket is requested, which is a signal that sending or receiving, or both have been discontinued.";			
				break;    
			case 10059://WSAETOOMANYREFS
				//Too many references.
				//Too many references to some kernel object.
				sockErr.strError = "WSAETOOMANYREFS";
				sockErr.strDescription = "Too many references to some kernel object.";			
				break; 
			case 10060://WSAETIMEDOUT 
				//Connection timed out. 
				//A connection attempt failed because the connected party did not properly respond after a period of time, 
				//	or the established connection failed because the connected host has failed to respond.
				sockErr.strError = "WSAETIMEDOUT";
				sockErr.strDescription = "A connection attempt failed because the connected party did not properly respond after a period of time, or the established connection failed because the connected host has failed to respond.";			
				break; 
			case 10061://WSAECONNREFUSED
				//Connection refused.
				//No connection could be made because the target computer actively refused it. 
				//This usually results from trying to connect to a service that is inactive on the foreign host—that is, 
				//	one with no server application running.
				sockErr.strError = "WSAECONNREFUSED";
				sockErr.strDescription = "No connection could be made because the target computer actively refused it. This usually results from trying to connect to a service that is inactive on the foreign host—that is, one with no server application running.";			
				break;  
			case 10062://WSAELOOP
				//Cannot translate name.
				//Cannot translate a name.
				sockErr.strError = "WSAELOOP";
				sockErr.strDescription = "Cannot translate a name.";			
				break;   
			case 10063://WSAENAMETOOLONG
				//Name too unsigned long.
				//A name component or a name was too unsigned long.
				sockErr.strError = "WSAENAMETOOLONG";
				sockErr.strDescription = "A name component or a name was too unsigned long.";			
				break;
			case 10064://WSAEHOSTDOWN
				//Host is down.
				//A socket operation failed because the destination host is down. 
				//A socket operation encountered a dead host. Networking activity on the local host has not been initiated. 
				//These conditions are more likely to be indicated by the error WSAETIMEDOUT.
				sockErr.strError = "WSAEHOSTDOWN";
				sockErr.strDescription = "A socket operation failed because the destination host is down. A socket operation encountered a dead host. Networking activity on the local host has not been initiated. ";			
				break;
			case 10065://WSAEHOSTUNREACH
				//No route to host. 
				//A socket operation was attempted to an unreachable host. See WSAENETUNREACH.
				sockErr.strError = "WSAEHOSTUNREACH";
				sockErr.strDescription = "No route to host - a socket operation was attempted to an unreachable host.";			
				break;
			case 10066://WSAENOTEMPTY
				//Directory not empty. 
				//Cannot remove a directory that is not empty.
				sockErr.strError = "WSAENOTEMPTY";
				sockErr.strDescription = "Directory not empty - cannot remove a directory that is not empty.";			
				break;  
			case 10067://WSAEPROCLIM
				//Too many processes.  
				//A Windows Sockets implementation may have a limit on the number of applications that can use it simultaneously.
				//WSAStartup may fail with this error if the limit has been reached.
				sockErr.strError = "WSAEPROCLIM";
				sockErr.strDescription = "Too many processes.  Windows Sockets has reached its limit on the number of applications that can use it simultaneously.";			
				break; 
			case 10068://WSAEUSERS
				//User quota exceeded. 
				//Ran out of user quota.
				sockErr.strError = "WSAEUSERS";
				sockErr.strDescription = "User quota exceeded.";			
				break; 
			case 10069://WSAEDQUOT
				//Disk quota exceeded.
				//Ran out of disk quota.
				sockErr.strError = "WSAEDQUOT";
				sockErr.strDescription = "Disk quota exceeded.";			
				break;    
			case 10070://WSAESTALE
				//Stale file handle reference. 
				//The file handle reference is no longer available.
				sockErr.strError = "WSAESTALE";
				sockErr.strDescription = "The file handle reference is no longer available (it has gone 'stale').";			
				break;  
			case 10071://WSAEREMOTE
				//Item is remote. 
				//The item is not available locally.
				sockErr.strError = "WSAEREMOTE";
				sockErr.strDescription = "Item is remote (not available locally).";			
				break;   
			case 10091://WSASYSNOTREADY
				//Network subsystem is unavailable. 
				//This error is returned by WSAStartup if the Windows Sockets implementation cannot function at this time because 
				//	the underlying system it uses to provide network services is currently unavailable. Users should check:
				//
				//That the appropriate Windows Sockets DLL file is in the current path. 
				//That they are not trying to use more than one Windows Sockets implementation simultaneously. If there is more than 
				//	one Winsock DLL on your system, be sure the first one in the path is appropriate for the network subsystem currently loaded. 
				//The Windows Sockets implementation documentation to be sure all necessary components are currently installed and configured correctly. 
				sockErr.strError = "WSASYSNOTREADY";
				sockErr.strDescription = "Network subsystem is unavailable. This error is returned by WSAStartup if Windows Sockets cannot function at this time because the underlying system it uses to provide network services is currently unavailable. Ensure: (1) That the appropriate Windows Sockets DLL file is in the current path. (2) That you are not trying to use more than one Windows Sockets implementation simultaneously. If there is more than one Winsock DLL on your system, be sure the first one in the path is appropriate for the network subsystem currently loaded. (3) You have read the Windows Sockets implementation documentation to be sure all necessary components are currently installed and configured correctly.";			
				break;  
			case 10092://WSAVERNOTSUPPORTED
				//Winsock.dll version out of range. 
				//The current Windows Sockets implementation does not support the Windows Sockets specification version requested by the application. 
				//Check that no old Windows Sockets DLL files are being accessed.
				sockErr.strError = "WSAVERNOTSUPPORTED";
				sockErr.strDescription = "Winsock.dll version out of range. The current Windows Sockets implementation does not support the Windows Sockets specification version requested by the application. Check that no old Windows Sockets DLL files are being accessed.";			
				break;  
			case 10093://WSANOTINITIALISED
				//Successful WSAStartup not yet performed.
				//Either the application has not called WSAStartup or WSAStartup failed. 
				//The application may be accessing a socket that the current active task does not own (that is, trying to share a 
				//	socket between tasks), or WSACleanup has been called too many times.
				sockErr.strError = "WSANOTINITIALISED";
				sockErr.strDescription = "Successful WSAStartup not yet performed (either the application has not called WSAStartup or WSAStartup failed). It is possible that the application is trying to access a socket that the current active task does not own (ie trying to share a socket between tasks), or WSACleanup has been called too many times.";			
				break;    
			case 10101://WSAEDISCON
				//Graceful shutdown in progress. 
				//Returned by WSARecv and WSARecvFrom to indicate that the remote party has initiated a graceful shutdown sequence.
				sockErr.strError = "WSAEDISCON";
				sockErr.strDescription = "Graceful shutdown in progress (returned by WSARecv and WSARecvFrom to indicate that the remote party has initiated a graceful shutdown sequence).";			
				break;     
			case 10102://WSAENOMORE
				//No more results.
				//No more results can be returned by the WSALookupServiceNext function.
				sockErr.strError = "WSAENOMORE";
				sockErr.strDescription = "No more results can be returned by the WSALookupServiceNext function.";			
				break;  
			case 10103://WSAECANCELLED
				//Call has been canceled. 
				//A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.
				sockErr.strError = "WSAECANCELLED";
				sockErr.strDescription = "A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.";			
				break;  
			case 10104://WSAEINVALIDPROCTABLE
				//Procedure call table is invalid. 
				//The service provider procedure call table is invalid. A service provider returned a bogus procedure table to Ws2_32.dll. 
				//This is usually caused by one or more of the function pointers being NULL.
				sockErr.strError = "WSAEINVALIDPROCTABLE";
				sockErr.strDescription = "The service provider procedure call table is invalid. A service provider returned a bogus procedure table to Ws2_32.dll. This is usually caused by one or more of the function pointers being NULL.";			
				break; 
			case 10105://WSAEINVALIDPROVIDER
				//Service provider is invalid. 
				//The requested service provider is invalid. This error is returned by the WSCGetProviderInfo and 
				//	WSCGetProviderInfo32 functions if the protocol entry specified could not be found. 
				//This error is also returned if the service provider returned a version number other than 2.0.
				sockErr.strError = "WSAEINVALIDPROVIDER";
				sockErr.strDescription = "The requested service provider is invalid. This error is returned by the WSCGetProviderInfo and WSCGetProviderInfo32 functions if the protocol entry specified could not be found. This error is also returned if the service provider returned a version number other than 2.0.";			
				break; 
			case 10106://WSAEPROVIDERFAILEDINIT
				//Service provider failed to initialize.
				//The requested service provider could not be loaded or initialized. 
				//This error is returned if either a service provider's DLL could not be loaded (LoadLibrary failed) 
				//	or the provider's WSPStartup or NSPStartup function failed.
				sockErr.strError = "WSAEPROVIDERFAILEDINIT";
				sockErr.strDescription = "The requested service provider could not be loaded or initialized. This error is returned if either a service provider's DLL could not be loaded (LoadLibrary failed) or the provider's WSPStartup or NSPStartup function failed.";			
				break;  
			case 10107://WSASYSCALLFAILURE
				//System call failure. 
				//A system call that should never fail has failed. This is a generic error code, returned under various conditions.
				//Returned when a system call that should never fail does fail. 
				//For example, if a call to WaitForMultipleEvents fails or one of the registry functions fails trying to 
				//	manipulate the protocol/namespace catalogs.
				//Returned when a provider does not return SUCCESS and does not provide an extended error code. 
				//Can indicate a service provider implementation error.
				sockErr.strError = "WSASYSCALLFAILURE";
				sockErr.strDescription = "A system call that should never fail has failed. This is a generic error code, returned under various conditions: Returned when a system call that should never fail does fail. For example, if a call to WaitForMultipleEvents fails or one of the registry functions fails trying to manipulate the protocol/namespace catalogs. Returned when a provider does not return SUCCESS and does not provide an extended error code. Can indicate a service provider implementation error.";		
				break; 
			case 10108://WSASERVICE_NOT_FOUND
				//Service not found. 
				//No such service is known. The service cannot be found in the specified name space.
				sockErr.strError = "WSASERVICE_NOT_FOUND";
				sockErr.strDescription = "No such service is known. The service cannot be found in the specified namespace.";		
				break;
			case 10109://WSATYPE_NOT_FOUND
				//Class type not found.
				//The specified class was not found.
				sockErr.strError = "WSATYPE_NOT_FOUND";
				sockErr.strDescription = "The specified class was not found.";		
				break;  
			case 10110://WSA_E_NO_MORE
				//No more results.
				//No more results can be returned by the WSALookupServiceNext function.
				sockErr.strError = "WSA_E_NO_MORE";
				sockErr.strDescription = "No more results can be returned by the WSALookupServiceNext function.";		
				break; 
			case 10111://WSA_E_CANCELLED
				//Call was canceled. 
				//A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.
				sockErr.strError = "WSA_E_CANCELLED";
				sockErr.strDescription = "A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.";		
				break;  
			case 10112://WSAEREFUSED
				//Database query was refused. 
				//A database query failed because it was actively refused.
				sockErr.strError = "WSAEREFUSED";
				sockErr.strDescription = "A database query failed because it was actively refused.";		
				break;   
			case 11001://WSAHOST_NOT_FOUND
				//Host not found. 
				//No such host is known. The name is not an official host name or alias, or it cannot be found in the database(s) 
				//	being queried. This error may also be returned for protocol and service queries, and means that the specified 
				//	name could not be found in the relevant database.
				sockErr.strError = "WSAHOST_NOT_FOUND";
				sockErr.strDescription = "Host not found. The name is not an official host name or alias, or it cannot be found in the database(s) being queried. This error may also be returned for protocol and service queries, and means that the specified name could not be found in the relevant database.";		
				break;
			case 11002://WSATRY_AGAIN
				//Nonauthoritative host not found. 
				//This is usually a temporary error during host name resolution and means that the local server did not receive a 
				//	response from an authoritative server. 
				//A retry at some time later may be successful.
				sockErr.strError = "WSATRY_AGAIN";
				sockErr.strDescription = "Nonauthoritative host not found. This is usually a temporary error during host name resolution and means that the local server did not receive a response from an authoritative server. A retry at some time later may be successful.";		
				break;
			case 11003://WSANO_RECOVERY
				//This is a nonrecoverable error. 
				//This indicates that some sort of nonrecoverable error occurred during a database lookup. 
				//This may be because the database files (for example, BSD-compatible HOSTS, SERVICES, or PROTOCOLS files) 
				//	could not be found, or a DNS request was returned by the server with a severe error.
				sockErr.strError = "WSANO_RECOVERY";
				sockErr.strDescription = "A nonrecoverable error occurred during a database lookup. This may be because the database files (for example, BSD-compatible HOSTS, SERVICES, or PROTOCOLS files) could not be found, or a DNS request was returned by the server with a severe error.";		
				break; 
			case 11004://WSANO_DATA
				//Valid name, no data record of requested type. 
				//The requested name is valid and was found in the database, but it does not have the correct associated data being resolved for.
				//The usual example for this is a host name-to-address translation attempt (using gethostbyname or WSAAsyncGetHostByName)
				//	which uses the DNS (Domain Name Server). 
				//An MX record is returned but no A record—indicating the host itself exists, but is not directly reachable.
				sockErr.strError = "WSANO_DATA";
				sockErr.strDescription = "The requested name is valid and was found in the database, but it does not have the correct associated data being resolved for. The usual example for this is a host name-to-address translation attempt (using gethostbyname or WSAAsyncGetHostByName) which uses the DNS (Domain Name Server). ";		
				break; 
			case 11005://WSA_QOS_RECEIVERS
				//QOS receivers.
				//At least one QOS reserve has arrived.
				sockErr.strError = "WSA_QOS_RECEIVERS";
				sockErr.strDescription = "At least one QOS reserve has arrived.";		
				break;  
			case 11006://WSA_QOS_SENDERS
				//QOS senders. 
				//At least one QOS send path has arrived.
				sockErr.strError = "WSA_QOS_SENDERS";
				sockErr.strDescription = "At least one QOS send path has arrived.";		
				break;
			case 11007://WSA_QOS_NO_SENDERS
				//No QOS senders.
				//There are no QOS senders.
				sockErr.strError = "WSA_QOS_NO_SENDERS";
				sockErr.strDescription = "There are no QOS senders.";		
				break; 
			case 11008://WSA_QOS_NO_RECEIVERS
				//QOS no receivers. 
				//There are no QOS receivers.
				sockErr.strError = "WSA_QOS_NO_RECEIVERS";
				sockErr.strDescription = "There are no QOS receivers.";		
				break;  
			case 11009://WSA_QOS_REQUEST_CONFIRMED
				//QOS request confirmed. 
				//The QOS reserve request has been confirmed.
				sockErr.strError = "WSA_QOS_REQUEST_CONFIRMED";
				sockErr.strDescription = "The QOS reserve request has been confirmed.";		
				break; 
			case 11010://WSA_QOS_ADMISSION_FAILURE
				//QOS admission error. 
				//A QOS error occurred due to lack of resources.
				sockErr.strError = "WSA_QOS_ADMISSION_FAILURE";
				sockErr.strDescription = "A QOS error occurred due to lack of resources.";		
				break; 
			case 11011://WSA_QOS_POLICY_FAILURE
				//QOS policy failure.
				//The QOS request was rejected because the policy system couldn't allocate the requested resource within the existing policy. 
				sockErr.strError = "WSA_QOS_POLICY_FAILURE";
				sockErr.strDescription = "The QOS request was rejected because the policy system couldn't allocate the requested resource within the existing policy. ";		
				break; 
			case 11012://WSA_QOS_BAD_STYLE
				//QOS bad style.
				//An unknown or conflicting QOS style was encountered.
				sockErr.strError = "WSA_QOS_BAD_STYLE";
				sockErr.strDescription = "An unknown or conflicting QOS style was encountered.";		
				break;  
			case 11013://WSA_QOS_BAD_OBJECT
				//QOS bad object.
				//A problem was encountered with some part of the filterspec or the provider-specific buffer in general.
				sockErr.strError = "WSA_QOS_BAD_OBJECT";
				sockErr.strDescription = "A problem was encountered with some part of the filterspec or the provider-specific buffer in general.";		
				break; 
			case 11014://WSA_QOS_TRAFFIC_CTRL_ERROR
				//QOS traffic control error. 
				//An error with the underlying traffic control (TC) API as the generic QOS request was converted for local enforcement by the TC API. 
				//This could be due to an out of memory error or to an internal QOS provider error. 
				sockErr.strError = "WSA_QOS_TRAFFIC_CTRL_ERROR";
				sockErr.strDescription = "An error with the underlying traffic control (TC) API as the generic QOS request was converted for local enforcement by the TC API. This could be due to an out of memory error or to an internal QOS provider error. ";		
				break; 
			case 11015://WSA_QOS_GENERIC_ERROR
				//QOS generic error.
				//A general QOS error.
				sockErr.strError = "WSA_QOS_GENERIC_ERROR";
				sockErr.strDescription = "Generic QOS error.";		
				break; 
			case 11016://WSA_QOS_ESERVICETYPE
				//QOS service type error. 
				//An invalid or unrecognized service type was found in the QOS flowspec.
				sockErr.strError = "WSA_QOS_ESERVICETYPE";
				sockErr.strDescription = "An invalid or unrecognized service type was found in the QOS flowspec.";		
				break;  
			case 11017://WSA_QOS_EFLOWSPEC
				//QOS flowspec error. 
				//An invalid or inconsistent flowspec was found in the QOS structure.
				sockErr.strError = "WSA_QOS_EFLOWSPEC";
				sockErr.strDescription = "An invalid or inconsistent flowspec was found in the QOS structure.";		
				break;
			case 11018://WSA_QOS_EPROVSPECBUF
				//Invalid QOS provider buffer.
				//An invalid QOS provider-specific buffer.
				sockErr.strError = "WSA_QOS_EPROVSPECBUF";
				sockErr.strDescription = "An invalid QOS provider-specific buffer.";
				break;
			case 11019://WSA_QOS_EFILTERSTYLE
				//Invalid QOS filter style. 
				//An invalid QOS filter style was used.
				sockErr.strError = "WSA_QOS_EFILTERSTYLE";
				sockErr.strDescription = "An invalid QOS filter style was used.";
				break;   
			case 11020://WSA_QOS_EFILTERTYPE
				//Invalid QOS filter type.
				//An invalid QOS filter type was used.
				sockErr.strError = "WSA_QOS_EFILTERTYPE";
				sockErr.strDescription = "An invalid QOS filter type was used.";
				break;
			case 11021://WSA_QOS_EFILTERCOUNT
				//Incorrect QOS filter count. 
				//An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.
				sockErr.strError = "WSA_QOS_EFILTERCOUNT";
				sockErr.strDescription = "An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.";
				break; 
			case 11022://WSA_QOS_EOBJLENGTH
				//Invalid QOS object length. 
				//An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.
				sockErr.strError = "WSA_QOS_EOBJLENGTH";
				sockErr.strDescription = "An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.";
				break; 
			case 11023://WSA_QOS_EFLOWCOUNT
				//Incorrect QOS flow count.  
				//An incorrect number of flow descriptors was specified in the QOS structure.
				sockErr.strError = "WSA_QOS_EFLOWCOUNT";
				sockErr.strDescription = "An incorrect number of flow descriptors was specified in the QOS structure.";
				break;
			case 11024://WSA_QOS_EUNKOWNPSOBJ
				//Unrecognized QOS object. 
				//An unrecognized object was found in the QOS provider-specific buffer.
				sockErr.strError = "WSA_QOS_EUNKOWNPSOBJ";
				sockErr.strDescription = "An unrecognized object was found in the QOS provider-specific buffer.";
				break;
			case 11025://WSA_QOS_EPOLICYOBJ
				//Invalid QOS policy object. 
				//An invalid policy object was found in the QOS provider-specific buffer.
				sockErr.strError = "WSA_QOS_EPOLICYOBJ";
				sockErr.strDescription = "An invalid policy object was found in the QOS provider-specific buffer.";
				break; 
			case 11026://WSA_QOS_EFLOWDESC
				//Invalid QOS flow descriptor. 
				//An invalid QOS flow descriptor was found in the flow descriptor list.
				sockErr.strError = "WSA_QOS_EFLOWDESC";
				sockErr.strDescription = "An invalid QOS flow descriptor was found in the flow descriptor list.";
				break; 
			case 11027://WSA_QOS_EPSFLOWSPEC
				//Invalid QOS provider-specific flowspec. 
				//An invalid or inconsistent flowspec was found in the QOS provider-specific buffer.
				sockErr.strError = "WSA_QOS_EPSFLOWSPEC";
				sockErr.strDescription = "An invalid or inconsistent flowspec was found in the QOS provider-specific buffer.";
				break;    
			case 11028://WSA_QOS_EPSFILTERSPEC
				//Invalid QOS provider-specific filterspec. 
				//An invalid FILTERSPEC was found in the QOS provider-specific buffer.
				sockErr.strError = "WSA_QOS_EPSFILTERSPEC";
				sockErr.strDescription = "An invalid FILTERSPEC was found in the QOS provider-specific buffer.";
				break;  
			case 11029://WSA_QOS_ESDMODEOBJ
				//Invalid QOS shape discard mode object. 
				//An invalid shape discard mode object was found in the QOS provider-specific buffer.
				sockErr.strError = "WSA_QOS_ESDMODEOBJ";
				sockErr.strDescription = "An invalid shape discard mode object was found in the QOS provider-specific buffer.";
				break; 
			case 11030://WSA_QOS_ESHAPERATEOBJ
				//Invalid QOS shaping rate object. 
				//An invalid shaping rate object was found in the QOS provider-specific buffer.
				sockErr.strError = "WSA_QOS_ESHAPERATEOBJ";
				sockErr.strDescription = "An invalid shaping rate object was found in the QOS provider-specific buffer.";
				break;
			case 11031://WSA_QOS_RESERVED_PETYPE
				//Reserved policy QOS element type. 
				//A reserved policy element was found in the QOS provider-specific buffer.
				sockErr.strError = "WSA_QOS_RESERVED_PETYPE";
				sockErr.strDescription = "A reserved policy element was found in the QOS provider-specific buffer.";
				break; 
			default:
				sockErr.strError = "UNRECOGNIZED_WSA_ERROR";
				sockErr.strDescription = "The error returned from WSAGetLastError was not recognized as a valid WSA error";
				break;
			}//switch(err)

			return sockErr;
		}//end function
	}//end SocketErrors namespace
}