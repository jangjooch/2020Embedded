using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0624_AVR_UART
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
        }

        private void UART_Open(object sender, EventArgs e)
        {
            serialPort1.PortName = comboBoxCOMPort.SelectedItem.ToString();
            try
            {
                serialPort1.BaudRate = int.Parse(textBoxBaudRate.Text);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Invaild Buad Rate Value");
            }
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

        private void UART_Receive(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            richTextBoxDataReceived.Invoke(new MethodInvoker(delegate ()
            {
                int count = serialPort1.BytesToRead; // 읽은 시점의 데이터 수
                // 미리 기록하는 이유는 한번 처리할때마다 차감될 것이기 때문이다.
                byte[] dataBuffer = new byte[count];
                // 대기하고 있는 데이터 만큼의 크기를 할당
                serialPort1.Read(dataBuffer, 0, count);
                // Read는 byte배열에 자신이 받은 데이터를 복사해주는 것이다.
                
                richTextBoxDataReceived.Text += Encoding.Default.GetString(dataBuffer);
                // 배열 dataBuffer을 String 화 하여 붙이는 것이다.


              /*
                if (serialPort1.IsOpen)
                {
                    richTextBoxDataReceived.Text += serialPort1.ReadLine();
                }
                */
                // ReadLine
                // \n이 들어오기 전까지 Serial을 통해 받은 데이터를 Text에 추가하는 것이다.
                // 즉 이를 기반으로 데이터의 끝을 인지하고 Parsing하면 된다.

                // ReadExisting
            }));
        }

        private void SerialDataSend(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                serialPort1.Write(textBoxSend.Text);
                textBoxSend.Text = "";
            }
        }
    }
}
