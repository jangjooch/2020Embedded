using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0713_MiddleTest01
{
    public partial class Form1 : Form
    {
        List<byte> data;
        byte uidLength = 0;
        List<byte> uid;        
        List<string> serials;
        Dictionary<string, string> history;
        

        string portName = "COM8";
        int baudRate = 9600;


        public Form1()
        {
            InitializeComponent();
            data = new List<byte>();
            uid = new List<byte>();
            serials = new List<string>();
            history = new Dictionary<string, string>();

            buttonOpen.Enabled = true;
            buttonClose.Enabled = false;
            buttonSave.Enabled = false;
            buttonDel.Enabled = false;
            buttonSearch.Enabled = false;
            timer1.Enabled = false;

            dataGridView1.ColumnCount = 1;
            dataGridView1.Columns[0].HeaderText = "DATE";

            try
            {
                string[] data = File.ReadAllLines(@"./serials.txt");
                foreach (string s in data)
                {
                    serials.Add(s);
                }
            }
            catch
            {
                MessageBox.Show("No Serials Data");
            }
            try
            {
                string[] data = File.ReadAllLines(@"./history.txt");
                foreach (string s in data)
                {
                    string[] datas = s.Split('_');
                    history.Add(datas[0], datas[1]);
                }
            }
            catch
            {
                MessageBox.Show("No History Data");
            }
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
                timer1.Enabled = true;
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

        private void LogEditing(object sender, EventArgs e)
        {
            string uidStr = "";
            for (int i = 0; i < uid.Count; i++)
            {
                uidStr += uid[i].ToString();
                if (i != uid.Count - 1)
                {
                    uidStr += "|";
                }
            }            
            
            if (serials.Contains(uidStr))
            {
                if (((Button)sender).Name == "buttonDel")
                {
                    serials.Remove(uidStr);
                    MessageBox.Show("Delete Compelete");
                }
                else if (((Button)sender).Name == "buttonSearch")
                {
                    label3.Text = "Found";
                    MessageBox.Show("Search Compelete");
                    dataGridView1.Rows.Clear();
                    foreach(var getHistory in history)
                    {
                        if(getHistory.Value == uidStr)
                        {
                            dataGridView1.Rows.Add(getHistory.Key);
                        }
                    }
                }
            }
            else
            {
                if (((Button)sender).Name == "buttonSave")
                {
                    serials.Add(uidStr);
                    MessageBox.Show("Save Compelete");
                }
                else if (((Button)sender).Name == "buttonSearch")
                {
                    label3.Text = "NoData";
                    MessageBox.Show("Search Compelete");
                }
            }
            
        }

        private void Send0(object sender, EventArgs e)
        {
            if (serialPortAVR.IsOpen)
            {
                byte[] data = new byte[1];
                data[0] = 0x00;
                serialPortAVR.Write(data, 0, 1);
            }
        }

        private void Send1(object sender, EventArgs e)
        {
            if (serialPortAVR.IsOpen)
            {
                byte[] data = new byte[1];
                data[0] = 0x01;
                serialPortAVR.Write(data, 0, 1);
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
            if(data.Count >= 6)
            {
                if (data[0] == 255)
                {
                    data.RemoveAt(0);

                    uid.Clear();

                    uidLength = data[0];
                    data.RemoveAt(0);

                    for(int i = 0; i < uidLength; i++)
                    {
                        uid.Add(data[0]);
                        data.RemoveAt(0);
                    }
                    string uidStr = "";
                    for(int i = 0; i < uid.Count; i++)
                    {
                        uidStr += uid[i].ToString();
                        if(i != uid.Count - 1)
                        {
                            uidStr += "|";
                        }
                        if (serials.Contains(uidStr))
                        {
                            byte[] data = new byte[1];
                            data[0] = 0x01;
                            serialPortAVR.Write(data, 0, 1);
                            history.Add(DateTime.Now.ToString(), uidStr);
                        }
                        else
                        {
                            byte[] data = new byte[1];
                            data[0] = 0x00;
                            serialPortAVR.Write(data, 0, 1);
                        }
                    }
                    label2.Invoke(new MethodInvoker(delegate ()
                    {
                        label2.Text = uidStr;
                    }));
                    buttonSave.Invoke(new MethodInvoker(delegate ()
                    {
                        buttonSave.Enabled = true;
                    }));

                    buttonDel.Invoke(new MethodInvoker(delegate ()
                    {
                        buttonDel.Enabled = true;
                    }));

                    buttonSearch.Invoke(new MethodInvoker(delegate ()
                    {
                        buttonSearch.Enabled = true;
                    }));
                }                
            }
            if (data.Count > 100)
            {
                data.Clear();
            }
        }

        private void TimerInterrupt(object sender, EventArgs e) { 
}

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (serialPortAVR.IsOpen)
            {
                serialPortAVR.Close();
            }
            using (StreamWriter sw = new StreamWriter(@"./serials.txt", false))
            {
                foreach (string s in serials)
                {
                    sw.WriteLine(s);
                }
            }

            using (StreamWriter sw = new StreamWriter(@"./history.txt", false))
            {
                foreach (var v in history)
                {
                    string writing = v.Key;
                    writing += "_" + v.Value;
                    sw.WriteLine(writing);
                }
            }
        }
    }
}
