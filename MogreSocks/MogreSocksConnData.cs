using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace MogreSocks
{
    public struct MogreSocksConnData
    {
        public Socket Socket { get; set; }
        public IPEndPoint SockAddr { get; set; }
        public IPEndPoint SockAddrRemote { get; set; }
        public string IPAddr { get; set; }
        public ulong Port { get; set; }
        public bool IsConnected { get; set; }
        public byte[] BytesSend { get; set; }
        public ulong ByesToSend { get; set; }
        public ulong LastNumBytesSent { get; set; }
        public ulong LastNumTriesToSend { get; set; }
        public bool IsRetryingSend { get; set; }
        public ulong TotalBytesSend { get; set; }
        public byte[] TotalBytesSent { get; set; }
        public byte[] BytesReceive { get; set; }
        public ulong LastNumBytesReceived { get; set; }
        public ulong TotalBytesReceived { get; set; }
        public bool IsInitShutdown { get; set; }
        public byte[] BytesLastSent { get; set; }

        public static bool operator ==(MogreSocksConnData lhs, MogreSocksConnData rhs)
        {
            if (lhs.Socket == rhs.Socket)
            {
                return true;
            }
            return false;
        }

        public static bool operator !=(MogreSocksConnData lhs, MogreSocksConnData rhs)
        {
            if (lhs.Socket != rhs.Socket)
            {
                return true;
            }
            return false;
        }
    }
}
