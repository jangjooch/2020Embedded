using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0625_serial_Delegate_control
{
    class SerialController
    {
        SerialPort serialPort = null;
        public SerialController(SerialPort serialGet)
        {
            serialPort = serialGet;
        }


        public void SerialOpen(string port, int buadRate)
        {
            serialPort.PortName = port;
            serialPort.BaudRate = buadRate;
            serialPort.Open();
        }
        public void SerialClose()
        {
            if (serialPort.IsOpen)
            {
                serialPort.Close();
            }            
        }
    }
}
