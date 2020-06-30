using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0625_serial_Delegate_control
{
    public partial class Form1 : Form
    {
        List<int> data = new List<int>();
        int dataIdx = 0;
        int parsedNum = 0;
        public Form1()
        {
            InitializeComponent();
        }
        
        public void SerialOpen()
        {

        }

        private void UART_Receive(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            int count = serialPort1.BytesToRead;
            for (int i = 0; i < count; i++)
            {
                int receive = serialPort1.ReadByte();
                data.Add((Byte)receive);
            }

            if (data.Count > 6)
            {
                if (data[dataIdx] == 255)
                {
                    if (data.IndexOf(254) - data.IndexOf(255) == 4)
                    {
                        // 255 255 X X 254 254
                        data.RemoveAt(0);
                        if (data.IndexOf(254) - data.IndexOf(255) == 3)
                        {
                            // 255 X X 254 254
                            data.RemoveAt(0);
                            int num = (int)data[dataIdx];
                            data.RemoveAt(0);
                            num += ((int)data[dataIdx] << 8);
                            data.RemoveAt(0);
                            parsedNum = mapping(num, 0, 1024, 0, 250);
                            textBoxValue.Text = parsedNum.ToString();
                            ChartPointAdd();
                            while (data[dataIdx] == 254)
                            {
                                data.RemoveAt(0);
                            }
                        }
                    }
                }
                else
                {
                    data.RemoveAt(0); // 255 시작이 아니라면 삭제
                }
            }
        }

        public void DataParsing()
        {
            if (data[dataIdx] == 255 && data[dataIdx + 1] == 255)
            {
                if (data[dataIdx + 4] == 254 && data[dataIdx + 5] == 254)
                {
                    int num = (int)data[dataIdx + 2];
                    num += ((int)data[dataIdx + 3] << 8);
                    parsedNum = mapping(num, 0, 1024, 0, 250);
                }
            }
        }

        int mapping(int x, int in_min, int in_max, int out_min, int out_max)
        {
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
        }

        private void ChartPointAdd()
        {
            ChartMove01();
            chartADCValue.Series[0].Points.AddXY(DateTime.Now.ToString(), parsedNum);
            chartADCValue.ChartAreas[0].RecalculateAxesScale();
        }

        private void ChartMove01()
        {
            if (chartADCValue.Series[0].Points.Count > 30)
            {
                chartADCValue.Series[0].Points.RemoveAt(0);
            }
        }
    }
}
