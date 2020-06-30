using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0629_Review02_Delegate
{
    delegate void TestDel01();
    delegate int TestDel02(int num1, int num2);
    delegate T TestDel03<T>(T x, T y);
    // T에 무엇이 오든 사용가능. object같은 역할이다.
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public void ListDelegate()
        {
            List<TestDel01> Functions = new List<TestDel01>();
            Functions.Add(method01);
            Functions.Add(method02);
            Functions.Add(method03);
        }
        public void MethodsDelegate()
        {
            
        }

        public void method01()
        {
            MessageBox.Show("Method01");
        }
        public void method02()
        {
            MessageBox.Show("Method02");
        }
        public void method03()
        {
            MessageBox.Show("Method03");
        }
    }

    
}
