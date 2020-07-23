using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0706_HW01
{
    public partial class Form1 : Form
    {

        List<byte> data;
        List<double> distances;

        string portName = "COM8";
        int baudRate = 9600;

        bool status = false;
        bool trigger = false;


        public Form1()
        {
            InitializeComponent();
            data = new List<byte>();
            distances = new List<double>();

            buttonOpen.Enabled = true;
            buttonClose.Enabled = false;
            buttonSend.Enabled = false;
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
                buttonSend.Enabled = true;
            }
        }
        private void SerialClose(object sender, EventArgs e)
        {
            if (serialPortAVR.IsOpen)
            {
                serialPortAVR.Close();
                buttonOpen.Enabled = true;
                buttonClose.Enabled = false;
                buttonSend.Enabled = false;
            }
        }

        private void AngleSend(object sender, EventArgs e)
        {
            try
            {
                byte angle = byte.Parse(textBoxAngle.Text);
                textBoxAngle.Text = "";
                byte[] sendData = new byte[1];
                sendData[0] = angle;
                serialPortAVR.Write(sendData, 0, 1);
                MessageBox.Show("Angle Send");
            }
            catch(Exception ex)
            {
                MessageBox.Show("Invaild Angle Value");
                textBoxAngle.Text = "";
            }
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

                    byte valueH = data[0];
                    data.RemoveAt(0);

                    byte valueL = data[0];
                    data.RemoveAt(0);

                    byte valueMM = data[0];
                    data.RemoveAt(0);

                    double value = (byte)(valueH << 8) + valueL + (valueMM * 0.1);

                    trigger = true;

                    label3.Invoke(new MethodInvoker(delegate ()
                    {
                        label3.Text = valueH.ToString() + "|" + valueL.ToString() + "|" + valueMM.ToString();
                    }));
                    label2.Invoke(new MethodInvoker(delegate ()
                    {
                        label2.Text = value.ToString();
                    }));

                    distances.Add(value);
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
            if (distances.Count > 10)
            {
                double averrage = 0;
                for(int i = 0; i < 10; i++)
                {
                    averrage += distances[i];
                }
                averrage = averrage / 10;
                distances.RemoveAt(0);

                chart1.Invoke(new MethodInvoker(delegate ()
                {
                    chart1.Series[0].Points.AddXY(DateTime.Now.ToString(), averrage);
                    if (chart1.Series[0].Points.Count > 20)
                    {
                        chart1.Series[0].Points.RemoveAt(0);
                    }
                    chart1.ChartAreas[0].RecalculateAxesScale();
                }));
            }            
        }
    }
}
