using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0709_ADC_Beginning01
{
    public partial class ShowHistory : Form
    {


        public ShowHistory()
        {
            InitializeComponent();
            dataGridView1.ColumnCount = 2;
            dataGridView1.Columns[0].HeaderText = "Time";
            dataGridView1.Columns[1].HeaderText = "LightSensor";
        }

        private void SearchHistory(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();

            string start = textBox1.Text;
            string end = textBox2.Text;
            if (!start.Contains(".") || !end.Contains("."))
            {
                MessageBox.Show("Invaild Date Format");                
            }
            try
            {
                string[] starts = start.Split('.');
                string[] ends = end.Split('.');

                int startMonth = int.Parse(starts[0]);
                int startDay = int.Parse(starts[1]);
                int startHour = int.Parse(starts[2]);

                int endMonth = int.Parse(ends[0]);
                int endDay = int.Parse(ends[1]);
                int endHour = int.Parse(ends[2]);

                History history = History.CreateHistory();

                int idx = 0;

                Dictionary<DateTime, int> copy = new Dictionary<DateTime, int>(history.lightSensor);

                foreach (DateTime dateTime in copy.Keys)
                {
                    if ((dateTime.Month >= startMonth) && (dateTime.Month <= endMonth))
                    {
                        if ((dateTime.Day >= startDay) && (dateTime.Day <= endDay))
                        {
                            if ((dateTime.Hour >= startHour) && (dateTime.Hour <= endHour))
                            {
                                string parsed = dateTime.Month.ToString() + "|" + dateTime.Day.ToString()
                                    + "|" + dateTime.Hour.ToString();
                                string values = copy[dateTime].ToString();
                                string[] row = { parsed, values };
                                dataGridView1.Rows.Add(row);
                            }
                        }
                    }
                }
            }
            catch(Exception ex)
            {
                textBox1.Text = " . . ";
                textBox1.Text = " . . ";
            }       
        }
    }
}
