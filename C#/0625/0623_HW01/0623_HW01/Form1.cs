using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0623_HW01
{
    public partial class Form1 : Form
    {
        byte ledValue;
        List<byte> datas;
        public Form1()
        {
            InitializeComponent();
            datas = new List<byte>();
            ledValue = 0;
        }

        ~Form1()
        {
            timerInterrupt.Enabled = false;
            if (serialPort1.IsOpen)
            {
                serialPort1.Close();
            }            
        }

        private void UART_Open(object sender, EventArgs e)
        {
            serialPort1.PortName = "COM8";
            serialPort1.BaudRate = 9600;
            serialPort1.Open();
            timerInterrupt.Enabled = true;
            buttonOpen.Enabled = false; // 한번 Open 했으니 기능 잠금
            buttonClose.Enabled = true; // 한번 Open 했으니 기능 오픈
        }

        private void UART_Close(object sender, EventArgs e)
        {
            serialPort1.Close();
            timerInterrupt.Enabled = false;
            buttonOpen.Enabled = true; // UART 잠갔으니 Open할 버튼허가
            buttonClose.Enabled = false;
        }

        private void Button_Click(object sender, EventArgs e)
        {
            // 캐스팅 연산자를 통해 각 LED에 대한 버튼을 통합적으로 관리
            int select = 0;
            if(((Button)sender).Name == "button1")
            {
                select = 0;                
            }
            else if(((Button)sender).Name == "button2")
            {
                select = 1;
            }
            else if (((Button)sender).Name == "button3")
            {
                select = 2;
            }
            else if (((Button)sender).Name == "button4")
            {
                select = 3;
            }
            else if (((Button)sender).Name == "button5")
            {
                select = 4;
            }
            else if (((Button)sender).Name == "button6")
            {
                select = 5;
            }
            else if (((Button)sender).Name == "button7")
            {
                select = 6;
            }
            else if (((Button)sender).Name == "button8")
            {
                select = 7;
            }

            if( (ledValue & (1 << select)) == 0)
            {
                // 해당 자리가 0이라면 1로 Set
                ledValue |= (Byte)(1 << select);
            }
            else
            {
                // 해당 자리가 1이라면 0으로 Clear
                ledValue &= (Byte)(~(1 << select));
            }
            if (serialPort1.IsOpen)
            {
                byte[] send = new byte[1];
                send[0] = ledValue;
                serialPort1.Write(send, 0, 1);
                
                //textBoxDataSend.Text = ledValue.ToString();
                textBoxDataSend.Text = send[0].ToString();
            }
        }
        private void UART_Receive(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            int count = serialPort1.BytesToRead;
            byte[] getdata = new byte[count];
            serialPort1.Read(getdata, 0, count);
            ledValue = getdata[count - 1];

            textBoxDataReceive.Invoke(new MethodInvoker(delegate ()
            {
                textBoxDataReceive.Text = ledValue.ToString();
            }));
        }

        private void SettingPictures(object sender, EventArgs e)
        {
            int dataGet = ledValue;
            if( (dataGet & (1 << 0)) != 0)
            {
                pictureBoxLed01.ImageLocation = "./On.jpg";
            }
            else
            {
                pictureBoxLed01.ImageLocation = "./Off.jpg";
            }

            if ((dataGet & (1 << 1)) != 0)
            {
                pictureBoxLed02.ImageLocation = "./On.jpg";
            }
            else
            {
                pictureBoxLed02.ImageLocation = "./Off.jpg";
            }

            if ((dataGet & (1 << 2)) != 0)
            {
                pictureBoxLed03.ImageLocation = "./On.jpg";
            }
            else
            {
                pictureBoxLed03.ImageLocation = "./Off.jpg";
            }
            if ((dataGet & (1 << 3)) != 0)
            {
                pictureBoxLed04.ImageLocation = "./On.jpg";
            }
            else
            {
                pictureBoxLed04.ImageLocation = "./Off.jpg";
            }
            if ((dataGet & (1 << 4)) != 0)
            {
                pictureBoxLed05.ImageLocation = "./On.jpg";
            }
            else
            {
                pictureBoxLed05.ImageLocation = "./Off.jpg";
            }
            if ((dataGet & (1 << 5)) != 0)
            {
                pictureBoxLed06.ImageLocation = "./On.jpg";
            }
            else
            {
                pictureBoxLed06.ImageLocation = "./Off.jpg";
            }
            if ((dataGet & (1 << 6)) != 0)
            {
                pictureBoxLed07.ImageLocation = "./On.jpg";
            }
            else
            {
                pictureBoxLed07.ImageLocation = "./Off.jpg";
            }
            if ((dataGet & (1 << 7)) != 0)
            {
                pictureBoxLed08.ImageLocation = "./On.jpg";
            }
            else
            {
                pictureBoxLed08.ImageLocation = "./Off.jpg";
            }
        }

        
    }
}
