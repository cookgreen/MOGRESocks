using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace MogreSocks
{
    public class MogreSocksLogger
    {
        private StreamWriter writer;
        private FileStream theSocketLogFile;
        private bool isWantComms;
        private bool isWantLog;
        private Mutex mutex;

        public bool IsWantLog 
        { 
            get { return isWantLog; } 
            set { isWantLog = value; }
        }

        public bool IsWantComms
        {
            get { return isWantComms; }
            set { isWantComms = value; }
        }

        public MogreSocksLogger()
        {
            isWantLog = true;
            isWantComms = true;
            mutex = new Mutex();
        }

        public MogreSocksLogger(string name, bool isWantLog = true, bool isWantComms = true)
        {
            Init(name, isWantLog, isWantComms);
            this.isWantLog = isWantLog;
            this.isWantComms = isWantComms;
        }

        public void Init(string name, bool isWantLong, bool isWantComms)
        {
            if (theSocketLogFile != null)
            {
                writer.Dispose();
                theSocketLogFile = null;
            }

            string fileName;
            if (isWantLog)
            {
                fileName = name + ".log";
                theSocketLogFile = new FileStream(fileName, FileMode.OpenOrCreate, FileAccess.ReadWrite);
                writer = new StreamWriter(theSocketLogFile);
            }
        }

        public void Log(string text)
        {
            while (mutex.WaitOne(0)) ;
            if (theSocketLogFile != null && isWantLog)
            {
                writer.WriteLine(string.Format("{0}-{1}:{2}", DateTime.Now.Date.ToString(), DateTime.Now.TimeOfDay.ToString(), text));
            }
            mutex.ReleaseMutex();
        }

        public void LogSockError(string text, int errcode)
        {
            string strText = text;
            strText += ". WSAGetLastError returned : ";
            SocketErrors.WINSOCKERROR err = SocketErrors.WINSOCKERROR.GetWINSOCKERROR(errcode);
            strText += err.Error;
            strText += " - [";
            strText += err.Description;
            strText += "]";

            Log(strText);
        }
    }
}
