using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MogreSocks.SocketErrors
{
    public struct WINSOCKERROR
    {
        public string Error { get; set; }
        public string Description { get; set; }

        public static WINSOCKERROR GetWINSOCKERROR(int err)
        {
            WINSOCKERROR sockErr = new WINSOCKERROR();
            sockErr.Description = "(description not set)";
            sockErr.Error = "(error not set)";


            switch (err)
            {
                case 6://WSA_INVALID_HANDLE
                       //Specified event object handle is invalid. 
                       //An application attempts to use an event object, but the specified handle is not valid. 
                       //Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
                    sockErr.Error = "WSA_INVALID_HANDLE";
                    sockErr.Description = "An application attempted to use an event object, but the specified handle is not valid.";
                    break;
                case 8://WSA_NOT_ENOUGH_MEMORY
                       //Insufficient memory available. 
                       //An application used a Windows Sockets function that directly maps to a Windows function. 
                       //The Windows function is indicating a lack of required memory resources. 
                       //Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
                    sockErr.Error = "WSA_NOT_ENOUGH_MEMORY";
                    sockErr.Description = "An application used a Windows Sockets function that has insufficient memory resources.";
                    break;
                case 87://WSA_INVALID_PARAMETER
                        //One or more parameters are invalid. 
                        //An application used a Windows Sockets function which directly maps to a Windows function. 
                        //The Windows function is indicating a problem with one or more parameters. 
                        //Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
                    sockErr.Error = "WSA_INVALID_PARAMETER";
                    sockErr.Description = "An application used a Windows Sockets function that indicates a problem with one or more parameters.";
                    break;
                case 995://WSA_OPERATION_ABORTED
                         //Overlapped operation aborted. 
                         //An overlapped operation was canceled due to the closure of the socket, or the execution of the SIO_FLUSH command in WSAIoctl. 
                         //Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
                    sockErr.Error = "WSA_OPERATION_ABORTED";
                    sockErr.Description = "An overlapped operation was canceled due to the closure of the socket, or the execution of the SIO_FLUSH command in WSAIoctl.";
                    break;
                case 996://WSA_IO_INCOMPLETE
                         //Overlapped I/O event object not in signaled state. 
                         //The application has tried to determine the status of an overlapped operation which is not yet completed. 
                         //Applications that use WSAGetOverlappedResult (with the fWait flag set to FALSE) in a polling mode to determine when an overlapped operation has completed, get this error code until the operation is complete. 
                         //Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
                    sockErr.Error = "WSA_IO_INCOMPLETE";
                    sockErr.Description = "The application has tried to determine the status of an overlapped operation which is not yet completed.";
                    break;
                case 997://WSA_IO_PENDING
                         //Overlapped operations will complete later.
                         //The application has initiated an overlapped operation that cannot be completed immediately. 
                         //A completion indication will be given later when the operation has been completed. 
                         //Note that this error is returned by the operating system, so the error number may change in future releases of Windows.
                    sockErr.Error = "WSA_IO_PENDING";
                    sockErr.Description = "The application has initiated an overlapped operation that cannot be completed immediately.";
                    break;
                case 10004://WSAEINTR
                           //Interrupted function call.
                           //A blocking operation was interrupted by a call to WSACancelBlockingCall.
                    sockErr.Error = "WSAEINTR";
                    sockErr.Description = "A blocking operation was interrupted by a call to WSACancelBlockingCall.";
                    break;
                case 10009://WSAEBADF
                           //File handle is not valid. 
                           //The file handle supplied is not valid.
                    sockErr.Error = "WSAEBADF";
                    sockErr.Description = "The file handle supplied is not valid.";
                    break;
                case 10013://WSAEACCES
                           //Permission denied.
                           //An attempt was made to access a socket in a way forbidden by its access permissions. 
                           //An example is using a broadcast address for sendto without broadcast permission being set using setsockopt(SO_BROADCAST). 
                           //Another possible reason for the WSAEACCES error is that when the bind function is called (on Windows NT 4 SP4 or later), 
                           //	another application, service, or kernel mode driver is bound to the same address with exclusive access. 
                           //Such exclusive access is a new feature of Windows NT 4 SP4 and later, and is implemented by using the SO_EXCLUSIVEADDRUSE option.
                    sockErr.Error = "WSAEACCES";
                    sockErr.Description = "Permission denied. An attempt was made to access a socket in a way forbidden by its access permissions.";
                    break;
                case 10014://WSAEFAULT
                           //Bad address.
                           //The system detected an invalid pointer address in attempting to use a pointer argument of a call. 
                           //This error occurs if an application passes an invalid pointer value, or if the length of the buffer is too small. 
                           //For instance, if the length of an argument, which is a sockaddr structure, is smaller than the sizeof(sockaddr).
                    sockErr.Error = "WSAEFAULT";
                    sockErr.Description = "Bad address. The system detected an invalid pointer address in attempting to use a pointer argument of a call.";
                    break;
                case 10022://WSAEINVAL
                           //Invalid argument.
                           //An invalid argument was supplied to a function (for example, specifying an invalid level to the setsockopt function). 
                           //In some instances, it also refers to the current state of the socket梖or instance, calling accept on a socket that is not listening.
                    sockErr.Error = "WSAEINVAL";
                    sockErr.Description = "An invalid argument was supplied to a function.";
                    break;
                case 10024://WSAEMFILE
                           //Too many open files, or too many open sockets. 
                           //Each implementation may have a maximum number of socket handles available, either globally, per process, or per thread.
                    sockErr.Error = "WSAEMFILE";
                    sockErr.Description = "Too many open sockets.";
                    break;
                case 10035://WSAEWOULDBLOCK
                           //Resource temporarily unavailable.
                           //This error is returned from operations on nonblocking sockets that cannot be completed immediately, 
                           //	for example recv when no data is queued to be read from the socket. 
                           //It is a nonfatal error, and the operation should be retried later. 
                           //It is normal for WSAEWOULDBLOCK to be reported as the result from calling connect on a nonblocking SOCK_STREAM socket, 
                           //	since some time must elapse for the connection to be established.
                    sockErr.Error = "WSAEWOULDBLOCK";
                    sockErr.Description = "An operation on a nonblocking socket cannot be completed immediately.";
                    break;
                case 10036://WSAEINPROGRESS
                           //Operation now in progress.
                           //A blocking operation is currently executing. 
                           //Windows Sockets only allows a single blocking operation 梡er task or thread?to be outstanding, 
                           //	and if any other function call is made (whether or not it references that or any other socket) 
                           //	the function fails with the WSAEINPROGRESS error.
                    sockErr.Error = "WSAEINPROGRESS";
                    sockErr.Description = "A blocking operation is currently executing, and another function call has been made.";
                    break;
                case 10037://WSAEALREADY
                           //Operation already in progress.
                           //An operation was attempted on a nonblocking socket with an operation already in progress ?that is, calling connect a second time on a nonblocking socket that is already connecting, or canceling an asynchronous request (WSAAsyncGetXbyY) that has already been canceled or completed.
                    sockErr.Error = "WSAEALREADY";
                    sockErr.Description = "Operation already in progress. An operation was attempted on a nonblocking socket with an operation already in progress; for example calling connect a second time on a nonblocking socket that is already connecting, or canceling an asynchronous request that has already been canceled or completed.";
                    break;
                case 10038://WSAENOTSOCK
                           //Socket operation on nonsocket.
                           //An operation was attempted on something that is not a socket. 
                           //Either the socket handle parameter did not reference a valid socket, or for select, a member of an fd_set was not valid.
                    sockErr.Error = "WSAENOTSOCK";
                    sockErr.Description = "An operation was attempted on something that is not a socket. Probably the socket handle parameter did not reference a valid socket.";
                    break;
                case 10039://WSAEDESTADDRREQ
                           //Destination address required.
                           //A required address was omitted from an operation on a socket. 
                           //For example, this error is returned if sendto is called with the remote address of ADDR_ANY.
                    sockErr.Error = "WSAEDESTADDRREQ";
                    sockErr.Description = "A required address was omitted from an operation on a socket; for example, if sendto is called with the remote address of ADDR_ANY.";
                    break;
                case 10040://WSAEMSGSIZE
                           //Message too unsigned long.
                           //A message sent on a datagram socket was larger than the internal message buffer or some other network limit, 
                           //	or the buffer used to receive a datagram was smaller than the datagram itself.
                    sockErr.Error = "WSAEMSGSIZE";
                    sockErr.Description = "A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram was smaller than the datagram itself.";
                    break;
                case 10041://WSAEPROTOTYPE
                           //Protocol wrong type for socket. 
                           //A protocol was specified in the socket function call that does not support the semantics of the socket type requested. 
                           //For example, the ARPA Internet UDP protocol cannot be specified with a socket type of SOCK_STREAM.
                    sockErr.Error = "WSAEPROTOTYPE";
                    sockErr.Description = "A protocol was specified in the socket function call that does not support the semantics of the socket type requested. For example, the ARPA Internet UDP protocol cannot be specified with a socket type of SOCK_STREAM.";
                    break;
                case 10042://WSAENOPROTOOPT
                           //Bad protocol option.
                           //An unknown, invalid or unsupported option or level was specified in a getsockopt or setsockopt call.
                    sockErr.Error = "WSAENOPROTOOPT";
                    sockErr.Description = "Bad protocol option - an unknown, invalid or unsupported option or level was specified in a getsockopt or setsockopt call.";
                    break;
                case 10043://WSAEPROTONOSUPPORT
                           //Protocol not supported. 
                           //The requested protocol has not been configured into the system, or no implementation for it exists. 
                           //For example, a socket call requests a SOCK_DGRAM socket, but specifies a stream protocol.
                    sockErr.Error = "WSAEPROTONOSUPPORT";
                    sockErr.Description = "Protocol not supported - the requested protocol has not been configured into the system, or no implementation for it exists. For example, a socket call has requested a SOCK_DGRAM socket, but has specified a stream protocol.";
                    break;
                case 10044://WSAESOCKTNOSUPPORT
                           //Socket type not supported. 
                           //The support for the specified socket type does not exist in this address family. 
                           //For example, the optional type SOCK_RAW might be selected in a socket call, and the implementation does not support SOCK_RAW sockets at all.
                    sockErr.Error = "WSAESOCKTNOSUPPORT";
                    sockErr.Description = "Socket type not supported - the support for the specified socket type does not exist in this address family. For example, the optional type SOCK_RAW might be selected in a socket call, and the implementation does not support SOCK_RAW sockets at all.";
                    break;
                case 10045://WSAEOPNOTSUPP
                           //Operation not supported.
                           //The attempted operation is not supported for the type of object referenced. 
                           //Usually this occurs when a socket descriptor to a socket that cannot support this operation is trying to accept a connection on a datagram socket.
                    sockErr.Error = "WSAEOPNOTSUPP";
                    sockErr.Description = "Operation not supported - the attempted operation is not supported for the type of object referenced. Usually this occurs when a socket descriptor to a socket that cannot support this operation is trying to accept a connection on a datagram socket.";
                    break;
                case 10046://WSAEPFNOSUPPORT
                           //Protocol family not supported.
                           //The protocol family has not been configured into the system or no implementation for it exists. 
                           //This message has a slightly different meaning from WSAEAFNOSUPPORT. 
                           //However, it is interchangeable in most cases, and all Windows Sockets functions that return one of these messages also specify WSAEAFNOSUPPORT.
                    sockErr.Error = "WSAEPFNOSUPPORT";
                    sockErr.Description = "Protocol family not supported - the protocol family has not been configured into the system or no implementation for it exists.";
                    break;
                case 10047://WSAEAFNOSUPPORT
                           //Address family not supported by protocol family. 
                           //An address incompatible with the requested protocol was used. 
                           //All sockets are created with an associated address family (that is, AF_INET for Internet Protocols) and a generic protocol type (that is, SOCK_STREAM). 
                           //This error is returned if an incorrect protocol is explicitly requested in the socket call, 
                           //	or if an address of the wrong family is used for a socket, for example, in sendto.
                    sockErr.Error = "WSAEAFNOSUPPORT";
                    sockErr.Description = "Address family (eg AF_INET for Internet Protocols) not supported by protocol family (eg SOCK_STREAM for TCP/IP). For example, a SOCK_STREAM has been used with sendto.";
                    break;
                case 10048://WSAEADDRINUSE
                           //Address already in use. 
                           //Typically, only one usage of each socket address (protocol/IP address/port) is permitted. 
                           //This error occurs if an application attempts to bind a socket to an IP address/port that has already been used for an existing socket, 
                           //	or a socket that was not closed properly, or one that is still in the process of closing. 
                           //For server applications that need to bind multiple sockets to the same port number, consider using setsockopt (SO_REUSEADDR). 
                           //Client applications usually need not call bind at all?connect chooses an unused port automatically. 
                           //When bind is called with a wildcard address (involving ADDR_ANY), a WSAEADDRINUSE error could be delayed until the specific address is committed. 
                           //This could happen with a call to another function later, including connect, listen, WSAConnect, or WSAJoinLeaf.
                    sockErr.Error = "WSAEADDRINUSE";
                    sockErr.Description = "Address already in use. The application has attempted to bind a socket to an IP address/port that has already been used for an existing socket, or a socket that was not closed properly, or one that is still in the process of closing.";
                    break;
                case 10049://WSAEADDRNOTAVAIL
                           //Cannot assign requested address.
                           //The requested address is not valid in its context.
                           //This normally results from an attempt to bind to an address that is not valid for the local computer.
                           //This can also result from connect, sendto, WSAConnect, WSAJoinLeaf, or WSASendTo when the remote address or port 
                           //	is not valid for a remote computer (for example, address or port 0).
                    sockErr.Error = "WSAEADDRNOTAVAIL";
                    sockErr.Description = "Cannot assign requested address. The requested address (either local or remote) is not valid in its context (either address or port).";
                    break;
                case 10050://WSAENETDOWN
                           //Network is down.
                           //A socket operation encountered a dead network. 
                           //This could indicate a serious failure of the network system (that is, the protocol stack that the Windows Sockets DLL 
                           //	runs over), the network interface, or the local network itself.
                    sockErr.Error = "WSAENETDOWN";
                    sockErr.Description = "Network is down. This could indicate a serious failure of the network system (that is, the protocol stack that the Windows Sockets DLL runs over), the network interface, or the local network itself.";
                    break;
                case 10051://WSAENETUNREACH
                           //Network is unreachable.
                           //A socket operation was attempted to an unreachable network. 
                           //This usually means the local software knows no route to reach the remote host.
                    sockErr.Error = "WSAENETUNREACH";
                    sockErr.Description = "A socket operation attempted to an unreachable network. This usually means the local software knows no route to reach the remote host.";
                    break;
                case 10052://WSAENETRESET
                           //Network dropped connection on reset.
                           //The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. 
                           //It can also be returned by setsockopt if an attempt is made to set SO_KEEPALIVE on a connection that has already failed.
                    sockErr.Error = "WSAENETRESET";
                    sockErr.Description = "The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. It can also be returned by setsockopt if an attempt is made to set SO_KEEPALIVE on a connection that has already failed.";
                    break;
                case 10053://WSAECONNABORTED
                           //Software caused connection abort. 
                           //An established connection was aborted by the software in your host computer, possibly due to a data transmission time-out or protocol error.
                    sockErr.Error = "WSAECONNABORTED";
                    sockErr.Description = "An established connection was aborted by the software in your host computer, possibly due to a data transmission time-out or protocol error.";
                    break;
                case 10054://WSAECONNRESET
                           //Connection reset by peer. 
                           //An existing connection was forcibly closed by the remote host. 
                           //This normally results if the peer application on the remote host is suddenly stopped, the host is rebooted, 
                           //	the host or remote network interface is disabled, or the remote host uses a hard close (see setsockopt for more information on the SO_LINGER option on the remote socket). 
                           //This error may also result if a connection was broken due to keep-alive activity detecting a failure while one or more operations are in progress. 
                           //Operations that were in progress fail with WSAENETRESET. Subsequent operations fail with WSAECONNRESET.
                    sockErr.Error = "WSAECONNRESET";
                    sockErr.Description = "Connection reset by peer - an existing connection was forcibly closed by the remote host. This normally results if the peer application on the remote host is suddenly stopped, the host is rebooted, the host or remote network interface is disabled, or the remote host uses a hard close. This error may also result if a connection was broken due to keep-alive activity detecting a failure while one or more operations are in progress. Operations that were in progress fail with WSAENETRESET. Subsequent operations fail with WSAECONNRESET.";
                    break;
                case 10055://WSAENOBUFS
                           //No buffer space available.
                           //An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.
                    sockErr.Error = "WSAENOBUFS";
                    sockErr.Description = "No buffer space available. An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.";
                    break;
                case 10056://WSAEISCONN
                           //Socket is already connected. 
                           //A connect request was made on an already-connected socket. 
                           //Some implementations also return this error if sendto is called on a connected SOCK_DGRAM socket (for SOCK_STREAM sockets, 
                           //	the to parameter in sendto is ignored) although other implementations treat this as a legal occurrence.
                    sockErr.Error = "WSAEISCONN";
                    sockErr.Description = "A connect request was made on an already-connected socket.";
                    break;
                case 10057://WSAENOTCONN
                           //Socket is not connected. 
                           //A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram 
                           //	socket using sendto) no address was supplied. 
                           //Any other type of operation might also return this error梖or example, setsockopt setting SO_KEEPALIVE if the connection has been reset.
                    sockErr.Error = "WSAENOTCONN";
                    sockErr.Description = "A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using sendto) no address was supplied.";
                    break;
                case 10058://WSAESHUTDOWN
                           //Cannot send after socket shutdown.
                           //A request to send or receive data was disallowed because the socket had already been shut down in that direction 
                           //	with a previous shutdown call. 
                           //By calling shutdown a partial close of a socket is requested, which is a signal that sending or receiving, 
                           //	or both have been discontinued.
                    sockErr.Error = "WSAESHUTDOWN";
                    sockErr.Description = "A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call. By calling shutdown a partial close of a socket is requested, which is a signal that sending or receiving, or both have been discontinued.";
                    break;
                case 10059://WSAETOOMANYREFS
                           //Too many references.
                           //Too many references to some kernel object.
                    sockErr.Error = "WSAETOOMANYREFS";
                    sockErr.Description = "Too many references to some kernel object.";
                    break;
                case 10060://WSAETIMEDOUT 
                           //Connection timed out. 
                           //A connection attempt failed because the connected party did not properly respond after a period of time, 
                           //	or the established connection failed because the connected host has failed to respond.
                    sockErr.Error = "WSAETIMEDOUT";
                    sockErr.Description = "A connection attempt failed because the connected party did not properly respond after a period of time, or the established connection failed because the connected host has failed to respond.";
                    break;
                case 10061://WSAECONNREFUSED
                           //Connection refused.
                           //No connection could be made because the target computer actively refused it. 
                           //This usually results from trying to connect to a service that is inactive on the foreign host梩hat is, 
                           //	one with no server application running.
                    sockErr.Error = "WSAECONNREFUSED";
                    sockErr.Description = "No connection could be made because the target computer actively refused it. This usually results from trying to connect to a service that is inactive on the foreign host梩hat is, one with no server application running.";
                    break;
                case 10062://WSAELOOP
                           //Cannot translate name.
                           //Cannot translate a name.
                    sockErr.Error = "WSAELOOP";
                    sockErr.Description = "Cannot translate a name.";
                    break;
                case 10063://WSAENAMETOOLONG
                           //Name too unsigned long.
                           //A name component or a name was too unsigned long.
                    sockErr.Error = "WSAENAMETOOLONG";
                    sockErr.Description = "A name component or a name was too unsigned long.";
                    break;
                case 10064://WSAEHOSTDOWN
                           //Host is down.
                           //A socket operation failed because the destination host is down. 
                           //A socket operation encountered a dead host. Networking activity on the local host has not been initiated. 
                           //These conditions are more likely to be indicated by the error WSAETIMEDOUT.
                    sockErr.Error = "WSAEHOSTDOWN";
                    sockErr.Description = "A socket operation failed because the destination host is down. A socket operation encountered a dead host. Networking activity on the local host has not been initiated. ";
                    break;
                case 10065://WSAEHOSTUNREACH
                           //No route to host. 
                           //A socket operation was attempted to an unreachable host. See WSAENETUNREACH.
                    sockErr.Error = "WSAEHOSTUNREACH";
                    sockErr.Description = "No route to host - a socket operation was attempted to an unreachable host.";
                    break;
                case 10066://WSAENOTEMPTY
                           //Directory not empty. 
                           //Cannot remove a directory that is not empty.
                    sockErr.Error = "WSAENOTEMPTY";
                    sockErr.Description = "Directory not empty - cannot remove a directory that is not empty.";
                    break;
                case 10067://WSAEPROCLIM
                           //Too many processes.  
                           //A Windows Sockets implementation may have a limit on the number of applications that can use it simultaneously.
                           //WSAStartup may fail with this error if the limit has been reached.
                    sockErr.Error = "WSAEPROCLIM";
                    sockErr.Description = "Too many processes.  Windows Sockets has reached its limit on the number of applications that can use it simultaneously.";
                    break;
                case 10068://WSAEUSERS
                           //User quota exceeded. 
                           //Ran out of user quota.
                    sockErr.Error = "WSAEUSERS";
                    sockErr.Description = "User quota exceeded.";
                    break;
                case 10069://WSAEDQUOT
                           //Disk quota exceeded.
                           //Ran out of disk quota.
                    sockErr.Error = "WSAEDQUOT";
                    sockErr.Description = "Disk quota exceeded.";
                    break;
                case 10070://WSAESTALE
                           //Stale file handle reference. 
                           //The file handle reference is no longer available.
                    sockErr.Error = "WSAESTALE";
                    sockErr.Description = "The file handle reference is no longer available (it has gone 'stale').";
                    break;
                case 10071://WSAEREMOTE
                           //Item is remote. 
                           //The item is not available locally.
                    sockErr.Error = "WSAEREMOTE";
                    sockErr.Description = "Item is remote (not available locally).";
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
                    sockErr.Error = "WSASYSNOTREADY";
                    sockErr.Description = "Network subsystem is unavailable. This error is returned by WSAStartup if Windows Sockets cannot function at this time because the underlying system it uses to provide network services is currently unavailable. Ensure: (1) That the appropriate Windows Sockets DLL file is in the current path. (2) That you are not trying to use more than one Windows Sockets implementation simultaneously. If there is more than one Winsock DLL on your system, be sure the first one in the path is appropriate for the network subsystem currently loaded. (3) You have read the Windows Sockets implementation documentation to be sure all necessary components are currently installed and configured correctly.";
                    break;
                case 10092://WSAVERNOTSUPPORTED
                           //Winsock.dll version out of range. 
                           //The current Windows Sockets implementation does not support the Windows Sockets specification version requested by the application. 
                           //Check that no old Windows Sockets DLL files are being accessed.
                    sockErr.Error = "WSAVERNOTSUPPORTED";
                    sockErr.Description = "Winsock.dll version out of range. The current Windows Sockets implementation does not support the Windows Sockets specification version requested by the application. Check that no old Windows Sockets DLL files are being accessed.";
                    break;
                case 10093://WSANOTINITIALISED
                           //Successful WSAStartup not yet performed.
                           //Either the application has not called WSAStartup or WSAStartup failed. 
                           //The application may be accessing a socket that the current active task does not own (that is, trying to share a 
                           //	socket between tasks), or WSACleanup has been called too many times.
                    sockErr.Error = "WSANOTINITIALISED";
                    sockErr.Description = "Successful WSAStartup not yet performed (either the application has not called WSAStartup or WSAStartup failed). It is possible that the application is trying to access a socket that the current active task does not own (ie trying to share a socket between tasks), or WSACleanup has been called too many times.";
                    break;
                case 10101://WSAEDISCON
                           //Graceful shutdown in progress. 
                           //Returned by WSARecv and WSARecvFrom to indicate that the remote party has initiated a graceful shutdown sequence.
                    sockErr.Error = "WSAEDISCON";
                    sockErr.Description = "Graceful shutdown in progress (returned by WSARecv and WSARecvFrom to indicate that the remote party has initiated a graceful shutdown sequence).";
                    break;
                case 10102://WSAENOMORE
                           //No more results.
                           //No more results can be returned by the WSALookupServiceNext function.
                    sockErr.Error = "WSAENOMORE";
                    sockErr.Description = "No more results can be returned by the WSALookupServiceNext function.";
                    break;
                case 10103://WSAECANCELLED
                           //Call has been canceled. 
                           //A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.
                    sockErr.Error = "WSAECANCELLED";
                    sockErr.Description = "A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.";
                    break;
                case 10104://WSAEINVALIDPROCTABLE
                           //Procedure call table is invalid. 
                           //The service provider procedure call table is invalid. A service provider returned a bogus procedure table to Ws2_32.dll. 
                           //This is usually caused by one or more of the function pointers being NULL.
                    sockErr.Error = "WSAEINVALIDPROCTABLE";
                    sockErr.Description = "The service provider procedure call table is invalid. A service provider returned a bogus procedure table to Ws2_32.dll. This is usually caused by one or more of the function pointers being NULL.";
                    break;
                case 10105://WSAEINVALIDPROVIDER
                           //Service provider is invalid. 
                           //The requested service provider is invalid. This error is returned by the WSCGetProviderInfo and 
                           //	WSCGetProviderInfo32 functions if the protocol entry specified could not be found. 
                           //This error is also returned if the service provider returned a version number other than 2.0.
                    sockErr.Error = "WSAEINVALIDPROVIDER";
                    sockErr.Description = "The requested service provider is invalid. This error is returned by the WSCGetProviderInfo and WSCGetProviderInfo32 functions if the protocol entry specified could not be found. This error is also returned if the service provider returned a version number other than 2.0.";
                    break;
                case 10106://WSAEPROVIDERFAILEDINIT
                           //Service provider failed to initialize.
                           //The requested service provider could not be loaded or initialized. 
                           //This error is returned if either a service provider's DLL could not be loaded (LoadLibrary failed) 
                           //	or the provider's WSPStartup or NSPStartup function failed.
                    sockErr.Error = "WSAEPROVIDERFAILEDINIT";
                    sockErr.Description = "The requested service provider could not be loaded or initialized. This error is returned if either a service provider's DLL could not be loaded (LoadLibrary failed) or the provider's WSPStartup or NSPStartup function failed.";
                    break;
                case 10107://WSASYSCALLFAILURE
                           //System call failure. 
                           //A system call that should never fail has failed. This is a generic error code, returned under various conditions.
                           //Returned when a system call that should never fail does fail. 
                           //For example, if a call to WaitForMultipleEvents fails or one of the registry functions fails trying to 
                           //	manipulate the protocol/namespace catalogs.
                           //Returned when a provider does not return SUCCESS and does not provide an extended error code. 
                           //Can indicate a service provider implementation error.
                    sockErr.Error = "WSASYSCALLFAILURE";
                    sockErr.Description = "A system call that should never fail has failed. This is a generic error code, returned under various conditions: Returned when a system call that should never fail does fail. For example, if a call to WaitForMultipleEvents fails or one of the registry functions fails trying to manipulate the protocol/namespace catalogs. Returned when a provider does not return SUCCESS and does not provide an extended error code. Can indicate a service provider implementation error.";
                    break;
                case 10108://WSASERVICE_NOT_FOUND
                           //Service not found. 
                           //No such service is known. The service cannot be found in the specified name space.
                    sockErr.Error = "WSASERVICE_NOT_FOUND";
                    sockErr.Description = "No such service is known. The service cannot be found in the specified namespace.";
                    break;
                case 10109://WSATYPE_NOT_FOUND
                           //Class type not found.
                           //The specified class was not found.
                    sockErr.Error = "WSATYPE_NOT_FOUND";
                    sockErr.Description = "The specified class was not found.";
                    break;
                case 10110://WSA_E_NO_MORE
                           //No more results.
                           //No more results can be returned by the WSALookupServiceNext function.
                    sockErr.Error = "WSA_E_NO_MORE";
                    sockErr.Description = "No more results can be returned by the WSALookupServiceNext function.";
                    break;
                case 10111://WSA_E_CANCELLED
                           //Call was canceled. 
                           //A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.
                    sockErr.Error = "WSA_E_CANCELLED";
                    sockErr.Description = "A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.";
                    break;
                case 10112://WSAEREFUSED
                           //Database query was refused. 
                           //A database query failed because it was actively refused.
                    sockErr.Error = "WSAEREFUSED";
                    sockErr.Description = "A database query failed because it was actively refused.";
                    break;
                case 11001://WSAHOST_NOT_FOUND
                           //Host not found. 
                           //No such host is known. The name is not an official host name or alias, or it cannot be found in the database(s) 
                           //	being queried. This error may also be returned for protocol and service queries, and means that the specified 
                           //	name could not be found in the relevant database.
                    sockErr.Error = "WSAHOST_NOT_FOUND";
                    sockErr.Description = "Host not found. The name is not an official host name or alias, or it cannot be found in the database(s) being queried. This error may also be returned for protocol and service queries, and means that the specified name could not be found in the relevant database.";
                    break;
                case 11002://WSATRY_AGAIN
                           //Nonauthoritative host not found. 
                           //This is usually a temporary error during host name resolution and means that the local server did not receive a 
                           //	response from an authoritative server. 
                           //A retry at some time later may be successful.
                    sockErr.Error = "WSATRY_AGAIN";
                    sockErr.Description = "Nonauthoritative host not found. This is usually a temporary error during host name resolution and means that the local server did not receive a response from an authoritative server. A retry at some time later may be successful.";
                    break;
                case 11003://WSANO_RECOVERY
                           //This is a nonrecoverable error. 
                           //This indicates that some sort of nonrecoverable error occurred during a database lookup. 
                           //This may be because the database files (for example, BSD-compatible HOSTS, SERVICES, or PROTOCOLS files) 
                           //	could not be found, or a DNS request was returned by the server with a severe error.
                    sockErr.Error = "WSANO_RECOVERY";
                    sockErr.Description = "A nonrecoverable error occurred during a database lookup. This may be because the database files (for example, BSD-compatible HOSTS, SERVICES, or PROTOCOLS files) could not be found, or a DNS request was returned by the server with a severe error.";
                    break;
                case 11004://WSANO_DATA
                           //Valid name, no data record of requested type. 
                           //The requested name is valid and was found in the database, but it does not have the correct associated data being resolved for.
                           //The usual example for this is a host name-to-address translation attempt (using gethostbyname or WSAAsyncGetHostByName)
                           //	which uses the DNS (Domain Name Server). 
                           //An MX record is returned but no A record梚ndicating the host itself exists, but is not directly reachable.
                    sockErr.Error = "WSANO_DATA";
                    sockErr.Description = "The requested name is valid and was found in the database, but it does not have the correct associated data being resolved for. The usual example for this is a host name-to-address translation attempt (using gethostbyname or WSAAsyncGetHostByName) which uses the DNS (Domain Name Server). ";
                    break;
                case 11005://WSA_QOS_RECEIVERS
                           //QOS receivers.
                           //At least one QOS reserve has arrived.
                    sockErr.Error = "WSA_QOS_RECEIVERS";
                    sockErr.Description = "At least one QOS reserve has arrived.";
                    break;
                case 11006://WSA_QOS_SENDERS
                           //QOS senders. 
                           //At least one QOS send path has arrived.
                    sockErr.Error = "WSA_QOS_SENDERS";
                    sockErr.Description = "At least one QOS send path has arrived.";
                    break;
                case 11007://WSA_QOS_NO_SENDERS
                           //No QOS senders.
                           //There are no QOS senders.
                    sockErr.Error = "WSA_QOS_NO_SENDERS";
                    sockErr.Description = "There are no QOS senders.";
                    break;
                case 11008://WSA_QOS_NO_RECEIVERS
                           //QOS no receivers. 
                           //There are no QOS receivers.
                    sockErr.Error = "WSA_QOS_NO_RECEIVERS";
                    sockErr.Description = "There are no QOS receivers.";
                    break;
                case 11009://WSA_QOS_REQUEST_CONFIRMED
                           //QOS request confirmed. 
                           //The QOS reserve request has been confirmed.
                    sockErr.Error = "WSA_QOS_REQUEST_CONFIRMED";
                    sockErr.Description = "The QOS reserve request has been confirmed.";
                    break;
                case 11010://WSA_QOS_ADMISSION_FAILURE
                           //QOS admission error. 
                           //A QOS error occurred due to lack of resources.
                    sockErr.Error = "WSA_QOS_ADMISSION_FAILURE";
                    sockErr.Description = "A QOS error occurred due to lack of resources.";
                    break;
                case 11011://WSA_QOS_POLICY_FAILURE
                           //QOS policy failure.
                           //The QOS request was rejected because the policy system couldn't allocate the requested resource within the existing policy. 
                    sockErr.Error = "WSA_QOS_POLICY_FAILURE";
                    sockErr.Description = "The QOS request was rejected because the policy system couldn't allocate the requested resource within the existing policy. ";
                    break;
                case 11012://WSA_QOS_BAD_STYLE
                           //QOS bad style.
                           //An unknown or conflicting QOS style was encountered.
                    sockErr.Error = "WSA_QOS_BAD_STYLE";
                    sockErr.Description = "An unknown or conflicting QOS style was encountered.";
                    break;
                case 11013://WSA_QOS_BAD_OBJECT
                           //QOS bad object.
                           //A problem was encountered with some part of the filterspec or the provider-specific buffer in general.
                    sockErr.Error = "WSA_QOS_BAD_OBJECT";
                    sockErr.Description = "A problem was encountered with some part of the filterspec or the provider-specific buffer in general.";
                    break;
                case 11014://WSA_QOS_TRAFFIC_CTRL_ERROR
                           //QOS traffic control error. 
                           //An error with the underlying traffic control (TC) API as the generic QOS request was converted for local enforcement by the TC API. 
                           //This could be due to an out of memory error or to an internal QOS provider error. 
                    sockErr.Error = "WSA_QOS_TRAFFIC_CTRL_ERROR";
                    sockErr.Description = "An error with the underlying traffic control (TC) API as the generic QOS request was converted for local enforcement by the TC API. This could be due to an out of memory error or to an internal QOS provider error. ";
                    break;
                case 11015://WSA_QOS_GENERIC_ERROR
                           //QOS generic error.
                           //A general QOS error.
                    sockErr.Error = "WSA_QOS_GENERIC_ERROR";
                    sockErr.Description = "Generic QOS error.";
                    break;
                case 11016://WSA_QOS_ESERVICETYPE
                           //QOS service type error. 
                           //An invalid or unrecognized service type was found in the QOS flowspec.
                    sockErr.Error = "WSA_QOS_ESERVICETYPE";
                    sockErr.Description = "An invalid or unrecognized service type was found in the QOS flowspec.";
                    break;
                case 11017://WSA_QOS_EFLOWSPEC
                           //QOS flowspec error. 
                           //An invalid or inconsistent flowspec was found in the QOS structure.
                    sockErr.Error = "WSA_QOS_EFLOWSPEC";
                    sockErr.Description = "An invalid or inconsistent flowspec was found in the QOS structure.";
                    break;
                case 11018://WSA_QOS_EPROVSPECBUF
                           //Invalid QOS provider buffer.
                           //An invalid QOS provider-specific buffer.
                    sockErr.Error = "WSA_QOS_EPROVSPECBUF";
                    sockErr.Description = "An invalid QOS provider-specific buffer.";
                    break;
                case 11019://WSA_QOS_EFILTERSTYLE
                           //Invalid QOS filter style. 
                           //An invalid QOS filter style was used.
                    sockErr.Error = "WSA_QOS_EFILTERSTYLE";
                    sockErr.Description = "An invalid QOS filter style was used.";
                    break;
                case 11020://WSA_QOS_EFILTERTYPE
                           //Invalid QOS filter type.
                           //An invalid QOS filter type was used.
                    sockErr.Error = "WSA_QOS_EFILTERTYPE";
                    sockErr.Description = "An invalid QOS filter type was used.";
                    break;
                case 11021://WSA_QOS_EFILTERCOUNT
                           //Incorrect QOS filter count. 
                           //An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.
                    sockErr.Error = "WSA_QOS_EFILTERCOUNT";
                    sockErr.Description = "An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.";
                    break;
                case 11022://WSA_QOS_EOBJLENGTH
                           //Invalid QOS object length. 
                           //An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.
                    sockErr.Error = "WSA_QOS_EOBJLENGTH";
                    sockErr.Description = "An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.";
                    break;
                case 11023://WSA_QOS_EFLOWCOUNT
                           //Incorrect QOS flow count.  
                           //An incorrect number of flow descriptors was specified in the QOS structure.
                    sockErr.Error = "WSA_QOS_EFLOWCOUNT";
                    sockErr.Description = "An incorrect number of flow descriptors was specified in the QOS structure.";
                    break;
                case 11024://WSA_QOS_EUNKOWNPSOBJ
                           //Unrecognized QOS object. 
                           //An unrecognized object was found in the QOS provider-specific buffer.
                    sockErr.Error = "WSA_QOS_EUNKOWNPSOBJ";
                    sockErr.Description = "An unrecognized object was found in the QOS provider-specific buffer.";
                    break;
                case 11025://WSA_QOS_EPOLICYOBJ
                           //Invalid QOS policy object. 
                           //An invalid policy object was found in the QOS provider-specific buffer.
                    sockErr.Error = "WSA_QOS_EPOLICYOBJ";
                    sockErr.Description = "An invalid policy object was found in the QOS provider-specific buffer.";
                    break;
                case 11026://WSA_QOS_EFLOWDESC
                           //Invalid QOS flow descriptor. 
                           //An invalid QOS flow descriptor was found in the flow descriptor list.
                    sockErr.Error = "WSA_QOS_EFLOWDESC";
                    sockErr.Description = "An invalid QOS flow descriptor was found in the flow descriptor list.";
                    break;
                case 11027://WSA_QOS_EPSFLOWSPEC
                           //Invalid QOS provider-specific flowspec. 
                           //An invalid or inconsistent flowspec was found in the QOS provider-specific buffer.
                    sockErr.Error = "WSA_QOS_EPSFLOWSPEC";
                    sockErr.Description = "An invalid or inconsistent flowspec was found in the QOS provider-specific buffer.";
                    break;
                case 11028://WSA_QOS_EPSFILTERSPEC
                           //Invalid QOS provider-specific filterspec. 
                           //An invalid FILTERSPEC was found in the QOS provider-specific buffer.
                    sockErr.Error = "WSA_QOS_EPSFILTERSPEC";
                    sockErr.Description = "An invalid FILTERSPEC was found in the QOS provider-specific buffer.";
                    break;
                case 11029://WSA_QOS_ESDMODEOBJ
                           //Invalid QOS shape discard mode object. 
                           //An invalid shape discard mode object was found in the QOS provider-specific buffer.
                    sockErr.Error = "WSA_QOS_ESDMODEOBJ";
                    sockErr.Description = "An invalid shape discard mode object was found in the QOS provider-specific buffer.";
                    break;
                case 11030://WSA_QOS_ESHAPERATEOBJ
                           //Invalid QOS shaping rate object. 
                           //An invalid shaping rate object was found in the QOS provider-specific buffer.
                    sockErr.Error = "WSA_QOS_ESHAPERATEOBJ";
                    sockErr.Description = "An invalid shaping rate object was found in the QOS provider-specific buffer.";
                    break;
                case 11031://WSA_QOS_RESERVED_PETYPE
                           //Reserved policy QOS element type. 
                           //A reserved policy element was found in the QOS provider-specific buffer.
                    sockErr.Error = "WSA_QOS_RESERVED_PETYPE";
                    sockErr.Description = "A reserved policy element was found in the QOS provider-specific buffer.";
                    break;
                default:
                    sockErr.Error = "UNRECOGNIZED_WSA_ERROR";
                    sockErr.Description = "The error returned from WSAGetLastError was not recognized as a valid WSA error";
                    break;
            }

            return sockErr;
        }
    }
}
