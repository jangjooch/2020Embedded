using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0626_HW_MP3_01
{
    public partial class Form1 : Form
    {
        
        public Form1()
        {
            InitializeComponent();
            serialPort1.PortName = "COM8";
            serialPort1.BaudRate = 9600;
            serialPort1.Open();

            if (serialPort1.IsOpen)
            {
                byte[] startSend = new byte[1];
                startSend[0] = 0x09;
                serialPort1.Write(startSend, 0, 1);
                
            }
            else
            {
                
            }
        }

        private void MP3_Controller(object sender, EventArgs e)
        {            
            byte[] data = new byte[1];
            if (((Button)sender).Name.Equals(buttonPlay.Name))
            {
                data[0] = 0x0D;
            }
            else if (((Button)sender).Name.Equals(buttonNext.Name))
            {
                data[0] = 0x01;
            }
            else if (((Button)sender).Name.Equals(buttonPrevious.Name))
            {
                data[0] = 0x02;
            }
            else if (((Button)sender).Name.Equals(buttonPause.Name))
            {
                data[0] = 0x0E;
            }
            else if (((Button)sender).Name.Equals(buttonVolUp.Name)){
                data[0] = 0x04;
            }
            else if (((Button)sender).Name.Equals(buttonVolDown.Name)){
                data[0] = 0x05;
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write(data, 0, 1);
            }
        }
    }
}
