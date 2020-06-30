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


namespace _0619_HW01
{
    public partial class Form1 : Form
    {
        List<User> user;
        Dictionary<string, User> dicUsers;
        public Form1()
        {
            InitializeComponent();
            user = new List<User>();
            dicUsers = new Dictionary<string, User>();

            try
            {
                string[] loaded = File.ReadAllLines(@"./User.txt");
                foreach (string s in loaded)
                {
                    string[] data = s.Split('|');
                    User userGet = new User(data[0], data[1], int.Parse(data[2]));
                    user.Add(userGet);
                    
                    dicUsers.Add(userGet.getPhone(), userGet);
                }
            }
            catch(Exception e)
            {
                MessageBox.Show("NO DATA");
            }            
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            bool fine = true;
            string getName = textBoxInputName.Text;
            string getPhone = textBoxInputPhone.Text;
            string getAge = textBoxInputAge.Text;
            int numAge = 0;
            try
            {
                numAge = int.Parse(getAge);
            }
            catch(Exception ex)
            {
                fine = false;
            }
            if (fine)
            {
                MessageBox.Show("SAVE");
                textBoxInputAge.Text = "";
                textBoxInputName.Text = "";
                textBoxInputPhone.Text = "";
                user.Add(new User(getName, getPhone, numAge));

                if (!dicUsers.ContainsKey(getPhone))
                {
                    // 중복 키 조회
                    dicUsers.Add(getPhone, new User(getName, getPhone, numAge));
                }
                else
                {
                    MessageBox.Show("Already exist");
                }

                using (StreamWriter sw = new StreamWriter("User.txt", false))//덮어쓰기
                {
                    foreach (User u in user)
                    {
                        string data = u.Personal();
                        sw.WriteLine(data);
                    }
                }
            }
            else
            {
                textBoxInputAge.Text = "";
                MessageBox.Show("Invaild Age Value");
            }
        }

        private void buttonSearch_Click(object sender, EventArgs e)
        {
            bool fine = true;
            string getName = textBoxSearchName.Text;
            string getPhone = textBoxSearchPhone.Text;
            string getAge = textBoxSearchAge.Text;
            int numAge = 0;
            if(getAge != "")
            {
                try
                {
                    numAge = int.Parse(getAge);
                }
                catch (Exception ex)
                {
                    fine = false;
                    MessageBox.Show("Invaild Age Value");
                }
            }            
            if (fine)
            {
                foreach (User u in user)
                {
                    if ((u.getAge() == numAge) || (u.getName().Equals(getName)) || (u.getPhone().Equals(getPhone)))
                    {
                        textBoxSearchAge.Text = u.getAge().ToString();
                        textBoxSearchName.Text = u.getName();
                        textBoxSearchPhone.Text = u.getPhone();
                        break;
                    }
                }

                foreach(string s in dicUsers.Keys)
                {
                    if (s.Equals(getPhone))
                    {
                        break;
                    }
                }
                
            }
            else
            {
                textBoxInputAge.Text = "";
            }
        }

        private void buttonReset_Click(object sender, EventArgs e)
        {
            textBoxSearchAge.Text = "";
            textBoxSearchName.Text = "";
            textBoxSearchPhone.Text = "";
        }

        private void buttonWrite_Click(object sender, EventArgs e)
        {
            //StreamWriter sw = new StreamWriter("User.txt", false);
            
            using (StreamWriter sw = new StreamWriter("User.txt", false))//덮어쓰기
            {
                foreach (User u in user)
                {
                    string data = u.Personal();
                    sw.WriteLine(data);
                }
            }
        }

        private void buttonLoad_Click(object sender, EventArgs e)
        {
            user = new List<User>();
            string[] loaded = File.ReadAllLines(@"./User.txt");
            foreach(string s in loaded)
            {
                string[] data = s.Split('|');
                User userGet = new User(data[0], data[1], int.Parse(data[2]));
                user.Add(userGet);
            }
        }

        private void buttonList_Click(object sender, EventArgs e)
        {
            string data;
            textBoxList.Text = "";
            foreach(User u in user)
            {
                data = u.Personal();
                textBoxList.Text += data;
                textBoxList.Text += "\r\n";
            }            
        }
    }
}
