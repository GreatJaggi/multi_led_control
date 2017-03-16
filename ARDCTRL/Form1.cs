using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace ARDCTRL
{
    public partial class Form1 : Form
    {
        private SerialPort ardPort;
        Boolean buttonsEnabled = false;

        public Form1()
        {
            InitializeComponent();
            init();
        }

        private void init()
        {
            try
            {
                ardPort = new SerialPort();
                ardPort.BaudRate = 9600;
                ardPort.PortName = "COM3";
                ardPort.Open();

                // Turn off all led initially
                ardPort.WriteLine("7");
            }
            catch (Exception e)
            {
                MessageBox.Show("Unexpected Error");
            }


        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {
            // Room 1 Checkbox
            ardPort.WriteLine("1");
            
        }

        private void checkBox7_CheckedChanged(object sender, EventArgs e)
        {
            // Room 2 Checkbox
            ardPort.WriteLine("2");
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            // Bathroom Checkbox
            ardPort.WriteLine("3");
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            // Living Room Checkbox
            ardPort.WriteLine("4");
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            // Kitchen Checkbox
            ardPort.WriteLine("5");
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            // Garage Checkbox
            ardPort.WriteLine("6");
        }

        // When the form loads
        private void Form1_Load(object sender, EventArgs e)
        {
            // Turn off all leds
            ardPort.WriteLine("7");
        }

        // If the checkbox has changed its value
        private void checkBox6_CheckedChanged(object sender, EventArgs e)
        {
            // If the checkbox is now checked
            if(checkBox6.Checked)
            {

                checkBox5.Checked = true;
                checkBox7.Checked = true;
                checkBox3.Checked = true;
                checkBox1.Checked = true;
                checkBox2.Checked = true;
                checkBox4.Checked = true;

                // Turn on all leds
                ardPort.WriteLine("8");
                

            }
            
            if(!checkBox6.Checked)
            {
                

                checkBox5.Checked = false;
                checkBox7.Checked = false;
                checkBox3.Checked = false;
                checkBox1.Checked = false;
                checkBox2.Checked = false;
                checkBox4.Checked = false;
                

                // Turn off all leds
                ardPort.WriteLine("7");


            }
        }
    }
}
