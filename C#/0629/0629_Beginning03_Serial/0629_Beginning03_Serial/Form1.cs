using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0629_Beginning03_Serial
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            for(int i = 0; i < 15; i++)
            {
                comboBoxCOMPort.Items.Add("COM" + i.ToString());
            }
            comboBoxCOMPort.SelectedIndex = 0;

            buttonSerialClose.Enabled = false;
            buttonSerialOpen.Enabled = true;
            comboBoxCOMPort.Enabled = true;
            textBoxBuadRate.Enabled = true;
        }

        private void SerialOpen(object sender, EventArgs e)
        {
            string portGet = comboBoxCOMPort.Text;
            string buadGet = textBoxBuadRate.Text;
            int intBuad = 0;
            try
            {
                intBuad = int.Parse(buadGet);
                serialPortToAVR.PortName = portGet;
                serialPortToAVR.BaudRate = intBuad;
                serialPortToAVR.Open();
                textBoxBuadRate.Text = "";

                buttonSerialClose.Enabled = true;
                buttonSerialOpen.Enabled = false;
                comboBoxCOMPort.Enabled = false;
                textBoxBuadRate.Enabled = false;

                MessageBox.Show("Serial Open");
            }
            catch(Exception)
            {
                MessageBox.Show("Invaild Buad Rate Value");
                textBoxBuadRate.Text = "";
            }
        }

        private void SerialClose(object sender, EventArgs e)
        {
            if (serialPortToAVR.IsOpen)
            {
                serialPortToAVR.Close();
                buttonSerialClose.Enabled = false;
                buttonSerialOpen.Enabled = true;
                comboBoxCOMPort.Enabled = true;
                textBoxBuadRate.Enabled = true;
            }
        }
        private void SerialWrite(object sender, EventArgs e)
        {
            if (serialPortToAVR.IsOpen)
            {
                serialPortToAVR.WriteLine(textBoxSendContent.Text);

                byte[] bytesending = new byte[1];
                bytesending[0] = 0x32;
                serialPortToAVR.Write(bytesending, 0, 1);
            }
        }

        private void SerialPortReceive(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            int count = serialPortToAVR.BytesToRead;
            byte[] received = new byte[count];
            serialPortToAVR.Read(received, 0, count);

            /*
             string a = Encoding.ASCII.GetString(바이트 배열);             
             */
            richTextBoxReceived.Invoke(new MethodInvoker(delegate ()
            {
                richTextBoxReceived.Text += received.ToString();
                richTextBoxReceived.Text += "\r\n";
            }));
        }
    }
}
