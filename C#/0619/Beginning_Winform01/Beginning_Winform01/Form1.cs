using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text;
using System.IO;

namespace Beginning_Winform01
{
    public partial class Form1 : Form
    {
        List<User> users;

        bool found;
        int foundIdx;

        public Form1()
        {
            InitializeComponent();
            users = new List<User>();
            found = false;
            foundIdx = 0;
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            bool fineState = true;
            string getName = textBoxName.Text;
            string getPhone = textBoxPhone.Text;
            string getAge = textBoxAge.Text;
            int intage = 0;
            try
            {
                intage = int.Parse(getAge);
            }
            catch(Exception ex)
            {
                MessageBox.Show("Not Available Age Data");
                fineState = false;
                textBoxAge.Text = "";
            }
            if (getName.Equals(""))
            {
                fineState = false;
            }
            if (getPhone.Equals("") || !getPhone.Contains("-"))
            {
                fineState = false;
                textBoxPhone.Text = "";
            }
            if (fineState)
            {
                textBoxUsers.Text = "";
                User newUser = new User(getName, getPhone, intage);
                users.Add(newUser);
                int idx = 0;                
                foreach(User u in users)
                {                    
                    textBoxUsers.Text += idx + " = ";
                    textBoxUsers.Text += u.Personal();
                    textBoxUsers.Text += "\r\n";
                    idx++;
                }                
                textBoxAge.Text = "";
                textBoxName.Text = "";
                textBoxPhone.Text = "";
            }
            else
            {
                
            }
        }

        private void buttonSearch_Click(object sender, EventArgs e)
        {
            string getName = textBoxSearch.Text;
            string getPhone = textBoxSearchPhone.Text;
            string getAge = textBoxSearchAge.Text;
            
            textBoxSearch.Text = "";
            textBoxSearchPhone.Text = "";
            textBoxSearchAge.Text = "";
            int idx = 0;
            foreach (User u in users)
            {
                if (u.getName().Equals(getName))
                {
                    LableSearchResult.Text = "Result : " + u.Personal();
                    break;
                }
                if(u.getAge().ToString().Equals(getAge))
                {
                    LableSearchResult.Text = "Result : " + u.Personal();
                    break;
                }
                if (u.getPhone().Equals(getPhone))
                {
                    LableSearchResult.Text = "Result : " + u.Personal();
                    break;
                }
                idx++;
            }
            if (idx == users.Count)
            {
                LableSearchResult.Text = "NOT FOUND";
            }
            else
            {
                textBoxSearch.Text = users[idx].getName();
                textBoxSearchPhone.Text = users[idx].getPhone();
                textBoxSearchAge.Text = users[idx].getAge().ToString();
                found = true;
                foundIdx = idx;
            }
        }
        private void buttonEdit_Click(object sender, EventArgs e)
        {
            if (found)
            {
                string getName = textBoxSearch.Text;
                string getPhone = textBoxSearchPhone.Text;
                string getAge = textBoxSearchAge.Text;
                int intage = 0;

                try
                {
                    intage = int.Parse(getAge);
                }
                catch
                {
                    MessageBox.Show("Invaild Age Value");
                    textBoxSearchAge.Text = "";
                }
                if(!textBoxSearchAge.Text.Equals(""))
                {
                    users[foundIdx].setAge(intage);
                    users[foundIdx].setName(getName);
                    users[foundIdx].setPhone(getPhone);
                    found = false;

                    textBoxSearch.Text = "";
                    textBoxSearchAge.Text = "";
                    textBoxSearchPhone.Text = "";
                }
                
            }
        }
        private void buttonSave_Click(object sender, EventArgs e)
        {
            using(StreamWriter sw = new StreamWriter("User.txt", false))//덮어쓰기
            {
                string strGet = "";
                strGet = textBoxUsers.Text;
                sw.WriteLine(strGet);
            }
        }

        private void buttonLoad_Click(object sender, EventArgs e)
        {
            string loaded = File.ReadAllText(@"./User.txt");
            textBoxUsers.Text = loaded;
        }

        private void buttonLog_Click(object sender, EventArgs e)
        {
            string today = DateTime.Today.ToString("yyyy-mm-dd");
            string data = DateTime.Today.ToString("yyyy-mm-dd HH:mm:ss") + "LOG";
            using (StreamWriter sw = new StreamWriter(today + ".txt", true))//이어쓰기
            {
                sw.WriteLine(data);
            }
        }

        private void buttonReadLog_Click(object sender, EventArgs e)
        {
            string today = DateTime.Today.ToString("yyyy-mm-dd");
            string loaded = File.ReadAllText(@"./" + today + ".txt");
            textBoxLOG.Text = loaded;
        }

        
    }
}
