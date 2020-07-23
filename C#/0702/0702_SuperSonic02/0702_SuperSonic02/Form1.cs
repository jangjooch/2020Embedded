using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0702_SuperSonic02
{

    public partial class Form1 : Form
    {
        int total;
        List<byte> data;
        string portName;
        int baudRate;
        bool status = false;
        bool trigger = false;
        int imageSelect;

        public Form1()
        {
            InitializeComponent();
            
            total = 0;
            data = new List<byte>();
            portName = "COM8";
            baudRate = 9600;

            buttonOpen.Enabled = true;
            buttonClose.Enabled = false;

            imageSelect = 0;
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
            }
        }
        private void SerialClose(object sender, EventArgs e)
        {
            if (serialPortAVR.IsOpen)
            {
                serialPortAVR.Close();
                buttonOpen.Enabled = true;
                buttonClose.Enabled = false;
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
            if(data.Count > 3)
            {
                if(data[0] == 255)
                {
                    data.RemoveAt(0);

                    byte rel = data[0];
                    data.RemoveAt(0);

                    byte reh = data[0];
                    data.RemoveAt(0);

                    total = rel + (reh << 8);

                    status = true;
                }
                else
                {
                    data.RemoveAt(0);
                }
            }
            if(data.Count > 100)
            {
                data.Clear();
            }

            labelICR.Invoke(new MethodInvoker(delegate ()
            {
                if (status)
                {
                    labelICR.Text = total.ToString();
                }
            }));

            labelDistance.Invoke(new MethodInvoker(delegate ()
            {
                if (status)
                {
                    // 260 ~ 1500
                    // 270 ~ 1400


                    //double result = ((double)(total)) * 4 * 377 * 100 * 0.0000002;
                    double result = ((double)(total)) * 1000000.0 * 64 / 16000000;
                    //double result = map(total, 260, 1450, 3, 50);
                    labelDistance.Text = result.ToString() + " cm";
                    status = false;
                    trigger = true;
                    if(result > 40)
                    {
                        imageSelect = 0;
                    }
                    else if(result > 30)
                    {
                        imageSelect = 1;
                    }
                    else if (result > 20)
                    {
                        imageSelect = 2;
                    }
                    else
                    {
                        imageSelect = 3;
                    }
                }
                
            }));

            pictureBoxCar.Invoke(new MethodInvoker(delegate ()
            {
                if (trigger)
                {
                    trigger = false;
                    pictureBoxCar.ImageLocation = "./" +imageSelect.ToString() +".jpg";
                }
            }));


        }
        long map(long x, long in_min, long in_max, long out_min, long out_max)
        {
            if(x < in_min)
            {
                x = in_min;
            }
            if(x > in_max)
            {
                x = in_max;
            }
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
        }
    }
}
