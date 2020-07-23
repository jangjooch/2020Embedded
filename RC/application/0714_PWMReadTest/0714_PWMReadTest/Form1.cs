using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0714_PWMReadTest
{
    public partial class Form1 : Form
    {
        List<byte> data = new List<byte>();
        public Form1()
        {
            InitializeComponent();
            serialPortAVR.PortName = "COM8";
            serialPortAVR.BaudRate = 9600;
            button1.Enabled = true;
            button2.Enabled = false;
        }

        private void SerialOpen(object sender, EventArgs e)
        {
            serialPortAVR.Open();
            button1.Enabled = false;
            button2.Enabled = true;
        }
        private void SerialClose(object sender, EventArgs e)
        {
            serialPortAVR.Close();
            button1.Enabled = true;
            button2.Enabled = false;
        }

        private void SerialReceive(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            int dataBufferNums = serialPortAVR.BytesToRead;
            
            for(int i = 0; i < dataBufferNums; i++)
            {
                int receive = serialPortAVR.ReadByte();
                data.Add((Byte)receive);
                richTextBox6.Invoke(new MethodInvoker(delegate ()
                {
                    richTextBox6.Text += ((Byte)receive).ToString() + " ";
                    if(i == dataBufferNums - 1)
                    {
                        richTextBox6.Text += "\r\n";
                    }
                }));
                textBox1.Invoke(new MethodInvoker(delegate ()
                {
                    if (i == 0)
                    {
                        textBox1.Text = "";
                    }
                    textBox1.Text += ((Byte)receive).ToString() + " ";
                }));
            }
            /*
            string[] strs = textBox1.Text.Split(' ');
            if (strs.Length > 1)
            {
                textBox1.Invoke(new MethodInvoker(delegate ()
                {
                    long result = 0;
                    result += int.Parse(strs[0]);
                    result = (result << 8) + int.Parse(strs[1]);

                    textBox1.Text += result.ToString();
                }));
            }
            */
            if (data.Count > 4)
            {



                if (data[0] == 255)
                {
                    data.RemoveAt(0);

                    if(data[0] >=1 && data[0] <= 4)
                    {
                        byte idx = data[0];
                        data.RemoveAt(0);

                        long result = 0;

                        result = data[0];
                        data.RemoveAt(0);

                        result += (data[0] << 8);
                        data.RemoveAt(0);

                        switch (idx)
                        {
                            case 0:
                                richTextBox1.Invoke(new MethodInvoker(delegate ()
                                {
                                    richTextBox1.Text += result.ToString() + "\r\n";
                                }));
                                break;
                            case 1:
                                richTextBox2.Invoke(new MethodInvoker(delegate ()
                                {
                                    richTextBox2.Text += result.ToString() + "\r\n";
                                }));
                                break;
                            case 2:
                                richTextBox3.Invoke(new MethodInvoker(delegate ()
                                {
                                    richTextBox3.Text += result.ToString() + "\r\n";
                                }));
                                break;
                            case 3:
                                richTextBox4.Invoke(new MethodInvoker(delegate ()
                                {
                                    richTextBox4.Text += result.ToString() + "\r\n";
                                }));
                                break;
                            case 4:
                                richTextBox5.Invoke(new MethodInvoker(delegate ()
                                {
                                    richTextBox5.Text += result.ToString() + "\r\n";
                                }));
                                break;
                            default:
                                break;
                        }
                    }
                }
                else
                {
                    data.RemoveAt(0);
                }
            }
            else if (data.Count > 100)
            {
                data.Clear();
            }
        }
    }
}
