using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0625_HW_Rewind01
{
    public partial class Form1 : Form
    {
        List<byte> data;
        List<int> dataPoints;
        int dataIdx;
        int parsedNum;
        int chartMaxPoint;
        public Form1()
        {
            InitializeComponent();
            dataPoints = new List<int>();
            data = new List<byte>();            
            dataIdx = 0;
            parsedNum = 0;
            chartMaxPoint = 30;
        }

        private void UART_Open(object sender, EventArgs e)
        {
            serialPort1.PortName = "COM8";
            serialPort1.BaudRate = 9600;            
            serialPort1.Open();

            buttonOpen.Enabled = false; // 한번 Open 했으니 기능 잠금
            buttonClose.Enabled = true; // 한번 Open 했으니 기능 오픈
        }

        private void UART_Close(object sender, EventArgs e)
        {
            serialPort1.Close();
            buttonOpen.Enabled = true; // UART 잠갔으니 Open할 버튼허가
            buttonClose.Enabled = false;
        }

        private void ChartPointAdd()
        {
            ChartMove01();
            chartADCValue.Series[0].Points.AddXY(DateTime.Now.ToString(), parsedNum);
            chartADCValue.ChartAreas[0].RecalculateAxesScale();
        }

        private void ChartMove01()
        {
            if (chartADCValue.Series[0].Points.Count > chartMaxPoint)
            {
                chartADCValue.Series[0].Points.RemoveAt(0);
            }
        }

        private void UART_Receive(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            int count = serialPort1.BytesToRead;
            for(int i = 0; i < count; i++)
            {
                int receive = serialPort1.ReadByte();
                data.Add((Byte)receive);
            }
            
            // 데이터를 읽을때 마다 데이터를 저장
            textBoxShowValue.Invoke(new MethodInvoker(delegate ()
            {
                if(data.Count > 6)
                {
                    if(data[dataIdx] == 255)
                    {
                        if(data.IndexOf(254) - data.IndexOf(255) == 4)
                        {
                            // 255 255 X X 254 254
                            data.RemoveAt(0);
                            if(data.IndexOf(254) - data.IndexOf(255) == 3)
                            {
                                // 255 X X 254 254
                                data.RemoveAt(0);
                                int num = (int)data[dataIdx];
                                data.RemoveAt(0);
                                num += ((int)data[dataIdx] << 8);
                                data.RemoveAt(0);
                                parsedNum = mapping(num, 0, 1024, 0, 250);
                                textBoxShowValue.Text = parsedNum.ToString();
                                ChartPointAdd();
                                while (data[dataIdx] == 254) {
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
            }));            
        }

        public void DataParsing()
        {
            if(data[dataIdx] == 255 && data[dataIdx +1] == 255)
            {
                if(data[dataIdx + 4] == 254 && data[dataIdx + 5] == 254)
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
    }
}
