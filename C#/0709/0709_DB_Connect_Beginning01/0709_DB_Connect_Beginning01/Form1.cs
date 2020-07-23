using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0709_DB_Connect_Beginning01
{
    public partial class Form1 : Form
    {

        MySqlConnection connection = new MySqlConnection("Server=localhost;Database=db_test01;Uid=Application01;Pwd=1234;");
        
        public Form1()
        {
            InitializeComponent();

            dataGridView1.ColumnCount = 3;
            dataGridView1.Columns[0].HeaderText = "Number";
            dataGridView1.Columns[1].HeaderText = "Name";
            dataGridView1.Columns[2].HeaderText = "Age";
            //dataGridView1.Columns[1].HeaderText = "LightSensor";

            connection.Open();
        }

        private void SelectAstaric(object sender, EventArgs e)
        {
            try
            {
                string selectAll = "Select * From user";
                MySqlCommand mySqlCommand = new MySqlCommand(selectAll, connection);

                dataGridView1.Rows.Clear();

                using (MySqlDataReader reader = mySqlCommand.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        dataGridView1.Rows.Add(reader.GetValue(0).ToString(),
                            reader.GetValue(1).ToString(),
                            reader.GetValue(2).ToString());
                    }
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }            
        }

        private void SelectJang(object sender, EventArgs e)
        {
            try
            {
                string selectJang = "Select * From user Where name =\"Jang\"";
                MySqlCommand mySqlCommand = new MySqlCommand(selectJang, connection);

                dataGridView1.Rows.Clear();

                using (MySqlDataReader reader = mySqlCommand.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        dataGridView1.Rows.Add(reader.GetValue(0).ToString(),
                            reader.GetValue(1).ToString(),
                            reader.GetValue(2).ToString());
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }
        }

        private void ShowCount(object sender, EventArgs e)
        {
            int count = 0;
            try
            {
                string selectCount = "Select Count(*) From user";
                MySqlCommand mySqlCommand = new MySqlCommand(selectCount, connection);

                using (MySqlDataReader reader = mySqlCommand.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        count = int.Parse(reader.GetValue(0).ToString());
                    }
                }
                MessageBox.Show(count.ToString());
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }
        }

        private void AddUser(object sender, EventArgs e)
        {
            /*
            int count = 0;
            try
            {
                string selectCount = "Select UserNumber From user";
                MySqlCommand mySqlCommand = new MySqlCommand(selectCount, connection);
                
                using (MySqlDataReader reader = mySqlCommand.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        count = int.Parse(reader.GetValue(0).ToString());
                    }
                }
                count = count + 1;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }
            */
            try
            {

                string name = textBoxName.Text;
                int age = int.Parse(textBoxAge.Text);                

                string AddUser = "INSERT INTO user(Name, Age) VALUES("
                    + "'" + name + "'," + age.ToString() + ")";                
                MySqlCommand mySqlCommand = new MySqlCommand(AddUser, connection);
                mySqlCommand.ExecuteNonQuery();
                textBoxName.Text = "";
                textBoxAge.Text = "";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }
        }

        private void DelUser(object sender, EventArgs e)
        {
            try
            {

                string name = textBoxName.Text;
                int age = int.Parse(textBoxAge.Text);

                int userNumber = int.Parse(textBoxUserNumber.Text);

                string DelUser = "Delete From user " +
                    "Where UserNumber = " + userNumber;
                MySqlCommand mySqlCommand = new MySqlCommand(DelUser, connection);
                mySqlCommand.ExecuteNonQuery();
                textBoxName.Text = "";
                textBoxAge.Text = "";
                textBoxUserNumber.Text = "";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }
        }

        private void UpdateUser(object sender, EventArgs e)
        {
            try
            {

                string name = textBoxName.Text;
                int age = int.Parse(textBoxAge.Text);

                int userNumber = int.Parse(textBoxUserNumber.Text);

                string UpdateUser = "Update user " +
                    "set Age = " + age.ToString() +
                    ", Name = '" + name + "' " +
                    " Where UserNumber = " + userNumber;
                MySqlCommand mySqlCommand = new MySqlCommand(UpdateUser, connection);
                mySqlCommand.ExecuteNonQuery();
                textBoxName.Text = "";
                textBoxAge.Text = "";
                textBoxUserNumber.Text = "";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }
        }
    }
}
