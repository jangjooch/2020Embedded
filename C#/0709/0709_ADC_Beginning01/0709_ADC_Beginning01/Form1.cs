using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0709_ADC_Beginning01
{
    public partial class Form1 : Form
    {
        History history = History.CreateHistory();
        List<byte> data;

        string portName = "COM8";
        int baudRate = 9600;

        bool status = false;
        bool trigger = false;


        public Form1()
        {
            InitializeComponent();            

            buttonOpen.Enabled = true;
            buttonClose.Enabled = false;
            buttonHistory.Enabled = false;
            data = new List<byte>();
        }

        private void SerialOpen(object sender, EventArgs e)
        {
            if (!serialPortAVR.IsOpen)
            {
                serialPortAVR.PortName = portName;
                serialPortAVR.BaudRate = baudRate;
                serialPortAVR.Open();
                buttonOpen.Enabled = false;
                buttonClose.Enabled = true;
                buttonHistory.Enabled = true;
            }
        }
        private void SerialClose(object sender, EventArgs e)
        {
            if (serialPortAVR.IsOpen)
            {
                serialPortAVR.Close();
                buttonOpen.Enabled = true;
                buttonClose.Enabled = false;
                buttonHistory.Enabled = false;
            }
        }

        private void ShowSearch(object sender, EventArgs e)
        {
            ShowHistory showHistory = new ShowHistory();
            showHistory.ShowDialog();            
        }        
        private void serialPortAVR_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {

            int datanums = serialPortAVR.BytesToRead;

            for (int i = 0; i < datanums; i++)
            {
                int receive = serialPortAVR.ReadByte();
                data.Add((Byte)receive);
            }
            if (data.Count > 4)
            {
                if (data[0] == 255)
                {
                    data.RemoveAt(0);

                    byte valueL = data[0];
                    data.RemoveAt(0);

                    byte valueH = data[0];
                    data.RemoveAt(0);

                    int value = (byte)(valueH << 8) + valueL;

                    history.lightSensor.Add(DateTime.Now, value);

                    chart1.Invoke(new MethodInvoker(delegate ()
                    {
                        chart1.Series[0].Points.AddXY(DateTime.Now.ToString(), value);
                        if (chart1.Series[0].Points.Count > 50)
                        {
                            chart1.Series[0].Points.RemoveAt(0);
                        }
                        chart1.ChartAreas[0].RecalculateAxesScale();
                    }));

                    label1.Invoke(new MethodInvoker(delegate ()
                    {
                        label1.Text = valueH.ToString() + "|" + valueL.ToString();
                    }));
                }
                else
                {
                    data.RemoveAt(0);
                }
            }
            if (data.Count > 100)
            {
                data.Clear();
            }            
        }
    }
}
