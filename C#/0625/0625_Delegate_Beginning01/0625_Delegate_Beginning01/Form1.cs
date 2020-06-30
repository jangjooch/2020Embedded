using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0625_Delegate_Beginning01
{
    public partial class Form1 : Form
    {
        DataSend dataSend = null;
        public Form1()
        {
            InitializeComponent();
            dataSend = new DataSend();
            // 포인터 함수를 전달해줄 클래스를 단일객체로 사용하기 위하여
            // 생성자를 통해 한번만 생성하도록 한다.
            dataSend.setDelegate(DataReceive);
            // 이후 생성된 DataSend 객체에 전달될 Class Pointer를
            // 할당한다. 즉 Method자체는 여기에 생성되어 있지만
            // 사용할 수 있는 권한이 DataSend에게도 생기게 된것이다.
        }

        private void MethodStart(object sender, EventArgs e)
        {
            dataSend.DataStart();
        }
        
        private void MethodStop(object sender, EventArgs e)
        {
            dataSend.DataStop();
        }

        private void DataReceive(string str)
        {
            // DataReceive가 DataSend로 delegate를 통해 전해졌기때문에
            // 실제 작동에 있어서는 Winform Thread를 벗어난 것이기 때문에
            // Invoke를 사용하여 DataSend에서 textBoxDataReceive에 접근할 수 있도록 한다.
            textBoxDataReceive.Invoke(new MethodInvoker(delegate ()
            {
                textBoxDataReceive.Text = str;
            }));
        }        
    }

    
}
