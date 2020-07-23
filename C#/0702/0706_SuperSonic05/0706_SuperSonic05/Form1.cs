using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0706_SuperSonic05
{
    public partial class Form1 : Form
    {
        List<byte> data;
        List<double> totals;
        int maxTotals = 10;

        string portName;
        int baudRate;
        bool status = false;
        bool trigger = false;
        byte imageSelect;

        double total;
        byte rel = 0;
        byte reh = 0;

        byte cmj = 0;
        byte cml = 0;
        byte mm = 0;

        public Form1()
        {
            InitializeComponent();

            total = 0;
            data = new List<byte>();
            totals = new List<double>();
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

                    total = rel + (reh * 0.1);
                    totals.Add(total);

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

            label2.Invoke(new MethodInvoker(delegate ()
            {
                if (status)
                {
                    label2.Text = rel.ToString() + "." + reh.ToString() + " .cm";

                }
            }));

            label3.Invoke(new MethodInvoker(delegate ()
            {
                if (status)
                {
                    if(totals.Count > 10)
                    {
                        double totalSum = 0;
                        for(int i = 0; i < 10; i++)
                        {
                            totalSum += totals[i];
                        }
                        totals.RemoveAt(0);
                        totalSum /= 10.0;
                        label3.Text = totalSum.ToString()+ ".cm |" + imageSelect.ToString();
                    }
                    trigger = true;
                    status = false;
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
