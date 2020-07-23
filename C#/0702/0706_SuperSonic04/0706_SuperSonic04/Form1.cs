using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0706_SuperSonic04
{
    public partial class Form1 : Form
    {
        List<byte> data;
        string portName;
        int baudRate;
        bool status = false;
        bool trigger = false;
        byte imageSelect;

        uint total;
        uint rel = 0;
        uint reh = 0;

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
            if (data.Count > 3)
            {
                if (data[0] == 255)
                {
                    data.RemoveAt(0);

                    rel = data[0];
                    data.RemoveAt(0);

                    reh = data[0];
                    data.RemoveAt(0);

                    imageSelect = data[0];
                    data.RemoveAt(0);

                    total = rel + (reh << 8);

                    status = true;
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

            labelDis.Invoke(new MethodInvoker(delegate ()
            {
                if (status)
                {
                    labelDis.Text = rel.ToString() + "." + reh + " .cm";
                    
                }
            }));

            label2.Invoke(new MethodInvoker(delegate ()
            {
                if (status)
                {
                    label2.Text = rel.ToString() + "|" + reh.ToString() + "|" + imageSelect.ToString();                    status = false;
                    trigger = true;
                }
            }));

            pictureBoxCar.Invoke(new MethodInvoker(delegate ()
            {
                if (trigger)
                {
                    trigger = false;
                    pictureBoxCar.ImageLocation = "./" + imageSelect.ToString() + ".jpg";
                }
            }));


        }
        long map(long x, long in_min, long in_max, long out_min, long out_max)
        {
            if (x < in_min)
            {
                x = in_min;
            }
            if (x > in_max)
            {
                x = in_max;
            }
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
        }
    }
}
