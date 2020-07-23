using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace _0702_SuperSonic_Serial01
{

    public partial class Form1 : Form
    {
        List<byte> super;
        int result;
        byte reh = 0;
        byte rel = 0;
        public Form1()
        {
            InitializeComponent();
            serialPortAVR.PortName = "COM8";
            serialPortAVR.BaudRate = 9600;
            serialPortAVR.Open();
            super = new List<byte>();
            result = 0;
        }
        ~Form1()
        {
            if (serialPortAVR.IsOpen)
            {
                serialPortAVR.Close();
                textBox1.Text = "";
            }            
        }
        private void serialPortAVR_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            int datanums = serialPortAVR.BytesToRead;
            
            for(int i = 0; i < datanums; i++)
            {
                int receive = serialPortAVR.ReadByte();
                super.Add((Byte)receive);                
            }

            textBox1.Invoke(new MethodInvoker(delegate ()
            {
                textBox1.Text = "Data in " + datanums.ToString();
            }));

            textBox2.Invoke(new MethodInvoker(delegate ()
            {
                textBox2.Text = "Count " + super.Count;
            }));

            textBox3.Invoke(new MethodInvoker(delegate ()
            {
                
                double parsed = result * (0.000002) * 8 * 377 * 10;
                textBox3.Text = parsed.ToString();
            }));

            textBox4.Invoke(new MethodInvoker(delegate ()
            {
                textBox4.Text = result.ToString();
            }));

            textBox5.Invoke(new MethodInvoker(delegate ()
            {
                textBox5.Text = reh.ToString();
            }));
            textBox6.Invoke(new MethodInvoker(delegate ()
            {
                textBox6.Text = rel.ToString();
            }));

            richTextBox1.Invoke(new MethodInvoker(delegate ()
            {
                if(super.Count > 2)
                {                    
                    if (super[0] == 255)
                    {
                        super.RemoveAt(0);

                        rel = super[0];
                        super.RemoveAt(0);

                        reh = super[0];
                        super.RemoveAt(0);

                        result = rel + (reh << 8);
                    }
                    else
                    {
                        super.RemoveAt(0);
                    }                    
                }
                if (super.Count > 100)
                {
                    super.Clear();
                }
            }));
        }
    }

}
