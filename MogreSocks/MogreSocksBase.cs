using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MogreSocks
{
    public struct ThreadRecvData
    {
        public byte[] Data { get; set; }
        public string IPAddr { get; set; }
        public ulong Port { get; set; }
    }

    public class MogreSocksBase
    {
        public event Action<string, ulong, int> Connect;
        public event Action<byte[], string, ulong> Receive;
        public event Action<string, ulong> Disconnect;
    }
}
